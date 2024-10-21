#include "QueueTypes.h"

void InitializeQueue (Queue *Q);
int Empty(Queue *Q);
int Full(Queue *Q);
void Insert(ItemType R, Queue *Q);
void Remove(Queue *Q, ItemType *F);
