#include <bits/stdc++.h>

using namespace std;
int owo[3]={0,0,0};

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int N; cin >> N;
    for (int i=0,a,b,c;i<N;++i){
        cin >> a >> b >> c;
        a=max(owo[1]+a,owo[2]+a);
        b=max(owo[0]+b,owo[2]+b);
        c=max(owo[0]+c,owo[1]+c);
        owo[0]=a; owo[1]=b; owo[2]=c;
    }
    cout << max(max(owo[0],owo[1]),owo[2]) << '\n';
}