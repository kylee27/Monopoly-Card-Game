#include "header.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

//generate all cards at game start
//and return a vector of cards
vector<card> genCards() {
    vector<card> cardPool;
    { //pushback cards to cardPool
    //34 action cards
    cardPool.push_back( { 0, "Deal Breaker", 5, "None" } );
    cardPool.push_back( { 1, "Deal Breaker", 5, "None" } );
    cardPool.push_back( { 2, "Just Say No", 4, "None" } );
    cardPool.push_back( { 3, "Just Say No", 4, "None" } );
    cardPool.push_back( { 4, "Just Say No", 4, "None" } );
    cardPool.push_back( { 5, "Sly Deal", 3, "None" } );
    cardPool.push_back( { 6, "Sly Deal", 3, "None" } );
    cardPool.push_back( { 7, "Sly Deal", 3, "None" } );
    cardPool.push_back( { 8, "Force Deal", 3, "None" } );
    cardPool.push_back( { 9, "Force Deal", 3, "None" } );
    cardPool.push_back( { 10, "Force Deal", 3, "None" } );
    cardPool.push_back( { 11, "Debt Collector", 3, "None" } );
    cardPool.push_back( { 12, "Debt Collector", 3, "None" } );
    cardPool.push_back( { 13, "Debt Collector", 3, "None" } );
    cardPool.push_back( { 14, "It\'s My Birthday", 2, "None" } );
    cardPool.push_back( { 15, "It\'s My Birthday", 2, "None" } );
    cardPool.push_back( { 16, "It\'s My Birthday", 2, "None" } );
    cardPool.push_back( { 17, "Pass Go", 1, "None" } );
    cardPool.push_back( { 18, "Pass Go", 1, "None" } );
    cardPool.push_back( { 19, "Pass Go", 1, "None" } );
    cardPool.push_back( { 20, "Pass Go", 1, "None" } );
    cardPool.push_back( { 21, "Pass Go", 1, "None" } );
    cardPool.push_back( { 22, "Pass Go", 1, "None" } );
    cardPool.push_back( { 23, "Pass Go", 1, "None" } );
    cardPool.push_back( { 24, "Pass Go", 1, "None" } );
    cardPool.push_back( { 25, "Pass Go", 1, "None" } );
    cardPool.push_back( { 26, "Pass Go", 1, "None" } );
    cardPool.push_back( { 27, "House", 3, "None" } );
    cardPool.push_back( { 28, "House", 3, "None" } );
    cardPool.push_back( { 29, "House", 3, "None" } );
    cardPool.push_back( { 30, "Hotel", 4, "None" } );
    cardPool.push_back( { 31, "Hotel", 4, "None" } );
    cardPool.push_back( { 32, "Hotel", 4, "None" } );
    cardPool.push_back( { 33, "Double The Rent", 1, "None" } );
    cardPool.push_back( { 34, "Double The Rent", 1, "None" } );


    //28 property cards
    cardPool.push_back( { 35, "Green Property Card", 4, "Green" } );
    cardPool.push_back( { 36, "Green Property Card", 4, "Green" } );
    cardPool.push_back( { 37, "Green Property Card", 4, "Green" } );
    cardPool.push_back( { 38, "Dark Blue Property Card", 4, "DarkBlue" } );
    cardPool.push_back( { 39, "Dark Blue Property Card", 4, "DarkBlue" } );
    cardPool.push_back( { 40, "Light Blue Property Card", 1, "LightBlue" } );
    cardPool.push_back( { 41, "Light Blue Property Card", 1, "LightBlue" } );
    cardPool.push_back( { 42, "Light Blue Property Card", 1, "LightBlue" } );
    cardPool.push_back( { 43, "Red Property Card", 3, "Red" } );
    cardPool.push_back( { 44, "Red Property Card", 3, "Red" } );
    cardPool.push_back( { 45, "Red Property Card", 3, "Red" } );
    cardPool.push_back( { 46, "Utility Property Card", 2, "Utility" } );
    cardPool.push_back( { 47, "Utility Property Card", 2, "Utility" } );
    cardPool.push_back( { 48, "Yellow Property Card", 3, "Yellow" } );
    cardPool.push_back( { 49, "Yellow Property Card", 3, "Yellow" } );
    cardPool.push_back( { 50, "Yellow Property Card", 3, "Yellow" } );
    cardPool.push_back( { 51, "Orange Property Card", 2, "Orange" } );
    cardPool.push_back( { 52, "Orange Property Card", 2, "Orange" } );
    cardPool.push_back( { 53, "Orange Property Card", 2, "Orange" } );
    cardPool.push_back( { 54, "Brown Property Card", 1, "Brown" } );
    cardPool.push_back( { 55, "Brown Property Card", 1, "Brown" } );
    cardPool.push_back( { 56, "Purple Property Card", 2, "Purple" } );
    cardPool.push_back( { 57, "Purple Property Card", 2, "Purple" } );
    cardPool.push_back( { 58, "Purple Property Card", 2, "Purple" } );
    cardPool.push_back( { 59, "Railroad Property Card", 1, "Railroad" } );
    cardPool.push_back( { 60, "Railroad Property Card", 1, "Railroad" } );
    cardPool.push_back( { 61, "Railroad Property Card", 1, "Railroad" } );
    cardPool.push_back( { 62, "Railroad Property Card", 1, "Railroad" } );


    //11 property wildcards
    cardPool.push_back( { 63, "Purple/Orange Property Wildcard", 2, "Purple,Orange" } );
    cardPool.push_back( { 64, "Purple/Orange Property Wildcard", 2, "Purple,Orange" } );
    cardPool.push_back( { 65, "Light Blue/Brown Property Wildcard", 1, "LightBlue,Brown" } );
    cardPool.push_back( { 66, "Light Blue/Railroad Property Wildcard", 4, "LightBlue,Railroad" } );
    cardPool.push_back( { 67, "Dark Blue/Green Property Wildcard", 4, "DarkBlue,Green" } );
    cardPool.push_back( { 68, "Railroad/Green Property Wildcard", 4, "Railroad,Green" } );
    cardPool.push_back( { 69, "Red/Yellow Property Wildcard", 3, "Red,Yellow" } );
    cardPool.push_back( { 70, "Red/Yellow Property Wildcard", 3, "Red,Yellow" } );
    cardPool.push_back( { 71, "Utility/Railroad Property Wildcard", 2, "Utility,Railroad" } );
    cardPool.push_back( { 72, "Multi-Coloured Property Wildcard", 0, "All" } );
    cardPool.push_back( { 73, "Multi-Coloured Property Wildcard", 0, "All" } );


    //13 rent cards
    cardPool.push_back( { 74, "Purple/Orange Rent Card", 1, "Purple,Orange" } );
    cardPool.push_back( { 75, "Purple/Orange Rent Card", 1, "Purple,Orange" } );
    cardPool.push_back( { 76, "Railroad/Utility Rent Card", 1, "Railroad,Utility" } );
    cardPool.push_back( { 77, "Railroad/Utility Rent Card", 1, "Railroad,Utility" } );
    cardPool.push_back( { 78, "Green/Dark Blue Rent Card", 1, "Green,DarkBlue" } );
    cardPool.push_back( { 79, "Green/Dark Blue Rent Card", 1, "Green,DarkBlue" } );
    cardPool.push_back( { 80, "Brown/Light Blue Rent Card", 1, "Brown,LightBlue" } );
    cardPool.push_back( { 81, "Brown/Light Blue Rent Card", 1, "Brown,LightBlue" } );
    cardPool.push_back( { 82, "Red/Yellow Rent Card", 1, "Red,Yellow" } );
    cardPool.push_back( { 83, "Red/Yellow Rent Card", 1, "Red,Yellow" } );
    cardPool.push_back( { 84, "Wild Rent Card", 3, "All" } );
    cardPool.push_back( { 85, "Wild Rent Card", 3, "All" } );
    cardPool.push_back( { 86, "Wild Rent Card", 3, "All" } );


    //20 money cards
    cardPool.push_back( { 87, "$10M", 10, "None" } );
    cardPool.push_back( { 88, "$5M", 5, "None" } );
    cardPool.push_back( { 89, "$5M", 5, "None" } );
    cardPool.push_back( { 90, "$4M", 4, "None" } );
    cardPool.push_back( { 91, "$4M", 4, "None" } );
    cardPool.push_back( { 92, "$4M", 4, "None" } );
    cardPool.push_back( { 93, "$3M", 3, "None" } );
    cardPool.push_back( { 94, "$3M", 3, "None" } );
    cardPool.push_back( { 95, "$3M", 3, "None" } );
    cardPool.push_back( { 96, "$2M", 2, "None" } );
    cardPool.push_back( { 97, "$2M", 2, "None" } );
    cardPool.push_back( { 98, "$2M", 2, "None" } );
    cardPool.push_back( { 99, "$2M", 2, "None" } );
    cardPool.push_back( { 100, "$2M", 2, "None" } );
    cardPool.push_back( { 101, "$1M", 1, "None" } );
    cardPool.push_back( { 102, "$1M", 1, "None" } );
    cardPool.push_back( { 103, "$1M", 1, "None" } );
    cardPool.push_back( { 104, "$1M", 1, "None" } );
    cardPool.push_back( { 105, "$1M", 1, "None" } );
    cardPool.push_back( { 106, "$1M", 1, "None" } );
    }

    return cardPool;
}


