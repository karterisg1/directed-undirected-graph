#define MAXSTACKSIZE 100
typedef int ItemType;
typedef struct
{
	int Count;
	ItemType Items[MAXSTACKSIZE];
} Stack;