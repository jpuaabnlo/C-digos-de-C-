#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    bool b = false;
    cin >> n;
    vector< vector<int> > adj(n+1);
    vector<bool> vis(n+1, false);
    vector<int> p(n+1, -1), ans; // parents
    queue<int> q;
    for(int i=1; i<n; i++){
        int m;
        cin >> m;
        for(int j=0; j<m; j++){
            int x;
            cin >> x;
            adj[i].push_back(x);
        }
        // sort to make it lexicographically smaller
        sort(adj[i].begin(), adj[i].end());
        /*cout << i << ": ";
        for(int y: adj[i]) cout << y << " ";
        cout << "\n";*/
    }
    q.push(1);
    vis[1] = true;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        if(x == n){
            b = true;
            break;
        }
        for(int y: adj[x]){
            if(!vis[y]){
                p[y] = x;
                vis[y] = true;
                q.push(y);
            }
        }
    }
    if(!b){
        cout<<"-1\n";
        return;
    }
    int m = n;
    while(p[m]!=-1){
        m = p[m];
        ans.push_back(m);
    }
    cout << ans.size() << "\n";
    for(int i=ans.size()-1; i>=0; i--){
        cout << ans[i];
        if(i>0) cout << " ";
        else cout << "\n";
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;

    while(t--){
        solve();
        if(t>0) cout << "\n";
    }
}
