//
//  main.c
//  Rounding Floating Point Numbers 9.9
//
//  Created by Courtney Holsinger on 7/18/15.
//  Copyright (c) 2015 Courtney Holsinger. All rights reserved.
//

#include <stdio.h>

int main(void) {
    
    double value = 100.453627;
    
    printf("This program prints rounded integers to the console at various lengths.\n");
    
    //rounding to tenth place value
    printf("%f rounded to the tenths place value is: \n", value);
    printf("%*.*f\n\n", 7, 1, value);
    
    //rounding to the hundredths place value
    printf("%f rounded to the hundredths place value is: \n", value);
    printf("%*.*f\n\n", 7, 2, value);
    
    //rounding to the thousand's place value
    printf("%f rounded to the thousandths place value is: \n", value);
    printf("%*.*f\n\n", 7, 3, value);
    
    //rounding to the ten thousandths place value
    printf("%f rounded to the ten thousandths place value is: \n", value);
    printf("%*.*f\n\n", 7, 4, value);
    
    
} //end main
