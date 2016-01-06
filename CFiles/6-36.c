//
//  main.c
//  TEST String Backwards 6.36
//
//  Created by Courtney Holsinger on 7/9/15.
//  Copyright (c) 2015 Courtney Holsinger. All rights reserved.
//

#include <stdio.h>
#include <string.h>

//function prototype
void backwards( const char string[], int subscript);
//for printing an array backwards

int main(void) {
    
    char stringArray[13] = "Hello World";
    
    
    backwards(stringArray, 13);
    
    
    
   
}

//begin function to print letters backwards
void backwards(const char string[], int subscript){
    
    if (subscript >= 0){
        printf("%c", string[subscript]);
        backwards(string, subscript - 1);
    }
   
}

//function to print array subscripts