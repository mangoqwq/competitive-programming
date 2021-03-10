#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

map<int,int> mp={{0,0},{1,1},{2,5},{5,2},{8,8}};
char ree;

int main(){
    //cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int h, m; cin >> h >> m;
        int ch, cm; cin >> ch >> ree >> cm;
        while (true){
            int a=ch/10;
            int b=ch%10;
            int c=cm/10;
            int d=cm%10;
            if (mp.count(a)&&mp.count(b)&&mp.count(c)&&mp.count(d)){
                int th=mp[d]*10+mp[c];
                int tm=mp[b]*10+mp[a];
                if (th<h&&tm<m){
                    printf("%02d:%02d\n",ch,cm);
                    break;
                }
            }
            cm++;
            if (cm==m) ch++, cm=0;
            if (ch==h) ch=0;
        }
    }
}