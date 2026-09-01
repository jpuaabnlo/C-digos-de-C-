#include <bits/stdc++.h>
using namespace std;
void rec(int x, vector<int> &mrk, int n){
    if(x==-1){
        cout << n << "\n";
        return;
    }
    rec(mrk[x], mrk, n+1);
    cout << x + 1 << " ";
}
void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> mrk(n,0);
    vector<vector<int>> a(n);
    vector<bool> vis(n,false);
    queue<int> q;
    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        x--, y--;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    q.push(0);
    vis[0] = true;
    mrk[0] = -1;
    while(!q.empty()){
        auto x = q.front();
        q.pop();
        if(x==n-1){
            rec(x, mrk, 0);
            return;
        }
        for(auto y: a[x]){
            if(!vis[y]){
                vis[y]=true;
                mrk[y]=x;
                q.push(y);
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
