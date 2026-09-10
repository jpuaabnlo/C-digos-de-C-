#include <bits/stdc++.h>
using namespace std;
long long inf = 1e18;
struct Edge{
    int a, b;
    long long w;
};
void solve(){
    int n, m, point = - 1;
    cin >> n >> m;
    vector<int> p(n, -1);
    vector<long long> dp(n, inf);
    vector<Edge> edges;
    for(int i=0; i<m; i++){
        int x, y;
        long long w;
        cin >> x >> y >> w;
        x--, y--;
        edges.push_back({x, y, w});
    }
    for(int i=0; i<n; i++){
        point = - 1;
        bool change = false;
        for(auto e: edges){
            if(dp[e.b] > dp[e.a] + e.w){
                dp[e.b] = dp[e.a] + e.w;
                p[e.b] = e.a;
                point = e.b;
                change = true;
            }
        }
        if(!change) break;
    }
    //cout << point << "\n";
    if(point == -1){
        cout << "NO\n";
    }
    else{
        cout << "YES\n";
        for(int i=0; i<n; i++){
            point = p[point];
        }
        vector<int> path;
        for(int y = point;;y = p[y]){
            path.push_back(y);
            if(y==point && path.size()>1)
                break;
        }
        reverse(path.begin(), path.end());
        for(auto x: path) 
            cout << x+1 << " ";
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