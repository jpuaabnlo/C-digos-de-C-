#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n, m;
    cin >> n >> m;
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
    vector<long long> dist(n,1e18);
    vector<bool> vis(n,false);
    vector<vector<pair<int, long long>>> a(n);
    dist[0] = 0;
    vis[0]=true;
    for(int i=0; i<m; i++){
        int x, y;
        long long w;
        cin >> x >> y >> w;
        a[x-1].push_back({y-1,w});
    }
    pq.push({0, 0});
    while(!pq.empty()){
        auto [t, x] = pq.top();
        pq.pop();
        if(t>dist[x]) continue;
        for(auto [y,w]: a[x]){
            if(dist[y] > w+t){
                pq.push({w+t, y});
                dist[y] = w+t;
            }
        }
    }
    for(int i=0; i<n; i++){
        cout << dist[i] << " ";
    }
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
