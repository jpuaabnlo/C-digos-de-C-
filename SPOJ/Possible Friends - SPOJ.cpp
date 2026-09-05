#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
void solve(){
    string s;
    cin >> s;
    int n = s.size();
    vector<pair<int, int>> ans(n, {0,0});
    vector<vector<int>> dp(n, vector<int>(n,false));
    for(int i=0; i<n; i++) dp[i][i]=2, ans[i].second = i;
    for(int i=0; i<n; i++){
        if(i!=0) cin >> s;
        for(int j=0; j<n; j++){
            if(s[j]=='Y') dp[i][j]=1;
        }
    }
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            if(i==k) continue;
            for(int j=0; j<n; j++){
                if(i==j || j==k) continue;
                if(dp[i][j]==0 && dp[i][k]==1 && dp[k][j]==1){
                    dp[i][j]=2;
                    ans[i].first++;
                }
                if(dp[j][i]==0 && dp[j][k]==1 && dp[k][i]==1){
                    dp[j][i]=2;
                    ans[j].first++;
                }
            }
        }
    }
    sort(ans.rbegin(), ans.rend(), [](const pair<int,int> &a, const pair<int,int> &b){
        if(a.first != b.first) return a.first < b.first;
        return a.second > b.second;
    });
    //for(auto [x, y]: ans) cout << y << ": " << x << "\n";
    cout << ans[0].second << " " << ans[0].first << "\n";
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    while(t--){
        solve();
    }
}
