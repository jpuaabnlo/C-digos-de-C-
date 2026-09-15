#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
void solve(){
    int n, m, ans = mod;
    cin >> n >> m;
    vector<pair<long long, long long>> dp(n, {1e18, 0});
    vector<pair<int, int>> mdp(n, {1e9+7,0});
    vector<bool> vis(n, false);
    priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<>> pq;
    vector<vector<pair<int, long long>>> a(n);
    for(int i=0; i<m; i++){
        int x, y;
        long long w;
        cin >> x >> y >> w;
        a[x-1].push_back({y-1, w});
    }
    pq.push({0LL, 0, 0});
    dp[0] = {0LL, 1};
    mdp[0] = {0, 0};
    //cout << "---------------------\n";
    while(!pq.empty()){
        auto [t, x, f] = pq.top();
        pq.pop();
        //cout << x+1 << " " << t << " " << f << "\n";
        if(t > dp[x].first || x == n-1) continue;
        for(auto [y,w]: a[x]){
            //cout << "---" << y+1 << "\n";
            if(dp[y].first > t + w){
                dp[y] = {t + w, dp[x].second};
                mdp[y] = {mdp[x].first+1, mdp[x].second+1};
                pq.push({t+w, y, f+1});
            }
            else if(dp[y].first == t+w){
                dp[y].second += dp[x].second;
                mdp[y] = {min(mdp[y].first, mdp[x].first+1), max(mdp[y].second, mdp[x].second+1)};
                if(dp[y].second >= mod) dp[y].second -= mod;
            }
        }
        /*cout << "dp: " << x+1 << "\n";
        for(int i=0; i<n; i++){
            cout << i+1 << "| " << dp[i].first << " " << dp[i].second << " - " << mdp[i].first << " " << mdp[i].first << "\n";
        }*/
    }
    cout << dp[n-1].first << " " << dp[n-1].second << " " << mdp[n-1].first << " " << mdp[n-1].second << " ";
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