//return if the card is available (not used)
bool cardUnpicked(int cardID);


//randomly distribute an available card to P
//remove card from cardPool
void getCard(player P) {
    srand(time(NULL));
    //check if is JustSayNo, update P.sayNo to true
}

void printInfo();

//print action menu of P
// "S: save current progress\na: end turn\nb: change property colour\nc: my birthday\nd: green property card\n..."
//note: S=save current progress, a=end turn and b=change property colour must appear in menu
void printMenu(player P);


//return if P wins the game, i.e. has 3 complete sets of property
bool checkWin(player P);

//different output for player by/to!
//if not available: put into bank (e.g. using JustSayNo)
//if available: ask to use card or put into bank?
//use card: discard card, (if is attack: check opponent JustSayNo), perform actions
//put into bank: append card to player.bankHead, increase player.wealth
//print player action (e.g. "You used Pass Go.\n")
//ask for further options for some cards (e.g. which property to steal?)
//print result (e.g. "But the opponent used Just Say No.\n", or "You stole Green Property Card from the opponent.\n")
void makeAction(card actionCard, player &by, player &to, vector<card> &discarded, vector<card> &cardPool);


//ask to put on land or put into bank?
//put on land:
    //if not single colour: ask for colour, put the chosen colour at the front of propertyCard.colour
    //if new colour: pushback card to landHead
    //if existing colour: append card to the list of the colour
