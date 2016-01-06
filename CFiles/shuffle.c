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

//prototypes

//shuffling modifies wDeck
void
shuffle (size_t wDeck[][FACES]);

//dealing doesn't modify the arrays
void
dealHands (size_t wDeck[][FACES], size_t wHands[][HAND]);

// Prints a single card
void
printCard (size_t wCard, const char *wSuits[SUITS], const char *wFaces[FACES]);

// Determines the suit (index) of a given card
size_t
determineSuitOfCard (size_t wCard);

// Determines the face (index) of a given card
size_t
determineFaceOfCard (size_t wCard);

// Find pair
unsigned int
findOnePair (size_t wHand[HAND]);

// Find two pairs
unsigned int
findTwoPairs (size_t wHand[HAND]);

// Find three of a kind
unsigned int
findThreeOfAKind (size_t wHand[HAND]);

// Straight
unsigned int
findStraight (size_t wHand[HAND]);

// Flush
unsigned int
findFlush (size_t wHand[HAND]);

// Full House
unsigned int
findFullHouse (size_t wHand[HAND]);

// Four of a kind
unsigned int
findFourOfAKind (size_t wHand[HAND]);

// Straight Flush
unsigned int
findStraightFlush (size_t wHand[HAND]);

int
main (void)
{

  //initialize suit array
  const char *suits[SUITS] =
    { "Hearts", "Diamonds", "Clubs", "Spades" };

  //initialize face array
  const char *faces[FACES] =
    { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
        "Ten", "Jack", "Queen", "King" };

  size_t deck[SUITS][FACES] =
    {
      { 0 } };

  size_t hands[PLAYERS][HAND] =
    {
      { 0 } };

  // initialize random number generator
  srand (time (NULL));

  shuffle (deck);
  dealHands (deck, hands);

}

//shuffle cards in deck
void
shuffle (size_t wDeck[][FACES])
{
  size_t row;
  size_t column;
  size_t card;

  for (card = 0; card < CARDS; ++card)
    {

      //choose a random location until unoccupied slot found
      do
        {
          row = rand () % SUITS;
          column = rand () % FACES;
        }
      while (wDeck[row][column] != 0);

      //place card number in chosen slot of deck
      wDeck[row][column] = card;
    }
}

// The deal function deals a hand for each player from the deck by picking cards
// from the top of the deck, alternating between players.
void
dealHands (size_t wDeck[][FACES], size_t wHands[][HAND])
{

  size_t player;
  size_t card;

  size_t current = 0;
  size_t current_suit = 0;
  size_t current_face = 0;

  for (card = 0; card < HAND; card++)
    {

      for (player = 0; player < PLAYERS; player++)
        {

          current = card * PLAYERS + player;

          current_suit = determineSuitOfCard (current);
          current_face = determineFaceOfCard (current);

          wHands[player][card] = wDeck[current_suit][current_face];
        }
    }
}

void
printCard (size_t wCard, const char *wSuits[SUITS], const char *wFaces[FACES])
{
  size_t suit;
  size_t face;

  suit = determineSuitOfCard (wCard);
  face = determineFaceOfCard (wCard);

  printf ("%s of %s", wFaces[face], wSuits[suit]);
}

size_t
determineSuitOfCard (size_t wCard)
{

  return wCard / SUITS;
}

size_t
determineFaceOfCard (size_t wCard)
{

  return wCard % FACES;
}

