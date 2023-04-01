#include "header.h"
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;


//generate all cards at game start
//and return a vector of cards
void genCards() {
    cardPool = {
      //pushback cards to cardPool
      //34 action cards
      { 0, "Deal Breaker", 5, "None", NULL},
      { 1, "Deal Breaker", 5, "None", NULL},
      { 2, "Just Say No", 4, "None", NULL},
      { 3, "Just Say No", 4, "None", NULL},
      { 4, "Just Say No", 4, "None", NULL},
      { 5, "Sly Deal", 3, "None", NULL},
      { 6, "Sly Deal", 3, "None", NULL},
      { 7, "Sly Deal", 3, "None", NULL},
      { 8, "Force Deal", 3, "None", NULL},
      { 9, "Force Deal", 3, "None", NULL},
      { 10, "Force Deal", 3, "None", NULL},
      { 11, "Debt Collector", 3, "None", NULL},
      { 12, "Debt Collector", 3, "None", NULL},
      { 13, "Debt Collector", 3, "None", NULL},
      { 14, "It\'s My Birthday", 2, "None", NULL},
      { 15, "It\'s My Birthday", 2, "None", NULL},
      { 16, "It\'s My Birthday", 2, "None", NULL},
      { 17, "Pass Go", 1, "None", NULL},
      { 18, "Pass Go", 1, "None", NULL},
      { 19, "Pass Go", 1, "None", NULL},
      { 20, "Pass Go", 1, "None", NULL},
      { 21, "Pass Go", 1, "None", NULL},
      { 22, "Pass Go", 1, "None", NULL},
      { 23, "Pass Go", 1, "None", NULL},
      { 24, "Pass Go", 1, "None", NULL},
      { 25, "Pass Go", 1, "None", NULL},
      { 26, "Pass Go", 1, "None", NULL},
      { 27, "House", 3, "House", NULL},
      { 28, "House", 3, "House", NULL},
      { 29, "House", 3, "House", NULL},
      { 30, "Hotel", 4, "Hotel", NULL},
      { 31, "Hotel", 4, "Hotel", NULL},
      { 32, "Hotel", 4, "Hotel", NULL},
      { 33, "Double The Rent", 1, "None", NULL},
      { 34, "Double The Rent", 1, "None", NULL},


    //28 property cards
      { 35, "Green Property Card", 4, "Green", NULL},
      { 36, "Green Property Card", 4, "Green", NULL},
      { 37, "Green Property Card", 4, "Green", NULL},
      { 38, "Dark Blue Property Card", 4, "DarkBlue", NULL},
      { 39, "Dark Blue Property Card", 4, "DarkBlue", NULL},
      { 40, "Light Blue Property Card", 1, "LightBlue", NULL},
      { 41, "Light Blue Property Card", 1, "LightBlue", NULL},
      { 42, "Light Blue Property Card", 1, "LightBlue", NULL},
      { 43, "Red Property Card", 3, "Red", NULL},
      { 44, "Red Property Card", 3, "Red", NULL},
      { 45, "Red Property Card", 3, "Red", NULL},
      { 46, "Utility Property Card", 2, "Utility", NULL},
      { 47, "Utility Property Card", 2, "Utility", NULL},
      { 48, "Yellow Property Card", 3, "Yellow", NULL},
      { 49, "Yellow Property Card", 3, "Yellow", NULL},
      { 50, "Yellow Property Card", 3, "Yellow", NULL},
      { 51, "Orange Property Card", 2, "Orange", NULL},
      { 52, "Orange Property Card", 2, "Orange", NULL},
      { 53, "Orange Property Card", 2, "Orange", NULL},
      { 54, "Brown Property Card", 1, "Brown", NULL},
      { 55, "Brown Property Card", 1, "Brown", NULL},
      { 56, "Purple Property Card", 2, "Purple", NULL},
      { 57, "Purple Property Card", 2, "Purple", NULL},
      { 58, "Purple Property Card", 2, "Purple", NULL},
      { 59, "Railroad Property Card", 1, "Railroad", NULL},
      { 60, "Railroad Property Card", 1, "Railroad", NULL},
      { 61, "Railroad Property Card", 1, "Railroad", NULL},
      { 62, "Railroad Property Card", 1, "Railroad", NULL},


    //11 property wildcards
      { 63, "Purple/Orange Property Wildcard", 2, "Purple|Orange", NULL},
      { 64, "Purple/Orange Property Wildcard", 2, "Purple|Orange", NULL},
      { 65, "Light Blue/Brown Property Wildcard", 1, "LightBlue|Brown", NULL},
      { 66, "Light Blue/Railroad Property Wildcard", 4, "LightBlue|Railroad", NULL},
      { 67, "Dark Blue/Green Property Wildcard", 4, "DarkBlue|Green", NULL},
      { 68, "Railroad/Green Property Wildcard", 4, "Railroad|Green", NULL},
      { 69, "Red/Yellow Property Wildcard", 3, "Red|Yellow", NULL},
      { 70, "Red/Yellow Property Wildcard", 3, "Red|Yellow", NULL},
      { 71, "Utility/Railroad Property Wildcard", 2, "Utility|Railroad", NULL},
      { 72, "Multi-Coloured Property Wildcard", 0, "All", NULL},
      { 73, "Multi-Coloured Property Wildcard", 0, "All", NULL},


    //13 rent cards
      { 74, "Purple/Orange Rent Card", 1, "Purple,Orange", NULL},
      { 75, "Purple/Orange Rent Card", 1, "Purple,Orange", NULL},
      { 76, "Railroad/Utility Rent Card", 1, "Railroad,Utility", NULL},
      { 77, "Railroad/Utility Rent Card", 1, "Railroad,Utility", NULL},
      { 78, "Green/Dark Blue Rent Card", 1, "Green,DarkBlue", NULL},
      { 79, "Green/Dark Blue Rent Card", 1, "Green,DarkBlue", NULL},
      { 80, "Brown/Light Blue Rent Card", 1, "Brown,LightBlue", NULL},
      { 81, "Brown/Light Blue Rent Card", 1, "Brown,LightBlue", NULL},
      { 82, "Red/Yellow Rent Card", 1, "Red,Yellow", NULL},
      { 83, "Red/Yellow Rent Card", 1, "Red,Yellow", NULL},
      { 84, "Wild Rent Card", 3, "All", NULL},
      { 85, "Wild Rent Card", 3, "All", NULL},
      { 86, "Wild Rent Card", 3, "All", NULL},


    //20 money cards
      { 87, "$10M", 10, "None", NULL},
      { 88, "$5M", 5, "None", NULL},
      { 89, "$5M", 5, "None", NULL},
      { 90, "$4M", 4, "None", NULL},
      { 91, "$4M", 4, "None", NULL},
      { 92, "$4M", 4, "None", NULL},
      { 93, "$3M", 3, "None", NULL},
      { 94, "$3M", 3, "None", NULL},
      { 95, "$3M", 3, "None", NULL},
      { 96, "$2M", 2, "None", NULL},
      { 97, "$2M", 2, "None", NULL},
      { 98, "$2M", 2, "None", NULL},
      { 99, "$2M", 2, "None", NULL},
      { 100, "$2M", 2, "None", NULL},
      { 101, "$1M", 1, "None", NULL},
      { 102, "$1M", 1, "None", NULL},
      { 103, "$1M", 1, "None", NULL},
      { 104, "$1M", 1, "None", NULL},
      { 105, "$1M", 1, "None", NULL},
      { 106, "$1M", 1, "None", NULL}};
}


//return if the card is available (not used)
bool cardUnpicked(int cardID){
    int i = cardPool.size()-1;
    while (cardPool[i].id != cardID){
      i--;
      if (i < 0)
        return false;
    }
    return true;
}

int index(int cardID, vector<card> v){
  int i = v.size()-1;
  while (v[i].id != cardID){
    i--;
  }
  return i;
}


//randomly distribute an available card to P
//remove card from cardPool
void getCard(player &P) {
    srand(time(NULL));
    //check if is JustSayNo, update P.sayNo to true
    int s = cardPool.size(), id = rand() % s;

    if ((id <= 4) && (id >= 2))
      P.sayNo = true;

    draw.push_back(cardPool[index(id, cardPool)]);
    cardPool.erase(cardPool.begin()+index(id, cardPool));
    cardPool.shrink_to_fit();
    if (P.handHead != NULL){
      if (P.handHead->next == NULL)
        P.handHead->next = &draw.back();
      else{
        card *first = P.handHead;
        while (P.handHead->next != NULL){
          P.handHead = P.handHead->next;
        }
        P.handHead->next = &draw.back();
        P.handHead->next->next = NULL;
        P.handHead = first;
        }
    }
    else if (draw.size() == 1){
      P.handHead = &draw.front();
      P.handHead->next = NULL;
    }
    else{
      P.handHead = &draw.back();
      P.handHead->next = NULL;
    }

    if (cardPool.empty()){
      cardPool.swap(discarded);
      for (vector<card>::iterator i = cardPool.begin(); i != cardPool.end(); i++){
        i->next = NULL;
      }
      discarded.shrink_to_fit();
    }
}

//count number of cards in hand
int count(card *&current){
  card *first = current;
  int len = 0;
  if (current == NULL)
    return 0;
  if (current->next == NULL){
    return 1;
  }
  while (current->next != NULL) {
    len++;
    current = current->next;
  }
  current = first;
  return len+1;
}

