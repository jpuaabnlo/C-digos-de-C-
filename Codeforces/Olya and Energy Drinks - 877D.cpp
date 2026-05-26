#include<bits/stdc++.h>
using namespace std;
int mx[] = {1,-1,0,0}, my[] = {0,0,1,-1}; 
void solve(){
    int n, m, k;
    int xo, yo, xd, yd;
    cin >> n >> m >> k;
    vector< string > a(n);
    vector< vector<bool> > vis(n, vector<bool>(m, false));
    vector< vector<int> > val(n, vector<int>(m, 1e9));
    queue< tuple<int, int, int> > q;
    for(int i=0; i<n; i++) cin >> a[i];
    cin >> xo >> yo >> xd >> yd;
    xo--, yo--, xd--, yd--;
    q.push({xo, yo, 0});
    vis[xo][yo]=true;
    val[xo][yo]=0;
    while(!q.empty()){
        auto [x, y, z] = q.front();
        //cout<<x<<" "<<y<<" - "<<z<<":\n";
        q.pop();
        if(x==xd && y==yd){
            cout<<z<<"\n";
            return;
        }
        for(int i=0; i<4; i++){
            int nx = x + mx[i], ny = y + my[i];
                //cout<<nx<<" : "<<ny<<"\n";
            for(int j=0; j<k; j++){
                if(nx>=0 && nx<n && ny>=0 && ny<m && a[nx][ny]=='.' && z+1<=val[nx][ny]){
                    if(!vis[nx][ny]){
                        q.push({nx, ny, z+1});
                        val[nx][ny] = z+1;
                        vis[nx][ny] = true;
                    }
                    if(nx==x && ny==y){
                        cout<<z+1<<"\n";
                        return;
                    }
                    //cout<<nx<<" - "<<ny<<" : "<<z+1<<"\n";
                    nx+=mx[i], ny+=my[i];
                }
                else j=k;
            }
        }
    }

    cout<<"-1\n";
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
