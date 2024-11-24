// Time Complexity	O(k^n)	
// 𝑘
// k colors for 
// 𝑛
// n vertices, exploring all combinations.
// Space Complexity	O(n)	Space for the colors array and recursion stack.


#include <iostream>
#include <vector>
#include <cstring>

class CSP {
private:
    std::vector<std::vector<int>> graph;
    int numColors;
    std::vector<int> colors;

public:
    CSP(const std::vector<std::vector<int>>& graph, int numColors)
        : graph(graph), numColors(numColors), colors(graph.size(), -1) {}

    bool isSafe(int vertex, int color) {
        for (size_t i = 0; i < colors.size(); i++) {
            if (graph[vertex][i] == 1 && colors[i] == color) {
                return false;
            }
        }
        return true;
    }

    bool solve(int vertex) {
        if (vertex == graph.size()) return true;

        for (int i = 0; i < numColors; i++) {
            if (isSafe(vertex, i)) {
                colors[vertex] = i;

                if (solve(vertex + 1)) return true;
                colors[vertex] = -1;  // Backtrack
            }
        }
        return false;
    }

    bool colorGraph() {
        return solve(0);
    }

    void printColors() {
        for (int color : colors) {
            std::cout << color << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    std::vector<std::vector<int>> graph = {
        {0, 1, 1, 1},
        {1, 0, 0, 1},
        {1, 0, 0, 1},
        {1, 1, 1, 0}
    };
    int numColors = 3;

    CSP csp(graph, numColors);
    if (csp.colorGraph()) {
        std::cout << "Coloring: ";
        csp.printColors();
    } else {
        std::cout << "No solution exists" << std::endl;
    }

    return 0;
}
