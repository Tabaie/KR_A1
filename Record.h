#include <stdio.h>

#define K 100


typedef enum TSex
{
	M='M', F='F', I='I'
} TSex;


typedef enum AttrIndex
{
Sex=-1,
Length=0,
Diameter=1,
	Height=2,
	WholeWeight=3,
	ShuckedWeight=4,
	VisceraWeight=5,
	ShellWeight=6
} AttrIndex;
 	
typedef struct Record
{
	TSex sex;
	float contAttrs[7];
	int rings;

//Linked list stuff	
	struct Record *next;
	
} Record;


int ReadRecord(char [], Record *);

void WriteRecord(Record *);

void PrintSet(Record *head);

void CreateTestSet(Record *TrainH, Record *TestH, int testCount);

