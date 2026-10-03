#include<bits/stdc++.h>
using namespace std;
void BFS(vector<vector<int>>&adj,int start,int V){
    vector<int>vis(V,0);
    queue<int>q;
    q.push(start);
    vis[start]=1;
    while(!q.empty()){
        auto node=q.front();
        q.pop();
        cout<<node<<endl;
        for(auto it:adj[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push(it);
            }
        }
    }
}
int main(){
    int V,E;
    cout<<"Enter no of Vertices and edges: ";
    cin>>V>>E;
    vector<vector<int>>adj(V);
    for(int i=0;i<E;i++){
        int u,v;
        cout<<"Enter Starting and ending edges: ";
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int start;
    cout<<"Enter Starting Point: ";
    cin>>start;
    cout<<"BFS is:  ";
    BFS(adj,start,V);
    return 0;
}