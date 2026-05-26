#include<bits/stdc++.h>
using namespace std;
int dfs(int nodo, int level, vector<vector<int>> &a){
    int ans = level;
    //cout<<nodo<<": "<<level<<"\n";
    for(auto x: a[nodo]){
        ans = max(ans, dfs(x, level+1, a));
    }
    return ans;
}
void solve(){
    int n, ans = 0;
    cin >> n;
    vector<vector<int>> a(n);
    queue<int> q;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        if(x != -1){
            a[x-1].push_back(i);
        }
        else q.push(i);
    }
    while(!q.empty()){
        int x = q.front();
        //cout<<x<<"\n";
        q.pop();
        ans = max(ans, dfs(x, 1, a));
    }
    cout<<ans<<"\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cout<<fixed<<setprecision(6)<<"\n";
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t = 1;
    //cin >> t;

    while(t--){
        solve();
    }
}
