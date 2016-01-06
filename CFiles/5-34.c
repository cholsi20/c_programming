//
//  main.c
//  recursive-exponentiation
//
//  Created by Courtney Holsinger on 6/23/15.
//  Copyright (c) 2015 Courtney Holsinger. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

//prototype for power function
int power( int, unsigned int );

int main(void) {
    
    int base;
    unsigned int exponent;
    int sum;

    //prompt user for base input
    printf("Please enter an integer for a base number: \n");
    scanf("%i", &base);
    
    //prompts user for exponential value
    printf("Please enter an integer for the exponential value: \n");
    scanf("%u", &exponent);
    
    sum = power(base, exponent);
    
    //prints exponential value
    printf("The value of %d raised to the %d is %d.\n",base, exponent, sum);
    
   
} // end main


int power(int x, unsigned int n){
    if ( n == 1 ){
        return x;
    } //end if
    else {
        return (x * power( x, (n-1)));
    } // end else
} // end power funtion