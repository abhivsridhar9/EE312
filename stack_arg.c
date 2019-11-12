#include <stdio.h>
#include <stdbool.h>

#define MAX_ELEMENTS 100

typedef char StackEntry;

typedef struct Stack312 {
    int top;
    StackEntry elements[MAX_ELEMENTS];
} Stack312;

void makeStack(Stack312 *s)
{
	s->top=-1;
}

bool isFull(Stack312 s)
{
	if(s.top==MAX_ELEMENTS-1)
		return true;
	return false;
}
bool isEmpty(Stack312 s)
{
	return (s.top==-1);
}

void push(StackEntry e,Stack312 *s)
{
	
	s->top=(s->top)+1;
	s->elements[s->top]=e;	

}

StackEntry pop(Stack312 *s)
{	
	StackEntry item=s->elements[s->top];
	s->top=(s->top)-1;
	return item;
}
