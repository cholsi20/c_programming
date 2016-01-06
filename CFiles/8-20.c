//
//  main.c
//  Number of Words in a String 8.20
//
//  Created by Courtney Holsinger on 7/18/15.
//  Copyright (c) 2015 Courtney Holsinger. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main(void) {
    
    char string[] = "Some text to analyze for tokens and how many there are.";
    char *tokenPtr; //creates character pointer
    
    //tokenize sentence
    tokenPtr = strtok(string, " ");
    
    //count words in sentence
    int counter = 0;
    
    while (tokenPtr != NULL){
        counter++;
        tokenPtr = strtok(NULL, " "); //get the next token
        //printf("The number of words in this sentence is %d", counter);
    } //end while
    
    printf("The number of words in the string is: %d\n", counter);
}// end main
