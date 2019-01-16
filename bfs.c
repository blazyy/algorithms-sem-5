#include<stdio.h>
#define SIZE 10
#define initial 1
#define waiting 2
#define visited 3

int queue[SIZE], num;
int G[SIZE][SIZE];
int front = -1; 
int rear = -1;
int state[SIZE];

int isEmpty(){
	if(front == -1 || front > rear)
		return 1;
	else
		return 0;
}

void enqueue(int v){
	if(rear == SIZE-1){
		printf("Queue overflow!");
	}  
	else{
		if(front == -1) 
            front = 0;
		rear++;
		queue[rear] = v;
	}
}

int dequeue(){
	
	if(isEmpty()){
		printf("Queue is empty!");
		//exit(1);
	}
	
	int returnValue = queue[front];
	front++;
	return returnValue;

}

void BFS(int v){
	int i, j;
	
	enqueue(v);
	
	while(!isEmpty()){
		v = dequeue();
		printf("%d ", v);
		state[v] = visited;
		
		for(i=0; i<num; i++){
			if(G[v][i] == 1 && state[i] == initial){
				enqueue(i);
				state[i] = visited;
			}
		}
	}
	printf("\n");
}

void main(){
	
	int i, j;
	printf("How many vertices?: ");
	scanf("%d", &num);
	
	for(i=0; i<num; i++){
		for(j=0; j<num; j++){
			scanf("%d", &G[i][j]);
		}
	}
	
	for(i=0; i<num; i++)
		state[i] = initial;
	
	BFS(0);
}
