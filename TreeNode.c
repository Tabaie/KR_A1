#include "TreeNode.h"
#include <math.h>

#define DIVISION_SIDE(data, node) ((data->contAttrs[node->dividingAttr] > node->divisionPoint)?1:0)

float ResultingEntropy(TreeNode *t)
{
	int i,j;
	int nums[3][NUM_TARGET_CATEGORIES];
	int total[3];
	Record *r;
	float categoryEntropy;
	float divisionWeight;
	float entropy;
	float divisionEntropy;	
	
	for (i=0; i<(t->dividingAttribute == Sex)?3:2 ; i++)
	{
		total[i]=0;
		for (j=0; j<= NUM_TARGET_CATEGORIES; j++)
			nums[i][j]=0;
	}
	
	//this only works for sex
	if (t->dividingAttribute == Sex)
	{
		for (r=t->data; r; r=r->next)
		{
			nums[r->sex][r->rings]++;
			total[r->sex]++;
		}
	
		entropy=.0;
		for (j=0; j<3; j++)
		{
			divisionEntropy=.0;
			divisionWeight= ((float)total[j])/(total[0]+total[1]+total[2]);
		
			for (i=0; i<NUM_TARGET_CATEGORIES; i++)
				if (nums[i]>0)
				{
					categoryEntropy= ((float) nums[j][i])/total[j];
					divisionEntropy+= categoryEntropy * log2(categoryEntropy);
				}
			
			entropy+= divisionWeight * divisionEntropy;
		}
	}
	else
	{
		for (r=t->data; r; r=r->next)
		{
			nums[DIVISION_SIDE(r, t)][r->rings]++;
			total[DIVISION_SIDE(r, t)]++;
		}
	
		entropy=.0;
		for (j=0; j<2; j++)
		{
			divisionEntropy=.0;
			divisionWeight= ((float)total[j])/(total[0]+total[1]);
		
			for (i=0; i<NUM_TARGET_CATEGORIES; i++)
				if (nums[i]>0)
				{
					categoryEntropy= ((float) nums[j][i])/total[j];
					divisionEntropy+= categoryEntropy * log2(categoryEntropy);
				}
			
			entropy+= divisionWeight * divisionEntropy;
		}

	}
	
	return -entropy;
}

float AttributeDivisionPoint(TreeNode *t)
{
	int n;
	float x;
	float y;
	float xy;
	float xsq;
	Record *r;
	
	n=0;
	xbar=ybar=xy=xsq=.0;
	
	for (r= t->data->next; r; r= r->next)
	{
		
		n++;
		
		x+= data->contAttrs[t->dividingAttribute];
		y+= data
	}
}

AttrIndex ChooseDividingAttribute(TreeNode *t)
{
	int i;
	int bestI;
	float bestE;
	int bestV=0; //the one who is versus all!!!
	float entropy;
	
	
	t->dividingAttribute= bestI= Sex;
	bestE= ResultingEntropy(t);
	
	for (i=Sex; i<= ShellWeight; i++)
	{
		t->dividingAttribute= i;
		t->divisionPoint= AttributeDivisionPoint(t);
		entropy= ResultingEntropy(t);
		if (entropy < bestE)
		{
			bestE=entropy;
			bestI= i;
		}
	}
	
	return i;
}

/*float Entropy(Record *data)
{
	int nums[NUM_TARGET_CATEGORIES];
	int total;
	int i;
	float entropy;
	float categoryEntropy;
	
	for (i=0; i<NUM_TARGET_CATEGORIES; i++)
		nums[i]=0;
		
	total=0;
	
	for (data=data->next; data; data=data->next)
	{
		nums[data->rings]++;
		total++;
	}
	
	entropy=.0;
	for (i=0; i<NUM_TARGET_CATEGORIES; i++)
	{
		if (nums[i]>0)
		{
			categoryEntropy= ((float) nums[i])/total;
			entropy+= categoryEntropy * log2(categoryEntropy);
		}
	}
	
	return -entropy;
}*/



