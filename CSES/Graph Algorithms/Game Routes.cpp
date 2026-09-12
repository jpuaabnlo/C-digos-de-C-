#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> dp(n, -1);
    vector<vector<int>> a(n);
    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        a[x-1].push_back(y-1);
    }
    dp[n-1] = 1;
    auto rec = [&](auto& self, int x) -> int {
        //cout << x+1 << ": " << dp[x] << "\n";
        if(dp[x]!=-1) return dp[x] % mod;
        dp[x] = 0;
        for(auto y: a[x]){
            dp[x] = (dp[x] + self(self, y)) % mod;
        }
        //cout << "Sale " << x+1 << ": " << dp[x] << "\n";
        return dp[x] % mod;
    };
    rec(rec, 0);
    cout << dp[0] << "\n";
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
