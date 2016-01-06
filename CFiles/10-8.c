//
//  main.c
//  Using Unions 10.8
//
//  Created by Courtney Holsinger on 7/21/15.
//  Copyright (c) 2015 Courtney Holsinger. All rights reserved.
//

#include <stdio.h>

//set union defintion
union set {
    int i;
    char c;
    short s;
    long b;
}; //end union set

int main(void) {
    
    union set value; //define union variable
    
    //value definitions
    value.i = 100;
    value.c = 12;
    value.s = 2;
    value.b = 30000;
    
    //begin printing these values
    puts("This is a listing of values assigned in a row, then printed.");
    
    printf("The value of i in union set is: %d\n", value.i);
    printf("The value of c in union set is: %c\n", value.c);
    printf("The value of s in union set is: %d\n", value.s);
    printf("The value of b in union set is: %ld\n\n", value.b);
    
    //alternate sequencing
    puts("This is a listing of vlaues assigned, then immediately printed separately.");
    
    value.i = 100;
    printf("The value of i in union set is: %d\n", value.i);
    
    value.c = 12;
    printf("The value of c in union set is: %d\n", value.c);
    
    value.s = 2;
    printf("The value of s in union set is: %d\n", value.s);
    
    value.b = 30000;
    printf("The value of b in union set is: %ld\n", value.b);
    
    
    
} //end main