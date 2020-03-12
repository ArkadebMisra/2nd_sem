#include<stdio.h>
#include<stdlib.h>

int top = -1;
#define MAX 100
struct Node
{
	int data;
	struct Node *left,*right;
};
typedef struct Node TREE;

TREE *getnode()
{
	TREE *newnode;
	newnode=(TREE *)malloc(sizeof(TREE));
	newnode->left=NULL;
	newnode->right=NULL;
	return(newnode);
}

void push(TREE *stack[], TREE *node){
	if(top == MAX-1){
		printf("\nStack Overflow");
	}
	else{
		top++;
		stack[top] = node;
	}
}

TREE *pop(TREE *stack[]){
	TREE *node;
	if(top == -1){
		printf("\nStack Underflow");
	}
	else{
		node = stack[top];
		top--;
		return node;
	}
	
}

TREE *create_BT(TREE *root)
{
	TREE *stk[50], *ptr;
	int key;
	char ch;
	do{
		if(root==NULL){
			root=getnode();
			printf("\nEnter the value of the node: ");
			fflush(stdin);
			scanf("%d",&root->data);
		}
		printf("\nCurrent Node value : %d",root->data);
		printf("\nDo you have left child: ");
		fflush(stdin);
		scanf("%c",&ch);
		if(ch=='y'){
			//printf("here")
			push(stk, root);
			root = root->left;
		}
		else if(ch=='n'){
			ptr = pop(stk);
			ptr->left = root;
			root = ptr;
		}
		printf("Current node value: %d",root->data);
		printf("\nDo you have right child: ");
		fflush(stdin);
		scanf("%c",&ch);
		if(ch=='y'){
			push(stk, root);
			root = root->right;
		}
		else if(ch=='n'){
			ptr = pop(stk);
			ptr->right = root;
			root = ptr;
		}
			
	}while(top>=0);
	return root;
}
void inorder(TREE *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d , ",root->data);
		inorder(root->right);
	}
}
int main()
{
	TREE *root=NULL;
	root=create_BT(root);
	inorder(root);
	return 0;
}
