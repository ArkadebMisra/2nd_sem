#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int qu[100];
int front =  -1;
int rear = -1;

void enque(int qu[], int val){
    if(rear == MAX-1){
        printf("\n queue overflow");
    }
    else{
        rear++;
        if(rear == 0){
            front++;
        }
        qu[rear] = val;
    }
}

int dqueue(int qu[]){
    int val;
    if(front>rear){
        printf("\n No element int queue");
        val =  -1;
    }
    else{
        val = qu[front];
        front++;
    }
    return (val);
}

void display(int qu[]){
    int i;
    for(i=front;i<=rear;i++){
        printf("%d ",qu[i]);
    }
}

int main(){
    int val, choice,d;
    do{
        printf("\n   Enter an option ");
        printf("\n1. Enqueue ");
        printf("\n2. Dqueue ");
        printf("\n3. Display ");
        printf("\n4. Exit \n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("\nEnter a value\n");
                scanf("%d",&val);
                enque(qu, val);
                break;
            case 2:
                d = dqueue(qu);
                printf("%d\n",d);
                break;
            case 3:
                display(qu);
                break;
        }
    }while(choice != 4);

}
