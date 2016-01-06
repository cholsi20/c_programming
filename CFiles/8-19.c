//
//  main.c
//  Counting Letters of Alphabet in a String 8.19
//
//  Created by Courtney Holsinger on 7/15/15.
//  Copyright (c) 2015 Courtney Holsinger. All rights reserved.
//
//  inner while loop taken from http://www.cplusplus.com/reference/cstring/strchr/

#include <stdio.h>
#include <string.h>
#include <ctype.h>


//function prototypes
//char arrayLowercase(const char *array);

int main(void) {
    
    const char *string = "Some text can go here, and be searched for character occurancesA.";
    const char *letters = "abcdefghijklmnopqrstuvwxyz";
    int i;
    
    
    
    for (i = 0; i < strlen(letters); i++)
    {
        int count = 0;
        //if character a is found in string
        char *pointerToCharacter;
        pointerToCharacter = strchr(string, letters[i]);
        while (pointerToCharacter != NULL)
        {
            pointerToCharacter = strchr(pointerToCharacter + 1, letters[i]);
            count++;

        } // end while
        printf ("\'%c\' was found %d times.\n", letters[i], count);
    }
    
    
    
    
} //end main




