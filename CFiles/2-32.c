//
//  main.c
//  exercise-2.32
//
//  Created by Courtney Holsinger on 6/10/15.
//  Copyright (c) 2015 Courtney Holsinger. All rights reserved.
//

#include <stdio.h>

int main(void){
    int integer1;
    int integer2;
    double bmi;

    puts("Welcome to the BMI Calculator!");
    
    
    //bodyweight number
    
    
    printf("Please Enter your body weight in pounds\n");
    scanf("%d", &integer1);
    
    
    //height number
    
    
    printf("Please enter your height in inches\n");
    scanf("%d", &integer2);
    
    
    //BMI calculation
    
    
    bmi=(integer1*703)/(integer2*integer2);
    
    printf("Your BMI is %f\n", bmi);
    
    
    //determination of weight class
    
    
    if (bmi <= 18.5){
        puts("You are considered underweight");
    }
    
    else if (18.6 <= bmi && bmi <= 24.9){
        puts("You are considered a normal weight");
    }
    
    else if (25 <= bmi && bmi <=29.9){
        puts("You are considered overweight");
    }
    
    else if (30<=bmi){
        puts("You are considered obese");
    }
    
    else {
        puts("We are not able to calculate your BMI.  Try using numbers instead of letters!");
    }
}
