#include "StackTypes.h"

void InitializeStack(Stack *);
int IsEmpty(Stack *);
int IsFull(Stack *);
void Push(ItemType, Stack *);
void Pop(Stack *, ItemType *);