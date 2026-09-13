#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
void solve(){
    int n;
    cin >> n;
    vector<string> a(n+1);
    vector<vector<int>> dp(n+1, vector<int>(n+1,0));
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    dp[1][1] = a[1][0]=='.';
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j && i==1) continue;
            if(a[i][j-1]=='.'){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
                dp[i][j] %= mod;
            }
        }
    }
    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=n; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    cout << dp[n][n] << "\n";
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
