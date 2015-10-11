#include "Record.h"
#include <stdio.h>
#include <stdlib.h>


void WriteRecord(Record *r)
{
	printf("%c,%f,%f,%f,%f,%f,%f,%f,%d\n", r->sex, r->contAttrs[0], r->contAttrs[1], r->contAttrs[2], r->contAttrs[3], r->contAttrs[4], r->contAttrs[5], r->contAttrs[6], r->rings);
}

int ReadRecord(char s[], Record *r)
{
	char *tempSar;
	char *tempTah;
	char c;
	int i;

	if (s[0]!='M' && s[0]!='F' && s[0]!='I')		
	{
		printf("We don't mean to judge, but this gender identity is not acceptable.\n");
		return -1;
	}
	r->sex= s[0];
	
	tempSar=s+2;
	for (i=0; i<7; i++)
	{
		tempTah= tempSar;
		while (*tempTah!=',')
			tempTah++;
		
		*tempTah=0;
		
		sscanf(tempSar, "%f", &(r->contAttrs[i]));
		
		tempSar=tempTah+1;
	}
	
	r->rings= atoi(tempSar);
	return 0;	//success
}

void CreateTestSet(Record *TrainH, Record *TestH, int testCount)
{
	time_t t;
	Record *trainI= TrainH->next;
	Record *trainPrev= TrainH;
	int i;
	int stride;
	TestH->next=0;
  srand((unsigned) time(&t));

	stride= 2*K;
	for (; testCount; testCount--)
	{
		for (i= rand()%stride; i; i--)
		{
			trainPrev= trainI;
			trainI= trainI->next;
			
			if (!trainI)
			{
				trainI= TrainH->next;
				trainPrev= TrainH;
			}
		}
		
		trainPrev->next= trainI->next;
		
		trainI->next= TestH->next;
		TestH->next= trainI;
		
		trainI= trainPrev;
		
		
		
	}
}

void PrintSet(Record *head)
{
	for (head= head->next; head; head=head->next)
		WriteRecord(head);
}

