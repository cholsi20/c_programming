//
//  main.c
//  Merging Ordered Lists 12.7
//
//  Created by Courtney Holsinger on 7/30/15.
//  Copyright (c) 2015 Courtney Holsinger. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 26

//defining a stucture of linked lists
struct listNode {
    unsigned int data; //each list node contains an unsigned int
    struct listNode *nextPtr; //pointer to next node
}; //end structure listNode

typedef  struct listNode ListOfOrderedInts; //synonym for listNode
typedef ListOfOrderedInts *ListOfOrderedInts_Ptr; //synonym for ListNode*

//function prototypes for array
unsigned int randomNumberGeneration(unsigned int min, unsigned int max); //generates random numbers
//between user defined
//range.
void bubbleSort( unsigned int a[SIZE]); //sorts an array of integers in incrementing order
void printArray( unsigned int array[]); //well, pretty self explanitory :)

//function prototypes for linked list
void linkedListPopulation( ListOfOrderedInts_Ptr *sPtr, unsigned int x);
int isEmpty(ListOfOrderedInts_Ptr sPtr);
void printList(ListOfOrderedInts_Ptr sPtr);
ListOfOrderedInts_Ptr merge(ListOfOrderedInts_Ptr currentPtr1, ListOfOrderedInts_Ptr currentPtr2);

//List sorting function prototypes
struct listNode *getTail(struct listNode *cur);
void quickSort(struct listNode **head_ref);
struct listNode *partition(struct listNode *head, struct listNode **head1_ref,struct listNode **head2_ref);




int main(void) {
    
    srand(time(NULL)); //random seed generator based on time
    int count;
    unsigned int number = 0; //gets a random number and adds it to the array
    unsigned int array[SIZE] = {0}; //initilized array
    unsigned int array2[SIZE] = {0};
    
    //for linked list
    ListOfOrderedInts_Ptr startPtr = NULL;
    ListOfOrderedInts_Ptr startPtr2 = NULL;
    
    //begin array population with random number data, and sum addition of each number
    for (count = 1; count < SIZE; ++count){
        number = randomNumberGeneration(0, 100);
        array[count] = number;
    } //end for
    
    //begin array2 population with random number data, and sum addition of each number
    for (count = 1; count < SIZE; ++count){
        number = randomNumberGeneration(0, 100);
        array2[count] = number;
    } //end for
    
    //populate the linked list
    for (count = 0; count < SIZE; count++) {
        linkedListPopulation(&startPtr, array[count]);
    } // end for
    
    //populate the linked list
    for (count = 0; count < SIZE; count++) {
        linkedListPopulation(&startPtr2, array2[count]);
    } // end for
    
    
    //sort the array
    bubbleSort(array);
    
    //sort array2
    bubbleSort(array2);
    
    puts("Array 1 is: ");
    //print the array
    printArray(array);
    
    puts("Array 2 is: ");
    //print array2
    printArray(array2);
    
    puts("");
    
    puts("List 1: ");
    //print the List
    printList(startPtr);
    
    puts("List 2: ");
    //print list2
    printList(startPtr2);
    
    puts("Sorted list after the merge: ");
    //merge lists
    merge(startPtr, startPtr2);
    //sort the list
    quickSort(&startPtr);
    //print the new list
    printList(startPtr);
    
   
} // end main

//****************
//ARRAY FUNCTIONS
//****************

//function to generate random numbers in a limit
unsigned int randomNumberGeneration(unsigned int min, unsigned int max)
{
    int randomNumber;
    const unsigned int range = 1 + max - min;
    const unsigned int bins = RAND_MAX / range;
    const unsigned int limit = bins * range;
    
    do
    {
        randomNumber = rand();
    } while (randomNumber >= limit);
    
    return min + (randomNumber / bins);
}

//function to generate random number list

//function to bubble sort array
void bubbleSort( unsigned int a[]){
    unsigned int pass; //pass counter
    size_t comparisonCounter;
    unsigned int hold; //temp location to swap elements
    
    //loop to control number of passes
    for (pass = 1; pass < SIZE; ++pass){
        
        //loop to control number of comparisons per pass
        for (comparisonCounter = 0; comparisonCounter < SIZE - 1; ++comparisonCounter) {
            
            //swap elements if out of orders
            if (a[ comparisonCounter ] > a[ comparisonCounter + 1 ]){
                
                hold = a[comparisonCounter];
                a[ comparisonCounter ] = a[ comparisonCounter + 1 ];
                a[ comparisonCounter + 1 ] = hold;
                
            } //end if
            
        } //end inner for comparison counter
        
    } //end for
} //end bubble sort array

