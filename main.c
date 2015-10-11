#include "Record.h"
#include <stdio.h>
#include <stdlib.h>


int main()
{
	int dataSize;
	Record TrainH;	//head of the training data set
	Record TestH;	//head of the test data set
	Record *r;
	FILE *f;
	char s[100];
	f= fopen("abalone.data", "rt");
	
	dataSize=0;
	
	r= &TrainH;
	r->next=0;
	while (fgets(s,100,f))
	{
		r->next= malloc(sizeof (Record));
		r= r->next;
		r->next=0;
		ReadRecord(s,r);
		dataSize++;
	}
	
	CreateTestSet(&TrainH, &TestH, dataSize/K);
	


}