//prints information of players (player P1 and computer)
//including land info (property cards) and bank info (money cards)
void printInfo(){
  card *first = P1.bankHead;
  int *temp = new int[6], i;
  for (i = 0; i < 6; i++){
    *(temp+i) = 0;
  }
  if (P1.bankHead!= NULL){
    while (P1.bankHead->next != NULL){
      switch (P1.bankHead->value) {
        case 1:
          temp[0]++;
          break;
        case 2:
          temp[1]++;
          break;
        case 3:
          temp[2]++;
          break;
        case 4:
          temp[3]++;
          break;
        case 5:
          temp[4]++;
          break;
        case 10:
          temp[5]++;
          break;
      };
    P1.bankHead = P1.bankHead->next;
    }
    switch (P1.bankHead->value) {
      case 1:
        temp[0]++;
        break;
      case 2:
        temp[1]++;
        break;
      case 3:
        temp[2]++;
        break;
      case 4:
        temp[3]++;
        break;
      case 5:
        temp[4]++;
        break;
      case 10:
        temp[5]++;
        break;
    };
    P1.bankHead = first;
  }

  printf("Player: \n  Bank: $1M*%d, $2M*%d, $3M*%d, $4M*%d, $5M*%d, $10M*%d, Total = %d\n  land: ", temp[0], temp[1], temp[2], temp[3], temp[4], temp[5], P1.wealth);
  for (i = P1.landHead.size()-1; i >= 0; i--){
    if (i != P1.landHead.size()-1)
      printf("\n      ");
    printf("%s", (P1.landHead[i].colour).c_str());
    first = P1.landHead[i].next;
    while (P1.landHead[i].next != NULL){
      printf(", %s", (P1.landHead[i].next->colour).c_str());
      P1.landHead[i].next = P1.landHead[i].next->next;
    }
    P1.landHead[i].next = first;
  }

  for (i = 0; i < 6; i++){
    *(temp+i) = 0;
  }
  first = comp.bankHead;
  if (comp.bankHead!= NULL){
    while (comp.bankHead->next != NULL){
      switch (comp.bankHead->value) {
        case 1:
          temp[0]++;
          break;
        case 2:
          temp[1]++;
          break;
        case 3:
          temp[2]++;
          break;
        case 4:
          temp[3]++;
          break;
        case 5:
          temp[4]++;
          break;
        case 10:
          temp[5]++;
          break;
      };
    comp.bankHead = comp.bankHead->next;
    }
    switch (comp.bankHead->value) {
      case 1:
        temp[0]++;
        break;
      case 2:
        temp[1]++;
        break;
      case 3:
        temp[2]++;
        break;
      case 4:
        temp[3]++;
        break;
      case 5:
        temp[4]++;
        break;
      case 10:
        temp[5]++;
        break;
    };
    comp.bankHead = first;
  }
  printf("\n\nComputer: \n  Bank: $1M*%d, $2M*%d, $3M*%d, $4M*%d, $5M*%d, $10M*%d, Total = %d\n  land: ", temp[0], temp[1], temp[2], temp[3], temp[4], temp[5], comp.wealth);
  for (i = 0; i < comp.landHead.size(); i--){
    if (i != 0)
      printf("\n      ");
    printf("%s", (comp.landHead[i].colour).c_str());
    first = comp.landHead[i].next;
    while (comp.landHead[i].next != NULL){
      printf(", %s", (comp.landHead[i].next->colour).c_str());
      comp.landHead[i].next = comp.landHead[i].next->next;
    }
    comp.landHead[i].next = first;
  }
  printf("\n");
  delete[] temp;
}

//print action menu of P
// "a: end turn\nb: change property colour\nc: my birthday\nd: green property card\n..."
//note: a=end turn and b=change property colour must appear in menu
void printMenu(player P){
  printf("a: end turn\n");
  card *first = P.handHead;
  int i = 0;
  for(int i = 0; i < count(P.handHead); i++){
    printf("%c: %s\n", (char)(98+i), (P.handHead->name).c_str());
    P.handHead = P.handHead->next;
  }
  printf("%c: %s\n", (char)(98+i), (P.handHead->name).c_str());
  P.handHead = first;
}

int find_target(string colour){
  string temp = "";
  size_t pos = colour.find("|");
  if (pos != string::npos){
    for (int i = 0; i < pos; i++){
      temp += colour[i];
    }
  }
  else
    temp = colour;

  if ((((((temp == "Green") || (temp == "LightBlue")) || (temp == "Red")) || (temp == "Yellow")) || (temp == "Orange")) || (temp == "Purple"))
    return 3;
  else if (((temp == "DarkBlue") || (temp == "Utility")) || (temp == "Brown"))
    return 2;
  else
    return 4;
}

//return if the coloured property set is completed
bool checkFull(string colour, player P, int i){
  int  now = 1, target = find_target(colour);
  card *first = P.landHead[i].next;
  bool full = false;
  if (P.landHead[i].next != NULL){
    while (P.landHead[i].next->next != NULL){
      P.landHead[i].next = P.landHead[i].next->next;
      now++;
    }
    now++;
    P.landHead[i].next = first;
  }
  if (now >= target)
    full = true;
  return full;
}

//return number of completed property set
int checkFullNum(player P){
  int i, full = 0;
  for (i = 0; i < P.landHead.size(); i++){
    if (checkFull(P.landHead[i].colour, P, i))
      full++;
  }
  return full;
}

//return if P wins the game, i.e. has >=3 complete sets of property
bool checkWin(player P){
  return (checkFullNum(P) >= 3);
}

//put on land:
    //if not single colour: ask for colour, put the chosen colour at the front of propertyCard.colour
    //if new colour: pushback card to landHead
    //if existing colour: append card to the list of the colour
//print player action (e.g. "You put Blue Property Card on your land.\n")
void putProperty(card *propertyCard, player &by){
  card *first;
  string color;
  size_t pos = propertyCard->colour.find("|");
  int i;
  if (propertyCard->colour != "ALL"){
    //single colour
    if (pos == string::npos){
      for (i = by.landHead.size()-1; i >= 0; i--){
        color = by.landHead[i].colour;
        if ((color == propertyCard->colour) && (not checkFull(color, by, i)))
          break;
        }
      if (i == -1)
        by.landHead.push_back(*propertyCard);
      else{
        if (by.landHead[i].next == NULL)
          by.landHead[i].next = propertyCard;
        else{
          first = by.landHead[i].next;
          while (by.landHead[i].next->next != NULL){
            by.landHead[i].next = by.landHead[i].next->next;
          }
          by.landHead[i].next->next = propertyCard;
          by.landHead[i].next = first;
        }
      }
    }
    //two colour
    else{
      string str1 = "", str2 = "", opt, chosen;
      for (i = 0; i < pos; i++){
        str1 = str1 + propertyCard->colour[i];
      }
      for (i = propertyCard->colour.length(); i > pos; i--){
        str2 = str2 + propertyCard->colour[i];
      }
      if (&by == &P1){
        printf(" Which colour do you want to put, 1 - %s or 2 - %s: ", str1.c_str(), str2.c_str());
        while (true){
          cin >> opt;
          if ((opt.length() == 1) && ((opt[0] == '1') || (opt[0] == '2')))
            break;
          printf("Invalid option! Please input option again: ");
          }
      }
      else{
        srand(time(NULL));
        opt[0] = rand()%2+'1';
      }
      if (opt[0] == '1')
        chosen = str1;
      else{
        chosen = str2;
        propertyCard->colour = str2 + "|" +str1;
      }

      for (i = by.landHead.size()-1; i >= 0; i--){
        color = by.landHead[i].colour;
        if ((color == chosen) && (not checkFull(color, by, i)))
          break;
      }
      if (i == -1)
        by.landHead.push_back(*propertyCard);
      else{
        if (by.landHead[i].next == NULL)
          by.landHead[i].next = propertyCard;
        else{
          first = by.landHead[i].next;
          while (by.landHead[i].next->next != NULL){
            by.landHead[i].next = by.landHead[i].next->next;
          }
          by.landHead[i].next->next = propertyCard;
          by.landHead[i].next = first;
        }
      }
    }
  }
  //all
  else{
    int choice = 0, *list = new int[10];
    for (i = 0; i < by.landHead.size(); i++){
      if (not checkFull(by.landHead[i].colour, by, i)){
        printf("%d - ", choice);
        list[choice] = i;
        choice++;
      }
      else
        printf("     ");
      printf("%s", by.landHead[i].colour.c_str());
      first = by.landHead[i].next;
      while (by.landHead[i].next->next != NULL){
        printf(", %s", by.landHead[i].next->colour.c_str());
        by.landHead[i].next = by.landHead[i].next->next;
      }
      printf(", %s\n", by.landHead[i].next->colour.c_str());
      by.landHead[i].next = first;
    }
    string opt;
    if (&by == &P1){
      cin >> opt;
      while (true){
        if ((opt.length() == 1) && ((opt[0]-'0' >= 0) || (opt[0]-'0' <= choice)))
          break;
        printf("Invalid option! Please input option again: ");
      }
    }
    else{
        srand(time(NULL));
        opt[0] = rand()%10+'0';
    }
    choice = list[opt[0]-'0'];
    if (by.landHead[choice].next == NULL)
      by.landHead[choice].next = propertyCard;
    else{
      first = by.landHead[choice].next;
      while (by.landHead[choice].next->next != NULL){
        by.landHead[choice].next = by.landHead[choice].next->next;
      }
      by.landHead[choice].next->next = propertyCard;
      by.landHead[choice].next = first;
    }
  }
  if (&by == &P1)
    printf("You put %s on your land.\n", propertyCard->name.c_str());
  else
    printf("Opponent puts %s on land.\n", propertyCard->name.c_str());
}

void ALL(int i, player &P){
  if (checkFullNum(P) != P.landHead.size())
    putProperty(&P.landHead[i], P);
  else{
    card *first = P.handHead;
    if (P.handHead == NULL){
      P.handHead = &draw[index(P.landHead[i].id, draw)];
    }
    else{
      while (P.handHead->next != NULL){
        P.handHead = P.handHead->next;
      }
      P.handHead->next = &draw[index(P.landHead[i].id, draw)];
      P.handHead = first;
    }
  }
  P.landHead.erase(P.landHead.begin() + index(P.landHead[i].id, P.landHead));
  P.landHead.shrink_to_fit();
}

//append card to player.bankHead, increase player.wealth
//print player action (e.g. "You put '$5M' into yout bank.\n")
void depositMoney(card *moneyCard, player &by){
  if (by.bankHead == NULL){
    by.bankHead = moneyCard;
    by.bankHead->next = NULL;
  }
  else{
    card *first = by.bankHead;
    while (by.bankHead->next != NULL){
      by.bankHead = by.bankHead->next;
    }
    by.bankHead->next = moneyCard;
    by.bankHead->next->next = NULL;
    by.bankHead = first;
  }
  by.wealth += moneyCard->value;
  if (&by == &P1)
    printf("You put \'%s\' into your bank.\n", (moneyCard->name).c_str());
  else
    printf("Opponent puts \'%s\' into bank.\n", (moneyCard->name).c_str());
  printf("Current wealth is $%dM.\n", by.wealth);
}


