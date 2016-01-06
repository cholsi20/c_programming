//
//  main.c
//  11.11
//
//  Created by Courtney Holsinger on 7/29/15.
//  Copyright (c) 2015 Courtney Holsinger. All rights reserved.
//

#include <stdio.h>

struct person {
    char lastName[ 15 ];
    char firstName[ 15 ];
    char age[ 4 ];
};

int main(void) {
    
    unsigned int counter;
    
    struct person personData = { "unassigned", "", "0" };
    
    FILE *personPtr;
    
    //*******************
    //CREATES 100 RECORDS
    //*******************
    //fopen the file; exists if the file canot be opened
    if ((personPtr = fopen("nameage.dat", "wb")) == NULL ){
        puts("File cannot be opened");
    } //ed if
    else { //output 100 blank records to the file
        for (counter = 1; counter <= 100; ++counter){
            fwrite(&personData, sizeof( struct person), 1, personPtr);
        } //end for
        
        fclose( personPtr ); //closes the file
        
    }// end else
    
    
    //************************************
    //INPUTS 10 RECORDS MANUALLY WITH INFO
    //************************************
    
    if ((personPtr = fopen("nameage.dat", "r+")) == NULL ){
        puts("File cannot be opened");
    } //ed if
    else { //output 100 blank records to the file
        for (counter = 1; counter <= 10; ++counter){
            printf("%s\n","Please enter lastname, firstname, and age: ");
            fscanf(stdin, "%15s%15s%4s", personData.lastName, personData.firstName, personData.age);
            fseek(personPtr, sizeof(struct person), SEEK_SET);
            fwrite(&personData, sizeof(struct person), 1, personPtr);
        } //end for
        
        fclose( personPtr ); //closes the file
        
    }// end else
    
    
    //***************
    //UPDATE A RECORD
    //***************
    
    if ((personPtr = fopen("nameage.dat", "r+")) == NULL ){
        puts("File cannot be opened");
    } //ed if
    else { //output 100 blank records to the file
            printf("%s\n","Please enter lastname, firstname, and age: ");
            fscanf(stdin, "%15s%15s%4s", personData.lastName, personData.firstName, personData.age);
            fseek(personPtr, sizeof(struct person), SEEK_SET);
            fwrite(&personData, sizeof(struct person), 1, personPtr);
        
        while ( !feof(personPtr)){
            int result = fread(&personData, sizeof( struct person), 1, personPtr);
            
            //display record
            if ( result != 0 ){
                printf("%s, %s, %s\n", personData.lastName, personData.firstName, personData.age);
            } //end if
        } //end while
        
        fclose( personPtr ); //closes the file
    } //end else
    
    
    //****************
    //DELETE A RECORD
    //****************
    
    if ((personPtr = fopen("nameage.dat", "r+")) == NULL ){
        puts("File cannot be opened");
    } //ed if
    else { //output 100 blank records to the file
            
            fseek(personPtr, sizeof(struct person), SEEK_SET);
            fread(&personData, sizeof(struct person), 1, personPtr);
            
            if (&personPtr == 0){
                printf("Record %d does not exist.", counter);
            }
            
            else {
                fseek(personPtr, (counter - 1) * sizeof(struct person), SEEK_SET);
                fwrite( &personData, sizeof(struct person), 1, personPtr);
            }
        
        fclose( personPtr ); //closes the file
    } //end else
    
} //end main

