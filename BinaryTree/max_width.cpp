#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
};
Node* buildTree(){
    int data;
    cin>>data;
    if(data==-1)return nullptr;
    Node* root= new Node(data);
    root->left=buildTree();
    root->right=buildTree();
    return root;
}
int FindMaxWidth(Node* root){
    queue<pair<Node*,int>>q;
    q.push({root,0});
    int maxi=0;
    while(!q.empty()){
        int n=q.size();
        vector<int>level;
        for(int i=0;i<n;i++){
            Node* val=q.front().first;
            int t=q.front().second;
            level.push_back(t);
            if(val->left)q.push({val->left,2*t+1});
            if(val->right)q.push({val->right,2*t+2});
            q.pop();
        }
        int m=level.size();
        maxi=max(maxi,level[m-1]-level[0]+1);
    }
    return maxi;
}
int main(){
    int n;
    Node* root=buildTree();
    cout<<"Max Width of a Bt is :"<< FindMaxWidth(root);
    return 0;
}