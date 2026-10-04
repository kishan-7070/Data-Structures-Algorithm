#include<bits/stdc++.h>
using namespace std;
int RottenOranges(vector<vector<int>>&arr,vector<vector<int>>&vis,int n,int m){
    queue<pair<pair<int,int>,int>>q;
    int maxi=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==2){
                q.push({{i,j},0});
                vis[i][j]=2;
            }
        }
    }
    int nRow[4]={-1,0,1,0};
    int nCol[4]={0,1,0,-1};
    while(!q.empty()){
        int row=q.front().first.first;
        int col=q.front().first.second;
        int time=q.front().second;
        maxi=max(maxi,time);
        q.pop();
        for(int i=0;i<4;i++){
            int newRow=row+nRow[i];
            int newCol=col+nCol[i];
            if(newRow>=0 && newRow<n && newCol>=0 && newCol<m &&vis[newRow][newCol]!=2 && arr[newRow][newCol]==1){
                q.push({{newRow,newCol},time+1});
                vis[newRow][newCol]=2;
            }
        }
    }
    return maxi;
}
int main(){
    int n,m;
    cout<<"Enter number of row: ";
    cin>>n;
    cout<<"Enter number of column: ";
    cin>>m;
    vector<vector<int>>arr(n,vector<int>(m));
    vector<vector<int>>vis(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    int ans=RottenOranges(arr,vis,n,m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==1 && vis[i][j]==0){
                ans=-1;
                break;
            }
        }
    }
    cout<<"Total Time taken is : "<<ans;
    return 0;
}