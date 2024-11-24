#include <iostream>
#include <vector>
#include <limits.h> // For INT_MAX

#define MAX 100
#define INF 9999

using namespace std;

int adj_mat[MAX][MAX]; // Adjacency matrix
int heuristic[MAX];    // Heuristic values for nodes
int gCost[MAX];        // Cost from start node to current node
int fCost[MAX];        // Estimated total cost (gCost + heuristic)
int open_list[MAX];    // Open list (nodes to explore)
int closed_list[MAX];  // Closed list (visited nodes)
int num_vertices, num_edges; // Number of nodes and edges

int findMinFCost() {
    int minIndex = -1, minValue = INF;
    for (int i = 0; i < num_vertices; i++) {
        if (open_list[i] && fCost[i] < minValue) {
            minValue = fCost[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void A_star(int start, int goal) {
    // Initialize all values
    for (int i = 0; i < num_vertices; i++) {
        gCost[i] = INF;
        fCost[i] = INF;
        open_list[i] = 0;
        closed_list[i] = 0;
    }

    gCost[start] = 0;
    fCost[start] = heuristic[start];
    open_list[start] = 1;

    while (true) {
        int current = findMinFCost();

        if (current == -1) {
            cout << "No path to the goal node found.\n";
            return;
        }

        if (current == goal) {
            cout << "Goal node " << goal << " reached with cost " << gCost[goal] << ".\n";
            return;
        }

        open_list[current] = 0;
        closed_list[current] = 1;

        cout << "Visited node: " << current << endl;

        for (int i = 0; i < num_vertices; i++) {
            if (adj_mat[current][i] && !closed_list[i]) {
                int tentativeGCost = gCost[current] + adj_mat[current][i];

                if (!open_list[i]) {
                    open_list[i] = 1;
                }

                if (tentativeGCost < gCost[i]) {
                    gCost[i] = tentativeGCost;
                    fCost[i] = gCost[i] + heuristic[i];
                }
            }
        }
    }
}

int main() {
    int start, goal;
    int src, dest, weight;

    cout << "Enter the number of nodes: ";
    cin >> num_vertices;

    cout << "Enter the number of edges:\n";
    cin >> num_edges;

    // Initialize adjacency matrix with INF (no direct edges)
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            adj_mat[i][j] = INF;

    for (int i = 0; i < num_edges; i++) {
        cout << "\nEnter edge " << i + 1 << " (format: source destination weight): ";
        cin >> src >> dest >> weight;
        adj_mat[src][dest] = weight;
        adj_mat[dest][src] = weight;
    }

    cout << "Enter the heuristic values for each node:\n";
    for (int i = 0; i < num_vertices; i++) {
        cin >> heuristic[i];
    }

    cout << "Enter the start node: ";
    cin >> start;
    cout << "Enter the goal node: ";
    cin >> goal;

    A_star(start, goal);

    return 0;
}
