#ifndef header_h
#define header_h
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

struct card {
    int id; //from 0 to 106. 0-34: action, 35-73: property, 74-86: rent, 87-106: money
    string name;
    int value;
    string colour;
    //Green, DarkBlue, LightBlue, Red, Utility, Yellow, Orange, Brown, Purple, Railroad, All, None (for money cards and some action cards)
    //if more than one colour: the first colour is the one being used (e.g. "Red,Yellow" is a duo colour card used as red now)
    //for multi colour card used as red card: "Red, All"
    card *next;
};

struct player {

    card *handHead=NULL; //linked list of cards in hand
    card *bankHead=NULL; //linked list of cards in bank
    vector<card> landHead; //vector of linked list of property cards

    bool sayNo = false; //if card JustSayNo in hand
    bool doubleRent = false;
    int wealth = 0;
};
extern player P1, comp, *curP;     //current player

extern vector<card>  discarded, cardPool, draw;

void genCards();
void game();
void new_game();
int index(int cardID, vector<card> v);
//save game progress and return to mainpage
void saveProgress();
bool initialize(char n);
char filecheck();
void delete_file(char n);
#endif
