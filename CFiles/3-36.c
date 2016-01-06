//
//  main.c
//  homework3.36
//
//  Created by Courtney Holsinger on 6/11/15.
//  Copyright (c) 2015 Courtney Holsinger. All rights reserved.
//

#include <stdio.h>

int main(void) {
    unsigned int counter;
    //unsigned int number;
    counter=0;
    int pNumber;
    pNumber = counter;
    
    while (counter < 1000000000){
        counter++;
        while (pNumber < 1000000000) {
            pNumber+=100000000;
            printf("%d\n", pNumber);
        }
       
    }
}
