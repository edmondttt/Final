#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "cosewic.h"

//MAIN FUNCTIONS
void mainLogic(const struct Filedata data[], int records) {
    int selection;
    do
    {
        ("=======================================================\n");
        printf("         Canada Species at Risk Analysis\n");
        printf("            (Data Years: 2010 - 2019)\n");
        printf("=======================================================\n");
        printf("1. View by year (sorted ASCENDING by year)\n");
        printf("2. View by province (sorted DESCENDING by totals)\n");
        printf("3. View by taxon (sorted ASCENDING by totals)\n");
        printf("4. View by province and taxon\n");
        printf("-------------------------------------------------------\n");
        printf("0. Exit\n");
        printf("-------------------------------------------------------\n");
        printf("Selection: \n");
        switch (selection)
        {
        case 0:
            printf("Application Terminated!\n");
            break;
        case 1:
            ViewbyYear();
            break;
        case 2:
            ViewbyProvince();
            break;
        case 3:
            ViewbyTaxon();
            break;
        case 4:
            Viewbypt();
            break;
        }
    } while (selection); 


}

void loadData(const char* datafile, struct Filedata data[], int max) {
}

//Display FUNCTIONS
void displayHeader(int type) {
}


//Appilcation Funtions
ViewbyYear();

ViewbyProvince();

ViewbyTaxon();

Viewbypt();

//UTILITY FUNCTIONS
int getyear(const struct Filedata data[]) {
}