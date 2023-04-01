#include"header.h"
#include<fstream>

//takes in the number of the .txt file chosen (and return to the main function)
char filecheck(){
  bool f1 = false, f2 = false, f3 = false;
  string choice = "0 - return to mainpage", temp;
  ifstream file1 ("file1.txt"), file2 ("file2.txt"), file3 ("file3.txt");
  if (file3){
    f3 = true;
    choice = "3 - save file 3, " + choice;
    file3.close();
  }
  if (file2){
    f2 = true;
    choice = "2 - save file 2, " + choice;
    file2.close();
  }
  if (file1){
    f1 = true;
    choice = "1 - save file 1, " + choice;
    file1.close();
  }
  cout << choice << endl;
  printf("Choose a save file (enter with number): ");
  while (true){
    cin >> temp;
    if (temp.length() == 1)
      if (((temp[0] == '0') || (f1 && (temp[0] == '1'))) || ((f2 && (temp[0] == '2')) || (f3 && (temp[0] == '3'))))
        break;
    printf("Invalid option! Please input option again: ");
  }
  return temp[0];
}

//delete the saved .txt file
void delete_file(char n){
  string name = "file";
  name = name + n + ".txt";
  if (remove(name.c_str()) != 0)
      printf("File deleted successfully.\n");
  else
    printf("Error: file cannot be deleted.\n");
}

//save game progress and return to mainpage
void saveProgress(){
  save:
  string temp, name = "file";
  printf("1 - save file 1, 2 - save file 2, 3 - save file 3, 4 - Exit without saving\n");
  printf("Choose an option (enter with number): ");
  while (true){
      cin >> temp;
      if (temp.length() == 1)
        if ((temp[0] >= '1') && (temp[0] <= '4'))
          break;
      printf("Invalid option! Please input option again: ");
    }
  if (temp[0] == '4'){
    return;
  }
  else{
    name = name + temp[0] + ".txt";
    ifstream f (name.c_str());
    if (f){
      printf("The file is used. Do you want to overwrite it? (Y for yes, N for no) ");
      while (true){
        cin >> temp;
        if (temp.length() == 1)
          if ((temp[0] == 'Y') || (temp[0] == 'N'))
            break;
        printf("Invalid option! Please input option again: ");
      }
    f.close();
    if (temp[0] == 'N')
      goto save;
    }

    ofstream file (name.c_str(), ios::trunc | ios::out);
    if (file){
      for (vector<card>::iterator i = discarded.begin(); i != discarded.end(); i++){
        file << i->id << ' ';
      }
      file << "-1" << endl;
      for (vector<card>::iterator i = draw.begin(); i != draw.end(); i++){
        file << i->id << ' ';
      }
      file << "-1" <<endl;

      while (P1.handHead != NULL){
        file << P1.handHead->id << ' ';
        P1.handHead = P1.handHead->next;
      }
      file << "-1" << endl;
      while (P1.bankHead != NULL){
        file << P1.bankHead->id << ' ';
        P1.bankHead = P1.bankHead->next;
      }
      file << "-1" << endl;
      file << P1.landHead.size() << endl;;
      for (vector<card>::iterator i = P1.landHead.begin(); i != P1.landHead.end(); i++){
        card* j = i->next;
        file << i->id;
        while (j != NULL){
          file << ' ' << j->id;
          j = j->next;
        }
        file << " -1" << endl;
      }
      file << P1.sayNo << endl << P1.doubleRent << endl << P1.wealth << endl;

      while (comp.handHead != NULL){
        file << comp.handHead->id << ' ';
        comp.handHead = comp.handHead->next;
      }
      file << "-1" << endl;
      while (comp.bankHead != NULL){
        file << comp.bankHead->id << ' ';
        comp.bankHead = comp.bankHead->next;
      }
      file << "-1" << endl;
      file << comp.landHead.size() << endl;;
      for (vector<card>::iterator i = comp.landHead.begin(); i != comp.landHead.end(); i++){
        card* j = i->next;
        file << i->id;
        while (j != NULL){
          file << ' ' << j->id;
          j = j->next;
        }
        file << " -1" << endl;
      }
      file << comp.sayNo << endl << comp.doubleRent << endl << comp.wealth << endl;
      printf("File saved.\nBack to mainpage now.\n");
    }
    else{
      printf("Error: Saving fail.\n");
      file.close();
      goto save;
    }
  }
}

//initialize the status of players from data in the .txt file
bool initialize(char n){
  genCards();
  string name = "file";
  name = name + n + ".txt";
  ifstream f (name.c_str());
  if (f){
    int n, s;
    while (f >> n){
      if (n == -1)
        break;
      discarded.push_back(cardPool[index(n, cardPool)]);
      cardPool.erase(cardPool.begin()+index(n, cardPool));
    }
    while (f >> n){
      if (n == -1)
        break;
      draw.push_back(cardPool[index(n, cardPool)]);
      cardPool.erase(cardPool.begin()+index(n, cardPool));
    }
    card *cur , *first;
    int l = 0;
    while (f >> n){
      if (n == -1)
        break;
      l++;
      if (l == 1){
        P1.handHead = &draw[index(n ,draw)];
        cur = P1.handHead;
        first = cur;
      }
      else{
        cur->next = &draw[index(n ,draw)];
        cur = cur->next;
      }
    }
    P1.handHead = first;

    l = 0;
    while (f >> n){
      if (n == -1)
        break;
      l++;
      if (l == 1){
        P1.bankHead = &draw[index(n ,draw)];
        cur = P1.bankHead;
        first = cur;
      }
      else{
        cur->next = &draw[index(n ,draw)];
        cur = cur->next;
      }
    }
    P1.bankHead = first;

    f >> s;
    for (int i = 0; i < s; i++){
      f >> n;
      P1.landHead.push_back(draw[index(n, draw)]);
      f >> n;
      if (n != -1){
        P1.landHead[i].next = &draw[index(n, draw)];
        cur = P1.landHead[i].next;
        first = cur;
        while (f >> n){
          if (n == -1)
            break;
          cur->next = &draw[index(n, draw)];
          cur = cur->next;
        }
        P1.landHead[i].next = first;
      }
    }

    f >> P1.sayNo >> P1.doubleRent >> P1.wealth;

    l = 0;
    while (f >> n){
      if (n == -1)
        break;
      l++;
      if (l == 1){
        comp.handHead = &draw[index(n ,draw)];
        cur = comp.handHead;
        first = cur;
      }
      else{
        cur->next = &draw[index(n ,draw)];
        cur = cur->next;
      }
    }
    comp.handHead = first;

    l = 0;
    while (f >> n){
      if (n == -1)
        break;
      l++;
      if (l == 1){
        comp.bankHead = &draw[index(n ,draw)];
        cur = comp.bankHead;
        first = cur;
      }
      else{
        cur->next = &draw[index(n ,draw)];
        cur = cur->next;
      }
    }
    comp.bankHead = first;

    f >> s;
    for (int i = 0; i < s; i++){
      f >> n;
      comp.landHead.push_back(draw[index(n, draw)]);
      f >> n;
      if (n != -1){
        comp.landHead[i].next = &draw[index(n, draw)];
        cur = P1.landHead[i].next;
        first = cur;
        while (f >> n){
          if (n == -1)
            break;
          cur->next = &draw[index(n, draw)];
          cur = cur->next;
        }
        comp.landHead[i].next = first;
      }
    }

    f >> comp.sayNo >> comp.doubleRent >> comp.wealth;

    f.close();
    return true;
  }
  else{
    printf("Error: file cannot be opened.\nBack to mainpage now.\n");
    f.close();
    return false;
  }
}
