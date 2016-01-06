//
//  main.c
//  TEST 8.24 Strings Ending with 'ed'
//
//  Created by Courtney Holsinger on 7/22/15.
//  Copyright (c) 2015 Courtney Holsinger. All rights reserved.
//

#include <stdio.h>
#include <string.h>



int main(void) {
    
    const char *string = "This is a string.";
    const char *string2 = "but is not how you start a sentence.";
    const char *string3 = "Some of it begins with a 'b', some of it does not.";
    const char *string4 = "Well, we need to get started";
    
    
    char *stringPtr = strlen(string);
    char subscript1 = stringPtr - 1;
    char subscript2 = stringPtr - 2;
    if (string[subscript1] == 'e' && string[subscript2] == 'd'){
        printf("%s\n", string);
        } //end string if
    
    char *stringPtr2 = strlen(string2);
    char subscript3 = stringPtr - 1;
    char subscript4 = stringPtr - 2;
    if (string2[subscript4] == 'e' && string2[subscript3] == 'd'){
        printf("%s\n", string2);
    } //end string2 if
    
    
    char *stringPtr3 = strlen(string3);
    char subscript5 = stringPtr - 1;
    char subscript6 = stringPtr - 2;
    if (string3[subscript6] == 'e' && string3[subscript5] == 'd'){
        printf("%s\n", string3);
        
    } //end if
    
    char *stringPtr4 = strlen(string4);
    char subscript7 = stringPtr4 - 1;
    char subscript8 = stringPtr4 - 2;
    if (string4[subscript8] == 'e' && string4[subscript7] == 'd'){
        printf("%s\n", string4);
        
    } //end if
    
}


