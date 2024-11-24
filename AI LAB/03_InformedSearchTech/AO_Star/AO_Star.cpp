#include <iostream>
#include <vector>
#include <limits.h> // For INT_MAX

#define MAX 10
#define INF 9999

using namespace std;

int adj_mat[MAX][MAX];   // Adjacency matrix
int heuristic[MAX];       // Heuristic values for nodes
int num_vertices, num_edges;  
int marked[MAX];          // Tracks marked nodes
int solved[MAX];          // Tracks solved nodes
int backtrack[MAX];       // Backtrack path for the solution

int findBestSuccessor(int node) {
    int minCost = INF, successor = -1;

    for (int i = 0; i < num_vertices; i++) {
        if (adj_mat[node][i] && !marked[i]) { 
            int totalCost = adj_mat[node][i] + heuristic[i];
            if (totalCost < minCost) {
                minCost = totalCost;
                successor = i;
            }
        }
    }
    return successor;
}

void AOStar(int node) {
    if (!marked[node]) { // Process only unmarked nodes
        int bestSuccessor = findBestSuccessor(node);

        if (bestSuccessor == -1) { // If no valid successor, mark as solved
            marked[node] = 1;
            solved[node] = 1;
            return;
        }

        AOStar(bestSuccessor);

        if (solved[bestSuccessor]) { // Update cost and backtrack if successor is solved
            heuristic[node] = adj_mat[node][bestSuccessor] + heuristic[bestSuccessor];
            backtrack[node] = bestSuccessor;
            solved[node] = 1;
            marked[node] = 1;
        }
    }
}

int main() {
    int start;
    int src, dest, weight;

    cout << "Enter the number of nodes: ";
    cin >> num_vertices;

    cout << "Enter the number of edges:\n";
    cin >> num_edges;

    // Initialize adjacency matrix with 0 (no edge)
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            adj_mat[i][j] = 0;

    for (int i = 0; i < num_edges; i++) {
        cout << "\nEnter edge " << i + 1 << " (format: source destination weight): ";
        cin >> src >> dest >> weight;
        adj_mat[src][dest] = weight;
        adj_mat[dest][src] = weight;
    }

    // Initialize heuristic, marked, solved, and backtrack arrays
    for (int i = 0; i < num_vertices; i++) {
        heuristic[i] = INF;
        marked[i] = 0;
        solved[i] = 0;
        backtrack[i] = -1;
    }

    cout << "Enter the heuristic values for each node (enter 0 for goal nodes):\n";
    for (int i = 0; i < num_vertices; i++) {
        cin >> heuristic[i];
    }

    cout << "Enter the start node: ";
    cin >> start;

    AOStar(start);

    cout << "Solution Path:\n";
    int currentNode = start;
    while (backtrack[currentNode] != -1) {
        cout << currentNode << " -> ";
        currentNode = backtrack[currentNode];
    }
    cout << currentNode << endl;

    cout << "Total Cost: " << heuristic[start] << endl;

    return 0;
}