//put into bank: append card to player.bankHead, increase player.wealth
//print player action (e.g. "You put Blue Property Card on your land.\n")
void putProperty(card propertyCard, player &by);


//if not available: put into bank (e.g. red rent card but no red property)
//if available: ask to use card or put into bank?
//put into bank: append card to player.bankHead, increase player.wealth
//use card: discard card, check opponent JustSayNo, perform actions
//print player action (e.g. "You used Red/Yellow Rent Card on your Red Property.\n")
//print result (e.g. "But the opponent used Just Say No.\n", or "The opponent gave you $3M.\n")
void useRent(card rentCard, player &by, player &to, vector<card> &discarded);


//append card to player.bankHead, increase player.wealth
//print player action (e.g. "You put $5M into yout bank.\n")
void depositMoney(card moneyCard, player &by);


//when player P has more than 7 cards in hand at the end of turn,
//P has to discard the excess cards into the discarded card pool.
//if (P == P1) {
    //remind player to enter one option at a time (because option menu changes after discarding each card)
    //show option menu with abc...
    //check validity of input }
//remove card from P.handHead list, pushback card to discarded, excessNum--
//print "You" or "The opponent" + " discarded the card: " + name of the card
//repeat until excessNum=0
void discardHand(player &P, int excessNum, vector<card> &discarded);


//save game progress and return to mainpage
void saveProgress();


