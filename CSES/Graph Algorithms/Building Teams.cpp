#include <bits/stdc++.h>
using namespace std;
void rec(int x, vector<int> &mrk, int n){
    if(x==-1){
        cout << n << "\n";
        return;
    }
    rec(mrk[x], mrk, n+1);
    cout << x + 1 << " ";
}
void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n);
    vector<int> cont(n, 0);
    queue<int> q;
    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        x--, y--;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for(int i=0; i<n; i++){
        if(cont[i]==0){
            q.push(i);
            cont[i]=1;
            while(!q.empty()){
                auto x = q.front();
                int aux = cont[x]+(cont[x]==1)-(cont[x]==2);
                q.pop();
                for(auto y: a[x]){
                    if(cont[y]==cont[x]){
                        cout << "IMPOSSIBLE\n";
                        return;
                    }
                    if(cont[y]!=0) continue;
                    cont[y] = aux;
                    q.push(y);
                }
            }
        }
    }
    for(auto x: cont){
        cout << x << " ";
    }
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