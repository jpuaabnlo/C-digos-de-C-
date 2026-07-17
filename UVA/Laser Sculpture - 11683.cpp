#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    while(cin >> n && n!=0){
        int m, ans = 0;
        cin >> m;
        vector<int> blocks(m);
        for(int i=0; i<m; i++){
            cin >> blocks[i];
            if(i==0){
                ans += n-blocks[i];
            }
            else if(blocks[i] < blocks[i-1]){
                ans +=blocks[i-1] - blocks[i];
            }
        }
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
