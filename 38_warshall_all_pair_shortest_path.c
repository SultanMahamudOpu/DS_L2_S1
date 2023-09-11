#include <stdio.h>
#define INF 9999
#define MAX_VERTICES 100
int numVertices;
int distMatrix[MAX_VERTICES][MAX_VERTICES];

void initializeMatrix(){
    for (int i = 0; i < numVertices; i++){
        for (int j = 0; j < numVertices; j++){
            if (i == j)
                distMatrix[i][j] = 0;
            else
                distMatrix[i][j] = INF;
        }
    }
}

void addEdge(int src, int dest, int weight){
    distMatrix[src][dest] = weight;
}

void warshall(){
    for (int k = 0; k < numVertices; k++){
        for (int i = 0; i < numVertices; i++){
            for (int j = 0; j < numVertices; j++){
                if (distMatrix[i][k] + distMatrix[k][j] < distMatrix[i][j])
                    distMatrix[i][j] = distMatrix[i][k] + distMatrix[k][j];
            }
        }
    }
}

void displayDistanceMatrix(){
    printf("All Pair Shortest Path Matrix:\n");
    for (int i = 0; i < numVertices; i++){
        for (int j = 0; j < numVertices; j++){
            if (distMatrix[i][j] == INF)
                printf("INF\t");
            else
                printf("%d\t", distMatrix[i][j]);
        }
        printf("\n");
    }
}

int main(){
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
    initializeMatrix();
    int numEdges;
    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);
    printf("Enter the edges and weights (source, destination, weight):\n");
    for (int i = 0; i < numEdges; i++){
        int src, dest, weight;
        scanf("%d %d %d", &src, &dest, &weight);
        addEdge(src, dest, weight);
    }
    warshall();
    displayDistanceMatrix();
}
