#include<bits/stdc++.h>
using namespace std;
bool dfs(int node,int parent,int V,vector<vector<int>>&adj,vector<int>&vis){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            if(dfs(it,node,V,adj))return true;
        }else if(it!=parent){
            return true;
        }
    }
    return false;
}
bool is_Cycle(vector<vector<int>>&adj,int V){
    vector<int>vis(V,0);
    for(int i=0;i<V;i++){
        if(!vis[i]){
            if(dfs(i,-1,V,adj,vis))return true;
        } 
    }
    return false;
}
int main(){
    int V,E;
    cout<<"Enter no of vertices and Edges: ";
    cin>>V>>E;
    vector<vector<int>>adj(V);
    for(int i=0;i<E;i++){
        int u,v;
        cout<<"Enter vertices : ";
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int start;
    cout<<"Enter Starting Point: ";
    cin>>start;
    cout<<is_Cycle(adj,V);
}