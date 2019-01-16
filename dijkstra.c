#include<stdio.h>
#include<limits.h>
#include<stdbool.h>

#define V 9
#define INF 99999

int minDistance(int dist[], bool visited[]){
	int min = INF, min_index, v;
	
	for(v=0; v<V; v++){
		if(dist[v] <= min && visited[v] == false){
			min = dist[v];
			min_index = v;
		}
	}
	
	return min_index;
}

void printPath(int parent[], int j){ 
      
	    // Base Case : If j is source 
	    if (parent[j] == - 1) 
	        return; 
	  
	    printPath(parent, parent[j]); 
	    printf("%d ", j); 
} 

int printSolution(int dist[], int n, int parent[]) { 
    int src = 0, i; 
    printf("Vertex\t Distance\tPath"); 
    for (i = 1; i < V; i++) { 
        printf("\n%d -> %d \t\t %d\t\t%d ", 
                      src, i, dist[i], src); 
        printPath(parent, i); 
    } 
} 

void dijkstra(int graph[V][V], int src){
	
	int v, i, j;
	int dist[V];
	bool visited[V];
	int parent[V];
	
	//INITIALIZATION
	
	for(i=0; i<V; i++){
		dist[i] = INF;
		visited[i] = false;
	}	
	
	dist[src] = 0;
	parent[src] = -1; //parent of root is -1

	//LOGIC
	i = 0, v;
	for(i=0; i<V; i++){
		int u = minDistance(dist, visited);
		visited[u] = true;
		
		for(v=0; v<V; v++){
			if(!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v]){
				parent[v] = u;
				dist[v] = dist[u] + graph[u][v];
			}
		}
	}
	
	printSolution(dist, V, parent);	
}

int main() 
{ 
    //  Let us create the example 
    // graph discussed above 
    int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0}, 
                       {4, 0, 8, 0, 0, 0, 0, 11, 0}, 
                        {0, 8, 0, 7, 0, 4, 0, 0, 2}, 
                        {0, 0, 7, 0, 9, 14, 0, 0, 0}, 
                        {0, 0, 0, 9, 0, 10, 0, 0, 0}, 
                        {0, 0, 4, 0, 10, 0, 2, 0, 0}, 
                        {0, 0, 0, 14, 0, 2, 0, 1, 6}, 
                        {8, 11, 0, 0, 0, 0, 1, 0, 7}, 
                        {0, 0, 2, 0, 0, 0, 6, 7, 0} 
                    }; 
  
    dijkstra(graph, 0); 
    return 0; 
} 







