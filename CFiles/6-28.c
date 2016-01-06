//
//  main.c
//  Test 6. 28
//
//  Created by Courtney Holsinger on 7/9/15.
//  Copyright (c) 2015 Courtney Holsinger. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 20

//function prototypes
void printArray( unsigned int array[] );

int main(void) {
    
    unsigned int randomNumberArray[ SIZE ] = {0};
    unsigned int generator; //counter to generate random numbers
    unsigned int randomNumber; //inside random number array
    unsigned int randomNumberSum = 0;
    unsigned int newArray[ SIZE ] = {0};
    unsigned int newValues = 0;
    unsigned int count = 0;
    
    
    //generate random seed
    srand(time(NULL));
    
    
    for (generator = 0; generator < SIZE; ++generator){
        randomNumber = 1 + rand() % 10;
        ++randomNumberArray[ randomNumber ];
        
    }// end random number to array generation
    
    printf("The initial array values are as follows: \n");
    printArray(&randomNumberArray[ randomNumberSum ]);
    
    
    //for loop to add duplicate deletion values to new array
    for(randomNumber=0; randomNumber < SIZE; randomNumber++)
    {
        for(newValues=0; newValues < count; newValues++)
        {
            if(randomNumberArray[randomNumber]==newArray[newValues])
                break;
        }
        if(newValues==count)
        {
            newArray[count] = randomNumberArray[randomNumber];
            count++;
        }
    }
    
    printf("\nThe new array's values, with duplicates removed, is: \n");
    printArray(&newArray[ newValues ]);
    
} //end main


//function to print array subscripts
void printArray( unsigned int array[] ){
    size_t counter;
    
    for (counter = 0; counter < SIZE; ++counter){
        if (counter % 10 == 0) { //begin new line every ten values
            puts("");
            } //end if
        
        printf( "%u", array[counter]);
    } //end for
        
} // end function printArray