//
//  main.c
//  Unpacking Characters From An Integer 10.13
//
//  Created by Courtney Holsinger on 7/30/15.
//  Copyright (c) 2015 Courtney Holsinger. All rights reserved.
//

#include <stdio.h>

//function prototypes
void displayBits( unsigned int value); //function to display bits
void unpackCharacters(unsigned int packed, unsigned char char1, unsigned char char2, unsigned char char3, unsigned char char4); //function to unpack characters
unsigned int packCharacters( char char1, char char2, char char3, char char4 ); //function to first pack characters


//begin main
int main(void){
    
    unsigned int packed;
    unsigned char char1, char2, char3, char4 ;
    
    //prompt user to enter four characters
    printf("%s\n", "Please enter four characters separated by a comma: ");
    scanf("%c, %c, %c, %c", &char1, &char2, &char3, &char4);
    
    //display bits before and after
    printf("\n%s\n", "The characters displayed in bit format before packing: ");
    displayBits(char1);
    displayBits(char2);
    displayBits(char3);
    displayBits(char4);
    
    //***************
    //PACKING PROCESS
    //***************
    
    printf("\n%s\n", "The characters displayed in bit format after packing: ");
    packed = packCharacters(char1, char2, char3, char4);
    
    displayBits(packed);
    puts("");
    
    //***********************
    //BEGIN UNPACKING PROCESS
    //***********************
    
    
    printf("%s\n", "The characters unpacked again display as follows in bits: ");
    unpackCharacters(packed, char1, char2, char3, char4);
    displayBits(char1);
    displayBits(char2);
    displayBits(char3);
    displayBits(char4);
    
    
   
} //end main

unsigned int packCharacters( char char1, char char2, char char3, char char4 ){
    unsigned int packed;
    
    packed = (char1 << 8) | char2 | char3 | char4;
    return packed;
    
} //end pack characters


//begin function to unpack characters
void unpackCharacters(unsigned int packed, unsigned char char1, unsigned char char2, unsigned char char3, unsigned char char4){
    
    
    unsigned int mask = 4278190080;
    unsigned int mask2 = 16711680;
    unsigned int mask3 = 65280;
    unsigned int mask4 = 255;
    
    
    char1 = (packed & mask) >> 8;
    
    char2 = packed & mask2;
    
    char3 = packed & mask3;
    
    char4 = packed & mask4;
    
    
} //end function to pack characters


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
