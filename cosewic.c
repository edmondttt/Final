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
        selection = inputInt(0, 4);
        switch (selection)
        {
        case 0:
            printf("Application Terminated!\n");
            break;
        case 1:
            ViewbyYear(data,records);
            break;
        case 2:
            //ViewbyProvince();
            break;
        case 3:
            //ViewbyTaxon();
            break;
        case 4:
            //Viewbypt();
            break;
        }
    } while (selection); 


}



//Display FUNCTIONS
void displayHeader(int type) {
    printf("\nYEAR EXTINCT EXTIRPATED ENDANGERED THREATENED CONCERN     TOTAL\n");
    printf("---- ------- ---------- ---------- ---------- ------- ---------\n");
}


//Appilcation Funtions
void ViewbyYear(const struct FileData data[],int max) {
    displayHeader(1);
    int total = 0;
    int year=2010;
    int ex=0, et=0, en=0, th=0, con=0, sum = 0,se=0,sx=0,sn=0,st=0,sc=0;
    for (; year < 2020; year++)
    {
        ex = countex(data, max, year);
        et = countext(data, max, year);
        en = counted(data, max, year);
        th = countth(data, max, year);
        con = countcon(data, max, year);
        total = ex + et + en + th + con;
        printf("%d    %d       %d       %d       %d    %d     %d\n",year,ex,et,en,th,con,total);
        sum = total + sum;
        se += ex, sx += et, sn += en, st += th, sc += con;
        ex = 0, et = 0, en = 0, th = 0, con = 0,total;
    }
    printf("     ------- ---------- ---------- ---------- ------- ---------\n");
    printf("       %d      %d      %d      %d   %d    %d\n", se, sx, sn, st, sc,sum);
}

//ViewbyProvince();

//ViewbyTaxon();

//Viewbypt();

//UTILITY FUNCTIONS
int getyear(const struct FileData data[]) {
    int y=0;
    return y;
}

int countex(const struct FileData data[], int max, int year) {
    int i = 0;
    int total = 0;
    for (; i < max; i++)
    {
        if (data[i].year == year && !strcmp(data[i].status, "EXTINCT")) {
            total+=data[i].count;
        }
    }
    return total;
}
int countext(const struct FileData data[], int max, int year) {
    int i = 0;
    int total = 0;
    for (; i < max; i++)
    {
        if (data[i].year == year && !strcmp(data[i].status, "EXTIRPATED")) {
            total += data[i].count;
        }
    }
    return total;
}
int counted(const struct FileData data[], int max, int year) {
    int i = 0;
    int total = 0;
    for (; i < max; i++)
    {
        if (data[i].year == year && !strcmp(data[i].status, "ENDANGERED")) {
            total += data[i].count;
        }
    }
    return total;
}
int countth(const struct FileData data[], int max, int year) {
    int i = 0;
    int total = 0;
    for (; i < max; i++)
    {

        if (data[i].year == year && !strcmp(data[i].status, "THREATENED")) {
            total += data[i].count;
        }
    }
    return total;
}
int countcon(const struct FileData data[], int max, int year) {
    int i = 0;
    int total = 0;
    for (; i < max; i++)
    {
        if (data[i].year == year && !strcmp(data[i].status, "SPECIAL CONCERN")) {
            total += data[i].count;
        }
    }
    return total;
}

int inputInt() {
    int i = 0, a = 0;
    char c;
    do
    {
        scanf(" %d%c", &i, &c);
        if (i % 1 == 0 && c != '\n') { //checks the if  value is a number as  //
            printf("Error! Input a whole number: ");
            clearInputBuffer();
        }// i did not use size of but just read until the \n is detected.//
        else {
            a = i;
        }
    } while (i == 0);
    return a;
}

int loadData(const char* datafile, struct FileData data[], int max) {
    int i = 0;
    struct FileData t;
    FILE* fp = fopen(datafile, "r");
    if (fp != NULL)
    {
        fscanf(fp, "%*[^\n]\n");
        while (i < max) {
           fscanf(fp, "%d,%[^,],%[^,],%d,%s\n", &data[i].year, data[i].taxon, data[i].status, &data[i].count, data[i].province);
            i++;
        }
        fclose(fp);
        fp = NULL;
    }
    return i;
}

//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}
