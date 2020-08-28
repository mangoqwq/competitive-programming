#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e5+1,len=300;

struct Query{int l,r,id;};
int arr[MAXN], ans[MAXN], cnt[MAXN];
vector<Query> queries;

bool cmp(Query a, Query b){
    return make_pair(a.l/len,a.r)<make_pair(b.l/len,b.r);
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i){
        cin >> arr[i];
    }
    int q; cin >> q;
    for (int i=1,l,r;i<=q;++i){
        cin >> l >> r;
        queries.push_back({l,r,i});
    }
    sort(queries.begin(),queries.end(),cmp);
    int pl=1,pr=0,even=0;
    int prev,curr;
    for (Query x:queries){
        while (pr<x.r){
            pr++;
            cnt[arr[pr]]++;
            curr=cnt[arr[pr]];
            if (curr%2==0) even++;
            else if (curr!=1) even--;
        }
        while (pl>x.l){
            pl--;
            cnt[arr[pl]]++;
            curr=cnt[arr[pl]];
            if (curr%2==0) even++;
            else if (curr!=1) even--;
        }
        while (pr>x.r){
            cnt[arr[pr]]--;
            curr=cnt[arr[pr]];
            pr--;
            if (curr%2==1) even--;
            else if (curr!=0) even++;
        }
        while (pl<x.l){
            cnt[arr[pl]]--;
            curr=cnt[arr[pl]];
            pl++;
            if (curr%2==1) even--;
            else if (curr!=0) even++;
        }
        ans[x.id]=even;
    }
    for (int i=1;i<=q;++i){
        cout << ans[i] << '\n';
    }
}