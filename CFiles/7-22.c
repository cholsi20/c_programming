//
//  main.c
//  maze_traversal 7.22
//
//  Created by Courtney Holsinger on 7/14/15.
//  Copyright (c) 2015 Courtney Holsinger. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

//function prototypes
void mazeTraversal(char *maze[12][12]); //recursive function for "player" to route maze
void printMaze (char *maze[12][12]); //prints the maze, as well as calls the function in main to
                                     //work through maze
static int face = 6;

int main(void) {
    
    int counter;
    int start;
    int xpos;
    
    //build the maze from the book by initilizing to exact replica
    char maze[12][12] = {
        //0//1///2///3///4///5///6///7///8///9///10//11////
        "#","#","#","#","#","#","#","#","#","#","#","#",//0
        "#",".",".",".","#",".",".",".",".",".",".","#",//1
        ".",".","#",".","#",".","#","#","#","#",".","#",//2
        "#","#","#",".","#",".",".",".",".","#",".","#",//3
        "#",".",".",".",".","#","#","#",".","#",".",".",//4
        "#","#","#","#",".","#",".","#",".","#",".","#",//5
        "#",".",".","#",".","#",".","#",".","#",".","#",//6
        "#","#",".","#",".","#",".","#",".","#",".","#",//7
        "#",".",".",".",".",".",".",".",".","#",".","#",//8
        "#","#","#","#","#","#",".","#","#","#",".","#",//9
        "#",".",".",".",".",".",".","#",".",".",".","#",//10
        "#","#","#","#","#","#","#","#","#","#","#","#" //11
        };//end maze initilization
    
    for (counter = 0; counter <12; counter++)
        if (maze[counter][0] == "." ) {
            start = counter;
            maze[start][0] = "x";
            xpos = start;
            break;
        }
    
    printf("X is the starting point.\n");
    printf("Press Space Bar to watch the X move.\n\n\n");
    getchar();
    printMaze(maze);
    getchar();
    return 0;
    
    
    
} //end main

//maze printing function
void printMaze (char *maze[12][12]){
    int rowX = 0;
    int columnY = 0;
    
    system("cls");
    for (rowX = 0; rowX < 12; rowX++) {
        for (columnY = 0; columnY < 12; columnY++) {
            printf("%s", maze[rowX][columnY]);
        }
        printf("\n");
    }
    getchar();
    mazeTraversal(maze);
    
    
} //end maze printing function


void mazeTraversal(char *maze[12][12])
{
    int x = 0;
    int y = 0;
    
    for (x = 0; x < 12; x++) {
        for (y = 0; y < 12; y++) {
            if (maze[y][x] == "x")
                break;
        }
        if(maze[y][x] == "x")
            break;
    }
    
    for (y = 0; y < 12; y++) {
        for (x = 0; x < 12; x++) {
            if (maze[y][x] == "x")
                break;
        }
        if (maze[y][x] == "x")
            break;
    }
    
    maze[y][x] = ".";
    
    switch (face) {
        case 6:{
            if (maze[y][x-1] == ".") {
                maze[y][x-1] = "x";
                face = 5;
            } else if (maze[y + 1][x] == ".") {
                maze[y + 1][x] = "x";
                face = 6;
            } else if (maze[y][x+1] == ".") {
                maze[y][x+1] = "x";
                face = 8;
            } else if (maze[y - 1][x] == ".") {
                maze[y - 1][x] = "x";
                face = 4;
            }
            break;
        }
        case 8:{
            if (maze[y + 1][x] == ".") {
                maze[y + 1][x] = "x";
                face = 6;
            } else if (maze[y][x+1] == ".") {
                maze[y][x+1] = "x";
                face = 8;
            } else if (maze[y - 1][x] == ".") {
                maze[y - 1][x] = "x";
                face = 4;
            } else if (maze[y][x-1] == ".") {
                maze[y][x-1] = "x";
                face = 5;
            }
            break;
        }
        case 4:{
            if (maze[y][x+1] == ".") {
                maze[y][x+1] = "x";
                face = 8;
            } else if (maze[y - 1][x] == ".") {
                maze[y - 1][x] = "x";
                face = 4;
            } else if (maze[y][x-1] == ".") {
                maze[y][x-1] = "x";
                face = 5;
            } else if (maze[y + 1][x] == ".") {
                maze[y + 1][x] = "x";
                face = 6;
            }
            break;
        }
        case 5:{
            if (maze[y - 1][x] == ".") {
                maze[y - 1][x] = "x";
                face = 4;
            } else if (maze[y][x-1] == ".") {
                maze[y][x-1] = "x";
                face = 5;
            } else if (maze[y + 1][x] == ".") {
                maze[y + 1][x] = "x";
                face = 6;
            } else if (maze[y][x+1] == ".") {
                maze[y][x+1] = "x";
                face = 8;
            }
            break;
        }
    }
    
    mazePrint(maze);
}