//return 'y' if player used JustSayNo, else 'n'
//also printing all the required sentences on screen
//e.g. prompting for inputs, instructions
char sayingNo(player &P1, vector<card> &discarded) {
    string opt;
    printf("You have \'Just Say No\' in hand. Do you want to use it? Yes or No (y/n): ");
    while (true) {
        cin >> opt;
        if ((opt.length()==1) && ((opt[0] == 'y') || (opt[0] == 'n')))
          break;
        printf("Please enter either \'y\' for Yes or \'n\' for No: ");
    }
    if (opt[0]=='y') {
        card *prev = P1.handHead;
        card *sayNo;
        if (P1.handHead->id > 1 && P1.handHead->id < 5) {
            sayNo = P1.handHead;
            P1.handHead = P1.handHead->next;
        }
        else {
            while (prev->next->id < 2 || prev->next->id > 4) {
                prev = prev->next;
            }
            sayNo = prev->next;
            prev->next = prev->next->next;
        }
        sayNo->next = NULL;
        discarded.push_back(*sayNo);
        draw.erase(draw.begin()+index(discarded.back().id, draw));
        card *curCard = P1.handHead;
        while (curCard->next != NULL && (curCard->id < 2 || curCard->id > 4)) { curCard = curCard->next; }
        P1.sayNo = (curCard->id < 2 || curCard->id > 4);
    }
    return opt[0];
}


