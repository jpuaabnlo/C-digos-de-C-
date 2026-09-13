#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    if(n>3 || n==1){
        for(int i=2; i<=n; i+=2){
            cout << i << " ";
        }
        for(int i=1; i<=n; i+=2){
            cout << i << " ";
        }
    }
    else cout << "NO SOLUTION\n";
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
