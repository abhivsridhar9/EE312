#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Pixel {
   int row;
   int col;
   char color;
} Pixel;

typedef Pixel StackEntry;

typedef struct StackNode {
   StackEntry pixel;
   struct StackNode *next;
} StackNode;

typedef struct Stack312 {
   struct StackNode *top;
} Stack312;

void makeStack(Stack312 *s)
{
	s->top=NULL;
}
bool isFull(Stack312 s)
{
	return false;
}
bool isEmpty(Stack312 s)
{
	return (s.top==NULL);
}
void push(StackEntry e,Stack312 *s)
{
	StackNode *temp=(StackNode *)malloc(sizeof(StackNode));
	temp->pixel=e;
	temp->next=s->top;	
	s->top=temp;
}
StackEntry pop(Stack312 *s)
{
	StackNode *temp=s->top;
	StackEntry item=temp->pixel;
	s->top=temp->next;
	free(temp);
	return item;
}