//different output for player by/to!
//if not available: put into bank (e.g. using JustSayNo)
//if available: ask to use card or put into bank?
//use card: discard card, (if is attack: check opponent JustSayNo), perform actions
//put into bank: append card to player.bankHead, increase player.wealth
//print player action (e.g. "You used Pass Go.\n")
//ask for further options for some cards (e.g. which property to steal?)
//print result (e.g. "But the opponent used Just Say No.\n", or "You stole Green Property Card from the opponent.\n")
void makeAction(card *actionCard, player &by, bool isP1, player &to, vector<card> &discarded, vector<card> &cardPool) {
    //bool isP1 = (by == P1); //is it P1's turn?
    printf("%s used \'%s\'.\n", (isP1)? "You" : "The opponent", actionCard->name.c_str());
    card *prev = by.handHead;
    if (prev == actionCard) by.handHead = by.handHead->next;
    else {
        while (prev->next != actionCard) { prev = prev->next; }
        prev->next = prev->next->next;
    }
    switch (actionCard->id) {
        //case 2 ...4: //Just Say No
        case 2:
        case 3:
        case 4:
            printf("\'%s\' cannot be used now. It is deposited into %s bank.\n", actionCard->name.c_str(), (isP1)? "your" : "the opponent\'s");
            depositMoney(actionCard, by);

        //case 0 ...1: //Deal Breaker
        case 0:
        case 1:
            if (checkFullNum(to) < 1) {
                printf("\'%s\' cannot be used now because %s not have a completed property set. It is deposited into %s bank.\n", actionCard->name.c_str(), (isP1)? "the opponent does" : "you do", (isP1)? "your" : "the opponent\'s");
                depositMoney(actionCard, by);
            }
            else if (to.sayNo) {
                discarded.push_back(*actionCard);
                draw.erase(draw.begin()+index(discarded.back().id, draw));
                draw.shrink_to_fit();
                char opt = ((!isP1)? sayingNo(to, discarded) : "yn"[rand()%2]);
                if (opt == 'n' && !isP1) printf("You did not use \'Just Say No\'.\n");
                else { //opt = 'y'
                    printf("%s used \'Just Say No\'.\n", (isP1)? "The opponent" : "You");
                    break;
                }
            }
            else {
                discarded.push_back(*actionCard);
                draw.erase(draw.begin()+index(discarded.back().id, draw));
                draw.shrink_to_fit();
                char option;
                if (isP1) {
                    string opt;
                    printf("Choose one coloured set to take (enter one lowercase letter): ");

                    //print full sets
                    int count = -1;
                    for (int i = 0; i < to.landHead.size(); i++){
                        if (checkFull(to.landHead[i].colour, to, i)) {
                            count++;
                            printf("%c: %s\n", 'a'+count, to.landHead[i].colour.c_str());
                        }
                    }
                    while (true) {
                        cin >> opt;
                        if ((opt.length() == 1) && ((opt[0]-'a' < checkFullNum(to)) && (opt[0]-'a' >= 0)))
                          break;
                        printf("Please enter a valid input! Choose one cololured set to take (enter one lowercase letter): ");
                    }
                    option = opt[0];
                }
                else { //random moves by computer
                    option = rand() % checkFullNum(to) + 'a';
                }
                char count = 'a';
                for (int i=0; i < to.landHead.size(); i++) {
                    if (checkFull(to.landHead[i].colour, to, i)) {
                        if (count==option) {
                            by.landHead.push_back(to.landHead[i]);
                            while (i < to.landHead.size()-1) {
                                to.landHead[i] = to.landHead[i+1];
                                i++;
                            }
                            to.landHead.pop_back();
                            to.landHead.shrink_to_fit();
                            break;
                        }
                        else count = count+1;
                    }
                }
            }

        //case 5 ...7: //Sly Deal
        case 5:
        case 6:
        case 7:
            if (to.landHead.size() == checkFullNum(to)) {
                printf("\'%s\' cannot be used now because %s not have a card that outside a completed set. It is deposited into %s bank.\n", actionCard->name.c_str(), (isP1)? "the opponent does" : "you do", (isP1)? "your" : "the opponent\'s");
                depositMoney(actionCard, by);
            }
            else if (to.sayNo) {
                discarded.push_back(*actionCard);
                draw.erase(draw.begin()+index(discarded.back().id, draw));
                draw.shrink_to_fit();
                char opt = ((!isP1)? sayingNo(to, discarded) : "yn"[rand()%2]);
                if (opt == 'n' && !isP1) printf("You did not use \'Just Say No\'.\n");
                else { //opt = 'y'
                    printf("%s used \'Just Say No\'.\n", (isP1)? "The opponent" : "You");
                    break;
                }
            }
            else {
                discarded.push_back(*actionCard);
                draw.erase(draw.begin()+index(discarded.back().id, draw));
                draw.shrink_to_fit();
                string name="";
                if (isP1) {
                    int opt;
                    int availableID[40] = {-1};

                    printf("Available cards are:\n");
                    //print the available cards (i.e. not part of a completed set)
                    int count = 0;
                    for (int i=0; i < to.landHead.size(); i++) {
                        if (checkFull(to.landHead[i].colour, to, i)) continue;
                        card cur;
                        for (cur = to.landHead[i]; &(cur.next)!=NULL; cur = *(cur.next)) {
                            printf("ID: %d, name: %s\n", cur.id, cur.name.c_str());
                            availableID[count] = cur.id;
                            count++;
                        }
                        printf("ID: %d, name: %s\n", cur.id, cur.name.c_str());
                        availableID[count] = cur.id;
                        count++;
                    }
                    printf("Choose one card to take (enter the ID of the card): ");

                    check:
                    cin >> opt;
                    for (int i=0; i < 40; i++) {
                        if (availableID[i] == opt) goto valid;
                        if (i == 39) {
                            printf("Invalid input. Choose one card to take (enter the ID of the card): ");
                            goto check;
                        }
                    }
                    valid:
                    card *cur, *prev;
                    for (int i=0; i < to.landHead.size(); i++) {
                        if (checkFull(to.landHead[i].colour, to, i)) continue;
                        if (to.landHead[i].id == opt) {
                            cur = &to.landHead[i];
                            to.landHead[i] = *(to.landHead[i].next);
                            cur->next = NULL;
                            if (to.landHead[i].colour == "ALL")
                              ALL(i, to);
                            putProperty(cur, by);
                            break;
                        }
                        prev = &to.landHead[i];
                        while (prev->next->id != opt && prev->next->next != NULL) prev = prev->next;
                        cur = prev->next;
                        if (cur->id == opt) {
                            prev->next = prev->next->next;
                            cur->next = NULL;
                            break;

                        }
                    }
                    name = cur->name;
                }
                else {
                    int opt;
                    int availableID[40] = {-1};
                    int count = 0;
                    for (int i=0; i < to.landHead.size(); i++) {
                        if (checkFull(to.landHead[i].colour, to, i)) continue;
                        card cur;
                        for (cur = to.landHead[i]; &(cur.next)!=NULL; cur = *(cur.next)) {
                            availableID[count] = cur.id;
                            count++;
                        }
                        availableID[count] = cur.id;
                        count++;
                    }
                    opt = rand()%count;
                    opt = availableID[opt];

                    card *cur, *prev;
                    for (int i=0; i < to.landHead.size(); i++) {
                        if (checkFull(to.landHead[i].colour, to, i)) continue;
                        if (to.landHead[i].id == opt) {
                            cur = &(to.landHead[i]);
                            to.landHead[i] = *(to.landHead[i].next);
                            cur->next = NULL;
                            if (to.landHead[i].colour == "ALL")
                              ALL(i, to);
                            putProperty(cur, by);
                            break;
                        }
                        prev = &(to.landHead[i]);
                        while (prev->next->id != opt && prev->next->next != NULL) prev = prev->next;
                        cur = prev->next;
                        if (cur->id == opt) {
                            prev->next = prev->next->next;
                            cur->next = NULL;
                            putProperty(cur, by);
                            break;

                        }
                    }
                    name = cur->name;
                }
                printf("\'%s\' is chosen and put into %s land.\n", name.c_str(), (isP1)? "your" : "the opponent's");
            }

        //case 8 ...10: //Forced Deal
        case 8:
        case 9:
        case 10:
            if (to.landHead.size() == checkFullNum(to)) {
                printf("\'%s\' cannot be used now because %s not have a card that outside a completed set. It is deposited into %s bank.\n", actionCard->name.c_str(), (isP1)? "the opponent does" : "you do", (isP1)? "your" : "the opponent\'s");
                depositMoney(actionCard, by);
            }
            else if (by.landHead.size() == checkFullNum(by)) {
                printf("\'%s\' cannot be used now because %s not have a card that outside a completed set. It is deposited into %s bank.\n", actionCard->name.c_str(), (!isP1)? "the opponent does" : "you do", (!isP1)? "your" : "the opponent\'s");
                depositMoney(actionCard, by);
            }
            else if (to.sayNo) {
                discarded.push_back(*actionCard);
                draw.erase(draw.begin()+index(discarded.back().id, draw));
                draw.shrink_to_fit();
                char opt = ((!isP1)? sayingNo(to, discarded) : "yn"[rand()%2]);
                if (opt == 'n' && !isP1) printf("You did not use \'Just Say No\'.\n");
                else { //opt = 'y'
                    printf("%s used \'Just Say No\'.\n", (isP1)? "The opponent" : "You");
                    break;
                }
            }
            else {
                discarded.push_back(*actionCard);
                draw.erase(draw.begin()+index(discarded.back().id, draw));
                draw.shrink_to_fit();
                if (isP1) {
                    //choosing a card to take from the opponent
                    int opt;
                    int availableID[40] = {-1};
                    int count = 0;
                    printf("Available cards to steal from the opponent are:\n");
                    //print the available cards (i.e. not part of a completed set)
                    for (int i=0; i < to.landHead.size(); i++) {
                        if (checkFull(to.landHead[i].colour, to, i)) continue;
                        card cur;
                        for (cur = to.landHead[i]; &(cur.next)!=NULL; cur = *(cur.next)) {
                            printf("ID: %d, name: %s\n", cur.id, cur.name.c_str());
                            availableID[count] = cur.id;
                            count++;
                        }
                        printf("ID: %d, name: %s\n", cur.id, cur.name.c_str());
                        availableID[count] = cur.id;
                        count++;
                    }
                    printf("Choose one card to take (enter the ID of the card): ");

                    check2:
                    cin >> opt;
                    for (int i=0; i < 40; i++) {
                        if (availableID[i] == opt) goto valid2;
                        if (i == 39) {
                            printf("Invalid input. Choose one card to take (enter the ID of the card): ");
                            goto check2;
                        }
                    }
                    valid2:
                    card *cur, *prev;
                    for (int i=0; i < to.landHead.size(); i++) {
                        if (checkFull(to.landHead[i].colour, to, i)) continue;
                        if (to.landHead[i].id == opt) {
                            cur = &(to.landHead[i]);
                            to.landHead[i] = *(to.landHead[i].next);
                            cur->next = NULL;
                            if (to.landHead[i].colour == "ALL")
                              ALL(i, to);
                            putProperty(cur, by);
                            break;
                        }
                        prev = &(to.landHead[i]);
                        while (prev->next->id != opt && prev->next->next != NULL) prev = prev->next;
                        cur = prev->next;
                        if (cur->id == opt) {
                            prev->next = prev->next->next;
                            cur->next = NULL;
                            putProperty(cur, by);
                            break;

                        }
                    }

                    //choosing a card to give to the opponent
                    opt=0;
                    int newAvailableID[40] = {-1};

                    printf("Available cards to give the opponent are:\n");
                    count = 0;
                    //print the available cards (i.e. not part of a completed set)
                    for (int i=0; i < by.landHead.size(); i++) {
                        if (checkFull(by.landHead[i].colour, by, i)) continue;
                        card cur;
                        for (cur = by.landHead[i]; &(cur.next)!=NULL; cur = *(cur.next)) {
                            printf("ID: %d, name: %s\n", cur.id, cur.name.c_str());
                            newAvailableID[count] = cur.id;
                            count++;
                        }
                        printf("ID: %d, name: %s\n", cur.id, cur.name.c_str());
                        newAvailableID[count] = cur.id;
                        count++;
                    }
                    printf("Choose one card to give (enter the ID of the card): ");

                    newcheck:
                    cin >> opt;
                    for (int i=0; i < 40; i++) {
                        if (newAvailableID[i] == opt) goto newvalid;
                        if (i == 39) {
                            printf("Invalid input. Choose one card to give (enter the ID of the card): ");
                            goto newcheck;
                        }
                    }
                    newvalid:
                    card *cur2, *prev2;
                    for (int i=0; i < by.landHead.size(); i++) {
                        if (checkFull(by.landHead[i].colour, by, i)) continue;
                        if (by.landHead[i].id == opt) {
                            cur2 = &(by.landHead[i]);
                            by.landHead[i] = *(by.landHead[i].next);
                            cur2->next = NULL;
                            if (by.landHead[i].colour == "ALL")
                              ALL(i, by);
                            putProperty(cur2, to);
                            break;
                        }
                        prev2 = &by.landHead[i];
                        while (prev2->next->id != opt && prev2->next->next != NULL) prev2 = prev2->next;
                        cur2 = prev2->next;
                        if (cur2->id == opt) {
                            prev2->next = prev2->next->next;
                            cur2->next = NULL;
                            putProperty(cur2, to);
                            break;
                        }
                    }
                }
                else {

                    //choosing a card to take from P1
                    int opt;
                    int availableID[40] = {-1};
                    int count = 0;
                    for (int i=0; i < to.landHead.size(); i++) {
                        if (checkFull(to.landHead[i].colour, to, i)) continue;
                        card cur;
                        for (cur = to.landHead[i]; &(cur.next)!=NULL; cur = *(cur.next)) {
                            availableID[count] = cur.id;
                            count++;
                        }
                        availableID[count] = cur.id;
                        count++;
                    }
                    opt = rand()%count;
                    opt = availableID[opt];

                    card *cur, *prev;
                    for (int i=0; i < to.landHead.size(); i++) {
                        if (checkFull(to.landHead[i].colour, to, i)) continue;
                        if (to.landHead[i].id == opt) {
                            cur = &to.landHead[i];
                            to.landHead[i] = *(to.landHead[i].next);
                            cur->next = NULL;
                            if (to.landHead[i].colour == "ALL")
                              ALL(i, to);
                            putProperty(cur, by);
                            break;
                        }
                        prev = &to.landHead[i];
                        while (prev->next->id != opt && prev->next->next != NULL) prev = prev->next;
                        cur = prev->next;
                        if (cur->id == opt) {
                            prev->next = prev->next->next;
                            cur->next = NULL;
                            putProperty(cur, by);
                            break;

                        }
                    }

                    //choosing a card to give P1
                    opt=0;
                    int newAvailableID[40] = {-1};
                    count = 0;
                    for (int i=0; i < by.landHead.size(); i++) {
                        if (checkFull(by.landHead[i].colour, by, i)) continue;
                        card cur;
                        for (cur = by.landHead[i]; &(cur.next)!=NULL; cur = *(cur.next)) {
                            newAvailableID[count] = cur.id;
                            count++;
                        }
                        newAvailableID[count] = cur.id;
                        count++;
                    }
                    opt = rand()%count;
                    opt = newAvailableID[opt];

                    card *cur2, *prev2;
                    for (int i=0; i < by.landHead.size(); i++) {
                        if (checkFull(by.landHead[i].colour, by, i)) continue;
                        if (by.landHead[i].id == opt) {
                            cur2 = &by.landHead[i];
                            by.landHead[i] = *(by.landHead[i].next);
                            cur2->next = NULL;
                            if (by.landHead[i].colour == "ALL")
                              ALL(i, to);
                            putProperty(cur2, to);
                            break;
                        }
                        prev2 = &by.landHead[i];
                        while (prev2->next->id != opt && prev2->next->next != NULL) prev2 = prev2->next;
                        cur2 = prev2->next;
                        if (cur2->id == opt) {
                            prev2->next = prev2->next->next;
                            cur2->next = NULL;
                            putProperty(cur2, to);
                            break;
                        }
                    }
                }
            }

        //case 11 ...13: //Debt Collector
        case 11:
        case 12:
        case 13: {
            int collectable = to.wealth;
            card cur;
            for (int i=0; i < to.landHead.size(); i++) {
                cur = to.landHead[i];
                collectable += cur.value;
                while (cur.next != NULL) { collectable += cur.next->value; cur = *(cur.next); }
            }
            if (collectable < 5) {
                printf("\'%s\' cannot be used now because %s not have $5M to pay (only $%dM). It is deposited into %s bank.\n", actionCard->name.c_str(), (isP1)? "the opponent does" : "you do", collectable, (isP1)? "your" : "the opponent\'s");
                depositMoney(actionCard, by);
            }
            else if (to.sayNo) {
                discarded.push_back(*actionCard);
                draw.erase(draw.begin()+index(discarded.back().id, draw));
                draw.shrink_to_fit();
                char opt = ((!isP1)? sayingNo(to, discarded) : "yn"[rand()%2]);
                if (opt == 'n' && !isP1) printf("You did not use \'Just Say No\'.\n");
                else { //opt = 'y'
                    printf("%s used \'Just Say No\'.\n", (isP1)? "The opponent" : "You");
                    break;
                }
            }
            else {
                discarded.push_back(*actionCard);
                draw.erase(draw.begin()+index(discarded.back().id, draw));
                draw.shrink_to_fit();
                if (!isP1) {
                    int total = 5, opt;
                    printf("You have to pay $5M to the opponent. Choose cards from below to pay. Here are the available cards.\n");
                    int availableID[110] = {-1};
                    int count = 0;

                    //print the cards in bank
                    card currency = *to.bankHead;
                    while (&(currency.next) != NULL) {
                        printf("ID: %d, name: \'%s\', value: $%dM\n", currency.id, currency.name.c_str(), currency.value);
                        availableID[count] = currency.id;
                        count++;
                        currency = *(currency.next);
                    }
                    printf("ID: %d, name: \'%s\', value: $%dM\n", currency.id, currency.name.c_str(), currency.value);
                    availableID[count] = currency.id;
                    count++;
                    currency = *(currency.next);
                    //print the property cards in land
                    for (int i=0; i < to.landHead.size(); i++) {
                        card cur;
                        for (cur = to.landHead[i]; &(cur.next)!=NULL; cur = *(cur.next)) {
                            printf("ID: %d, name: \'%s\', value: $%dM\n", cur.id, cur.name.c_str(), cur.value);
                            availableID[count] = cur.id;
                            count++;
                        }
                        printf("ID: %d, name: \'%s\', value: $%dM\n", cur.id, cur.name.c_str(), cur.value);
                        availableID[count] = cur.id;
                        count++;
                    }

                    card *cur, *prev;
                    while (total > 0) {
                        printf("You need to pay $%dM more. Choose one card more from below (enter the ID of the card):", total);

                        check3:
                        cin >> opt;
                        for (int i=0; i < 110; i++) {
                            if (availableID[i] == opt) {
                                goto valid3;
                            }
                            if (i == 109) {
                                printf("Invalid input. You need to pay $%dM more. Choose one card to take (enter the ID of the card): ", total);
                                goto check3;
                            }
                        }
                        valid3:
                        if (opt >= 35 && opt <= 73) { //property card
                            for (int i=0; i < to.landHead.size(); i++) {
                                if (to.landHead[i].id == opt) {
                                    cur = &to.landHead[i];
                                    to.landHead[i] = *(to.landHead[i].next);
                                    cur->next = NULL;
                                    putProperty(cur, by);
                                    break;
                                }
                                prev = &to.landHead[i];
                                while (prev->next->id != opt && prev->next->next != NULL) prev = prev->next;
                                cur = prev->next;
                                if (cur->id == opt) {
                                    prev->next = prev->next->next;
                                    cur->next = NULL;
                                    putProperty(cur, by);
                                    break;
                                }
                            }
                        }
                        else { //in bank
                            if (to.bankHead->id == opt) {
                                cur = to.bankHead;
                                to.bankHead = to.bankHead->next;
                                cur->next = NULL;
                                depositMoney(cur, by);
                            }
                            prev = to.bankHead;
                            while (prev->next->id != opt) prev = prev->next;
                            cur = prev->next;
                            cur->next = NULL;
                            depositMoney(cur, by);
                        }
                        printf("You chose to pay with the card \'%s\', which has a value of $%dM.\n", cur->name.c_str(), cur->value);
                        total -= cur->value;
                    }
                }
                else { //P1's turn
                    int total = 5, opt;
                    printf("The opponent has to pay $5M to you.\n");
                    int availableID[110] = {-1};
                    int count = 0;

                    //the cards in bank
                    card currency = *to.bankHead;
                    while (&(currency.next) != NULL) {
                        availableID[count] = currency.id;
                        count++;
                        currency = *(currency.next);
                    }
                    availableID[count] = currency.id;
                    count++;
                    currency = *(currency.next);
                    //the property cards in land
                    for (int i=0; i < to.landHead.size(); i++) {
                        card cur;
                        for (cur = to.landHead[i]; &(cur.next)!=NULL; cur = *(cur.next)) {
                            availableID[count] = cur.id;
                            count++;
                        }
                        availableID[count] = cur.id;
                        count++;
                    }

                    card *cur, *prev;
                    while (total > 0) {
                        opt = availableID[rand() % count];
                        if (opt >= 35 && opt <= 73) { //property card
                            for (int i=0; i < to.landHead.size(); i++) {
                                if (to.landHead[i].id == opt) {
                                    cur = &to.landHead[i];
                                    to.landHead[i] = *(to.landHead[i].next);
                                    cur->next = NULL;
                                    putProperty(cur, by);
                                    break;
                                }
                                prev = &to.landHead[i];
                                while (prev->next->id != opt && prev->next->next != NULL) prev = prev->next;
                                cur = prev->next;
                                if (cur->id == opt) {
                                    prev->next = prev->next->next;
                                    cur->next = NULL;
                                    putProperty(cur, by);
                                    break;
                                }
                            }
                        }
                        else { //in bank
                            if (to.bankHead->id == opt) {
                                cur = to.bankHead;
                                to.bankHead = to.bankHead->next;
                                cur->next = NULL;
                                depositMoney(cur, by);
                            }
                            prev = to.bankHead;
                            while (prev->next->id != opt) prev = prev->next;
                            cur = prev->next;
                            cur->next = NULL;
                            depositMoney(cur, by);
                        }
                        printf("The opponent chose to pay with the card \'%s\', which has a value of $%dM.\n", cur->name.c_str(), cur->value);
                        total -= cur->value;
                    }
                }
            }
        }
        //case 14 ...16: //It's my birthday
        case 14:
        case 15:
        case 16: {
            int collectable = to.wealth;
            card cur2;
            for (int i=0; i < to.landHead.size(); i++) {
                cur2 = to.landHead[i];
                collectable += cur2.value;
                while (cur2.next != NULL) { collectable += cur2.next->value; cur2 = *(cur2.next); }
            }
            if (collectable < 2) {
                printf("\'%s\' cannot be used now because %s not have $2M to pay (only $%dM). It is deposited into %s bank.\n", actionCard->name.c_str(), (isP1)? "the opponent does" : "you do", collectable, (isP1)? "your" : "the opponent\'s");
                depositMoney(actionCard, by);
            }
            else if (to.sayNo) {
                discarded.push_back(*actionCard);
                draw.erase(draw.begin()+index(discarded.back().id, draw));
                draw.shrink_to_fit();
                char opt = ((!isP1)? sayingNo(to, discarded) : "yn"[rand()%2]);
                if (opt == 'n' && !isP1) printf("You did not use \'Just Say No\'.\n");
                else { //opt = 'y'
                    printf("%s used \'Just Say No\'.\n", (isP1)? "The opponent" : "You");
                    break;
                }
            }
            else {
                discarded.push_back(*actionCard);
                draw.erase(draw.begin()+index(discarded.back().id, draw));
                draw.shrink_to_fit();
                if (!isP1) {
                    int total = 2, opt;
                    printf("You have to pay $2M to the opponent. Choose cards from below to pay. Here are the available cards.\n");
                    int availableID[110] = {-1};
                    int count = 0;

                    //print the cards in bank
                    card currency = *to.bankHead;
                    while (&(currency.next) != NULL) {
                        printf("ID: %d, name: \'%s\', value: $%dM\n", currency.id, currency.name.c_str(), currency.value);
                        availableID[count] = currency.id;
                        count++;
                        currency = *(currency.next);
                    }
                    printf("ID: %d, name: \'%s\', value: $%dM\n", currency.id, currency.name.c_str(), currency.value);
                    availableID[count] = currency.id;
                    count++;
                    currency = *(currency.next);
                    //print the property cards in land
                    for (int i=0; i < to.landHead.size(); i++) {
                        card cur;
                        for (cur = to.landHead[i]; &(cur.next)!=NULL; cur = *(cur.next)) {
                            printf("ID: %d, name: \'%s\', value: $%dM\n", cur.id, cur.name.c_str(), cur.value);
                            availableID[count] = cur.id;
                            count++;
                        }
                        printf("ID: %d, name: \'%s\', value: $%dM\n", cur.id, cur.name.c_str(), cur.value);
                        availableID[count] = cur.id;
                        count++;
                    }

                    card *cur, *prev;
                    while (total > 0) {
                        printf("You need to pay $%dM more. Choose one card more from below (enter the ID of the card):", total);

                        check4:
                        cin >> opt;
                        for (int i=0; i < 110; i++) {
                            if (availableID[i] == opt) {
                                goto valid4;
                            }
                            if (i == 109) {
                                printf("Invalid input. You need to pay $%dM more. Choose one card to take (enter the ID of the card): ", total);
                                goto check4;
                            }
                        }
                        valid4:
                        if (opt >= 35 && opt <= 73) { //property card
                            for (int i=0; i < to.landHead.size(); i++) {
                                if (to.landHead[i].id == opt) {
                                    cur = &to.landHead[i];
                                    to.landHead[i] = *(to.landHead[i].next);
                                    cur->next = NULL;
                                    putProperty(cur, by);
                                    break;
                                }
                                prev = &to.landHead[i];
                                while (prev->next->id != opt && prev->next->next != NULL) prev = prev->next;
                                cur = prev->next;
                                if (cur->id == opt) {
                                    prev->next = prev->next->next;
                                    cur->next = NULL;
                                    putProperty(cur, by);
                                    break;
                                }
                            }
                        }
                        else { //in bank
                            if (to.bankHead->id == opt) {
                                cur = to.bankHead;
                                to.bankHead = to.bankHead->next;
                                cur->next = NULL;
                                depositMoney(cur, by);
                            }
                            prev = to.bankHead;
                            while (prev->next->id != opt) prev = prev->next;
                            cur = prev->next;
                            cur->next = NULL;
                            depositMoney(cur, by);
                        }
                        printf("You chose to pay with the card \'%s\', which has a value of $%dM.\n", cur->name.c_str(), cur->value);
                        total -= cur->value;
                    }
                }
                else { //P1's turn
                    int total = 2, opt;
                    printf("The opponent has to pay $2M to you.\n");
                    int availableID[110] = {-1};
                    int count = 0;

                    //the cards in bank
                    card currency = *to.bankHead;
                    while (&(currency.next) != NULL) {
                        availableID[count] = currency.id;
                        count++;
                        currency = *(currency.next);
                    }
                    availableID[count] = currency.id;
                    count++;
                    currency = *(currency.next);
                    //the property cards in land
                    for (int i=0; i < to.landHead.size(); i++) {
                        card cur;
                        for (cur = to.landHead[i]; &(cur.next)!=NULL; cur = *(cur.next)) {
                            availableID[count] = cur.id;
                            count++;
                        }
                        availableID[count] = cur.id;
                        count++;
                    }

                    card *cur, *prev;
                    while (total > 0) {
                        opt = availableID[rand() % count];
                        if (opt >= 35 && opt <= 73) { //property card
                            for (int i=0; i < to.landHead.size(); i++) {
                                if (to.landHead[i].id == opt) {
                                    cur = &to.landHead[i];
                                    to.landHead[i] = *to.landHead[i].next;
                                    cur->next = NULL;
                                    putProperty(cur, by);
                                    break;
                                }
                                prev = &to.landHead[i];
                                while (prev->next->id != opt && prev->next->next != NULL) prev = prev->next;
                                cur = prev->next;
                                if (cur->id == opt) {
                                    prev->next = prev->next->next;
                                    cur->next = NULL;
                                    putProperty(cur, by);
                                    break;
                                }
                            }
                        }
                        else { //in bank
                            if (to.bankHead->id == opt) {
                                cur = to.bankHead;
                                to.bankHead = to.bankHead->next;
                                cur->next = NULL;
                                depositMoney(cur, by);
                            }
                            prev = to.bankHead;
                            while (prev->next->id != opt) prev = prev->next;
                            cur = prev->next;
                            cur->next = NULL;
                            depositMoney(cur, by);
                        }
                        printf("The opponent chose to pay with the card \'%s\', which has a value of $%dM.\n", cur->name.c_str(), cur->value);
                        total -= cur->value;
                    }
                }
            }
        }

        //case 17 ...26: //Pass Go
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
        case 22:
        case 23:
        case 24:
        case 25:
        case 26:
            discarded.push_back(*actionCard);
            draw.erase(draw.begin()+index(discarded.back().id, draw));
            draw.shrink_to_fit();
            getCard(by);
            getCard(by);

        //case 27 ...29: //House
        case 27:
        case 28:
        case 29:
            if (checkFullNum(by) < 1) {
                printf("\'%s\' cannot be used now because %s not have a completed property set. It is deposited into %s bank.\n", actionCard->name.c_str(), (!isP1)? "the opponent does" : "you do", (isP1)? "your" : "the opponent\'s");
                depositMoney(actionCard, by);
            }
            else {
                char option;
                if (isP1) {
                    string opt;
                    printf("Choose one coloured set to build house on (enter one lowercase letter): ");

                    //print full sets
                    int counter = 0;
                    for (int i = 0; i < by.landHead.size(); i++){
                        if (checkFull(by.landHead[i].colour, to, i)) {
                            printf("%c: %s\n", 'a'+counter, by.landHead[i].colour.c_str());
                            counter++;
                        }
                    }
                    cin >> opt;
                    while (opt.length() != 1 || (opt[0]-'a') >= checkFullNum(to)) {
                        printf("Please enter a valid input! Choose one cololured set to take (enter one lowercase letter): ");
                        cin >> opt;
                    }
                    option = opt[0];
                }
                else { //random moves by computer
                    option = rand() % checkFullNum(by) + 'a';
                }
                char count = 'a';
                for (int i=0; i < by.landHead.size(); i++) {
                    if (checkFull(by.landHead[i].colour, by, i)) {
                        if (count==option) {
                            card *cur = &by.landHead[i];
                            while (cur->next != NULL) cur = cur->next;
                            cur->next = actionCard;
                            actionCard->next = NULL;
                            break;
                        }
                        else count = count+1;
                    }
                }
            }

        //case 30 ...32: //Hotel
        case 30:
        case 31:
        case 32:
            if (checkFullNum(by) < 1) {
                printf("\'%s\' cannot be used now because %s not have a completed property set. It is deposited into %s bank.\n", actionCard->name.c_str(), (!isP1)? "the opponent does" : "you do", (isP1)? "your" : "the opponent\'s");
                depositMoney(actionCard, by);
            }
            else {
                char option;
                if (isP1) {
                    string opt;
                    printf("Choose one coloured set to build hotel on (enter one lowercase letter): ");

                    //print full sets
                    int counter = 0;
                    for (int i = 0; i < by.landHead.size(); i++){
                        if (checkFull(by.landHead[i].colour, to, i)) {
                            printf("%c: %s\n", 'a'+counter, by.landHead[i].colour.c_str());
                            counter++;
                        }
                    }
                    cin >> opt;
                    while (opt.length() != 1 || (opt[0]-'a') >= checkFullNum(to)) {
                        printf("Please enter a valid input! Choose one cololured set to take (enter one lowercase letter): ");
                        cin >> opt;
                    }
                    option = opt[0];
                }
                else { //random moves by computer
                    option = rand() % checkFullNum(by) + 'a';
                }
                char count = 'a';
                for (int i=0; i < by.landHead.size(); i++) {
                    if (checkFull(by.landHead[i].colour, by, i)) {
                        if (count==option) {
                            card *cur = &by.landHead[i];
                            while (cur->next != NULL) cur = cur->next;
                            cur->next = actionCard;
                            actionCard->next = NULL;
                            break;
                        }
                        else count = count+1;
                    }
                }
            }
        //case 33 ...34: //Double The Rent
        case 33:
        case 34:
            discarded.push_back(*actionCard);
            draw.erase(draw.begin()+index(discarded.back().id, draw));
            draw.shrink_to_fit();
            by.doubleRent = true;
    }
}

