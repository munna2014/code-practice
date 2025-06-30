#include<bits/stdc++.h>
using namespace std;
#define ll long long int

const int le5 = 100000; // Example definition for 10^5
const int N = le5 + 2;  // Use it here

bool vis[N];
vector<int> adj[N];


void dfs(int node){
    //preorder
    vis[node] = 1;
    cout << node << " ";


    // inorder
    vector<int>::iterator it;
    for (it = adj[node].begin(); it != adj[node].end(); it++){
         if(vis[*it])
             ;
             else {
                 dfs(*it);
             }
    }

    //postorder
    //cout << node << " ";
} 

int main(){

    for (int i = 0; i < N;i++){
        vis[i] = 0;
    }

    int n, m;
    cin >> n >> m;

    int x, y;
    for (int i= 0; i < m;i++){
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1);

    return 0;
}