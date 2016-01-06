//
//  main.c
//  Reading an Integer with Each scanf Conversion Specifier 9.13
//
//  Created by Courtney Holsinger on 7/18/15.
//  Copyright (c) 2015 Courtney Holsinger. All rights reserved.
//

#include <stdio.h>

int main(void) {
    
    //list of int values to scan for
    int value1, value2, value3, value4, value5, value6, value7, value8;
    
    puts("Enter the integer 437 for each prompt");
    
    //scans for value in each integer conversion specifier
    scanf("%d%i%o%u%x%h%l%llu", &value1, &value2, &value3, &value4, &value5, &value6, &value7, &value8);
    
    //prints each value in every integer conversion specifier
    puts("The output of this integer in each format is: ");
    printf("%d, %i, %o, %u, %x, %h, %l, %llu\n", value1, value2, value3, value4, value5, value6, value7, value8);
    
} // end main