//function to print array
void printArray( unsigned int array[]){
    
    size_t counter;
    
    //output array contents
    for (counter = 0; counter < (SIZE) - 1; ++counter){
        //creates rows of 5
        if (counter % 5 == 0){
            
            puts("");
            
        } //end if
        
        printf("%2u ", array[counter]);
        
    } //end for
    
    puts("");
    
} //end function to print array


//*********************
//BEGIN LIST FUNCTIONS
//*********************

//begin linkedListPopulation function
void linkedListPopulation( ListOfOrderedInts_Ptr *sPtr, unsigned int x){
    
    ListOfOrderedInts_Ptr newPtr; //pointer to new node
    ListOfOrderedInts_Ptr previousPtr; //place value in node
    ListOfOrderedInts_Ptr currentPtr; //pointer to current node in list
    
    
    
    newPtr = malloc(sizeof(ListOfOrderedInts_Ptr));
    
    if (newPtr != NULL){ //is space available?
        
        newPtr->data = x; //place value in node
        newPtr->nextPtr = NULL; //node does not link to another node
        previousPtr = NULL;
        currentPtr = *sPtr;
        
        //loop to find the correct location in list
        while ( currentPtr != NULL && x > currentPtr->data) {
            
            previousPtr = currentPtr; //walk to...
            currentPtr = currentPtr->nextPtr; //...next node
            
        } //end while
        
        //insert a new node at the beginning of the list
        if (previousPtr == NULL){
            
            newPtr->nextPtr = *sPtr;
            *sPtr = newPtr;
            
        } //end if
        
        else { //insert a new node between previousPtr and currentPtr
            
            previousPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
            
        } //end else
        
    } //end if for newPtr
    
    else {
        
        printf("%c not inserted. No memory available.\n", x);
        
    } //end else statement
    
    
} //end linkedListPopulation function

//function to determine if a List is empty
int isEmpty(ListOfOrderedInts_Ptr sPtr){
    
    return sPtr == NULL;
    
} //end function isEmpty

//function to print the Linked List
void printList(ListOfOrderedInts_Ptr currentPtr){
    
    //if list is empty
    if ( isEmpty( currentPtr )){
        puts("List is empty\n");
    } //end if
    
    else {
        
        puts("The List is: ");
        
        //while not at the end of the list
        while (currentPtr != NULL){
            
            printf("%u --> ", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
            
        }// end while
        
        puts( "NULL\n");
        
    } //end else
    
} //end printList function

ListOfOrderedInts_Ptr merge(ListOfOrderedInts_Ptr currentPtr1, ListOfOrderedInts_Ptr currentPtr2){
    
    ListOfOrderedInts_Ptr current = currentPtr1;
    
    /* go to the end of the first */
    while (current->nextPtr != NULL) {
        current = current->nextPtr;
    }
    
    current->nextPtr = currentPtr2;
    return (currentPtr1);
}

//*****************************
//BEGING LIST SORTING FUNCTIONS
//*****************************


// Returns the last node of the list
struct listNode *getTail(struct listNode *cur){
    
    while (cur != NULL && cur->nextPtr != NULL)
        cur = cur->nextPtr;
    return cur;
} //end get tail pointer function

//begin function to quicksort
void quickSort(struct listNode **head_ref){
    
    struct listNode *head1,*head2,*pivot,*tail;
    
    if(*head_ref == NULL || (*head_ref)->nextPtr == NULL) {
        return;
    } //end if
    
    pivot = partition(*head_ref, &head1, &head2);
    quickSort(&head1);
    quickSort(&head2);
    
    if(head1 != NULL){
        tail = getTail(head1);
        tail->nextPtr = pivot;
    } //end if
    pivot->nextPtr = head2;
    
    *head_ref = head1 == NULL ? pivot : head1;
} //end quick sort function

//begin partition function 
struct listNode *partition(struct listNode *head, struct listNode **head1_ref,struct listNode **head2_ref){
    
    struct listNode *temp1 = head;
    struct listNode *temp2 = head;
    struct listNode *pivot = head;
    struct listNode *t;
    
    while(temp2->nextPtr!= NULL){
        
        if(temp2->nextPtr->data < pivot->data){
            if(temp1 == temp2){
                temp1 = temp1->nextPtr;
                temp2 = temp2->nextPtr;
            } //end if temp1 == temp2
            else {
                t = temp1->nextPtr;
                temp1->nextPtr = temp2->nextPtr;
                temp2->nextPtr = temp2->nextPtr->nextPtr;
                temp1 = temp1->nextPtr;
                temp1->nextPtr = t;
            } //end inner else
        } //end outer if
        else {
            temp2 = temp2->nextPtr;
        } //end outer else
    } //end while
    
    *head2_ref = temp1->nextPtr;
    temp1->nextPtr = NULL;
    *head1_ref = head->nextPtr;
    
    return pivot;
} //end function