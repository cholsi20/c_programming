//
//  main.c
//  TEST 7.13 Card Shuffling and Dealing
//
//  Created by Courtney Holsinger on 7/22/15.
//  Copyright (c) 2015 Courtney Holsinger. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SUITS 4
#define FACES 13
#define CARDS 52

#define HAND 5
#define PLAYERS 2

//prototypes for shuffle and deal
void shuffle( size_t wDeck[][FACES] ); //shuffling modifies wDeck
void deal( size_t wDeck[][FACES], const char *wFace[],
          const char *wSuit[] ); //dealing doesn't modify the arrays
void dealHand(size_t wHands[][HAND], size_t wDeck[][FACES]);

//prototypes for determing suit and face
size_t determineSuit(size_t wCard);
size_t determineFace(size_t wCard);


//prototypes for determing poker hand
unsigned int findAPair(size_t wHand[HAND]);
unsigned int findTwoPairs(size_t wHand[HAND]);
unsigned int findThreeOfAKind(size_t wHand[HAND]);
unsigned int findFourOfAKind(size_t wHand[HAND]);
unsigned int findFlush(size_t wHand[HAND]);
unsigned int findFullHouse(size_t wHand[HAND]);
unsigned int findStraightFlush(size_t wHand[HAND]);
unsigned int findStraight (size_t wHand[HAND]);

//prototypes for determing player outcomes
unsigned int determingPlayerHand(size_t wHand[HAND]);
void playerRank( size_t wHands[PLAYERS][HAND]);

//prototypes for print functions
void printCard(unsigned int wCard, const char *wFaces[FACES], const char *wSuit[SUITS]);
void printHand(size_t wHands[PLAYERS][HAND], const char *wFaces[FACES], const char *wSuit[SUITS]);



int main(void) {
    
   //initialize suit array
    const char *suit[SUITS] = {"Hearts", "Diamonds", "Clubs", "Spades" };
    
    //initilize face array
    const char *face[ FACES ] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven",
        "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
    
    //initilize deck array
    size_t deck[ SUITS ][FACES] = {{0}};
    
    size_t hands[PLAYERS][HAND] = {{0}};
    
    srand(time(NULL));  //random seed generator
    
    shuffle(deck); //shuffle the deck
    dealHand(hands, deck);
    
    playerRank(hands);
    
} //end main

//determine suit
size_t determineSuit(size_t wCard){
    return wCard / SUITS;
} // end determine suit

//determine face
size_t determineFace(size_t wCard){
    return wCard % FACES;
}//end determine face

//if four of a kind

//shuffle cards in deck
void shuffle( size_t wDeck[][FACES] ){
    size_t row; //row number
    size_t column; //column number
    size_t card; //counter
    
    for (card = 0; card <= CARDS; ++card){
        
        //choose a random location until unoccupied slot found
        do {
            row = rand() % SUITS; //random generator of suit
            column = rand() % FACES; //column is randomly generated as face
        } //end do
        while (wDeck[row][column] != 0); //end do while
        
        //place card number in chosen slot of deck
        wDeck[row][column] = card;
    }// end for
} //end shuffle function

//deal cards in deck
void deal( size_t wDeck[][FACES], const char *wFace[],
          const char *wSuit[] ){
    size_t card; //card counter
    size_t row; //row counter
    size_t column; //column counter
    
    //deal each of the cards
    for (card = 0; card <= CARDS; ++card){
        //loop through rows of wDeck
        for (row = 0; row < SUITS; ++row){
            //loop through columns in wDeck for current row
            for(column = 0; column < FACES; ++column){
                //if slot contians current card, display card
                if (wDeck[row][column] == card){
                    printf("%5s of %-8s%c", wFace[column], wSuit[row],
                           card % 2 == 0 ? '\n' : '\t'); //two column format
                } //end if
            } //end column for
        } //end row for
    } //end card for
} //end function deal

