#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1000;

int par[MAXN];

void build(vector<vector<int>> b);

inline int Find(int a){ return (par[a]==a?a:par[a]=Find(par[a])); }

int construct(vector<vector<int>> p){
    int n=p.size(); iota(par,par+n,0);
    vector<vector<int>> b(n,vector<int>(n,0));
    for (int i=0;i<n;++i)
        for (int j=0;j<n;++j)
            if (p[i][j]==3) return 0;
    for (int i=0;i<n;++i){
        if (par[i]!=i) continue;
        for (int j=i+1;j<n;++j){
            if (p[i][j]!=1) continue;
            b[i][j]=b[j][i]=1;
            for (int k=0;k<n;++k)
                if (k!=i&&k!=j) if (p[i][k]!=p[j][k]) return 0;
            par[j]=i;
        }
    }
    for (int i=0;i<n;++i){
        if (par[i]!=i) continue;
        vector<int> c={i};
        for (int j=i+1;j<n;++j){
            if (par[j]!=j||p[i][j]!=2) continue;
            c.push_back(j);
            for (int k=0;k<n;++k){
                if (Find(i)==Find(k)){ if (p[j][k]!=2||p[i][k]!=1) return 0; }
                else if (Find(j)==Find(k)){ if (p[i][k]!=2||p[j][k]!=1) return 0; }
                else{ if (p[i][k]!=p[j][k]) return 0; }
            }
        }
        if (c.size()==2) return 0;
        for (int i=1;i<c.size();++i) b[c[i]][c[i-1]]=b[c[i-1]][c[i]]=1, par[c[i]]=c[0];
        if (i!=c.back()) b[i][c.back()]=b[c.back()][i]=1;
    }
    for (int i=0;i<n;++i)
        for (int j=i+1;j<n;++j)
            if (Find(i)!=Find(j)&&p[i][j]&&i!=j) return 0;
    build(b);
    return 1;
}