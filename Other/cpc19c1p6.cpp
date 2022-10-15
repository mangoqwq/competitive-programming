#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=2e5+1, SZ=1000, B=201, QSZ=5000;

vector<int> v[B];
unordered_map<int,int> cnt[B];
int l[B], r[B], a[MAXN], n, q;

void rebuild(){
    int pa=0;
    for (int i=0;i<B;++i){
        for (int x:v[i]) a[pa++]=x;
        v[i].clear(), cnt[i].clear();
    }
    for (int i=0;i<pa;++i){
        v[i/SZ].push_back(a[i]);
        cnt[i/SZ][a[i]]++;
    }
    l[0]=0, r[0]=v[0].size()-1;
    for (int i=1;i<B;++i) l[i]=r[i-1]+1, r[i]=l[i]+v[i].size()-1;
}

void ins(int idx, int x){
    for (int i=0;i<B;++i){
        if (idx>=l[i]&&idx-1<=r[i]) cnt[i][x]++, v[i].insert(v[i].begin()+idx-l[i],x), r[i]++, idx=-1;
        else if (idx<l[i]) l[i]++, r[i]++;
    }
}

void rem(int idx){
    idx--;
    for (int i=0;i<B;++i){
        if (idx>=l[i]&&idx<=r[i]){
            cnt[i][v[i][idx-l[i]]]--;
            if (cnt[i][v[i][idx-l[i]]]==0) cnt[i].erase(v[i][idx-l[i]]);
            v[i].erase(v[i].begin()+idx-l[i]), r[i]--;
        }
        else if (idx<l[i]) l[i]--, r[i]--; 
    } 
}

void print(){
    for (int i=0;i<B;++i) for (int x:v[i]) cout << x << " ";
    cout << '\n';
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    for (int i=0;i<n;++i){
        int a; cin >> a;
        v[0].push_back(a);
    }
    rebuild();
    int ans=0;
    while (q--){
        if (q%QSZ==0) rebuild();
        // print();
        char op; int a, b, c;
        cin >> op;
        if (op=='I'){
            cin >> a >> b; a^=ans, b^=ans;
            ins(a,b);
        }
        if (op=='D'){
            cin >> a; a^=ans;
            rem(a);
        }
        if (op=='C'){
            cin >> a >> b >> c; a^=ans, b^=ans, c^=ans;
            a--; b--;
            ans=0;
            for (int i=0;i<B;++i){
                if (l[i]>=a&&r[i]<=b){ if (cnt[i].count(c)) ans+=cnt[i][c]; }
                else if (l[i]>b||r[i]<a) continue;
                else{
                    for (int j=max(a,l[i]);j<=min(b,r[i]);++j) {
                        ans+=v[i][j-l[i]]==c;
                    }
                }
            }
            cout << ans << '\n';
        }
    }
}