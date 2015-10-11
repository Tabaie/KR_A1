#include "Record.h"


#define NUM_TARGET_CATEGORIES 29
#define MIN_TARGET_CATEGORY 1
#define MAX_TARGET_CATEGORY (NUM_TARGET_CATEGORIES + MIN_TARGET_CATEGORY -1 )
#define TARGET_CATEGORY_ARRAYINDEX(i) (i- MIN_TARGET_CATEGORY)

#define FLOAT_INFINITY 900000000000000.0

typedef struct TreeNode
{
	AttrIndex dividingAttribute;
	struct TreeNode *parent;
	float divisionPoint;
	Record *data;
} TreeNode;

#define TOTAL_3

//float Entropy(Record *data);

float ResultingEntropy(TreeNode *t);

float AttributeDivisionPoint(TreeNode *t);

AttrIndex ChooseDividingAttribute(TreeNode *t);