//return value of rent to be paid, n is the number of cards with same colour
int rent(string colour, int n){
  if (colour == "Green")
    switch (n){
      case 1:
        return 2;
      case 2:
        return 4;
      case 3:
        return 7;
    }
  else if (colour == "LightBlue")
    switch (n){
      case 1:
        return 1;
      case 2:
        return 2;
      case 3:
        return 3;
    }
  else if (colour == "Red")
    switch (n){
      case 1:
        return 2;
      case 2:
        return 3;
      case 3:
        return 6;
    }
  else if (colour == "Yellow")
    switch (n){
      case 1:
        return 2;
      case 2:
        return 4;
      case 3:
        return 6;
    }
  else if (colour == "Orange")
    switch (n){
      case 1:
        return 1;
      case 2:
        return 3;
      case 3:
        return 5;
    }
  else if (colour == "Purple")
    switch (n){
      case 1:
        return 1;
      case 2:
        return 2;
      case 3:
        return 4;
    }
  else if (colour == "DarkBlue")
    switch (n){
      case 1:
        return 3;
      case 2:
        return 8;
    }
  else if (colour == "Utility")
    switch (n){
      case 1:
        return 1;
      case 2:
        return 2;
    }
  else if (colour == "Brown")
    switch (n){
      case 1:
        return 1;
      case 2:
        return 2;
    }
  else
    switch (n){
      case 1:
        return 1;
      case 2:
        return 2;
      case 3:
        return 3;
      case 4:
        return 4;
  }
  return 0;
}

