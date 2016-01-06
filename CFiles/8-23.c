//
//  main.c
//  TEST 8.23 Strings Starting with 'b'
//
//  Created by Courtney Holsinger on 7/22/15.
//  Copyright (c) 2015 Courtney Holsinger. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main(void) {
    
    const char *string = "This is a string.\n";
    const char *string2 = "but is not how you start a sentence.\n";
    const char *string3 = "Some of it begins with a 'b', some of it does not.\n";
    
    if (string[0] == 'b'){
            printf("%s", string);
            
        } //end if
    
    if (string2[0] == 'b'){
        printf("%s", string2);
    }
    
    if (string3[0] == 'b'){
        printf("%s", string3);
        
    } //end if
    
}
