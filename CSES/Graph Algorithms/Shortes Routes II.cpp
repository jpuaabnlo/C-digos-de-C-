#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
void solve(){
    int n, m, q;
    cin >> n >> m >> q;
    //vector<vector<pair<int, long long>>> a(n);
    vector<vector<long long>> dp(n, vector<long long>(n, inf));
    for(int i=0; i<m; i++){
        int x, y;
        long long w;
        cin >> x >> y >> w;
        x--, y--;
        /*a[x].push_back({y, w});
        a[y].push_back({x, w});*/
        dp[x][y] = min(dp[x][y], w);
        dp[y][x] = min(dp[y][x], w);
    }
    for(int i=0; i<n; i++){
        dp[i][i]=0;
    }
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(dp[i][k]<inf && dp[k][j]<inf)
                    dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
            }
        }
    }
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         cout << i+1 << " - " << j+1 << ": " << dp[i][j] << "\n";
    //     }
    // }
    for(int i=0; i<q; i++){
        int x, y;
        cin >> x >> y;
        x--, y--;
        if(dp[x][y]==inf && dp[y][x]==inf) cout << "-1\n";
        else cout << min(dp[x][y], dp[y][x]) << "\n";
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
