//
//  main.c
//  Creating a Linked List, Then Reversing its Elements 12.9
//
//  Created by Courtney Holsinger on 7/28/15.
//  Copyright (c) 2015 Courtney Holsinger. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>


/* Link list node */
struct node
{
    char data;
    struct node* next;
};

/* Function to reverse the linked list */
static void reverse(struct node** head_ref)
{
    struct node* prev   = NULL;
    struct node* current = *head_ref;
    struct node* next;
    while (current != NULL)
    {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

/* Function to push a node */
void push(struct node** head_ref, const char new_data)
{
    /* allocate node */
    struct node* new_node =
    (struct node*) malloc(sizeof(struct node));
    
    /* put in the data  */
    new_node->data  = new_data;
    
    /* link the old list off the new node */
    new_node->next = (*head_ref);
    
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}

/* Function to print linked list */
void printList(struct node *head)
{
    struct node *temp = head;
    while(temp != NULL)
    {
        printf("%c --> ", temp->data);
        temp = temp->next;
    }
}

/* Drier program to test above function*/
int main()
{
    /* Start with the empty list */
    struct node* head = NULL;
    
    push(&head, 'a');
    push(&head, 'b');
    push(&head, 'c');
    push(&head, 'd');
    push(&head, 'e');
    push(&head, 'f');
    push(&head, 'g');
    push(&head, 'h');
    push(&head, 'i');
    push(&head, 'j');
    
    printList(head);
    reverse(&head);
    struct node* head2 = head; //copy of original list
    puts("");
    printf("Reversed Copy of Linked list 'Head'\n");
    printList(head2);
    getchar();
}

/*
//create character structure
struct Char {
    char c;
    struct Char *next;
};

typedef struct Char charNode;
typedef charNode *charNodePtr;

//begin function prototypes
charNodePtr initialize(const char *string); //initilizes linked list of characters
void printList(charNodePtr a); //prints the list
void *myMalloc(unsigned int size);
void reverseList(charNodePtr a);


//begin main
int main(void) {
    
    charNodePtr string1 = initialize("abcdefghij");
    charNodePtr string2 = string1;
    printList(string1);
    
    reverseList(&string2);
    
    
    printList(string2);
    
} // end main

//***************
//Begin Functions
//***************

//begin initilize function
charNodePtr initialize(const char *string)
{
    
    unsigned int counter = 0;
    charNodePtr head = NULL;
    charNodePtr current = NULL;
    charNodePtr newNode = NULL;
    char buf;
    
    while ((buf = *(string + counter)) != '\0') {
        
        newNode = myMalloc(sizeof(charNode));
        newNode->c = buf;
        newNode->next = NULL;
        
        if (counter > 0) {
            current = current->next = newNode;
        } else {
            head = current = newNode;
        }
        
        counter++;
    }
    return head;
}//end initilize function


//begin print list function
void printList(charNodePtr a){
    
    charNodePtr current = a;
    while (current != NULL) {
        printf("%c _ ", current->c);
        current = current->next;
    }
    printf("NULL\n");
    
} //end print list function


//begin my Malloc function
void *myMalloc(unsigned int size){
    
    void *ptr;
    
    ptr = malloc(size);
    if (ptr == NULL) {
        printf("Heap memory is finished!");
    }
    return ptr;
 
} //end my malloc function

//begin reverse list function
void reverseList(charNodePtr a){
    
    charNodePtr previousNode = NULL;
    charNodePtr currentNode = a;
    charNodePtr next;
    
    
    while (currentNode != NULL){
    
        next = currentNode->next;
        currentNode->next = previousNode;
        previousNode = currentNode;
        currentNode = next;
        
        
    } //end while
    
    
    a = previousNode;
    
    
} //end reverse list
*/


