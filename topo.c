#include<stdio.h>

#define SIZE 6

int main(){
	
	int i, j, num, G[SIZE][SIZE];
	int indegree[SIZE], flag[SIZE];
	

	printf("Enter the directed acyclic graph in adjacency matrix format: \n");

	
	for(i=0; i<SIZE; i++){
		for(j=0; j<SIZE; j++)
			scanf("%d", &G[i][j]);
		indegree[i] = 0;
		flag[SIZE] = 0;
	}
	
	printf("topological sort: ");
	
	for(i=0; i<SIZE; i++){
		for(j=0; j<SIZE; j++){
			if(G[i][j] == 1)
				indegree[j]++;
		}
	}
	
	for(i=0; i<SIZE; i++){
		if(indegree[i] == 0) {
			printf("%d ", i);
			flag[i] = 1;
			indegree[i]--;
			
			for(j=0; j<SIZE; j++){
				if(G[i][j] == 1)
					indegree[j]--;
			}
			
			i = -1;
		}
		
	}

	printf("\nindegrees: ");
	for(i=0; i<SIZE; i++){
		printf("%d ", indegree[i]);
	}
	

	
	
	return 0;
}
