//
//  main.c
//  Concatenating Lists 12.6
//
//  Created by Courtney Holsinger on 7/27/15.
//  Copyright (c) 2015 Courtney Holsinger. All rights reserved.
//
//
// referencing lbraglia work online for clarity on printing list technique

#include <stdio.h>
#include <stdlib.h>

struct Char {
    char c;
    struct Char *next;
};

typedef struct Char charNode;
typedef charNode *charNodePtr;


charNodePtr initialize(const char *string);
charNodePtr concatenate(charNodePtr a, charNodePtr b);
void printList(charNodePtr a);
void *myMalloc(unsigned int size);

int main(void)
{
    
    charNodePtr string1 = initialize("Hello ");
    charNodePtr string2 = initialize("World!");
    printList(string1);
    printList(string2);
    printList(concatenate(string1, string2));
    return 0;
}


charNodePtr concatenate(charNodePtr a, charNodePtr b)
{
    
    charNodePtr current = a;
    
    /* go to the end of the first */
    while (current->next != NULL) {
        current = current->next;
    }
    
    current->next = b;
    return (a);
}

charNodePtr initialize(const char *string)
{
    
    unsigned int i = 0;
    charNodePtr head = NULL;
    charNodePtr current = NULL;
    charNodePtr newNode = NULL;
    char buf;
    
    while ((buf = *(string + i)) != '\0') {
        
        newNode = myMalloc(sizeof(charNode));
        newNode->c = buf;
        newNode->next = NULL;
        
        if (i > 0) {		/*not 0 length list */
            current = current->next = newNode;
        } else {		/*0 length list */
            head = current = newNode;
        }
        
        i++;
    }
    return head;
}

void printList(charNodePtr a)
{
    
    charNodePtr current = a;
    while (current != NULL) {
        printf("%c _ ", current->c);
        current = current->next;
    }
    printf("NULL\n");
    
}

void *myMalloc(unsigned int size)
{
    
    void *ptr;
    
    ptr = malloc(size);
    if (ptr == NULL) {
        printf("Heap memory is finished!");
    }
    return ptr;
    /*doing so, the code above is cleaner and the program will fail
     in the case NULL is used for dereferencing */
}