//Do the payment
//exchange money in bank
//if not enough, use property to pay
//print result (e.g. "But the opponent used Just Say No.\n", or "The opponent gave you $3M.\n")
void payment(player &by, player &to, int pay){
  card *first = by.bankHead, *card;
  int size = by.landHead.size(), *bank = new int[6+size], *choice = new int[6+size], i, len, temp, j;
  string opt;
  vector<string> property;
  if (&by == &P1){
    for (i = 0; i < 6; i++){
      *(bank+i) = 0;
    }
    if (by.bankHead != NULL){
      while (by.bankHead->next != NULL){
        switch (by.bankHead->value) {
          case 1:
            bank[0]++;
            break;
          case 2:
            bank[1]++;
            break;
          case 3:
            bank[2]++;
            break;
          case 4:
            bank[3]++;
            break;
          case 5:
            bank[4]++;
            break;
          case 10:
            bank[5]++;
            break;
        };
        by.bankHead = by.bankHead->next;
      }
      switch (by.bankHead->value) {
        case 1:
          bank[0]++;
          break;
        case 2:
          bank[1]++;
          break;
        case 3:
          bank[2]++;
          break;
        case 4:
          bank[3]++;
          break;
        case 5:
          bank[4]++;
          break;
        case 10:
          bank[5]++;
          break;
      };
    }
    by.bankHead = first;
    printf("You have to pay $%dM\n", pay);
    printf("You have: $1M*%d, $2M*%d, $3M*%d, $4M*%d, $5M*%d, $10M*%d\n    Land: ", bank[0], bank[1], bank[2], bank[3], bank[4], bank[5]);
    for (i = 0; i < size; i++){
      len = 1;
      if (i < 0)
        printf("\n          ");
      printf("%s", (by.landHead[i].colour).c_str());
      first = by.landHead[i].next;
      if (by.landHead[i].next != NULL){
        while (by.landHead[i].next->next != NULL){
          printf(", %s", (by.landHead[i].next->colour).c_str());
          by.landHead[i].next = by.landHead[i].next->next;
          if (by.landHead[i].next->colour != "ALL")
            len++;
          }
        printf(", %s", (by.landHead[i].next->colour).c_str());
        if (by.landHead[i].next->colour != "ALL")
          len++;
        by.landHead[i].next = first;
        bank[6+i] = len;
      }
    }
    printf("\n(LightBlue/Brown = $1M, Purple/Orange/Railroad/Utility = $2M, Red/Yellow = $3M, Green/DrakBlue = $4M, All cannot be used)\n");
    printf("Enter %d digits, separate by a space.End with Enter without space.\n", size+6);
    printf("First 6 digits represent number of money in bank to be paid, next %d digit(s) represent the property to ber transfered.\n",size);
    printf("Entering order same as the order of money and property listing out");
    while (true){
      cin >> opt;
      if (count(opt.begin(), opt.end(), ' ') == 5+size){
        i = 0;
        len = 0;
        temp = 0;
        while (i != opt.length()){
          if (opt[i] != ' '){
            temp = temp*10+(opt[i]-'0');
          }
          else{
            choice[len] = temp;
            if (choice[len] > bank[len])
              break;
            len++;
          }
          i++;
        }
        temp = choice[0] + 2*choice[1] + 3*choice[2] + 4*choice[3] + 5*choice[4] + 10*choice[5];
        for(int i = 6; i < size+6; i++){
          string c = "";
          size_t pos = by.landHead[i-6].colour.find("|");
          if (pos != string::npos){
            for (int i = 0; i < pos; i++){
              c += by.landHead[i-6].colour[i];
            }
          }
          else
            c = by.landHead[i-6].colour;
          if ((c == "LightBlue") || (c == "Brown"))
            temp += choice[i]*1;
          else if (((c == "Purple") || (c == "Orange")) || ((c == "Railroad") || (c == "Utility")))
            temp += choice[i]*2;
          else if ((c == "Red") || (c == "Yellow"))
            temp += choice[i]*3;
          else if ((c == "Green") || (c == "DarkBlue"))
            temp += choice[i]*4;
        }
        if (temp >= pay)
          break;
      }
      printf("Invalid option! Please input option again: ");
    }
  }
  else{
    for (i = 0; i < 6; i++){
      *(bank+i) = 0;
    }
    if (by.bankHead != NULL){
      while (by.bankHead->next != NULL){
        switch (by.bankHead->value) {
          case 1:
            bank[0]++;
            break;
          case 2:
            bank[1]++;
            break;
          case 3:
            bank[2]++;
            break;
          case 4:
            bank[3]++;
            break;
          case 5:
            bank[4]++;
            break;
          case 10:
            bank[5]++;
            break;
        };
        by.bankHead = by.bankHead->next;
      }
      switch (by.bankHead->value) {
        case 1:
          bank[0]++;
          break;
        case 2:
          bank[1]++;
          break;
        case 3:
          bank[2]++;
          break;
        case 4:
          bank[3]++;
          break;
        case 5:
          bank[4]++;
          break;
        case 10:
          bank[5]++;
          break;
      };
    }
    by.bankHead = first;
    for (i = 0; i < size; i++){
      len = 1;
      first = by.landHead[i].next;
      if (by.landHead[i].next != NULL){
        while (by.landHead[i].next->next != NULL){
          by.landHead[i].next = by.landHead[i].next->next;
          if (by.landHead[i].next->colour != "ALL")
            len++;
        }
        if (by.landHead[i].next->colour != "ALL")
          len++;
        by.landHead[i].next = first;
        bank[6+i] = len;
      }
    }
    while (true){
      for (i = 0; i < 5+size;i++){
        srand(time(NULL));
        choice[i] = rand()%(bank[i]+1);
      }
      temp = choice[0] + 2*choice[1] + 3*choice[2] + 4*choice[3] + 5*choice[4] + 10*choice[5];
      for(int i = 6; i < size+5; i++){
        string c = "";
        size_t pos = by.landHead[i-6].colour.find("|");
        if (pos != string::npos){
          for (int i = 0; i < pos; i++){
            c += by.landHead[i-6].colour[i];
          }
        }
        else
          c = by.landHead[i-6].colour;
        if ((c == "LightBlue") || (c == "Brown"))
          temp += choice[i]*1;
        else if (((c == "Purple") || (c == "Orange")) || ((c == "Railroad") || (c == "Utility")))
          temp += choice[i]*2;
        else if ((c == "Red") || (c == "Yellow"))
          temp += choice[i]*3;
        else if ((c == "Green") || (c == "DarkBlue"))
          temp += choice[i]*4;
      }
      if (temp >= pay)
        break;
    }
  }
  for (i = 0; i < 5; i++){
    for (j = 0; j < choice[i]; j++){
      if (by.bankHead->value == i+1){
        card = by.bankHead;
        by.bankHead = by.bankHead->next;
        depositMoney(card, to);
      }
      else{
        first = by.bankHead;
        while (by.bankHead->next->value != i+1){
          by.bankHead = by.bankHead->next;
        }
        card = by.bankHead->next;
        by.bankHead->next = by.bankHead->next->next;
        by.bankHead = first;
        depositMoney(card, to);
      }
    }
  }
  for (i = 0; i < choice[5]; j++){
    if (by.bankHead->value == 10){
      card = by.bankHead;
      by.bankHead = by.bankHead->next;
      depositMoney(card, to);
    }
    else{
      first = by.bankHead;
      while (by.bankHead->next->value != 10){
        by.bankHead = by.bankHead->next;
      }
      card = by.bankHead->next;
      by.bankHead->next = by.bankHead->next->next;
      by.bankHead = first;
      depositMoney(card, to);
    }
  }
  for (i = 6; i < size+6; i++){
    for (j = 0; j < choice[i]; j++){
      first = by.landHead[i-6].next;
        if (by.landHead[i-6].next == NULL){
          putProperty(&by.landHead[i-6], to);
          by.landHead.erase(by.landHead.begin()+i-6);
        }
        else if (by.landHead[i-6].next->next == NULL){
          putProperty(by.landHead[i-6].next->next, to);
          by.landHead[i-6].next = NULL;
        }
        else{
          first = by.landHead[i-6].next;
          while (by.landHead[i-6].next->next->next != NULL){
            by.landHead[i-6].next = by.landHead[i-6].next->next;
          }
          putProperty(by.landHead[i-6].next->next, to);
          by.landHead[i-6].next = NULL;
          by.landHead[i-6].next = first;
      }
    }
  }
}

