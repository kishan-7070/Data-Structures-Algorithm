#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>>&adj,int start,vector<int>&vis){
    vis[start]=1;
    cout<<start<<" ";
    for(auto it:adj[start]){
        if(!vis[it]){
            dfs(adj,it,vis);
        }
    }
}
int main(){
    int V,E;
    cout<<"Enter vertices and Edges: ";
    cin>>V>>E;
    vector<vector<int>>adj(V);
    for(int i=0;i<E;i++){
        int u,v;
        cout<<"Enter vertices: ";
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int start;
    cout<<"Enter starting Point:  ";
    cin>>start;
    vector<int>vis(V,0);
    dfs(adj,start,vis);
    return 0;
}