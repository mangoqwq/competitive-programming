#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

unordered_map<char,int> m={{'N',0},{'E',1},{'S',2},{'W',3}};
int dx[]={0,1,0,-1}, dy[]={1,0,-1,0};

void solve(){
    string s; cin >> s;
    for (char &c:s) c=m[c];
    for (int i=s.size()-1;i>=0;--i) s[i]=(s[i]+4-s[0])%4;
    int x=0, y=0, l=0;
    for (char c:s){
        if ((y==0&&c==0)||(y==1&&c==2)) l+=x<0;
        x+=dx[c], y+=dy[c];
    }
    cout << (l%2?"CCW":"CW") << '\n';
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
}