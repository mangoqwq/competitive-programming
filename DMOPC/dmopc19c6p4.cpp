#include <bits/stdc++.h>

using namespace std;
int arr[5000001];
int n,q;
int decomp[1000001][1000];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> q;

    int length=(int)sqrt(n+.0)+3;
    

    int op,a,b,c;
    for (int i=0;i<q;++i){
        cin >> op;
        if (op==1){
            cin >> a;
            decomp[arr[a]+500000][a/length]--;
            arr[a]++;
            decomp[arr[a]+500000][a/length]++;
        }
        else if (op==2){
            cin >> a;
            decomp[arr[a]+500000][a/length]--;
            arr[a]--;
            decomp[arr[a]+500000][a/length]++;
        }
        else if (op==3){
            int count=0;
            cin >> a >> b >> c;
            c+=5000000;
            for (int i=a;i<=b;){
                if (i%length==0&&i+length-1<=b){
                    count+=decomp[c][i/length];
                    i+=length;
                }
                else{
                    count+=arr[i];
                    i++;
                }
            }
            cout << count << '\n';
        }
    }
}