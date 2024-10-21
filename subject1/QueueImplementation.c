#include <stdio.h>
#include <stdlib.h>
#include "QueueInterface.h"

void InitializeQueue(Queue *Q)
{
	Q->Count = Q->Front = Q->Rear = 0;
}
int Empty(Queue *Q)
{
	return(Q->Count==0);
}
int Full(Queue *Q)
{
	return(Q->Count==MAXQUEUESIZE);
}

void Insert(ItemType R, Queue *Q)
{
	if (Full(Q))
		printf("attempt to insert item into a full queue");
	else
	{
		Q->Items[Q->Rear]=R;
		Q->Rear=(Q->Rear+1)%MAXQUEUESIZE;
		++(Q->Count);
	}
}

void Remove(Queue *Q, ItemType *F)
{
	if (Empty(Q))
		printf("attempt to remove item from empty queue");
	else
	{
		*F=Q->Items[Q->Front];
		Q->Front=(Q->Front+1)%MAXQUEUESIZE;
		--(Q->Count);
	}
}