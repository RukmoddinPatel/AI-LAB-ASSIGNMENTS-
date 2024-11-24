#include<bits/stdc++.h>
using namespace std;


typedef pair<int,int> pi;

void BFS(int start,int goal, vector<vector<pi>> graph){
    vector<int> visit(graph.size(),0);
    priority_queue<pi,vector<pi>, greater<pi>> pq;

    pq.push(make_pair(start,0));
    visit[start]=1;

    cout<<"The BFS traversal is : ";

    while(!pq.empty()){
    int front=pq.top().first;
    int cost=pq.top().second;

    cout<<front <<" ";
    
    pq.pop();
    if(front==goal) break;

    for(pi p:graph[front]){
        if(visit[p.first]==0){
            pq.push(make_pair(p.first,p.second+cost));
            visit[p.first]=1;
        }
    } 

    }
}


void addEdge(int src,int dest,int cost ,vector<vector<pi>> &graph){
    graph[src].push_back(make_pair(dest,cost));
    graph[dest].push_back(make_pair(src,cost));
}



int main(){
    int n,e;
    cout<<"Enter the number of nodes and edges: ";
    cin>>n>>e;

    vector<vector<pi>> graph(n);
    cout<<"Enter the graph details";

    int src,dest,cost;

    for(int i=0;i<e;i++){
        cout<<"Enter Src dest cost";
        cin>>src>>dest>>cost;
        addEdge(src,dest,cost,graph);

    }

    int start,goal;
    cout<<"Enter the start and goal: ";
    cin>>start>>goal;

    BFS(start,goal,graph);
}