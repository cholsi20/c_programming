//
//  main.c
//  Packing Characters into an Integer 10.12
//
//  Created by Courtney Holsinger on 7/27/15.
//  Copyright (c) 2015 Courtney Holsinger. All rights reserved.
//

#include <stdio.h>
#include <limits.h>
#define SIZE 3

//function protocols
void packCharacters( char char1, char char2, char char3, char char4 ); //function to pack characters
void displayBits( unsigned int value); //function to display bits

int main(void) {
    
    char char1, char2, char3, char4 ;
    
    //prompt user to enter four characters
    printf("%s\n", "Please enter four characters separated by a comma: ");
    scanf("%c, %c, %c, %c", &char1, &char2, &char3, &char4);
    
    //display bits before and after
    printf("%s\n", "The characters displayed in bit format before packing: ");
    displayBits(char1);
    displayBits(char2);
    displayBits(char3);
    displayBits(char4);
    
    printf("%s\n", "The characters displayed in bit format after packing: ");
    packCharacters(char1, char2, char3, char4);
    
}

//function to pack bits
void packCharacters( char char1, char char2, char char3, char char4 ){
    
    unsigned int packed;
    
    packed = char1;
    
    packed <<= 8;
    
    packed |= char2;
    
    packed |= char3;
    
    packed |= char4;
    
    printf( "CHARACTER - %c\n", packed );
    
    displayBits( packed );
    
    printf( "\n" );
    
} //end pack characters

//function to display bits
void displayBits( unsigned int value){
    
    unsigned c, displayMask = 1 << 31;
    
    printf( "%7u = ", value );
    
    for ( c = 1; c <= 32; c++ ) {
        putchar( value & displayMask ? '1' : '0' );
        
        value <<= 1;
        
        if ( c % 8 == 0 )
            putchar( ' ' );
    }
    
    putchar( '\n' );
    
    
} // end display bits


