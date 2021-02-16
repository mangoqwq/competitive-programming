#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=2001;

struct Coord{ int x, y; };
map<int,char> r[MAXN], c[MAXN];
int n, m;
queue<Coord> q;

void checkrow(int i){
    if (!r[i].empty()){
        auto it=r[i].begin();
        if (it->second=='W'){
            q.push({i,it->first});
            r[i].erase(it->first);
            c[it->first].erase(i);
        }
    }
    if (!r[i].empty()){
        auto it=--r[i].end();
        if (it->second=='E'){
            q.push({i,it->first});
            r[i].erase(it->first);
            c[it->first].erase(i);
        }
    }
}

void checkcol(int i){
    if (!c[i].empty()){
        auto it=c[i].begin();
        if (it->second=='N'){
            q.push({it->first,i});
            r[it->first].erase(i);
            c[i].erase(it->first);
        }
    }
    if (!c[i].empty()){
        auto it=--c[i].end();
        if (it->second=='S'){
            q.push({it->first,i});
            r[it->first].erase(i);
            c[i].erase(it->first);
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            char a; cin >> a;
            if (a=='.') continue;
            r[i][j]=a;
            c[j][i]=a;
        }
    }
    for (int i=1;i<=n;++i){
        checkrow(i);
        checkcol(i);
    }
    while (!q.empty()){
        Coord a=q.front(); q.pop();
        cout << "(" << a.x-1 << "," << a.y-1 << ")" << '\n';
        checkrow(a.x); checkcol(a.y);
    }
}