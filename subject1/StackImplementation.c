#include <stdio.h>
#include <stdlib.h>
#include "StackInterface.h"

void InitializeStack (Stack *S)
{
	S->Count = 0;
}

int IsEmpty(Stack *S)
{
	return (S->Count == 0);
}
int IsFull(Stack *S)
{
	return (S->Count == MAXSTACKSIZE);
}

void Pop(Stack *S, ItemType *X)
{ 
	if (Empty(S))
		printf("attempt to pop the empty stack");
	else 
	{
		--(S->Count);
		*X=S->Items[S->Count];
	}
}

void Push(ItemType X, Stack *S)
{
	if (Full(S))
		printf("attempt to push new item on a full stack");
	else
	{	
		S->Items[S->Count]= X;
		++(S->Count);
	}
}