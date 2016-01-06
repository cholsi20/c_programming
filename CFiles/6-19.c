//
//  main.c
//  6.19 Dice Rolling
//
//  Created by Courtney Holsinger on 6/30/15.
//  Copyright (c) 2015 Courtney Holsinger. All rights reserved.
//
//
//  The frequency of rolls for two dice

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 13

int main(void) {
   
    size_t rollSum; //sum of the rolls for both dice
    unsigned int roll; //roll counter for both dice
    unsigned int frequency [ SIZE ] = {0};
    unsigned int die1;
    unsigned int die2;
    
    //randomizing seed for dice rolling
    srand(time(NULL));
    
    //rolling the two dice 36000 times, and calculating the sum
    for (roll = 1; roll <= 36000; ++roll){
        die1 = 1 + rand() % 6; //should roll die 1 36000 times
        die2 = 1 + rand() % 6; //should roll die 2 36000 times
        rollSum = die1 + die2; //sum of the rolls of the two dice
        ++frequency [rollSum]; //in theory, adding each sum to the frequency array
    }//end roll for loop
    
    //printing table headers for tabular output
    printf("%s%17s\n", "SUM", "FREQUENCY");
    
    
    //output of elements 2-12 in a tabular format
    for (rollSum = 2; rollSum < SIZE; ++rollSum){
        printf("%4d%17d\n", rollSum, frequency[rollSum]);
    }//end for loop which prints table
    
    
}//end main
