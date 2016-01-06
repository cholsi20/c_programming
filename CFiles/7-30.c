//
//  main.c
//  Menu Driven System 7.30
//
//  Created by Courtney Holsinger on 7/15/15.
//  Copyright (c) 2015 Courtney Holsinger. All rights reserved.
//

#include <stdio.h>

//function prototypes
void circleCircumference( int radius );
void circleArea ( int radius );
void sphereVolume (int radius );

int main(void) {
    
    //initilize array of three pointers to functions that each take an
    //int argument and return void
    void (*functionArray[3])( unsigned long int ) = { circleCircumference, circleArea, sphereVolume };
    
    size_t choice; //variable that holds user's choice
    
    printf("%s\n%s\n%s\n", "Enter a number between 0 and 2.",
           "0 is for circumference.  1 for area.  2 for volume",
           "Enter 3 to end the program");
    scanf("%ul", &choice);
    
    //process user's choice
    while ( choice >= 0 && choice < 3 ){
        
        //invoke a function at location choice in the array and pass
        //choice as argument
        (*functionArray[ choice ])(choice);
        
        printf("%s\n%s\n%s\n", "Enter a number between 0 and 2.",
               "0 is for circumference.  1 for area.  2 for volume",
               "Enter 3 to end the program");
        scanf("%ul", &choice);
        
    }//end while
    
    puts( "Program execution completed." );
    
} //end main

//begin function to determine circle circumference
void circleCircumference( int radius ){
    
    double circumference;
    const double PI = 3.14159;
    
    //determines radius for following functions
    printf("%s", "Please enter the radius for your problem: ");
    scanf("%u", &radius);
    
    circumference = 2 * PI * radius;
    
    printf("%s\n%s%u\n%s%.2f\n", "You called the circle area function.",
           "The radius you entered is: ", radius,
           "The total circumference of this circle is: ", circumference);
    
} //end circle circumference function

//begin circle area function
void circleArea ( int radius ){
    
    double area;
    const double PI = 3.14159;
    
    //determines radius for following functions
    printf("%s", "Please enter the radius for your problem: ");
    scanf("%u", &radius);
    
    area = PI * (radius * radius);
    
    printf("%s\n%s%u\n%s%.2f\n", "You called the circle area function.",
           "The radius you entered is: ", radius,
           "The total area of the circle is: ", area);
    
} //end circle area function

// begin sphere volume function
void sphereVolume ( int radius ){
    
    double volume;
    const double PI = 3.14159;
    
    //determines radius for following functions
    printf("%s", "Please enter the radius for your problem: ");
    scanf("%u", &radius);
    
    volume = (4/3) * PI * (radius * radius * radius);
    
    printf("%s\n%s%u\n%s%.2f\n", "You called the sphere volume function.",
           "The radius you entered is: ", radius,
           "The total volume of this sphere is: ", volume);
    
} //end sphere volume function
