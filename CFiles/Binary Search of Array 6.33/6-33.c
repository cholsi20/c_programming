//
//  main.c
//  Binary Search of Array 6.33
//
//  Created by Courtney Holsinger on 7/7/15.
//  Copyright (c) 2015 Courtney Holsinger. All rights reserved.
//

#include <stdio.h>
#define SIZE 15

//function prototypes
size_t binarySearch(const int b[], int searchKey, size_t low, size_t high); //search parameters
void printHeader( void );
void printRow(const int b[], size_t low, size_t mid, size_t high);

//function main begins program execution
int main( void ) {
    int a[ SIZE ]; //creates array
    size_t i; //counter for initializing array elements in a[]
    int key; // desired value to locate in a[]
    size_t result; //variable to hold location of key or -1(no match found value)
    
    //create array data
    for (i = 0; i < SIZE; ++i){
        a[ i ] = 2 * i;
    } //end array data for loop
    
    printf("%s", "Enter a number between 0 and 28: ");
    scanf("%d", &key); //user generates integer value to search for in array
    
    printHeader();
    
    //search for key in array a[]
    result = binarySearch( a, key, 0, SIZE - 1);
    
    //display results
    if (result != -1){
        printf("\n%d found in array element %d\n", key, result);
    }//end if
    
    else {
        printf("\n%d not found\n", key);
    } //end else
    
} //end main

//function to perform binary search in array
size_t binarySearch(const int b[], int searchKey, size_t low, size_t high){
    int middle; //variable to hold middle integer during search
    
    //loop until low subscript is greater than high subscript
    while (low <= high) {
        
        //determine middle element of subarray being searched
        middle = (low + high) / 2;
        
        //displays subarray being used in loop iteration
        printRow(b, low, middle, high);
        
        //if searchKey matched middle element, return middle
        if (searchKey == b[ middle ]){
            return middle;
        } //end if
        
        //if searchKey is less than the middle element, set new high
        else if(searchKey < b[ middle ]){
            high = middle - 1; //searh low end of array
        } //end else if
        
        //if search key greater than middle element, set new low
        else {
            low = middle + 1; //search high end of array
        } //end else
        
    } //end while loop
    
    return -1; //searchKey not found
    
} //end binary search function

//a function to print a header for the output
void printHeader (void){
    
    unsigned int i; //counter
    
    puts("\nSubscripts:");
    
    //output for column head
    for (i = 0; i < SIZE; ++i){
        printf("%3u ", i);
    } //end for
    
    puts(""); //starts a new line of output
    
    //output lines of - characters
    for (i = 1; i <= 4 * SIZE; ++i){
        printf("%s", "-");
    } //end for
    
    puts( "" ); //start a new line of output
    
} //end function printHeader

//Print one row of output showing the current part of the array being processed
void printRow(const int b[], size_t low, size_t mid, size_t high){
    
    size_t i; // counter for iterating through array b[]
    
    //loop through entire array
    for (i = 0; i < SIZE; ++i){
        
        //display spaces if outside current subarray range
        if (i < low || i > high){
            printf("%s", "    ");
        } //end if
        else if (i == mid){  //display middle element
            printf("%3d*", b[i]); //mark middle value
        } //end else if
        else { //display other elements in subarray
            printf("%3d ", b[i]);
        } //end else
        
    } //end for loop
    
    puts(""); //starts a new line 
    
} //end function printRow
