#include <bits/stdc++.h>
#include <set>
using namespace std;
void solve(){
    int n, m, k, aux = 0;
    cin >> n >> m >> k;
    vector<long long> ans(k);
    vector<vector<pair<int,long long>>> a(n);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    vector<priority_queue<long long>> q(n);
    for(int i=0; i<m; i++){
        int x, y;
        long long w;
        cin >> x >> y >> w;
        x--, y--;
        a[x].push_back({y,w});
    }
    pq.push({0,0});
    q[0].push(0);
    while(!pq.empty() && aux<k){
        auto [t, x] = pq.top();
        pq.pop();
        if(q[x].size()>k && t>q[x].top()) continue;
        //cout << x+1 << " " << t << ": \n";
        if(x == n-1){
            //cout << t << " ";
            aux++;
            //continue;
        }
        for(auto [y, w]: a[x]){
            long long c = t + w;
            if(q[y].empty() || q[y].size()<k || c<q[y].top()){
                pq.push({c, y});
                q[y].push(c);
            }
            while(q[y].size()>k) q[y].pop();
        }
    }
    while(!q[n-1].empty()){
        ans[q[n-1].size() - 1] = q[n-1].top();
        q[n-1].pop();
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
