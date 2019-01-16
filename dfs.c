#include<stdio.h>

void DFS(int);
int G[10][10];
int visited[10];
int num;

/**
    DFS-recursive(G, s):
        mark s as visited
        for all neighbours w of s in Graph G:
            if w is not visited:
                DFS-recursive(G, w)
**/

void DFS(int i){
	int j;
	printf("%d ", i);	
	
	visited[i] = 1;
	for(j=0; j<num; j++){
		if(visited[j] != 1 && G[i][j] == 1)
			DFS(j);
	}
}

void main(){
	
	int i, j;
	int sourceNode = 0;	
	
	printf("Enter the number of vertices: ");
	scanf("%d", &num);
	
	printf("Enter the graph in adjacency matrix form: \n");
	printf("DFS: ");
	
	for(i=0; i<num; i++){
		for(j=0; j<num; j++){
			scanf("%d", &G[i][j]);
		}
		//initilializing visited array with 0s
		visited[i] = 0;
	}
	
	DFS(sourceNode);
}