//if not available: put into bank (e.g. red rent card but no red property)
//if available: ask to use card or put into bank?
//put into bank: append card to player.bankHead, increase player.wealth
//use card: discard card, check opponent JustSayNo, perform actions
//print player action (e.g. "You used Red/Yellow Rent Card on your Red Property.\n")
void useRent(card *rentCard, player &by, player &to){
  vector<string> property;
  size_t pos;
  for (vector<card>::iterator i = by.landHead.begin(); i != by.landHead.end(); i++){
    pos = i->colour.find("|");
    if (pos != string::npos){
      string c = "";
      for (int j = 0; j < pos; j++){
        c = c+i->colour[j];
      }
      property.push_back(c);
    }
    else
      property.push_back(i->colour);
  }
  if (rentCard->colour != "ALL"){
    string str1 = "", str2 = "", opt, chosen;
    pos = rentCard->colour.find(",");
    for (int i = 0; i < pos; i++){
      str1 = str1 + rentCard->colour[i];
    }
    for (int i = rentCard->colour.length(); i > pos; i--){
      str2 = str2 + rentCard->colour[i];
    }
    if ((find(property.begin(), property.end(), str1) != property.end()) && (find(property.begin(), property.end(), str2) != property.end())){
      if (&by == &P1){
        printf(" Which colour do you want to rent, 1 - %s or 2 - %s (0 - put in bank): ", str1.c_str(), str2.c_str());
        while (true){
          cin >> opt;
          if ((opt.length() == 1) && (((opt[0] == '1') || (opt[0] == '2')) || (opt[0] == '0')))
            break;
          printf("Invalid option! Please input option again: ");
        }
      }
      else{
        srand(time(NULL));
        opt[0] = rand()%3+'0';
      }
      if (opt[0] == '0'){
        depositMoney(rentCard, by);
        return;
      }
      if (opt[0] == '1')
        chosen = str1;
      else{
        chosen = str2;
      }
    }
    else if (find(property.begin(), property.end(), str1) != property.end())
      chosen = str1;
    else if (find(property.begin(), property.end(), str2) != property.end())
      chosen = str2;
    else{
      depositMoney(rentCard, by);
      return;
    }
    discarded.push_back(draw[index(rentCard->id, draw)]);
    draw.erase(draw.begin()+index(discarded.back().id, draw));
    draw.shrink_to_fit();
    int index = find(property.begin(), property.end(), chosen) - property.begin(), len = 1, extra;
    if (by.landHead[index].next != NULL){
      card *first = by.landHead[index].next;
      if (by.landHead[index].next != NULL){
        while ((by.landHead[index].next->next != NULL) && ((by.landHead[index].next->id >= 35) && (by.landHead[index].next->id <= 73))){
          by.landHead[index].next = by.landHead[index].next->next;
          len++;
        }
        if ((by.landHead[index].next->id >= 35) && (by.landHead[index].next->id <= 73)){
          len++;
        }
      }
      if (by.landHead[index].next->next != NULL){
        while (by.landHead[index].next->next != NULL){
          if (by.landHead[index].next->name == "Hotel")
            extra += 4;
          else if (by.landHead[index].next->name == "House")
            extra += 3;
          by.landHead[index].next = by.landHead[index].next->next;
          }
        if (by.landHead[index].next->name == "Hotel")
          extra += 4;
        else if (by.landHead[index].next->name == "House")
          extra += 3;
      }
      by.landHead[index].next = first;
    }
    if (&by == &P1)
      printf("You used %s on your %s Property.\n", rentCard->name.c_str(), property[index].c_str());
    else
      printf("Opponent used %s on your %s Property.\n", rentCard->name.c_str(), property[index].c_str());
    if (by.doubleRent){
      payment(to, by, (rent(property[index], len)+extra)*2);
      by.doubleRent = false;
    }
    else
      payment(to, by, rent(property[index], len)+extra);
  }
  else{
    int size = 1;
    string opt;
    if (&by == &P1){
      printf(" Which colour do you want to rent");
      for (vector<string>::iterator i = property.begin(); i != property.end(); i++){
        printf(", %d - %s", (char)(99+size), (*i).c_str());
        size++;
      }
      printf(", a - put in bank: ");
      while (true){
        cin >> opt;
        if ((opt.length() == 1) && ((opt[0]-'a' >= 0) && (opt[0]-'a' < size)))
          break;
        printf("Invalid option! Please input option again: ");
      }
    }
    else{
      srand(time(NULL));
      opt[0] = rand()%(property.size())+'a';
    }
    if (opt[0] == 'a'){
      depositMoney(rentCard, by);
      return;
    }
    discarded.push_back(draw[index(rentCard->id, draw)]);
    draw.erase(draw.begin()+index(discarded.back().id, draw));
    draw.shrink_to_fit();
    int index = find(property.begin(), property.end(), property[opt[0]-'b']) - property.begin(), len = 1, extra = 0;
    if (by.landHead[index].next != NULL){
      card *first = by.landHead[index].next;
      if (by.landHead[index].next != NULL){
        while ((by.landHead[index].next->next != NULL) && ((by.landHead[index].next->id >= 35) && (by.landHead[index].next->id <= 73))){
          by.landHead[index].next = by.landHead[index].next->next;
          len++;
        }
        if ((by.landHead[index].next->id >= 35) && (by.landHead[index].next->id <= 73)){
          len++;
        }
      }
      if (by.landHead[index].next->next != NULL){
        while (by.landHead[index].next->next != NULL){
          if (by.landHead[index].next->name == "Hotel")
            extra += 4;
          else if (by.landHead[index].next->name == "House")
            extra += 3;
          by.landHead[index].next = by.landHead[index].next->next;
          }
        if (by.landHead[index].next->name == "Hotel")
          extra += 4;
        else if (by.landHead[index].next->name == "House")
          extra += 3;
      }
      by.landHead[index].next = first;
    }
    if (&by == &P1)
      printf("You used %s on your %s Property.\n", rentCard->name.c_str(), property[index].c_str());
    else{
      printf("Opponent used %s on your %s Property.\n", rentCard->name.c_str(), property[index].c_str());
      if (to.sayNo){
        char no = sayingNo(to, discarded);
        if (no == 'y')
          return;
      }
    }
    if (by.doubleRent){
      payment(to, by, (rent(property[index], len)+extra)*2);
      by.doubleRent = false;
    }
    else
      payment(to, by, rent(property[index], len)+extra);
  }
}



