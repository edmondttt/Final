#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define CHAR_LENGHT 30
struct FileData
{
	int year;
	char taxon[CHAR_LENGHT];
	char status[CHAR_LENGHT];
	int count;
	char province[CHAR_LENGHT];
};

void mainLogic(const struct Filedata data[],int records);

int loadData(const char* datafile,struct FileData data[], int max);

int getyear(const struct Filedata data[]);


void displayHeader(int type);




//Appilcation Funtions
void ViewbyYear(const struct FileData data[],int max);

ViewbyProvince(const struct FileData data[],int max);

ViewbyTaxon(const struct FileData data[],int max);

//Viewbypt();

//Utility function
int getyear(const struct FileData data[]);

int inputInt();
int countex(const struct FileData data[], int max, int year, char provice[], char taxon[], int choice);
int counted(const struct FileData data[], int max, int year, char provice[], char taxon[], int choice);
int countext(const struct FileData data[], int max, int year, char provice[], char taxon[], int choice);
int countth(const struct FileData data[], int max, int year, char provice[], char taxon[], int choice);
int countcon(const struct FileData data[], int max, int year, char provice[], char taxon[], int choice);


//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer();

