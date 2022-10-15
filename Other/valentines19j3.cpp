#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    string uwu; cin >> uwu;
    int l,lo,lov,love; l=lo=lov=love=0;
    for (char x:uwu){
        if (x=='l') l++;
        if (x=='o') lo+=l;
        if (x=='v') lov+=lo;
        if (x=='e') love+=lov;
    }    
    cout << love << '\n';
}