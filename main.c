/* Engineering Toolkit - Release Version
   ELEC2645 Unit 2 Project
   Author: <Your Name>
*/

#include <stdio.h>
#include <stdlib.h>
#include "unitconv.h"
#include "rc.h"
#include "signal.h"
#include "fileio.h"

/* Menu function prototypes */
void show_main_menu(void);
int get_int(void);

int main(void) {
    int choice;

    while (1) {
        show_main_menu();
        choice = get_int();

        switch (choice) {
            case 1:
                unit_converter_menu();
                break;
            case 2:
                rc_helper_menu();
                break;
            case 3:
                signal_analyzer_menu();
                break;
            case 9:
                printf("\nExiting program.\n");
                return 0;
            default:
                printf("Invalid selection.\n");
        }

        printf("\nPress Enter to continue..");
        getchar();
        getchar();
    }

    return 0;
}

void show_main_menu(void) {
    printf("=========================================\n");
    printf("       ENGINEERING TOOLKIT v1.0\n");
    printf("=========================================\n");
    printf("1) Unit Converter\n");
    printf("2) RC Circuit Helper\n");
    printf("3) Signal Analyzer (RMS/Peaks)\n");
    printf("9) Exit\n");
    printf("-----------------------------------------\n");
    printf("Select an option: ");
}

int get_int(void) {
    int v;
    if (scanf("%d", &v) != 1) {
        while (getchar() != '\n');
        return -1;
    }
    return v;
}
