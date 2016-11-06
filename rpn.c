
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <math.h>

#include "rpn.h"
#include "nextword.h"
#include "stack.h"

double rpn_eval(char * fileName, double x) {
	double a,b,c;
//	x = stack_pop();//maaybe??
// c is result
// pop a and b each time
	FILE *fd;

	fd = fopen(fileName, "r");

	char*word;
	while ( (word=nextword(fd)) != NULL ) {
		if (strcmp(word , "+") ==0) {
			a = stack_pop();
			b = stack_pop();
			stack_push( b + a);
		} else 	if (strcmp( word,  "-") == 0) {
			a =stack_pop();
			b = stack_pop();
			stack_push(b-a);
	        } else 	if (strcmp(word, "*") == 0) {
			a = stack_pop();
			b = stack_pop();
			stack_push(a*b);
		} else 	if (strcmp( word, "/") == 0) {
			a = stack_pop();
			b = stack_pop();
			stack_push(b /a);
		} else if (strcmp( word, "sin" ) == 0) { //sin
			a = stack_pop();
			stack_push(sin(a ) );
		} else if ( strcmp(word, "cos") == 0) { //cos
			a = stack_pop();
			stack_push(cos(a ) );
		} else if ( strcmp(word, "pow") == 0  ) { //pow
			a = stack_pop();
			b = stack_pop();
			stack_push(pow(b, a));
			//a ^ b
		} else if ( strcmp(word, "exp") == 0 ) { //exp
			a = stack_pop();
			stack_push(exp(a));
		//e^a
		} else if( strcmp(word, "log") == 0) { //log
			a = stack_pop();
			stack_push(log(a));
       		} else if (strcmp(word,"x") == 0) {
			stack_push(x);
		} else {
		//change word into a float
		//push word
			float f = atof(word);
			stack_push(f);
		}
	}
	if(stack_top() != 1) {
		printf("Elements remain in the stack\n");
		exit(1);
	}

	double result = stack_pop();
	return result;
}

