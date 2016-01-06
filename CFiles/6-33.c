//
//  main.c
//  Recursive Linear search of Array 6.33
//
//  Created by Courtney Holsinger on 7/7/15.
//  Copyright (c) 2015 Courtney Holsinger. All rights reserved.
//

#include <stdio.h>
#define SIZE 100

//function prototype
int binarySearch(const int array[], int searchKey, int low, int high);

// begin function main
int main(void) {
  
    int a[SIZE]; //create array a
    int x; // counter for initializing elements in array a[]
    int searchKey; //value to locate in array a[]
    int element; //variable to hold location of searchKey or -1
    
    //creates array data
    for (x = 0; x < SIZE; ++x){
        a[x] = 2 * x;
    } //end for
    
    puts("Enter integer search key: ");
    scanf("%d", &searchKey);
    
    //attempt to locate searchKey in array a[]
    element = binarySearch( a, searchKey, 0, SIZE - 1);
    
    //display results
    if (element != -1){
        printf("Found value in element %d", element);
    } //end if
    
    else {
        puts("Value not found");
    } //end else
    
} //end main

//compare key to every element of array until location is found
//or until the end of array is reached; return subscript of element
//if key is found of -1 if key is not found
int binarySearch( const int array[], int searchKey, int low, int high){
    
    int middle = (low + high) / 2;; //creates middle number to initiate binary search
    
    //begin recursion
    if (searchKey == array[ middle ]){
        return middle;
    }
    
    else if (searchKey < array[middle]){
        return binarySearch(array, searchKey, low, middle - 1); //search low end of array
    }
    
    else if (low>high){
        return -1;
    }
    
    else {  //searchKey > array[middle])
        return binarySearch(array, searchKey, middle + 1, high); //searches high end of array
    }
    
    
}//end linearSearch function