void dealHand(size_t wHands[][HAND], size_t wDeck[][FACES]){
    
    size_t cards;
    size_t players;
    unsigned long int current;
    unsigned long int current_suit;
    unsigned long int current_face;
    
    for (cards = 0; cards <= HAND; cards++){
        
        for (players = 0; players < PLAYERS; players++){
            current = cards * PLAYERS + players;
            current_suit = determineSuit(current);
            current_face = determineFace(current);
            wHands[players][cards] = wDeck[current_suit][current_face];
        } // end players for
    } // end cards for

    
} // end deal hand


//PRINT THE CARD
void printCard(unsigned int wCard, const char *wFaces[FACES], const char *wSuit[SUITS]){
    //find suit and face
    size_t suit;
    size_t face;
    
    suit = determineSuit(wCard);
    face = determineFace(wCard);
    
    printf("%c of %c", *wFaces[face], *wSuit[suit]);
    
    
} //end print card

void printHand(size_t wHands[PLAYERS][HAND], const char *wFaces[FACES], const char *wSuit[SUITS]){
    
    size_t suit;
    size_t face;
    
    printf("%c of %c", *wFaces[face], *wSuit[suit]);
    
    
} //end print hand

//******************************
//BEGIN HAND TYPE DETERMINATION
//******************************


//find A PAIR
unsigned int findAPair(size_t wHand[HAND]){
    
    size_t countOfFaces[FACES] = { 0 };
    unsigned int foundAPair = 1;
    size_t card;
    
    
    for (card = 0; card < HAND; card++)
    {
        
        size_t face = determineFace(wHand[card]);
        
        countOfFaces[face]++;
        
        if (countOfFaces[face] == 3)
        {
            
            return 1;
        }
        else if (countOfFaces[face] == 2)
        {
            
            if (foundAPair)
            {
                
                return 1;
            }
            
            foundAPair = 0;
        }
    }
    return foundAPair;
    
} // end find a pair


//find TWO PAIRS
unsigned int findTwoPairs(size_t wHand[HAND]){
    
    size_t countOfFaces[FACES] = { 0 };
    
    unsigned int numberOfPairs = 0;
    
    size_t card;
    for (card = 0; card < HAND; card++){
        
        size_t face =  determineFace(wHand[card]);
        countOfFaces[face]++;
        
        if (countOfFaces[face] == 3)
        {
            
            return 1;
        }
        else if (countOfFaces[face] == 2)
        {
            
            numberOfPairs++;
        }
    }
    return numberOfPairs == 2;
    
} //end find two pairs


//find THREE OF A KIND
unsigned int findThreeOfAKind(size_t wHand[HAND]){
    
    size_t countOfFaces[FACES] = {0};
    size_t card;
    unsigned int foundThree = 1;
    
    for (card = 0; card < HAND; card++){
        size_t face = determineFace(wHand[card]);
        countOfFaces[face]++;
        
        if (countOfFaces[face] == 3){
            foundThree =  0;
        } //end if
        
        else if (countOfFaces[face] == 4){
            return 1;
        } //end else if
        
        else if (countOfFaces[face] == 2 && foundThree){
            return 1;
        } //end else if
    } //end card for loop
    
    return 1;
    
} //end find three of a kind



//find FOUR OF A KIND
unsigned int findFourOfAKind(size_t wHand[HAND]){
    
    size_t countOfFaces[FACES] = {0};
    size_t card;
    
    for (card = 0; card < HAND; card++){
        size_t face = determineFace(wHand[card]);
        countOfFaces[face]++;
        
        if (countOfFaces[face] == 4){
            return 0;
        } //end if
    } //end card for loop
    
    return 1;
    
} //end for of a kind

