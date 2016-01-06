//
//  main.c
//  Left Shifting Integer 10.11
//
//  Created by Courtney Holsinger on 7/21/15.
//  Copyright (c) 2015 Courtney Holsinger. All rights reserved.
//

#include <stdio.h>

//function protocols
unsigned int power2(unsigned int number, unsigned int pow); //function to shift bit by one

int main(void) {
    
    unsigned int number;
    unsigned int power;
    unsigned int solution;
    
    printf("%s\n", "Please input a number: ");
    scanf("%d", &number);
    
    printf("%s\n", "Please insput the power of two by which to multiply number: ");
    scanf("%d", &power);
    
    solution = power2(number, power);
    
    printf("The value of %d times 2 to the power of %d is: ", number, power);
    printf("%d\n", solution);
    
} //end main

//begin function
unsigned int power2(unsigned int number, unsigned int pow){
    
    unsigned int byTwo = 1;
    unsigned int newValue = 0;
    int count;
    
    //for loop to count how many times to shift by 1, or multiply by 2
    for (count = 1; count < pow; ++count){
        byTwo <<= 1; //shift bit by one to multiply value by two
        newValue = byTwo * 2 * number;
        
    } // end for loop
    
   return newValue; //return value
    
} //end power2 function

