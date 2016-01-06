//
//  main.c
//  Right Shifting Integers 10.10
//
//  Created by Courtney Holsinger on 7/30/15.
//  Copyright (c) 2015 Courtney Holsinger. All rights reserved.
//

#include <stdio.h>

//function prototype
void displayBits(unsigned int x);

//begin main
int main(void){
    
    unsigned int rightShift = 100000;
    printf("Before: ");
    displayBits(rightShift);
    printf("\nAfter:  ");
    rightShift >>= 4;
    displayBits(rightShift);
    printf("\n");
    
    return 0;
} //end main

// begin function to display bits
void displayBits(unsigned int x){
    unsigned int counter;
    unsigned int mask = 1 << 31;
    //for 32 bit system display either one or zero
    for (counter = 1; counter <= 32; counter++) {
        putchar(x & mask ? '1' : '0');
        x <<= 1;
        if (counter % 8 == 0)
            putchar(' ');
    } //end for
    
} //end function display bits
