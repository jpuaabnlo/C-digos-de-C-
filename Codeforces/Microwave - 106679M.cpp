#include <bits/stdc++.h>
using namespace std;
void solve(){
    long long n, m, k;
    cin >> n >> m >> k;
    map<long long, vector<tuple<long long,long long,long long>>> mp;
    vector<vector<long long>> vis(n, vector<long long>(k+1, 1e18));
    for(int i=0; i<m; i++){
        long long x, y, w, z;
        cin >> x >> y >> w >> z;
        x--, y--;
        mp[x].push_back({y, w, z});
        mp[y].push_back({x, w, z});
    }
    priority_queue<tuple<long long, long long, long long>, vector<tuple<long long, long long, long long>>, greater<>> pq;
    pq.push({0LL, 0LL, 0LL});
    vis[0][0]=true;
    while(!pq.empty()){
        auto [t, d, x] = pq.top();
        pq.pop();
        if(x==n-1){
            cout << t << "\n";
            return;
        }
        for(auto [y, w, z]: mp[x]){
            if(d+1<=k && z>=0 && vis[y][d+1]>t+z){
                pq.push({t+z, d+1, y});
                vis[y][d+1]=t+z;
            }
            if(vis[y][d]>t+w){
                pq.push({t+w, d, y});
                vis[y][d]=t+w;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
