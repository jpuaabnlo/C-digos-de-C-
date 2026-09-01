#include <bits/stdc++.h>
using namespace std;
void rec(int x, vector<bool> &vis, const vector<vector<int>> &adj){
    for(auto y: adj[x]){
        if(!vis[y]){
            vis[y] = true;
            rec(y, vis, adj);
        }
    }
}
void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> hojas;
    vector<vector<int>> adj(n);
    vector<bool> vis(n,false);
    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i=0; i<n; i++){
        if(!vis[i]){
            rec(i, vis, adj);
            hojas.push_back(i);
        }
    }
    cout << hojas.size()-1 << "\n";
    for(int i=1; i<hojas.size(); i++){
        cout << 1 << " " << hojas[i]+1 << "\n";
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
