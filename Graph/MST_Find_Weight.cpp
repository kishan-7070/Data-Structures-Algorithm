#include<bits/stdc++.h>
using namespace std;
int Find_MST(vector<vector<pair<int,int>>>&adj,int start,int V){
    int sum=0;
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
    vector<int>vis(V,0);
    pq.push({0,start,-1});
    // vis[start]=1;
    while(!pq.empty()){
        auto[wt,node,parent]=pq.top();
        pq.pop();
        if(!vis[node]){
            vis[node]=1;
            sum+=wt;
        }else{
            continue;
        }
        for(auto it:adj[node]){
            if(!vis[it.first]){
                pq.push({it.second,it.first,node});
            }
        }
    }
    return sum;
}
int main(){
    int V,E;
    cout<<"Enter no of Vertices and edges: ";
    cin>>V>>E;
    vector<vector<pair<int,int>>>adj(V);
    for(int i=0;i<E;i++){
        int u,v,w;
        cout<<"Enter Starting and ending edges and weight: ";
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    int start;
    cout<<"Enter Starting Point: ";
    cin>>start;
    cout<<"MST of the Graph is: "<<Find_MST(adj,start,V);
    return 0;
}