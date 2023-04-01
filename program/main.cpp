#include"header.h"
using namespace std;

player P1, comp, *curP;     //current player
vector<card>  discarded, cardPool, draw;

int main(){
  int opt;
  string temp, del;
  char input;

  mainpage:
  while (true){
    printf("Choose an option (enter with number).\n");
    printf("1.New game  2.load game 3.delete game 4.exit\n");
    cin >> temp;
    if (temp.length() == 1)
      if ((temp[0] < '5') && (temp[0] > '0'))
        break;
    printf("Please enter number 1-4 only.\n");
  }
  opt = temp[0] - 48;

  switch(opt){

    case 1:
      new_game();
      game();
      goto mainpage;
      break;

    case 2:
      input = filecheck();
      if (input != '0'){
        if (initialize(input))
          game();
      }
      goto mainpage;
      break;

    case 3:
      input = filecheck();
      if (input != '0'){
        printf("file %c will be delete. Are you sure?(Y for yes, N for no) ", input);
        while (true){
          cin >> del;
          if (del.length() == 1)
            if ((del[0] == 'Y') || (del[0] == 'N'))
              break;
          printf("Invalid option! Please input option again: ");
        }
        if (del[0] == 'Y'){
          delete_file(input);
        }
      }
      goto mainpage;

    case 4:
      printf("Bye!");
    }

  return 0;
}
