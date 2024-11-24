// Time Complexity: Time complexity of DLS algorithm is O(bℓ) where b is the branching factor of the search tree, and l is the depth limit.

// Space Complexity: Space complexity of DLS algorithm is O(b×ℓ) where b is the branching factor of the search tree, and l is the depth limit.


#include<bits/stdc++.h>
using namespace std;

    void dfs(int start,vector<int>& visit,vector<vector<int>>& ans){
        visit[start]=1;
        cout<<start<<" ";

        for(int i:ans[start]){
            if(visit[i]!=1){
                dfs(i, visit, ans);
                visit[i]=1;
            }
        }
    }

    void addEdge(int start,int dest ,vector<vector<int>>& ans){
       ans[start].push_back(dest);
    }

    int main() {
        int n=6;
        vector<vector<int>> ans(n);
        vector<int> visit(n,0);

        // for (int i = 0; i < visit.length; i++) {
        //     ans.add(new ArrayList<>());
        // }

        addEdge(0,5,ans);
        addEdge(0,1,ans);
        addEdge(0,4,ans);
        addEdge(1,0,ans);
        addEdge(1,4,ans);
        addEdge(1,2,ans);
        addEdge(2,1,ans);
        addEdge(2,3,ans);
        addEdge(3,2,ans);
        addEdge(3,4,ans);
        addEdge(4,0,ans);
        addEdge(4,1,ans);
        addEdge(4,3,ans);
        addEdge(0,5,ans);
        
        dfs(0,visit,ans);

        return 0;
    }


