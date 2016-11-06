
#include <stdio.h>
#include "stack.h"
#include <stdlib.h>

int top=0;
double stack[MAXSTACK];
int i = 0;

void stack_clear()
{
  top = 0;
}

double stack_pop()
{
	if (top == 0 ) {
		printf("Stack underflow\n");
		exit(1);
	}
	top--;
	i--;
	return stack[top];

}

void stack_push(double val)
{
	if (top == MAXSTACK ) {

	exit(1);

	}

	stack[top] = val;
	top ++;
	i++;

}

void stack_print()
{
 printf("Stack:\n");
if  ( top == 0) {
		printf("Stack is empty");
	}


	int j = 0;

		for (j = 0; j < i; j++) {
			printf("%d: %6f\n", j, stack[j]);
		}
/*
		if (stack_is_empty() == 0 ) {
			printf("Stack is empty");
		}
*/
}

int stack_top()
{
  return top;
}

int stack_max()
{
  return MAXSTACK;
}

int stack_is_empty()
{
  return top == 0;
}


