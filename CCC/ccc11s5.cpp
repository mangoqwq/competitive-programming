#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define is(x,idx) (1&(x>>idx))
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1<<25;

bool vis[MAXN];
int n;

void reduce(int &val){
    int cnt=0;
    for (int i=0;i<=n;++i){
        if (!is(val,i)){
            if (cnt<4) {cnt=0; continue;}
            for (int k=i-cnt;k<i;++k){ val-=(1<<k); }
            return;
        }
        else{
            cnt++;
        }
    }
}

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    int a=0;
    for (int i=0,b;i<n;++i){
        cin >> b;
        a|=b; a<<=1;
    }
    a>>=1;
    queue<int> q; int cnt=0,curr,temp;
    q.push(a); vis[a]=1;
    while (!q.empty()){
        int qsize=q.size();
        for (int _=0;_<qsize;++_){
            curr=q.front(); q.pop();
            if (curr==0) { cout << cnt << '\n'; return 0; }
            for (int i=0;i<n;++i){
                if (is(curr,i)) continue;
                temp=curr+(1<<i);
                reduce(temp);
                if (!vis[temp]) vis[temp]=1, q.push(temp);
            }
        }
        cnt++;
    }

}