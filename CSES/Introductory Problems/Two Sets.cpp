#include <bits/stdc++.h>
using namespace std;
void solve(){
    long long n;
    cin >> n;
    long long med = n*(n+1)/2;
    if(med%2 == 0){
        med /= 2;
        long long aux = med;
        vector<bool> ans(n+1, true);
        vector<int> ans1, ans2;
        for(int i=n; i>0; i--){
            if(ans[i] && aux-i>=0){
                aux -= i;
                ans[i] = false;
                ans1.push_back(i);
            }
        }
        aux = med;
        for(int i=n; i>0; i--){
            if(ans[i] && aux-i>=0){
                aux -= i;
                ans[i] = false;
                ans2.push_back(i);
            }
        }
        cout << "YES\n";
        cout << ans1.size() << "\n";
        for(auto x: ans1) cout << x << " ";
        cout << "\n";
        cout << ans2.size() << "\n";
        for(auto x: ans2) cout << x << " ";
        cout << "\n";
        return;
    }
    cout << "NO\n";
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
