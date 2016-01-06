//
//  main.c
//  Searching for Substrings 8.16
//
//  Created by Courtney Holsinger on 7/15/15.
//  Copyright (c) 2015 Courtney Holsinger. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define SIZE 20

int main(void) {
    
    char arrayString[SIZE]; //array to be searched, initilized to empty
    char searchPtr[SIZE]; //string to search for
    
    //get user input from command line for string to be searched
    printf("%s", "Please enter a string you would like to search ending with 0: \n");
    fgets(arrayString, SIZE, stdin);
    
    //get user input from command line for search key
    printf("%s", "Please enter a string you would like to search for: \n");
    fgets(searchPtr, SIZE, stdin);
    
    
    //printf("%s\n", "Please enter a string of 19 characters or less.");
    //sscanf("%s", &arrayString);
    
    printf("%s%s\n%s%s\n\n%s\n%s%s\n\n%s\n%s%s\n",
           "string = ", arrayString, "searchPtr = ", searchPtr,
           "The remainder of the string beginning with the",
           "first occrance of searchPtr is: ", strstr( arrayString, searchPtr),
           "The remainder of the string beginning with the ",
           "second occrance of searchPtr is: ", strstr( arrayString, searchPtr + 1));
    
} //end main
