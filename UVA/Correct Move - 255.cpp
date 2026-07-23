#include <bits/stdc++.h>
using namespace std;
void solve(){
    int a, b, c;
    while(cin >> a >> b >> c){
        if(a==b) cout<<"Illegal state\n";
        else{
            int x = b/8, y = b%8, kx=a/8, ky=a%8, tx=c/8, ty=c%8;
            bool f1=true, f2=true, f3=true, f4=true;
            vector<vector<int>> moves(8, vector<int>(8, 0));
            moves[kx][ky] = 5;
            if(kx-1>=0) moves[kx-1][ky]=1;
            if(kx+1<8) moves[kx+1][ky]=1;
            if(ky-1>=0) moves[kx][ky-1]=1;
            if(ky+1<8) moves[kx][ky+1]=1;
            moves[x][y] = 0;
            for(int i=1; i<8; i++){
                if(f1 && x+i<8){
                    f1=!(moves[x+i][y]==5);
                    if(moves[x+i][y]==0){
                        moves[x+i][y] = 2;
                    }
                    else{
                        moves[x+i][y] = 3;
                    }
                }

                if(f2 && x-i>=0){
                    f2=!(moves[x-i][y]==5);
                    if(moves[x-i][y]==0){
                        moves[x-i][y] = 2;
                    }
                    else{
                        moves[x-i][y] = 3;
                    }
                }

                if(f3 && y+i<8){
                    f3=!(moves[x][y+i]==5);
                    if(moves[x][y+i]==0){
                        moves[x][y+i] = 2;
                    }
                    else{
                        moves[x][y+i] = 3;
                    }
                }

                if(f4 && y-i>=0){
                    f4=!(moves[x][y-i]==5);
                    if(moves[x][y-i]==0){
                        moves[x][y-i] = 2;
                    }
                    else{
                        moves[x][y-i] = 3;
                    }
                }
            }
            moves[kx][ky]=1;
            if(moves[tx][ty]<=1){
                cout<<"Illegal move\n";
            }
            else if(moves[tx][ty]==3){
                cout<<"Move not allowed\n";
            }
            else{
                if((kx==0 && ky==0 && tx==1 && ty==1) ||
                (kx==0 && ky==7 && tx==1 && ty==6) ||
                (kx==7 && ky==0 && tx==6 && ty==1) ||
                (kx==7 && ky==7 && tx==6 && ty==6)){
                    cout << "Stop\n";
                }
                else{
                    cout<<"Continue\n";
                }
            }
            // cout <<"Goal: "<<tx<<" "<<ty<<"\n";
            // for(int i=0; i<8; i++){
            //     for(int j=0; j<8; j++){
            //         cout << moves[i][j]<<"|";
            //     }
            //     cout<<"\n";
            //     for(int j=0; j<16; j++){
            //         cout <<"-";
            //     }
            //     cout<<"\n";
            // }
        }

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
