//
//  main.c
//  Outputting Type Sizes to a File 11.16
//
//  Created by Courtney Holsinger on 7/28/15.
//  Copyright (c) 2015 Courtney Holsinger. All rights reserved.
//

struct data {
    int x;
};

#include <stdio.h>

int main(void) {
    
    FILE *filePointer;
    
    filePointer = fopen("datasize.dat", "w");
    
    fprintf(filePointer, "%-20s%4s\n", "Data type", "Size"); //formatted header
    fprintf(filePointer, "%-20s%4lu\n", "char", sizeof(char));
    fprintf(filePointer, "%-20s%4lu\n", "unsigned char", sizeof(unsigned char));
    fprintf(filePointer, "%-20s%4lu\n", "short int", sizeof(short int));
    fprintf(filePointer, "%-20s%4lu\n", "unsigned short int", sizeof(unsigned short int));
    fprintf(filePointer, "%-20s%4lu\n", "int", sizeof(int));
    fprintf(filePointer, "%-20s%4lu\n", "unsigned int", sizeof(unsigned int));
    fprintf(filePointer, "%-20s%4lu\n", "long int", sizeof(long int));
    fprintf(filePointer, "%-20s%4lu\n", "unsigned long int", sizeof(unsigned long int));
    fprintf(filePointer, "%-20s%4lu\n", "float", sizeof(float));
    fprintf(filePointer, "%-20s%4lu\n", "double", sizeof(double));
    fprintf(filePointer, "%-20s%4lu\n", "long double", sizeof(long double));
    fclose(filePointer);
    return 0;
    
}
