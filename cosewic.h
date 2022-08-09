#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define CHAR_LENGHT 30
struct FileData
{
	int year;
	char taxon[CHAR_LENGHT];
	char status[CHAR_LENGHT];
	int count;
	char status[CHAR_LENGHT];
};

void mainLogic(const struct Filedata data[],int records);

void loadData(const char* datafile,struct Filedata data[], int max);

int getyear(const struct Filedata data[]);


void displayHeader(int type);




//Appilcation Funtions
ViewbyYear();

ViewbyProvince();

ViewbyTaxon();

Viewbypt();