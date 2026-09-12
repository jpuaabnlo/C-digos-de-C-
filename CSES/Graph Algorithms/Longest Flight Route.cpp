#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> path(n), dp(n,0), ans;
    vector<bool> vis(n, false);
    vector<vector<int>> a(n);
    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        a[x-1].push_back(y-1);
    }
    path[n-1] = 0;
    auto rec = [&](auto& self, int x) -> void {
        //cout << x+1 << ": " << dp[x] << "\n";
        if(x==n-1){
            path[x] = -1;
            dp[x] = 1;
            return;
        }
        for(auto y: a[x]){
            //cout << x + 1 << ": " << dp[x] << " Itera en:" << y+1 <<"\n";
            if(!vis[y]){
                vis[y] = true;
                self(self, y);
            }
            if(dp[y] + 1 > dp[x] && dp[y]>0){
                dp[x] = dp[y] + 1;
                path[x] = y;
            }
        }
        //cout << x +1 << ": " << dp[x] << " Salida\n";
    };
    rec(rec, 0);
    if(path[n-1]!=-1){
        cout << "IMPOSSIBLE\n";
        return;
    }
    cout << dp[0] << "\n";
    for(int i=0;;i=path[i]){
        ans.push_back(i+1);
        if(path[i]==-1) break;
    }
    for(auto x: ans) cout << x << " ";
    cout << "\n";
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
