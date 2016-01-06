//
//  main.c
//  homework4.28
//
//  Created by Courtney Holsinger on 6/16/15.
//  Copyright (c) 2015 Courtney Holsinger. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int main(void) {
    //int emp;      // employee number
    int code;     // one code
    float sum1;   // managers
    float sum2;   // hourly workers
    float sum3;   // commission workers
    float sum4;   // pieceworkers
    int n;        //hours worked
    double y;     //hourly pay rate
    double g;     // gross sales
    double f;     // fixed dollar amount per item
    int j;        // number of items produced
    

    // prompting for paycode
    
    puts("Please enter a pay code for each employee.");
    puts("1 = Managers; 2 = Hourly Workers; 3 = Commission Workers; 4 = Pieceworkers");
    puts("Enter the EOF character to end this program \n");
    
    while ((code = getchar()) !=EOF){
        
        
        
        // determine user input
        switch (code){
                
                // salary worker weekly wage calculator
                case '1':
                printf("Please enter salary: \n");
                scanf("%f", &sum1);
                printf("Please enter next pay code\n");
                break;
                
                
                
                // hourly worker weekly wage calculator
                case '2':
                printf("Please enter hours worked: \n");
                scanf("%d", &n);
                if (n <= 40){
                    printf("Please enter hourly rate: \n");
                    scanf("%lf", &y);
                    sum2 = (n * y);
                }
                else {
                    printf("Please enter hourly rate: \n");
                    scanf("%lf", &y);
                    float z = (0.5 * y); //time and a half
                    sum2 = (((n - 40) * (1.5 * z)) + (40 * y));
                }
                printf("Please enter next pay code\n");
                break;
                
                // commission worker weekly wage calculator
                case '3':
                printf("Please enter the gross sales: \n");
                scanf("%lf", &g);
                sum3 = (250 + (5.7 * g));
                printf("Please enter next pay code\n");
                break;
                
                
                // pieceworker
                case '4':
                printf("Please enter the fixed dollar amount for the item produced: \n");
                scanf("%lf", &f);
                printf("Please enter the number of items produced: \n");
                scanf("%d", &j);
                sum4 = (f * j);
                printf("Please enter next pay code\n");
                break;
                
                case '\n': //ignore new lines
                case '\t': //ignore tabs
                case ' ':  //ignore spaces
                break;
                
                
                //default
                default:
                printf("%s", "Incorrect code entered.  Please try 1, 2, 3, or 4. \n");
                puts("Please enter a new code");
                break;
                
        } // switch ends
    }     // while ends
    
        printf("The weekly pay for this employee is: %.2f\n", sum1);
        printf("The weekly pay for this employee is: %.2f\n", sum2);
        printf("The weekly pay for this employee is: %.2f\n", sum3);
        printf("The weekly pay for this employee is: %.2f\n", sum4);
        
    


}        // main ends

