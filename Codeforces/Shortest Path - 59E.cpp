#include<bits/stdc++.h>
using namespace std;
/*int ans = 1e9;
vector<int> camino, res;
void dfs(int cont, int n1, int n2, int n3, const vector< vector<int> > &a, vector< vector<bool> > &vis, const set<tuple<int,int,int> > & paths, const int &n){
    if(cont>=ans) return;
    if(n3==n){
        ans = cont;
        res = camino;
    }
    for(auto x: a[n3]){
        if((n2==0 || !paths.count({n2, n3, x})) && !vis[n3][x]){
            vis[n3][x] = true;
            camino.push_back(x);
            dfs(cont + 1, n2, n3, x, a, vis, paths, n);
            camino.pop_back();
            vis[n3][x] = false;
        }
    }
}*/
void solve(){
    int n, m , k, ans = 1e9, re=0, l=0;
    cin >> n >> m >> k;
    vector< vector<int> > a(n+1);
    vector < pair<int,int> > p;
    vector< vector<bool> > vis(n+1, vector<bool>(n+1, false));
    set< tuple<int, int, int> > paths;
    for(int i = 0; i<m; i++){
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for(int i=0; i<k; i++){
        int x, y, z;
        cin >> x >> y >> z;
        paths.insert({x, y, z});
    }
    queue < tuple<int, int, int, int> > q;
    q.push({0,0,1,0});
    p.push_back({0, 1});
    re++;
    while(!q.empty()){
        auto [c, x, y, cam] = q.front();
        q.pop();
        if(y==n){
            ans = c;
            l = cam;
            break;
        }
        for(auto z: a[y]){
            if(!paths.count({x,y,z}) && !vis[y][z]){
                vis[y][z] = true;
                q.push({c+1, y, z, re});
                p.push_back({cam, z});
                re++;
            }
        }
    }
    if(ans==1e9){
        cout<<"-1\n";
        return;
    }
    vector<int> res;
    cout<<ans<<"\n";
    while(l!=0){
        auto[x, y] = p[l];
        res.push_back(y);
        l = x;
    }
    reverse(res.begin(), res.end());
    cout<<"1 ";
    for(auto x: res) cout<<x<<" ";
    cout<<"\n";
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
