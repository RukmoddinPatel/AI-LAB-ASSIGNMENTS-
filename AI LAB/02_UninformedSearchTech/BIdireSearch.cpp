#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

bool bidirectionalSearch(vector<vector<int>>& graph, int start, int target) {
    if (start == target) return true;

    queue<int> forwardQueue, backwardQueue;
    unordered_set<int> forwardVisited, backwardVisited;

    forwardQueue.push(start);
    forwardVisited.insert(start);
    backwardQueue.push(target);
    backwardVisited.insert(target);

    while (!forwardQueue.empty() && !backwardQueue.empty()) {
        // Forward BFS
        int forwardNode = forwardQueue.front();
        forwardQueue.pop();

        for (int neighbor : graph[forwardNode]) {
            if (backwardVisited.find(neighbor) != backwardVisited.end()) {
                return true;
            }
            if (forwardVisited.find(neighbor) == forwardVisited.end()) {
                forwardVisited.insert(neighbor);
                forwardQueue.push(neighbor);
            }
        }

        // Backward BFS
        int backwardNode = backwardQueue.front();
        backwardQueue.pop();

        for (int neighbor : graph[backwardNode]) {
            if (forwardVisited.find(neighbor) != forwardVisited.end()) {
                return true;
            }
            if (backwardVisited.find(neighbor) == backwardVisited.end()) {
                backwardVisited.insert(neighbor);
                backwardQueue.push(neighbor);
            }
        }
    }

    return false;
}

int main() {
    vector<vector<int>> graph = {
        {1, 2}, // Node 0
        {3},    // Node 1
        {4},    // Node 2
        {5},    // Node 3
        {},     // Node 4
        {}      // Node 5
    };

    int start = 0, target = 5;
    if (bidirectionalSearch(graph, start, target)) {
        cout << "Path exists between start and target!" << endl;
    } else {
        cout << "No path exists between start and target!" << endl;
    }

    return 0;
}
