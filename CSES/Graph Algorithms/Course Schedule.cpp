#include <bits/stdc++.h>
using namespace std;
void rec(int x, const vector<vector<int>> &a, vector<int> &tot,
    vector<int> &ans, vector<int> &vis){
        for(auto y: a[x]){
            if(x==y) continue;
            if(vis[y]==0){
                vis[y]=1;
                tot[x]--;
                rec(y, a, tot, ans, vis);
            }
            else if(tot[y]==0 && vis[y]==2) tot[x]--;
        }
        if(tot[x]==0) ans.push_back(x);
        vis[x] = 2;
        return;
    }
void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> tot(n, 0), ans;
    vector<int> vis(n,0);
    vector<vector<int>> a(n);
    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        a[x-1].push_back(y-1);
        tot[x-1]++;
    }
    for(int i=0; i<n; i++){
        if(!vis[i]){
            vis[i] = 1;
            rec(i, a, tot, ans, vis);
        }
    }
    if(ans.size()!=n) cout << "IMPOSSIBLE\n";
    else{
        for(int i=n-1; i>=0; i--) cout << ans[i]+1 << " ";
        cout << "\n";
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin >> t;
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    while(t--){
        solve();
    }
}