// Find pair (finds a single pair)
unsigned int
findOnePair (size_t wHand[HAND])
{

  size_t countOfFaces[FACES] =
    { 0 };

  unsigned int foundAPair = 1;

  size_t card;
  for (card = 0; card < HAND; card++)
    {

      size_t face = determineFaceOfCard (wHand[card]);

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
}

// Find two pairs
unsigned int
findTwoPairs (size_t wHand[HAND])
{

  size_t countOfFaces[FACES] =
    { 0 };

  unsigned int numberOfPairs = 0;

  size_t card;
  for (card = 0; card < HAND; card++)
    {

      size_t face = determineFaceOfCard (wHand[card]);

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
}

// Find three of a kind
unsigned int
findThreeOfAKind (size_t wHand[HAND])
{

  size_t countOfFaces[FACES] =
    { 0 };

  unsigned int foundThree = 1;

  size_t card;
  for (card = 0; card < HAND; card++)
    {

      size_t face = determineFaceOfCard (wHand[card]);

      countOfFaces[face]++;

      if (countOfFaces[face] == 3)
        {

          foundThree = 0;
        }
      else if (countOfFaces[face] == 4)
        {

          return 1;
        }
      else if (countOfFaces[face] == 2 && foundThree)
        {

          return 1;
        }
    }
  return foundThree;
}

// Straight
unsigned int
findStraight (size_t wHand[HAND])
{
  size_t card;

  size_t lowFace;
  size_t highFace;

  size_t firstSuit;
  unsigned int foundSecondSuit = 1;

  for (card = 0; card < HAND; card++)
    {
      size_t suit = determineSuitOfCard (wHand[card]);
      size_t face = determineFaceOfCard (wHand[card]);

      // first card
      if (card == 0)
        {
          lowFace = face;
          highFace = face;

          firstSuit = suit;
        }
      // all other cards
      // check for two equal faces first
      else if (face == lowFace || face == highFace)
        {

          return 1;
        }
      // update low and high face, if necessary
      else
        {

          if (suit != firstSuit)
            {

              foundSecondSuit = 0;
            }

          // an Ace can only go low if the low face is at most a Five
          if (face == 0 && lowFace > HAND - 1)
            {

              face = 13;
            }
          if (face < lowFace)
            {

              lowFace = face;
            }

          if (face > highFace)
            {

              highFace = face;
            }

          if ((highFace - lowFace + 1) != HAND)
            {

              return 1;
            }
        }
    }

  return foundSecondSuit;
}

// Flush (a flush is five cards of the same suit)
unsigned int
findFlush (size_t wHand[HAND])
{
  size_t card;

  size_t firstSuit;

  for (card = 0; card < HAND; card++)
    {
      size_t suit = determineSuitOfCard (wHand[card]);

      // first card
      if (card == 0)
        {

          firstSuit = suit;
        }
      // other cards
      else if (suit != firstSuit)
        {

          return 1;
        }
    }
  return 0;
}

// Full House (a pair and three of a kind)
unsigned int
findFullHouse (size_t wHand[HAND])
{

  if (findOnePair (wHand) && findThreeOfAKind (wHand))
    {

      return 0;
    }
  return 1;
}

// Four of a kind
unsigned int
findFourOfAKind (size_t wHand[HAND])
{

  size_t countOfFaces[FACES] =
    { 0 };

  size_t card;
  for (card = 0; card < HAND; card++)
    {

      size_t face = determineFaceOfCard (wHand[card]);

      countOfFaces[face]++;

      if (countOfFaces[face] == 4)
        {

          return 0;
        }
    }
  return 1;
}

// Straight Flush
unsigned int
findStraightFlush (size_t wHand[HAND])
{
  size_t card;

  size_t lowFace;
  size_t highFace;

  size_t firstSuit;

  for (card = 0; card < HAND; card++)
    {
      size_t suit = determineSuitOfCard (wHand[card]);
      size_t face = determineFaceOfCard (wHand[card]);

      // first card
      if (card == 0)
        {
          lowFace = face;
          highFace = face;

          firstSuit = suit;
        }
      // all other cards
      // check for flush or two equal faces first
      else if (suit != firstSuit || face == lowFace || face == highFace)
        {

          return 1;
        }
      // update low and high face, if necessary
      else
        {
          // an Ace can only go low if the low face is at most a Five
          if (face == 0 && lowFace > HAND - 1)
            {

              face = 13;
            }
          if (face < lowFace)
            {

              lowFace = face;
            }

          if (face > highFace)
            {

              highFace = face;
            }

          if ((highFace - lowFace + 1) != HAND)
            {

              return 1;
            }
        }
    }

  return 0;
}

