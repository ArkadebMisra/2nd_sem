#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define MAX 100

int stack[MAX],top = -1;

void push(int stack[], int val){
	if(top == MAX-1){
		printf("\nStack Overflow");
	}
	else{
		top++;
		stack[top] = val;
	}
}

int pop(int stack[]){
	int val;
	if(top == -1){
		printf("\nStack Underflow");
		return -1;
	}
	else{
		val = stack[top];
		top--;
		return val;
	}
	
}

int peek(int stack[]){
	if(top==-1){
		printf("stack is Empty\n");
		return -1;
	}
	else{
		return (stack[top]);
	}
}


