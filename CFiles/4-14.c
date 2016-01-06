//
//  main.c
//  homework4.14
//
//  Created by Courtney Holsinger on 6/17/15.
//  Copyright (c) 2015 Courtney Holsinger. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int main(void) {
    
    int number;
    int total = 0;
    
    for (number=1; number <=5; number++){
        
        int sum = 1;
        
        for (total=number; total>=1; total--){
            sum = total * sum;
        
            
        } // end 1st nested for loop
        
        printf("!%d   %d\n", number, sum);
        
        
    } // end for
    
    return 0; // terminates program
    
} //end main
