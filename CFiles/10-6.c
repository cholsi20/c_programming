//
//  main.c
//  Accessing Structure Memebers 10.6
//
//  Created by Courtney Holsinger on 7/21/15.
//  Copyright (c) 2015 Courtney Holsinger. All rights reserved.
//

#include <stdio.h>

//structure definition
struct customer{
    char lastName[15];
    char firstName[15];
    unsigned int customerNumber;
    
    struct {
        char phoneNumber[11];
        char address[50];
        char city[15];
        char state[3];
        char zipCode[6];
    } personal;
} customerRecord, *customerPtr;



int main(void) {
    
    customerPtr = &customerRecord;
    
    
    printf("%s", "The answer to a is: printf\(\"%s\", customerRecord.lastName)\n"); //answer to a
    printf("%s","The answer to b is: printf\(\"%s\", customerPtr->lastName)\n"); //answer to b
    printf("%s","The answer to c is: printf\(\"%s\", customerRecord.firstName)\n"); //answer to c
    printf("%s","The answer to d is: printf\(\"%s\", customerPtr->firstName)\n"); //answer to d
    printf("%s","The answer to e is: printf\(\"%s\", customerRecord.customerNumber)\n"); //answer to e
    printf("%s","The answer to f is: printf\(\"%s\", customerPtr->customerNumber)\n"); //andswer to f
    printf("%s","The answer to g is: printf\(\"%s\", customerRecord.personal.phoneNumber)\n");
    printf("%s","The answer to h is: printf\(\"%s\", customerPtr->personal.phoneNumber)\n");
    printf("%s","The answer to i is: printf\(\"%s\", customerRecord.personal.address)\n");
    printf("%s","The answer to j is: printf\(\"%s\", customerPtr->personal.address)\n");
    printf("%s","The answer to k is: printf\(\"%s\", customerRecord.personal.city)\n");
    printf("%s","The answer to l is: printf\(\"%s\", customerPtr->personal.city)\n");
    printf("%s","The answer to m is: printf\(\"%s\", customerRecord.personal.state)\n");
    printf("%s","The answer to n is: printf\(\"%s\", customerPtr->personal.state)\n");
    printf("%s","The answer to o is: printf\(\"%s\", customerRecord.personal.zipCode)\n");
    printf("%s","The answer to p is: printf\(\"%s\", customerPtr->personal.zipCode)\n");
    
    
} //end main
