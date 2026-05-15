#include<bits/stdc++.h>
using namespace std;
int vis[71][71][71][71];
void bfs(){
    memset(vis, -1, sizeof(vis));
    queue< array<int, 4> > q;
    q.push({1,2,3,4});
    vis[1][2][3][4] = 0;
    while(!q.empty()){
        auto a = q.front();
        int cont = vis[a[0]][a[1]][a[2]][a[3]];
        q.pop();
        for(int i=0; i<4; i++){
            for(int j: {-1,1}){
                int aux = a[i] + j;
                if(aux>=1 && aux<=70 && find(a.begin(), a.end(), aux) == a.end()){
                    array<int, 4> b = a;
                    b[i]=aux;
                    sort(b.begin(), b.end());

                    if(vis[b[0]][b[1]][b[2]][b[3]]==-1){
                        vis[b[0]][b[1]][b[2]][b[3]] = cont + 1;
                        q.push(b);
                    }
                }
            }
            for(int j=0; j<4; j++){
                if(i==j) continue;
                int aux = a[j] + (a[j] - a[i]);
                if(aux>=1 && aux<=70 && find(a.begin(), a.end(), aux) == a.end()){
                    array<int, 4> b = a;
                    b[i]=aux;
                    sort(b.begin(), b.end());

                    if(vis[b[0]][b[1]][b[2]][b[3]]==-1){
                        vis[b[0]][b[1]][b[2]][b[3]] = cont + 1;
                        q.push(b);
                    }
                }
            }
        }
    }
}
void solve(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    cout<<vis[a][b][c][d]<<"\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cout<<fixed<<setprecision(6)<<"\n";
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t = 1;
    cin >> t;
    bfs();

    while(t--){
        solve();
    }
}
/*
2
1 2 3 4
1 3 4 6
*/
