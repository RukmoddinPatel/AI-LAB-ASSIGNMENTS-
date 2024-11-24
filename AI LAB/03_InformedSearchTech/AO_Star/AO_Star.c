#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define INF 9999

int adj_mat[MAX][MAX];
int heuristic[MAX]; 
int num_vertices, num_edges; ; 
int marked[MAX];         
int solved[MAX];         
int backtrack[MAX];      

int findBestSuccessor(int node) 
{
    int minCost = INF, successor = -1;

    for (int i = 0; i < num_vertices; i++) 
    {
        if (adj_mat[node][i] && !marked[i]) 
        { 
            int totalCost = adj_mat[node][i] + heuristic[i];
            if (totalCost < minCost) {
                minCost = totalCost;
                successor = i;
            }
        }
    }

    return successor;
}


void AOStar(int node) 
{
    if (!marked[node]) 
    {     // Only process nodes that haven't been marked
        int bestSuccessor = findBestSuccessor(node);
        
        if (bestSuccessor == -1) 
        {
            marked[node] = 1; 
            solved[node] = 1; 
            return;
        }

        AOStar(bestSuccessor);
        
        // If the successor is solved, update the cost for the current node
        if (solved[bestSuccessor]) 
        {
            heuristic[node] = adj_mat[node][bestSuccessor] + heuristic[bestSuccessor];
            backtrack[node] = bestSuccessor;
            solved[node] = 1;
            marked[node] = 1;
        }
    }
}

int main() 
{
    int start;
    int src,dest, weight;

    printf("Enter the number of nodes: ");
    scanf("%d", &num_vertices);

    printf("Enter the number of edges:\n");
    scanf("%d", &num_edges);

    for (int i = 0; i < num_edges; i++)
    {
        printf("\nEnter edge %d (formatt---->source destination weight): ", i + 1);
        scanf("%d %d %d", &src, &dest, &weight);
        adj_mat[src][dest] = weight;
        adj_mat[dest][src] = weight;
    }


    for (int i = 0; i < num_vertices; i++) {
        heuristic[i] = INF;
        marked[i] = 0;
        solved[i] = 0;
        backtrack[i] = -1;
    }


    printf("Enter the heuristic values for each node (enter 0 for goal nodes):\n");
    for (int i = 0; i < num_vertices; i++) 
    {
        scanf("%d", &heuristic[i]);
    }


    printf("Enter the start node: ");
    scanf("%d", &start);

    AOStar(start);

    printf("Solution Path:\n");
    int currentNode = start;
    while (backtrack[currentNode] != -1) 
    {
        printf("%d -> ", currentNode);
        currentNode = backtrack[currentNode];
    }
    printf("%d\n", currentNode);

    printf("Total Cost: %d\n", heuristic[start]);

    return 0;
}