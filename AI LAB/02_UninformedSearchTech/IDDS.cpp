#include <iostream>
#include <vector>
using namespace std;

bool depthLimitedSearch(vector<vector<int>>& graph, int node, int target, int limit) {
    if (node == target) return true;
    if (limit <= 0) return false;

    for (int neighbor : graph[node]) {
        if (depthLimitedSearch(graph, neighbor, target, limit - 1)) {
            return true;
        }
    }
    return false;
}

bool iterativeDeepeningDFS(vector<vector<int>>& graph, int start, int target, int maxDepth) {
    for (int depth = 0; depth <= maxDepth; ++depth) {
        if (depthLimitedSearch(graph, start, target, depth)) {
            return true;
        }
    }
    return false;
}

int main() {
    vector<vector<int>> graph = {
        {1, 2}, // Node 0
        {3, 4}, // Node 1
        {5},    // Node 2
        {},     // Node 3
        {},     // Node 4
        {}      // Node 5
    };

    int start = 0, target = 5, maxDepth = 3;
    if (iterativeDeepeningDFS(graph, start, target, maxDepth)) {
        cout << "Target found!" << endl;
    } else {
        cout << "Target not found!" << endl;
    }

    return 0;
}