unsigned int findStraight (size_t wHand[HAND]){
    size_t card;
    
    size_t lowFace;
    size_t highFace;
    
    size_t firstSuit;
    unsigned int foundSecondSuit = 1;
    
    for (card = 0; card < HAND; card++){
        size_t suit = determineSuit(wHand[card]);
        size_t face = determineFace(wHand[card]);
        
        // first card
        if (card == 0){
            lowFace = face;
            highFace = face;
            
            firstSuit = suit;
        }
        // all other cards
        // check for two equal faces first
        else if (face == lowFace || face == highFace){
            
            return 1;
        }
        // update low and high face, if necessary
        else {
            
            if (suit != firstSuit){
                
                foundSecondSuit = 0;
            } //end if
            
            // an Ace can only go low if the low face is at most a Five
            if (face == 0 && lowFace > HAND - 1){
                
                face = 13;
            } //end if
            if (face < lowFace){
                
                lowFace = face;
            } //end if
            
            if (face > highFace){
                
                highFace = face;
            } //end if
            
            if ((highFace - lowFace + 1) != HAND){
                
                return 1;
            } //end if
        } //end else
    } //end for
    
    return foundSecondSuit;
} //end find straight


//find FLUSH
unsigned int findFlush(size_t wHand[HAND]){
    
    size_t card;
    size_t firstSuit = 5;
    for (card = 0; card < HAND; card++){
        size_t suit = determineSuit(wHand[card]);
        //determing if all cards are the same suit
        if (card == 0){
            firstSuit = suit;
        } //end if
        else if (suit != firstSuit){
            return 1;
        } //end else if
    } //end card for loop
    
    return 0;
    
} //end find flush



//find FULL HOUSE
unsigned int findFullHouse(size_t wHand[HAND]){
    if (findAPair(wHand) && findThreeOfAKind(wHand)){
        return 0;
    } //end if
    
    return 1;
} //end full house


//find STRAIGHT FLUSH
unsigned int findStraightFlush(size_t wHand[HAND]){
    
    size_t lowFace;
    size_t highFace;
    size_t card;
    size_t firstSuit;
    
    for (card = 0; card < HAND; card++){
        size_t suit = determineSuit(wHand[card]);
        size_t face = determineFace(wHand[card]);
        //determing if all cards are the same suit
        if (card == 0){
            firstSuit = suit;
            lowFace = face;
            highFace = face;
        } //end if
        else if (suit != firstSuit || face == lowFace || face == highFace){
            return 1;
        } //end else if
        
        //determination for ace being high or low, which depends on hand
        else{
            // an Ace can only go low if the low face is at most a Five
            if (face == 0 && lowFace > HAND - 1){
                
                face = 13;
            } //end if
            if (face < lowFace){
                
                lowFace = face;
            } //end if
            
            if (face > highFace){
                
                highFace = face;
            } //end if
            
            if ((highFace - lowFace + 1) != HAND){
                
                return 1;
            } //end if
        } //end else
    } //end for
    
    return 0;
    
} //end straight flush

//****************************
//DETERMINING PLAYER OUTCOMES
//****************************

//determing PLAYER HAND
unsigned int determingPlayerHand(size_t wHand[HAND]){
    
    if (findStraightFlush(wHand) == 0){
        return 8;
    } //end if
    
    else if (findFourOfAKind(wHand) == 0){
        return 7;
    } //end else if
    
    else if (findFullHouse(wHand) == 0){
        return 6;
    } //end else if
    
    else if (findFlush(wHand) == 0){
        return 5;
    } //end else if
    
    else if (findStraight(wHand) == 0){
        return 4;
    } //end else if
    
    else if (findThreeOfAKind(wHand) == 0){
        return 3;
    } //end else if
    
    else if (findTwoPairs(wHand) == 0){
        return 2;
    } //end else if
    
    else if (findAPair(wHand) == 0){
        return 1;
    }
    
    return 0;
    
} //end determing player hand
 



//determing PLAYER RANK
void playerRank( size_t wHands[PLAYERS][HAND]){
    
    
    size_t player1 = determingPlayerHand(wHands);
    unsigned int player2 = determingPlayerHand(wHands);
    
    if (player1 > player2){
        printf("%s", "Player 1 Wins!");
    }//end if
    
    else {
        printf("%s", "Player 2 Wins!");
    }
    
} //end player rank






