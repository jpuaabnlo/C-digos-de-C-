#include <bits/stdc++.h>
using namespace std;
void solve(){
    int a1,a2,a3, b1, b2;
    while(cin >> a1 >> a2 >> a3 >> b1 >> b2 && a1!=0){
        bool flag = false;
        vector<int> a(3), b(2);
        a[0] = a1, a[1] = a2, a[2] = a3;
        b[0] = b1, b[1] = b2;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        for(int i=1; i<=52; i++){
            if(i != a[2] && i != a[1] && i != a[0]
            && i != b[0] && i != b[1]){
                flag = true;
                if(a[2]>b[1]){
                    if(a[1]>b[0])
                        flag = false;
                    else if(a[0]>i)
                        flag = false;

                    if(a[1]>i){
                        flag = false;
                    }
                    else if(a[0]>b[0]){
                        flag = false;
                    }
                }
                if(a[2]>b[0]){
                    if(a[1]>b[1])
                        flag = false;
                    else if(a[0]>i)
                        flag = false;

                    if(a[1]>i){
                        flag = false;
                    }
                    else if(a[0]>b[1]){
                        flag = false;
                    }
                }

                if(a[2]>i){
                    if(a[1]>b[0])
                        flag = false;
                    else if(a[0]>b[1])
                        flag = false;

                    if(a[1]>b[1]){
                        flag = false;
                    }
                    else if(a[0]>b[0]){
                        flag = false;
                    }
                }
            }
            if(flag){
                cout << i << "\n";
                break;
            }
        }
        if(!flag)
            cout << "-1\n";
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
