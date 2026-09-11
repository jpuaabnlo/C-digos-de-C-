#include <bits/stdc++.h>
#include <set>
using namespace std;
void rec(int x, const vector<vector<int>> &a, vector<int> &path,
    vector<int> &vis, vector<int> &ans){
        bool b = false;
        if(ans.size()>0) return;
        for(auto y: a[x]){
            if(ans.size()>0) return;
            if(y == x) continue;
            if(vis[y]==0){
                vis[y] = 1;
                path[y] = x;
                rec(y, a, path, vis, ans);
                vis[y] = 2;
            }
            else if(vis[y]==1){
                ans.push_back(y);
                for(int nodo=x;;nodo=path[nodo]){
                    ans.push_back(nodo);
                    if(nodo==y) break;
                }
                b=true;
            }
        }
    }
void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> path(n,-1), vis(n,0), ans;
    vector<vector<int>> a(n);
    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        a[x-1].push_back(y-1);
    }
    for(int i=0; i<n; i++){
        if(ans.size()>0) break;
        if(vis[i]==0){
            vis[i] = 1;
            rec(i, a, path, vis, ans);
            vis[i] = 2;
        }
    }
    if(ans.size() ==0) cout << "IMPOSSIBLE\n";
    else{
        cout << ans.size() << "\n";
        reverse(ans.begin(), ans.end());
        for(auto x: ans) cout << x+1 << " ";
        cout << "\n";
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