void game() {
    //have not dealt with data loading, assumed new game

    player P1, comp, *curP; //current player
    vector<card> discarded;
    vector<card> cardPool = genCards();
    for (int i=0; i<5; i++) { getCard(P1); getCard(comp); } //distribute 5 cards for players

    curP = &P1;
    int actionsLeft = 3;
    int handLength = 0;
    char opt; //to be chosen from action menu
    card curCard = *curP.handHead;

    while (!checkWin(*curP)) {
        //new turn
        printInfo(); //print hand count, total wealth, land count of both players
        if ((*curP.handHead)==NULL) { for (int i=5; i > 0; i--) { getCard(*curP); }}
        else { getCard(*curP); getCard(*curP); }

        while (actionsLeft > 0) {
            //new action
            cout << "You have " << actionsLeft << " moves left.\n";
            handLength = 0; curCard = *curP.handHead;
            while ((curCard != NULL) && (curCard->next != NULL)) { handLength++; curCard = curCard->next; }
            cout << "You now have " << handLength << " card(s) in hand.\n";

            if (curP==&P1) {
                printMenu(P1);
                cin >> opt;
                if (opt=='S') { saveProgress(); break; }
                while ((opt-'a' > handLength+1) || (opt-'a' < 0)) { cout << "Invalid option! Please input option again: "; cin >> opt; }
                if (opt=='a') { cout << "You chose to end this turn.\n"; break; }
                if (opt=='b') {
                    //print non-single coloured property cards with options abcd...
                    //if no non-single coloured card: "Invalid input: no non-single coloured property card. Remake option.\n", actionsLeft++, continue
                    //ask for which property card to change its colour, save in curCard
                    //if is duo coloured: exchange order of colours in curCard.colour
                    //if is multi coloured: ask for new colour, replace old colour with it
                    //if new colour: pushback card to landHead
                    //if existing colour: append card to the list of the colour
                    //print result (e.g. "You changed Red/Yellow Property Card from Red to Yellow.\n")
                }

                for (int i=0; i < opt-'c'; i++) { curCard = curCard->next; }
                if (curCard.id < 35) { //action card
                    makeAction(curCard, P1, comp, discarded, cardPool);
                }
                else if (curCard.id < 74) { //property card
                    putProperty(curCard, P1);
                    if (checkWin(P1)) break;
                }
                else if (curCard.id < 87) { //rent card
                    useRent(curCard, P1, comp, discarded);
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

                if (opt=='a') { cout << "The opponent chose to end this turn.\n"; break; }
                if (opt=='b') {
                    //(dont print) list out non-single coloured property cards with options abcd...
                    //if no non-single coloured card: (no output) actionsLeft++, continue
                    //ask for which property card to change its colour, save in curCard
                    //if is duo coloured: exchange order of colours in curCard.colour
                    //if is multi coloured: ask for new colour, replace old colour with it
                    //if new colour: pushback card to landHead
                    //if existing colour: append card to the list of the colour
                    //print result (e.g. "The opponent changed Red/Yellow Property Card from Red to Yellow.\n")
                }

                for (int i=0; i < opt-'c'; i++) { curCard = curCard->next; }
                if (curCard.id < 35) { //action card
                    makeAction(curCard, comp, P1, discarded, cardPool);
                }
                else if (curCard.id < 74) { //property card
                    putProperty(curCard, comp);
                    if (checkWin(comp)) break;
                }
                else if (curCard.id < 87) { //rent card
                    useRent(curCard, comp, P1, discarded);
                }
                else { //money card
                    depositMoney(curCard, comp);
                }
            }

            actionsLeft--;
        }

        handLength = 0; curCard = *curP.handHead;
        while ((curCard != NULL) && (curCard->next != NULL)) { handLength++; curCard = curCard->next; }
        if (handLength > 7) {
            if (curP = &P1) { cout << "You have more than seven cards in hand. Discard " << handLength-7 << " card(s) from your hand:\n"; }
            else { cout << "The opponent has more than seven cards in hand. Discarding " << handLength-7 << " card(s) from hand...\n"; }
            discardHand(*curP, handLength-7, discarded);
        }


    curP = ((curP==&P1)? &comp : &P1);
    actionsLeft = 3;
    }

    if (checkWin(*curP) { cout << ((curP==&P1)? "Congratulations! You won" : "Oh no! You have lost") << " the game!\n"; }
    cout << "\nThanks for playing!\n";
}
