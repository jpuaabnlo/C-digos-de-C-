#include <bits/stdc++.h>
using namespace std;
const long long inf = -1e18;
struct Edge{
    int a, b;
    long long w;
};
void rec(int x, vector<bool> &b, const vector<vector<int>> &a){
    for(auto y: a[x]){
        if(!b[y]){
            b[y] = true;
            rec(y, b, a);
        }
    }
}
void solve(){
    int n, m;
    cin >> n >> m;
    vector<long long> dp(n, inf);
    vector<bool> ciclos(n, false), b(n, false), bb(n, false);
    vector<Edge> edges;
    vector<vector<int>> a(n), aa(n);
    dp[0]=0;
    for(int i=0; i<m; i++){
        int x, y;
        long long w;
        cin >> x >> y >> w;
        edges.push_back({x-1, y-1, w});
        a[x-1].push_back(y-1);
        aa[y-1].push_back(x-1);
    }
    for(int i=0; i<n-1; i++){
        bool change = false;
        for(auto e: edges){
            if(dp[e.a] > inf){
                if(dp[e.b] < dp[e.a] + e.w){
                    change = true;
                    dp[e.b] = dp[e.a] + e.w;
                }
            }
        }
    }
    bool change = false;
    for(auto e: edges){
        if(dp[e.a] > inf){
            if(dp[e.b] < dp[e.a] + e.w){
                ciclos[e.b] = true;
                dp[e.b] = dp[e.a] + e.w;
            }
        }
    }
    rec(0, b, a);
    rec(n-1, bb, aa);
    for(int i=0; i<n; i++){
        if(ciclos[i] && b[i] && bb[i]){
            cout << "-1\n";
            return;
        }
    }
    cout << dp[n-1] << "\n";
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