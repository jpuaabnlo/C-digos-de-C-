#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n, m;
    while(cin >> n >> m && n!=0 && m!=0){
        int ans = 0, c = 0;
        set<int> a, b;
        for(int i=0; i<n; i++){
            int x; cin >> x;
            a.insert(x);
        }
        for(int i=0; i<m; i++){
            int x;
            cin >> x;
            b.insert(x);
        }
        for(auto x: a){
            if(!b.count(x)){
                c++;
            }
        }
        ans = c;
        c = 0;
        for(auto x: b){
            if(!a.count(x)){
                c++;
            }
        }
        ans = min(ans, c);
        cout << ans << "\n";
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}
