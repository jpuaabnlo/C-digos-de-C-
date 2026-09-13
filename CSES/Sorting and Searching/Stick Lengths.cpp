#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    long long lsum=0, rsum = 0, tlsum = 0, trsum = 0, ans = 1e18;
    cin >> n;
    map<int,long long> mp;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        mp[x]++;
        rsum+=x;
        trsum++;
    }
    for(auto x: mp){
        long long act = x.first * x.second;
        rsum -= act, trsum-=x.second;
        ans = min(ans, abs(rsum-trsum*x.first) + abs(tlsum*x.first-lsum));
        // cout << x.first << "\n";
        // cout << abs(rsum-trsum*x.first) << " " << rsum << " " << trsum << "\n";
        // cout << abs(tlsum*x.first-lsum) << " " << lsum << " " << tlsum << "\n";
        lsum += act, tlsum+=x.second;
    }
    cout << ans << "\n";
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
