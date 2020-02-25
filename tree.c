#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *left, *right;
};

typedef struct Node TREE;

TREE *get_node(){
	TREE new_node;
	
	new_node = (TREE *)malloc(sizeof(TREE));
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
	
}

TREE create_bt(TREE *root){
	char ch;
	if(root == NULL){
		root = get_node();
		printf("Enter the value of root\n");
		scanf("%d",&root->data);
		
	}
	printf("Current root Value %d\n",root->data);
	printf("Does the root have left child\n");
	scanf("%c",&ch);
	if(ch=='y'){
		root->left = create_bt(root->left);
	}
	printf("Current root Value %d\n",root->data);
	printf("Does the root have left child\n");
	scanf("%c",&ch);
	if(ch=='y'){
		root->right = create_bt(root->right);
	}	
	return (root);
}

void inorder(TREE *root){
	if (root!=NULL){
		inorder(root->left);
		printf("%d\n",root->data);
		inorder(root->right);
	}
}
int main(){
	TREE *root = NULL;
	root = create_bt(root);
	inorder(root);
	return 0;
}
