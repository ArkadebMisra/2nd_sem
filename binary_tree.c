#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node *tree;

void create_tree(struct node *tree){
	tree = NULL;
}

struct node *insert_element(struct node *tree, int val){
	struct node *ptr, *node_ptr, *parent_ptr;
	ptr = (struct node *)malloc(sizeof(struct node));
	ptr->data = val;
	ptr->left = NULL;
	ptr->right = NULL;
	if(tree==NULL){
		tree = ptr;
		tree->left = NULL;
		tree->right = NULL;
	}
	else{
		parent_ptr = NULL;
		node_ptr = tree;
		while(node_ptr!=NULL){
			parent_ptr = node_ptr;
			if(val<node_ptr->data){
				node_ptr = node_ptr->left;
			}
			else{
				node_ptr = node_ptr->right;
			}
			
		}
		if(val<parent_ptr->data){
			parent_ptr->left = ptr;
		}
		else{
			parent_ptr->right = ptr;
		}
		
	}
	return tree;
}

void inorder(struct node *tree){
	if(tree!=NULL){
		inorder(tree->left);
		printf("%d\t",tree->data);
		inorder(tree->right);
	}
}

void preorder(struct node *tree){
	if(tree!=NULL){
		printf("%d\t",tree->data);
		inorder(tree->left);
		inorder(tree->right);
	}
}

void postorder(struct node *tree){
	if(tree!=NULL){
		inorder(tree->left);
		inorder(tree->right);
		printf("%d\t",tree->data);
	}
}

int main(){
	int option,nodes[100],num_nodes,i;
	struct node *ptr;
	create_tree(tree);
	do{
		printf("\n********MAIN MENU********");
		printf("\n 1. Enter data");
		printf("\n 2. Inorder Travarsal");
		printf("\n 3. Prerder Travarsal");
		printf("\n 4. Postorder Travarsal");
		printf("\n 5. Exit");
		printf("\nEnter your choice\n");
		scanf("%d",&option);
		getchar();
		switch(option){
			case 1:
				printf("Enter number of nodes\n");
				scanf("%d",&num_nodes);
				printf("Enter the nodes\n");
				for(i=0;i<num_nodes;i++){
					scanf("%d",&nodes[i]);
				}
				for(i=0;i<num_nodes;i++){
					tree = insert_element(tree, nodes[i]);
				}
				break;
			case 2:
				inorder(tree);
				printf("\n");
				break;
			case 3:
				preorder(tree);
				printf("\n");
				break;
			case 4:
				postorder(tree);
				printf("\n");
				break;
				
		}
	}while(option!=5);
	return 0;
}
