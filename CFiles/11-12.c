//
//  main.c
//  Hardware Inventory 11.12
//
//  Created by Courtney Holsinger on 7/29/15.
//  Copyright (c) 2015 Courtney Holsinger. All rights reserved.
//

#include <stdio.h>

//function prototypes
unsigned int enterChoice( void );
void textFile( FILE *readPtr);
void updateRecord( FILE *fPtr);
void newRecord( FILE *fPtr );
void deleteRecord( FILE *fPtr);


//struct
struct tools {
    unsigned int recordNumber;
    char name[20];
    unsigned int quantity;
    double cost;
}; //end tools

int main(void) {
    
    FILE *toolsPtr;
    unsigned int choice;
    
    if ((toolsPtr = fopen("inventory.dat", "wb+")) == NULL ){
        puts("File could not be opened");
    } //end if
    
    else {
        
        //enable user to specify action
        puts("Choose 1: text file, 2: update record, 3: new record, 4: delete record");
        while ((choice = enterChoice()) != 5) {
            switch (choice) {
            
        case 1:
            textFile( toolsPtr );
            break;
            
        case 2:
            updateRecord( toolsPtr );
            break;
            
        case 3:
            newRecord( toolsPtr );
            break;
            
        case 4:
            deleteRecord( toolsPtr );
            break;
        
        default:
            puts("Incorrect choice.");
            break;
            }//end switch
            
        } //end while
        
        fclose( toolsPtr );
        
    } //end else
    
    
} //end main

//****************
//BEGIN FUNCTIONS
//****************

//create formatted text file for printing
unsigned int enterChoice( void ){
    
    unsigned int menuChoice;
    
    //display options
    printf("%s", "\nEnter Your Choice\n"
           "1: text file\n"
           "2: update record\n"
           "3: new record\n"
           "4: delete record\n"
           "5: End prgram?\n");
    scanf("%u", &menuChoice);
    
    return menuChoice;
    
} //end enter choice function

//begin text file function
void textFile( FILE *readPtr){
    
    FILE *writePtr; //.txt file pointer
    int result; //test for fread if any bytes
    
    //create hardware data with default info
    struct tools toolsData = { 0, "", 0, 0 };
    
    //opens the file or exits if there is no info
    if ((writePtr = fopen("inventory.txt", "w")) == NULL){
        puts("File cound not be opened.");
    } //end if
    
    else {
        
        rewind( readPtr ); //sets pointer to beginning of file
        fprintf(writePtr, "%-6s%-20s%-10s%-10.2s\n", "Record", "Tool Name", "Quantity", "Cost");
        
        //copy all records from random access file to text file
        while (!feof(readPtr)){
            
            result = fread(&toolsData, sizeof(struct tools), 1, readPtr);
            
            //write single record to text file
            if (result != 0 && toolsData.recordNumber != 0){
                
                fprintf(writePtr, "%-6u%-20s%-10u%10.2f\n", toolsData.recordNumber, toolsData.name, toolsData.quantity, toolsData.cost);
                
            }//end if
            
        } //end while
        
    } //end else
    
} //end text file function

//update balance
void updateRecord( FILE *fPtr){
    
    unsigned int account;
    unsigned int quantity;
    
    //create hardware data with default info
    struct tools toolsData = { 0, "", 0, 0 };
    
    //obtain number of account to update
    printf("%s", "Enter account to update (1 - 100) :");
    scanf("%u", &account);
    
    
    fseek(fPtr, (account - 1) * sizeof(struct tools), SEEK_SET);
    
    //read record file
    fread(&toolsData, sizeof(struct tools), 1, fPtr);
    
    //display error if account does not exisit
    if (toolsData.recordNumber == 0){
        printf("Account %u does not exist\n", account);
    }// end if
    
    else {
        
        printf("%-6u%-20s%-10u%10.2f\n", toolsData.recordNumber, toolsData.name, toolsData.quantity, toolsData.cost);
        
        
        //request transaction amount from user
        printf("%s", "Enter change to quantity.");
        scanf("%u", &quantity);
        toolsData.quantity += quantity;
        
        printf("%-6u%-20s%-10u%10.2f\n", toolsData.recordNumber, toolsData.name, toolsData.quantity, toolsData.cost);
        
        //move file pointer to correct record in file
        fseek(fPtr, (account - 1) * sizeof(struct tools), SEEK_SET);
        
        
        //write updated record<#FILE *restrict#>
        fwrite(&account, sizeof(struct tools), 1, fPtr);
    } //end else
    
    
} //end balance function

//create a new record
void newRecord( FILE *fPtr ){
    
    //create hardware data with default info
    struct tools toolsData = { 0, "", 0, 0 };
    
    unsigned int accountNum; //account number
     //obtain account number to change
    printf("%s", "Enter an account number between 1 and 100: ");
    scanf("%u", &accountNum);
    
    //move file pointer to correct record in file
    fseek(fPtr, (accountNum - 1) * sizeof(struct tools), SEEK_SET);
    
    //read record file
    fread(&toolsData, sizeof(struct tools), 1, fPtr);
    
    if (toolsData.recordNumber != 0){
        printf("Account %u already contains information\n", accountNum);
    }// end if
    
    else {
        
        printf("%s", "Enter tool name, quantity, and price: ");
        scanf("%s%10u%lf", &toolsData.name, &toolsData.quantity, &toolsData.cost);
        
        toolsData.recordNumber = accountNum;
        
        //move file pointer to correct record in file
        fseek(fPtr, (accountNum - 1) * sizeof(struct tools), SEEK_SET);
        
        
        //write updated record<#FILE *restrict#>
        fwrite(&accountNum, sizeof(struct tools), 1, fPtr);
    } //end else
    
} // end new record function

//begin delete record function
void deleteRecord( FILE *fPtr){
    
    //create hardware data with default info
    struct tools toolsData;
    struct tools blankTools = { 0, "", 0, 0 };
    
    unsigned int accountNum; //account number
    
    //obtain number of account to delete
    printf("Enter the number of the account you would like to delete (1 - 100): ");
    scanf("%u", &accountNum);
    
    
    //move file pointer to correct record in file
    fseek(fPtr, (accountNum - 1) * sizeof(struct tools), SEEK_SET);
    
    //read record file
    fread(&toolsData, sizeof(struct tools), 1, fPtr);
    
    if (toolsData.recordNumber == 0){
        printf("Account %u does not exist\n", accountNum);
    }// end if
    
    else {
        //move file pointer to correct record in file
        fseek(fPtr, (accountNum - 1) * sizeof(struct tools), SEEK_SET);
        fwrite(&blankTools, sizeof(struct tools), 1, fPtr);
    } //end else
    
    
    
} //end delete record function
