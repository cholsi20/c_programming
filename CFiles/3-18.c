//
//  main.c
//  homework-3.18
//
//  Created by Courtney Holsinger on 6/11/15.
//  Copyright (c) 2015 Courtney Holsinger. All rights reserved.
//

#include <stdio.h>

int main(void) {
    // variables
    unsigned int grossSales;
    double earnings;
    unsigned int employees;
    unsigned int counter;
    counter = 0;
    
    printf("Welcome to the gross income calculator!  Enter -1 at any time to quit the program. \n");
    
    // prompt for number of employees
    
    puts("Please enter the number of employees: ");
    scanf("%d", &employees);
    
    //while statement
    
    while (counter < employees){
    
    
    // prompt for user input of gross sales
    
    puts("Please enter Sales in Dollars:");
    scanf("%d", &grossSales);
    
    earnings = 200 + (.09 * grossSales);
    
    
    printf("Salary is: %.2f\n", earnings);
        counter=counter+1;
    }
}
