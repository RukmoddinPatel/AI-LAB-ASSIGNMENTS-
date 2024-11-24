// here the d= depth of shallowest solution and b is a node at every state.
// T (b) = 1+b2+b3+.......+ bd= O (b^d);
// S.C = O(b^d);


#include <bits/stdc++.h>
using namespace std;

void bfs(int start, vector<int> &visit, vector<vector<int>> &graph) {
    queue<int> q;
    q.push(start);
    visit[start] = 1;

    while (!q.empty()) {
        int front = q.front();
        q.pop();
        cout << front << " ";
        for (int ele : graph[front]) {
            if (visit[ele] != 1) { 
                q.push(ele);
                visit[ele] = 1;
            }
        }
    }
}

void addEdge(int start, int dest, vector<vector<int>> &graph) {
    graph[start].push_back(dest);
}

int main() {
    int n = 6;
    vector<vector<int>> graph(n);
    vector<int> visit(n, 0);

    // Adding edges (Adjust indices to be 0-based)
    addEdge(0, 1, graph);
    addEdge(0, 4, graph);
    addEdge(0, 5, graph);
    addEdge(1, 0, graph);
    addEdge(1, 2, graph);
    addEdge(1, 4, graph);
    addEdge(2, 3, graph);
    addEdge(3, 2, graph);
    addEdge(3, 4, graph);
    addEdge(4, 0, graph);
    addEdge(4, 1, graph);
    addEdge(4, 3, graph);

    cout << "The BFS is: ";
    bfs(0, visit, graph);

    return 0;
}