//when player P has more than 7 cards in hand at the end of turn,
//P has to discard the excess cards into the discarded card pool.
//if (P == P1) {
    //remind player to enter one option at a time (because option menu changes after discarding each card)
    //show option menu with abc...
    //check validity of input }
//remove card from P.handHead list, pushback card to discarded, excessNum--
//print "You" or "The opponent" + " discarded the card: " + name of the card
//repeat until excessNum=0
void discardHand(player *P, int excessNum){
  card *first;
  int i = 0;
  if (P == &P1){
    first = P->handHead;
    while (P->handHead->next != NULL){
      printf("%c: %s\n", (char)(97+i), P->handHead->name.c_str());
      P->handHead = P->handHead->next;
      i++;
    }
    printf("%c: %s\n", (char)(97+i), P->handHead->name.c_str());
    i++;
    P->handHead = first;


    string opt;
    printf("Enter one option to discard one card: ");
    cin >> opt;
    while ((opt.length() != 1) || ((opt[0]-'a' < 0) || (opt[0]-'a' > excessNum+7))){
      cout <<"Invalid option! Please input option again: ";
      cin >> opt;
    }

    if (opt[0] == 'a'){
      printf("You dicrded the card: %s\n", P->handHead->name.c_str());
      discarded.push_back(draw[index(P->handHead->id, draw)]);;
      P->handHead = P->handHead->next;
      draw.erase(draw.begin()+index(discarded.back().id, draw));
      draw.shrink_to_fit();
    }
    else{
      for (i = (int)(opt[0]) - 2; i > 0; i--){
        P->handHead = P->handHead->next;
      }
      printf("You dicrded the card: %s\n", P->handHead->next->name.c_str());
      discarded.push_back(draw[index(P->handHead->next->id, draw)]);;
      P->handHead->next = P->handHead->next->next;
      draw.erase(draw.begin()+index(discarded.back().id, draw));
      draw.shrink_to_fit();
      P->handHead = first;
    }
  }
  else{
    int opt = rand() % (count(P->handHead));
    if (opt == 0){
      printf("The opponent dicrded the card: %s\n", P->handHead->name.c_str());
      discarded.push_back(draw[index(P->handHead->id, draw)]);;
      P->handHead = P->handHead->next;
      draw.erase(draw.begin()+index(discarded.back().id, draw));
      draw.shrink_to_fit();
    }
    else{
      for (i = opt - 2; i > 0; i--){
        P->handHead = P->handHead->next;
      }
      printf("The opponent dicrded the card: %s\n", P->handHead->next->name.c_str());
      discarded.push_back(draw[index(P->handHead->next->id, draw)]);;
      P->handHead->next = P->handHead->next->next;
      draw.erase(draw.begin()+index(discarded.back().id, draw));
      draw.shrink_to_fit();
      P->handHead = first;
    }
  }
  discardHand(P, excessNum-1);
}


//initialize with new game setting
void new_game(){
  genCards();
  discarded.clear();
  draw.clear();
  P1.handHead = NULL;
  P1.bankHead = NULL;
  P1.landHead.clear();
  P1.sayNo = false;
  P1.doubleRent = false;
  P1.wealth = 0;
  comp.handHead = NULL;
  comp.bankHead = NULL;
  comp.landHead.clear();
  comp.sayNo = false;
  comp.doubleRent = false;
  comp.wealth = 0;
  //distribute 5 cards for players
  for (int i=0; i<5; i++){
    getCard(P1);
    getCard(comp);
  }
}

void game() {
    curP = &comp;
    while (!checkWin(*curP)) {
        //new turn
        printInfo();
        curP = ((curP==&P1)? &comp : &P1);
        string opt;
        cout << "Save progress and Exit? (Y/N): ";
        while (true){
          cin >> opt;
          if ((opt.length() == 1) && ((opt[0] == 'Y') || (opt[0] == 'N')))
            break;
          cout <<"Invalid option! Please input option again: ";
        }

        if (opt[0]=='Y') {
          saveProgress();
          return;
        }


        int actionsLeft = 3, handLength, temp;
        card *curCard, *first;

        if (curP->handHead == NULL)
          temp = 5;
        else
          temp = 2;
        for (int i=temp; i > 0; i--) {
          getCard(*curP);
        }

        while (actionsLeft > 0) {
            //new action
            printInfo(); //print hand count, total wealth, land count of both players
            handLength = count(curP->handHead);
            cout << "You have " << actionsLeft << " moves left.\n";
            cout << "You now have " << handLength << " card(s) in hand.\n";

            if (curP==&P1) {
                printMenu(P1);
                cin >> opt;

                while (((opt[0]-'a' > handLength+1) || (opt[0]-'a' < 0)) || (opt.length() != 1)){
                  cout << "Invalid option! Please input option again: ";
                  cin >> opt;
                }

                if (opt[0]=='a') {
                  cout << "You chose to end this turn.\n";
                  break;
                }

                if (opt[0] == 'b'){
                  curCard = curP->handHead;
                  curP->handHead = curP->handHead->next;
                }
                else{
                  first = curP->handHead;
                  for (int i=0; i < opt[0]-'c'; i++) {
                    curP->handHead = curP->handHead->next;
                  }
                  curCard = curP->handHead->next;
                  curP->handHead->next = curP->handHead->next->next;
                  curP->handHead = first;
                }
                curCard->next = NULL;

                if (curCard->id < 35) { //action card
                    makeAction(curCard, P1, true, comp, discarded, cardPool);
                }
                else if (curCard->id < 74) { //property card
                    if (curCard->colour == "ALL"){
                      if (curP->landHead.size() == 0){
                        printf("%s cannot be put.\n", curCard->name.c_str());
                        actionsLeft++;
                      }
                      else{
                        int i;
                        bool full = true;
                        for (i = curP->landHead.size()-1; i > 0; i--){
                          if (not checkFull(curP->landHead[i].colour, *curP,i)){
                            full = false;
                            break;
                          }
                        }
                        if (full){
                          printf("%s cannot be put.\n", curCard->name.c_str());
                          actionsLeft++;
                        }
                        else{
                          putProperty(curCard, P1);
                          if (checkWin(P1)) break;
                        }
                      }
                    }
                    else{
                      putProperty(curCard, P1);
                      if (checkWin(P1)) break;
                    }
                }
                else if (curCard->id < 87) { //rent card
                    useRent(curCard, P1, comp);
                }
                else { //money card
                    depositMoney(curCard, P1);
                }
            }

            else { //current player is computer: all moves are randomly generated
                opt = rand() % (handLength+1) + 'a';
                //copy above but dont print action menu or ask for input
                    //make random move, print action
                    //if is attack/rent and P1 has JustSayNo: prompt and ask P1 if use
                    //if is rent: print action menu for P1 to choose cards to pay with
                    //print result

                if (opt[0]=='a') {
                  cout << "The opponent chose to end this turn.\n";
                  break;
                 }

                if (opt[0]=='b') {
                    //(dont print) list out non-single coloured property cards with options abcd...
                    //if no non-single coloured card: (no output) actionsLeft++, continue
                    //ask for which property card to change its colour, save in curCard
                    //if is duo coloured: exchange order of colours in curCard.colour
                    //if is multi coloured: ask for new colour, replace old colour with it
                    //if new colour: pushback card to landHead
                    //if existing colour: append card to the list of the colour
                    //print result (e.g. "The opponent changed Red/Yellow Property Card from Red to Yellow.\n")
                }

                if (opt[0] == 'c'){
                  curCard = curP->handHead;
                  curP->handHead = curP->handHead->next;
                }
                else{
                  first = curP->handHead;
                  for (int i=0; i < opt[0]-'d'; i++) {
                    curP->handHead = curP->handHead->next;
                  }
                  curCard = curP->handHead->next;
                  curP->handHead->next = curP->handHead->next->next;
                  curP->handHead = first;
                }
                curCard->next = NULL;

                if (curCard->id < 35) { //action card
                    makeAction(curCard, comp, false, P1, discarded, cardPool);
                }
                else if (curCard->id < 74) { //property card
                    if (curCard->colour == "ALL"){
                      if (curP->landHead.size() == 0){
                        actionsLeft++;
                      }
                      else{
                        int i;
                        bool full = true;
                        for (i = curP->landHead.size()-1; i > 0; i--){
                          if (not checkFull(curP->landHead[i].colour, *curP,i)){
                            full = false;
                            break;
                          }
                        }
                        if (full){
                          actionsLeft++;
                        }
                        else{
                          putProperty(curCard, comp);
                          if (checkWin(comp)) break;
                        }
                      }
                    }
                    else{
                      putProperty(curCard, comp);
                      if (checkWin(comp)) break;
                    }
                }
                else if (curCard->id < 87) { //rent card
                    useRent(curCard, comp, P1);
                }
                else { //money card
                    depositMoney(curCard, comp);
                }
            }
            actionsLeft--;
        }

        handLength = count(curCard);
        if (handLength > 7) {
            if (curP == &P1)
              cout << "You have more than seven cards in hand. Discard " << handLength-7 << " card(s) from your hand:\n";
            else
              cout << "The opponent has more than seven cards in hand. Discarding " << handLength-7 << " card(s) from hand...\n";
            discardHand(curP, handLength-7);
        }

    }

    cout << ((curP==&P1)? "Congratulations! You won" : "Oh no! You have lost") << " the game!\n";
    cout << "\nThanks for playing!\n";
}
