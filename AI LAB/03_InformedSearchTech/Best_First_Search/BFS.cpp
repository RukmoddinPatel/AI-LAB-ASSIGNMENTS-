// Just apply the normal bfs and use the priority Queue
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;

void bfs(int src,int dest,vector<vector<pi>> graph){
    int n=graph.size();
    vector<int> visit(n,0);

    priority_queue<pi,greater<pi>>pq;
    
    pq.push(make_pair(0,src));

    visit[src]=true;

    while(!pq.empty()){
        int front=pq.top().second;
        // displaying the path having the lowest cost

        cout<<front<<" ";
        pq.pop();
        if(front==dest) break;

        for(pi ele:graph[front]){
            if(visit[ele.second]!=1){
                visit[ele.second]=1;
                pq.push(make_pair(ele.first,ele.second));
            }
        }
    } 
}


void addedge(int src,int dest,int cost,vector<vector<pi>>& graph ){
    graph[src].push_back(make_pair(cost,dest));
    graph[dest].push_back(make_pair(cost,src));
}

int main(){
    int n=14;
    vector<vector<pi>> graph(14);

    addedge(0, 1, 3, graph);
    addedge(0, 2, 6, graph);
    addedge(0, 3, 5, graph);
    addedge(1, 4, 9, graph);
    addedge(1, 5, 8, graph);
    addedge(2, 6, 12, graph);
    addedge(2, 7, 14, graph);
    addedge(3, 8, 7, graph);
    addedge(8, 9, 5, graph);
    addedge(8, 10, 6, graph);
    addedge(9, 11, 1, graph);
    addedge(9, 12, 10, graph);
    addedge(9, 13, 2, graph);

    bfs(0,9,graph);

    return 0;
}