#include<bits/stdc++.h>
using namespace std;
bool dfs(vector<vector<int>>&adj,vector<int>&vis,vector<int>&pathVis,int V,int i){
    vis[i]=1;
    pathVis[i]=1;
    for(auto it:adj[i]){
        if(!vis[it]){
            if(dfs(adj,vis,pathVis,V,it))return true;
        }else if(pathVis[it]){
            return true;
        }
    }
    pathVis[i]=0;
    return false;
}
bool is_Cycle(vector<vector<int>>&adj,int V){
    vector<int>vis(V,0);
    vector<int>pathVis(V,0);
    for(int i=0;i<V;i++){
        if(!vis[i]){
            if(dfs(adj,vis,pathVis,V,i))return true;
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
    }
    int start;
    cout<<"Enter Starting Point: ";
    cin>>start;
    cout<<is_Cycle(adj,V);
}