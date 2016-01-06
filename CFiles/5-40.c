//
//  main.c
//  Test Recursive main 5.40
//
//  Created by Courtney Holsinger on 7/9/15.
//  Copyright (c) 2015 Courtney Holsinger. All rights reserved.
//

#include <stdio.h>

static char **p;

int main(int argc, char **argv)
{
    int n, rv;
    if (argc < 2) {
        printf("Usage: a.out <value>\n");
        exit(-1);
    }
    n = atoi(argv[1]);
    if (!n) {
        rv = 0;
    } else {
        if (n == 1) {
            rv = 1;
        } else {
            n = n - 1;
            **p = n;
            main(2, p);
        }
    }
    printf("%d\n", rv);
    return 0;
}



