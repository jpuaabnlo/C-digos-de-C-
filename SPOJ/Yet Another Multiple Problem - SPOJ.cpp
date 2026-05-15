#include<bits/stdc++.h>
using namespace std;
vector<long long> parent(10000, 0), value(10000, 0);
bool check(long long n, vector<bool> &a){
    while(n>0){
        if(a[n%10]){
            return false;
        }
        n/=10;
    }
    return true;
}
string constr(long long anc, vector<long long> &parent, vector<long long> &value){
    string s = "";
    while(anc >= 0){
        s = (char)(value[anc]+'0') + s;
        anc = parent[anc];
    }
    return s;
}
string bfs(long long &n, vector<bool> &a){
    vector<bool> vis(n, false);
    queue<long long> q;
    for(int i=1; i<=9; i++){
        if(!a[i] && !vis[i%n]){
            q.push(i);
            vis[i%n] = true;
            parent[i%n] = -1;
            value[i%n] = i;
        }
    }
    while(!q.empty()){
        long long x = q.front();
        q.pop();
        vis[x] = true;
        for(int i=0; i<=9; i++){
            long long y = (x*10 + i) % n;
            if(!a[i] && !vis[y]){
                q.push(y);
                vis[y] = true;
                parent[y] = x;
                value[y] = i;
            }
        }
        if(vis[0]){
            break;
        }
    }
    if(vis[0]){
        return constr(0, parent, value);
    }
    return "-1";
}
void solve(){
    long long n;
    int m, t=1;
    while(cin >> n >> m){
        string ans = to_string(n);
        vector<bool> a(12, false);
        for(int i=0; i<m; i++){
            int x; cin>>x;
            a[x]=true;
        }
        if(!check(n, a)){
            ans = bfs(n, a);
        }
        cout<<"Case "<<t++<<": "<<ans<<"\n";
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cout<<fixed<<setprecision(6)<<"\n";
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t = 1;
    //cin >> t;

    while(t--){
        solve();
    }
}
