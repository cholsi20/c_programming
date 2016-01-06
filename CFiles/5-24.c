//
//  main.c
//  homework 5.24
//
//  Created by Courtney Holsinger on 6/25/15.
//  Copyright (c) 2015 Courtney Holsinger. All rights reserved.
//

#include <stdio.h>

unsigned int fahrenheight( unsigned int c ); //function prototype for fahrenheight

unsigned int celsius( unsigned int f ); //function prototype for celsius

int main(void) {
    
    unsigned int c;
    unsigned int f;
    
    printf("Fahrenheight | Celsius\n");
    for( f = 32; f <= 212; ++f){
        
        printf("%u             %u\n", f, celsius(f));
        
         } // end celsius for loop
    
    printf("Celsius | Fahrenheight\n");
        
    for (c = 0; c <= 100; ++c){
        
        printf("%u        %u\n", c, fahrenheight(c));
        } // end fahrenheight for loop
    
       
    
} //end main


unsigned int fahrenheight( unsigned int c ){
    return ((c * 9) / 5) + 32 ;
} // end fahrenheight function

unsigned int celsius( unsigned int f ){
    return ((f -32) * 5) / 9;
} // end celsius function