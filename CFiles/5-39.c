//
//  main.c
//  TEST Recursive Greatest Common Divisor 5.39
//
//  Created by Courtney Holsinger on 7/9/15.
//  Copyright (c) 2015 Courtney Holsinger. All rights reserved.
//

#include <stdio.h>

int gcd( int x, int y );

int main() {
    
    int divisor;
    int integer1;
    int integer2;
    
    printf("Please enter your first integer\n");
    scanf("%d", &integer1);
    
    printf("Please enter your second integer\n");
    scanf("%d", &integer2);
    
    divisor = gcd( integer1, integer2 );
    
    printf("The GCD of %d and %d is: %d", integer1, integer2, divisor);
    
    
    
} //end main

//begin gcd function
int gcd( int x, int y ){
    
    
    if ((y >= x) && (y % x) == 0){
        return x;
    }
    
    else if ((x >= y) && (x % y) == 0){
        return y;
    }
    
    else {
        return 1;
    }
    
    
} //end gcd function 