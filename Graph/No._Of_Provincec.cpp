#include<bits/stdc++.h>
using namespace std;
void bfs(vector<vector<int>>&adj,int V,vector<int>&vis,int i){
    queue<int>q;
    q.push(i);
    vis[i]=1;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto it:adj[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push(it);
            }
        }
    }
}
int Provinces(vector<vector<int>>&adj,int V){
    vector<int>vis(V,0);
    int cnt=0;
    for(int i=0;i<V;i++){
        if(!vis[i]){
            cnt++;
            bfs(adj,V,vis,i);
        }
    }
    return cnt;
}
int main(){
    int V,E;
    cout<<"Enter number of vertices and edges: ";
    cin>>V>>E;
    vector<vector<int>>adj(V);
    for(int i=0;i<E;i++){
        int u,v;
        cout<<"Enter vertices and edges: ";
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout<<Provinces(adj,V);
    return 0;
}