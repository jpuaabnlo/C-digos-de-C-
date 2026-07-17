#include <bits/stdc++.h>
using namespace std;
int rec(int l, int r, int round, const int &p1, const int &p2){
    // cout << l << " - " << r << " : "<< (l+r)/2 << "\n";
    // cout << "R: " << round << ": [" << p1 << ", " << p2 << "]\n";
    if(l == r || round == 0) return 1e9;
    if(l <= p1 && p2 <= r){
        return min(round, min(rec(l, (l+r)/2, round-1, p1, p2), rec((l+r)/2+1, r, round-1, p1, p2)));
    }
    return 1e9;
}
void solve(){
    int n, p1, p2;
    while(cin >> n >> p1 >> p2){
        if(p1 > p2) swap(p1, p2);
        cout << rec(1, pow(2, n), n, p1, p2) << "\n";
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
