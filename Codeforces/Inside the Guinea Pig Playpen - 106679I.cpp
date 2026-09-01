#include <bits/stdc++.h>
using namespace std;
long long rec(int nodo, map<long long, long long> &mp, map<int, vector<int>> &adj){
    long long ans = mp[nodo];
    for(auto x: adj[nodo]){
        ans += rec(x, mp, adj);
    }
    return ans;
}
void solve(){
    int n, m;
    long long cont = 0, ans = 0;
    cin >> n >> m;
    vector<long long> a(m), hojas;
    map<long long, long long> mp;
    vector<tuple<long long, long long, long long>> rangos;
    map<int, vector<int>> adj;
    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        a[i]=x;
        mp[x]=y;
    }
    for(int i=0; i<m; i++){
        long long x, y;
        char c;
        cin >> c;
        if(c=='A'){
            cin >> x >> y;
            hojas.push_back(a[i]);
            rangos.push_back({x, x+y, a[i]});
        }
        else if(c=='T'){
            cin >> x;
            adj[x].push_back(a[i]);
        }
    }
    for(int i=0; i<hojas.size(); i++){
        // tamano[hojas[i]] = rec(hojas[i], mp, adj);
        // cout << tamano[hojas[i]] << "\n";
        get<2>(rangos[i]) = rec(hojas[i], mp, adj);
    }
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<>> pq;
    sort(rangos.begin(), rangos.end());
    for(int i=0; i<rangos.size(); i++){
        auto [x, y, z] = rangos[i];
        pq.push({y, z});
        while(x >= pq.top().first){
            cont -= pq.top().second;
            pq.pop();
        }
        //cout << x << " " << y << ": " << z << " - " << pq.top().first << "\n";
        cont += z;
        ans = max(ans, cont);
    }
    cout << ans << "\n";
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
