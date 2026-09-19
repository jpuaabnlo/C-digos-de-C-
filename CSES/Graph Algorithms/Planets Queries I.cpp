#include <bits/stdc++.h>
#include <cmath>
using namespace std;
const int mod = 1e9 + 7;
void solve(){
    int n, l;
    long long m;
    cin >> n >> m;
    l = 30;
    //cout << l << "l\n";
    vector<vector<int>> p(30, vector<int>(n));
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        x--;
        p[0][i] = x;
    }
    for(int i=1; i<l; i++){
        for(int j=0; j<n; j++){
            p[i][j] = p[i-1][p[i-1][j]];
        }
    }
    // for(int i=0; i<n; i++){
    //     cout << i+1 << "\n";
    //     for(int j=0; j<=l; j++){
    //         cout << "---" << j+1 << " " << p[j][i]+1 << "\n";
    //     }
    // }
    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        x-=1;
        for(int j=l; j>=0; j--){
            if(y & (1LL << j)){
                //cout << j << " Entra\n";
                x = p[j][x];
            }
        }
        cout << x+1 << "\n";
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
