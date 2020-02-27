#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

#define MAX 100
float st[MAX];
char stack[MAX];
int top = -1;
int top1 = -1;

void push_char_stack(char stack[],char val){
	if(top1 == MAX-1){
		printf("\nStack Overflow");
	}
	else{
		top1++;
		stack[top1] = val;
	}	
}

char pop_char_stack(char stack[]){
	char val=' ';
	if(top1 == -1){
		printf("\nStack Underflow");
	}
	else{
		val = stack[top1];
		top1--;
	}
	return val;
}

void push(float st[], float val){
	if(top == MAX-1){
		printf("\nStack Overflow");
	}
	else{
		top++;
		st[top] = val;
	}
}

float pop(float st[]){
	float val;
	if(top == -1){
		printf("\nStack Underflow");
		return -1;
	}
	else{
		val = st[top];
		top--;
		return val;
	}
	
}

int get_priority(char op){
	if(op=='/'||op=='*'||op=='%'){
		return 1;
	}
	else if(op=='+'||op=='-'){
		return 0;
	}
}

void infix_to_postfix(char source[], char target[]){
	int i=0, j=0;
	char temp;
	strcpy(target,"");
	while(source[i]!='\0'){
		if(source[i] == '('){
			push_char_stack(stack, source[i]);
			i++;
		}
		else if(source[i]==')'){
			while((top1!=-1)&&(stack[top1]!='(')){
				target[j] = pop_char_stack(stack);
				j++;
			}
			if(top1==-1){
				printf("\nIncorrect Expression");
				exit(1);
			}
			temp = pop_char_stack(stack);
			i++;
		}
		else if(isdigit(source[i])||isalpha(source[i])){
			target[j] = source[i];
			j++;
			i++;
		}
		else if(source[i]=='+'||source[i]=='-'||source[i]=='*'||source[i]=='/'||source[i]=='%'){
			while((top1!=-1)&&(stack[top1]!='(')&&(get_priority(stack[top1])>get_priority(source[i]))){
				target[j] = pop_char_stack(stack);
				j++;
			}
			push_char_stack(stack,source[i]);
			i++;
		}
		else{
			printf("\n Incorrect Element in expression ");
			exit(1);
		}
	}
	while((top1!=-1)&&(stack[top1]!='(')){
		target[j] = pop_char_stack(stack);
		j++;
	}
	target[j]= '\0';
}

float evaluate_postfix_exp(char exp[]){
	int i = 0;
	float op1,op2,value;
	while(exp[i]!='\0'){
		if(isdigit(exp[i])){
			push(st, (float)(exp[i]-'0'));
		}
		else{
			op2 = pop(st);
			op1 = pop(st);
			switch(exp[i]){
				case '+':
					value = op1+op2;
					break;
				case '-':
					value = op1 - op2;
					break;
				case '/':
					value = op1/op2;
					break;
				case '*':
					value = op1*op2;
					break;
				case '%':
					value = (int)op1 % (int)op2;
					break;
			}
			push(st,value);
		}
		i++;
	}
	return (pop(st));
}

int main(){
	float val;
	char postfix[100],infix[100];
	printf("\nEnter a infix Expression ");
	//clrscr();
	gets(infix);
	strcpy(postfix,"");
	infix_to_postfix(infix, postfix);
	printf("\nThe postfix expression is ");
	puts(postfix);
	val = evaluate_postfix_exp(postfix);
	printf("\nCalculated value is ");
	printf("%.2f", val);
	getch();
	return 0;
}
