#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#include "funcs.h"

void print_menu(void) {  
    printf("       ENGINEERING TOOLKIT    \n");
    printf("\n===========================\n");
    printf("1) Unit Converter\n");
    printf("2) Circuit Helper\n");
    printf("3) Signal Analyzer\n");
    printf("4) About\n");
    printf("9) Exit\n");
    printf("--------------\n");
    printf("Select option:");
}

int main(void) {
    int option = 0;

    while (option != 9) {
        print_menu();
        scanf("%d", &option);

        switch (option) {
            case 1: menu_item_1(); break;
            case 2: menu_item_2(); break;
            case 3: menu_item_3(); break;
            case 4: menu_item_4(); break;
            case 9: printf("Exiting program\n"); break;
            default:
                printf("Invalid input,please try again.\n");
                break;
        }
    }

    return 0;
}
