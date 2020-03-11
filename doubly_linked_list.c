#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node{
	struct node *next;
	int data;
	struct node *prev;
};

struct node *start=NULL;

struct node *create_ll(struct node *start){
	struct node *new_node, *ptr;
	int num;
	printf("Enter -1 to end\n");
	printf("Enter the data\n");
	scanf("%d",&num);
	while(num!=-1){
		new_node = (struct node*)malloc(sizeof(struct node));
		new_node->data = num;
		if(start==NULL){
			new_node->prev = NULL;
			new_node->next = NULL;
			start = new_node;
		}
		else{
			ptr = start;
			while(ptr->next!=NULL){
				ptr = ptr->next;
			}
			ptr->next = new_node;
			new_node->prev = ptr;
			new_node->next = NULL;
		}
		printf("Enter the data \n");
		scanf("%d",&num);
	}
	return start;
	
}

struct node *display(struct node *start){
	struct node *ptr;
	ptr = start;
	while(ptr!=NULL){
		printf("\t%d",ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
	return start;
}
struct node *insert_begining(struct node *start){
	struct node *ptr,*new_node;
	int val;
	ptr = start;
	printf("Enter the value\n");
	scanf("%d",&val);
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node->data = val;
	new_node->prev = NULL;
	new_node->next = ptr;
	start = new_node;
	return start;	
}
struct node *insert_end(struct node *start){
	struct node *ptr, *new_node;
	int val;
	new_node = (struct node *)malloc(sizeof(struct node));
	printf("Enter the value\n");
	scanf("%d",&val);
	new_node->data = val;
	new_node->next = NULL;
	ptr = start;
	while(ptr->next!=NULL){
		ptr = ptr->next;
	}
	ptr->next = new_node;
	new_node->prev = ptr;
	return start;
}

struct node *insert_before(struct node *start){
	int val,p_val;
	struct node *new_node, *ptr, *pre_ptr;
	new_node = (struct node *)malloc(sizeof(struct node));
	printf("Enter the data\n");
	scanf("%d",&val);
	printf("Enter the value before which the value has to be inserted\n ");
	scanf("%d",&p_val);
	ptr = start;
	while(ptr->data!=p_val){
		pre_ptr = ptr;
		ptr = ptr->next;
	}
	new_node->data = val;
	new_node->next = ptr;
	ptr->prev = new_node;
	pre_ptr->next = new_node;
	new_node->prev = pre_ptr;
	return start;
	
}

struct node *insert_after(struct node *start){
	struct node *new_node, *ptr, *post_ptr;
	int val, p_val;
	printf("Enter the data\n");
	scanf("%d",&val);
	printf("Enter the value after which the value has to be inserted\n");
	scanf("%d",&p_val);
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node->data = val;
	ptr = start;
	while(ptr->data!=p_val){
		//printf("%d ",ptr->data);
		ptr = ptr->next;
	}
	post_ptr = ptr->next;
	ptr->next = new_node;
	new_node->prev = ptr;
	new_node->next = post_ptr;
	post_ptr->prev = new_node;
	return start;
}
struct node *delete_beg(struct node *start){
	struct node *ptr;
	ptr = start;
	start = start->next;
	start->prev = NULL;
	free(ptr);
	return start;
}

struct node *delete_end(struct node *start){
	struct node *ptr, *pre_ptr;
	ptr = start;
	while(ptr->next!=NULL){
		pre_ptr = ptr;
		ptr = ptr->next;
	}
	pre_ptr->next = NULL;
	free(ptr);
	return start;
}

struct node *delete_before(struct node *start){
	int val;
	struct node *ptr,*pre_ptr;
	printf("Enter the value before which the node has to be deleted\n");
	scanf("%d",&val);
	ptr = start;
	while(ptr->data!=val){
		pre_ptr = ptr;
		ptr = ptr->next;
	}
	pre_ptr->prev->next = ptr;
	ptr->prev = pre_ptr->prev;
	free(pre_ptr);
	return start;

}

struct node *delete_after(struct node *start){
	int val;
	struct node *ptr,*post_ptr;
	printf("Enter the value after which the node has to be deleted\n");
	scanf("%d",&val);
	ptr = start;
	while(ptr->data!=val){
		ptr = ptr->next;
	}
	post_ptr = ptr->next;
	ptr->next = post_ptr->next;
	post_ptr->next->prev = ptr;
	free(post_ptr);
	return start;
}

struct node *delete_list(struct node *start){
	while(start!=NULL){
		start = delete_beg(start);
	}
	return start;
}

int main(){
	int option;
	do{
		printf("\n\n********MAIN MENU********");
		printf("\n 1.  Create a list");
		printf("\n 2.  Display the list");
		printf("\n 3.  Add a node at the bigining");
		printf("\n 4.  Add a node at the end");
		printf("\n 5.  Add a node before a given node");
		printf("\n 6.  Add a node after a given node");
		printf("\n 7.  Delete a node from the bigining");
		printf("\n 8.  Delete a node from the end");
		printf("\n 9.  Delete a node before given node");
		printf("\n 10. Delete a node after a given node");
		printf("\n 11. Delete the entire list");
		printf("\n 12. Sort the list");
		printf("\n 13. Exit");
		printf("\n\nEnter your option ");
		scanf("%d",&option);
		switch(option){
			case 1:
				start = create_ll(start);
				printf("\nLinked List created\n");
				break;
			case 2:
				start = display(start);
				break;
			case 3:
				start = insert_begining(start);
				printf("Added\n");
				break;
			case 4:
				start = insert_end(start);
				printf("Added\n");
				break;
			case 5:
				start = insert_before(start);
				printf("Added\n");
				break;
			case 6:
				start = insert_after(start);
				printf("Added\n");
				break;
			case 7:
				start = delete_beg(start);
				printf("Deleted\n");
				break;
			case 8:
				start = delete_end(start);
				printf("Deleted\n");
				break;
			case 9:
				start = delete_before(start);
				printf("Deleted\n");
				break;
			case 10:
				start = delete_after(start);
				printf("Deleted\n");
				break;
			case 11:
				start = delete_list(start);
				printf("Deleted\n");
				break;
		}
	}while(option!=12);
	return 0;
}
