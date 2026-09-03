#include <bits/stdc++.h>
using namespace std;
void rec(int x, vector<int> &pos, const vector<vector<int>> &a, bool &b, bool &f, vector<int> &ans){
    //cout << x+1 << " " << pos[x] << "\n";
    for(auto y: a[x]){
        //cout << "---" << y+1 << " " << pos[y] << "\n";
        if(b) continue;
        if(pos[x]-pos[y]>=2 && pos[y]>0){
            b=true;
            //cout << y+1 << " Aqui\n";
            ans.push_back(y+1);
            break;
        }
        if(pos[y]==0){
            pos[y] = pos[x] + 1;
            rec(y, pos, a, b, f, ans);
        }
    }
    if(b && !f){
        ans.push_back(x+1);
        if(x+1==ans[0]) f=true;
    }
    return;
}
void solve(){
    int n, m;
    bool b = false, f = false;
    cin >> n >> m;
    vector<vector<int>> a(n);
    vector<int> pos(n,0), ans;
    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        x--, y--;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for(int i=0; i<n; i++){
        if(ans.size()>0) break;
        if(pos[i]==0){
            pos[i]=1;
            rec(i, pos, a, b, f, ans);
        }
    }
    if(ans.size()==0){
        cout << "IMPOSSIBLE\n";
        return;
    }
    cout << ans.size() << "\n";
    for(auto x: ans) cout << x << " ";
    cout << "\n";
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}