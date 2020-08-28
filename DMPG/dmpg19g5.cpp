#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

// Centroid decomposition, difference array

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define f first
#define s second
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=200'001,MAXK=1'000'001;

int n,k;
ll total,prob[MAXN];
vector<pii> graph[MAXN];
int ss[MAXN]; bool marked[MAXN];//,marked[MAXN];
ll diff[MAXN];

int get_subsize(int node, int prev){
    ss[node]=1;
    for (pii x:graph[node]){
        if (x.f==prev||marked[x.f]) continue;
        ss[node]+=get_subsize(x.f,node);
    }
    return ss[node];
}

int find_centroid(int node,int prev,int size){
    for (pii x:graph[node]){
        if (x.f==prev||marked[x.f]) continue;
        if (ss[x.f]*2>size) return find_centroid(x.f,node,size);
    }
    return node;
}

int get_centroid(int node){
    get_subsize(node,0);
    int centroid=find_centroid(node,0,ss[node]);
    marked[centroid]=1;
    return centroid;
}

ll update(int node, int prev,int dist){
    if (dist>k) return 0;
    for (pii x:graph[node]){
        if (x.f==prev||marked[x.f]) continue;
        diff[node]+=update(x.f,node,dist+x.s);
    }
    prob[node]+=diff[node];
    ll temp=diff[node]; diff[node]=0;
    return temp;
}

multimap<int,int> m, cnt; int freq1[MAXK],freq2[MAXK];
void dfs(int node, int prev, int dist,int centroid){
    if (dist>k) return;
    diff[node]=0;
    if (dist==k){
        diff[node]++;
        prob[centroid]++;
        total++;
    }
    freq1[k-dist]=0;
    freq2[k-dist]=0;
    m.insert({dist,node});
    for (pii x:graph[node]){
        if (marked[x.f]||x.f==prev) continue;
        dfs(x.f,node,dist+x.s,centroid);
    }
}

void solve(int curr){
    int temp;
    for (pii x:graph[curr]){
        if (marked[x.f]) continue;
        temp=get_centroid(x.f);
        solve(temp);
        marked[temp]=0;
    }
    
    cnt.clear();
    ll tempadd=0;
    for (pii z:graph[curr]){
        if (marked[z.f]) continue;
        m.clear();
        dfs(z.f,curr,z.s,curr);
        for (auto y:m){
            freq1[y.f]++;
            cnt.insert(y);
        }
        for (auto x:m){
            diff[x.s]-=freq1[k-x.f];
            tempadd-=freq1[k-x.f];
        }
    }
    for (auto x:cnt){
        freq2[x.f]++;
    }
    for (auto x:cnt){
        diff[x.s]+=freq2[k-x.f];
        tempadd+=freq2[k-x.f];
    }
    prob[curr]+=tempadd/2;
    total+=tempadd/2;
    for (pii x:graph[curr]){
        if (marked[x.f]) continue;
        update(x.f,curr,x.s);
    }
}

ll gcd(ll a, ll b){
    if (b==0) return a;
    return gcd(b,a%b);
}

void printans(ll x){
    if (x==0){
        cout << 0 << " / " << 1 << '\n';
        return;
    }
    cout << x/__gcd(x,total) << " / " << total/__gcd(x,total) << '\n';
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0); cout.tie(0); cout.sync_with_stdio(0);
    cin >> n >> k;
    for (int i=0,a,b,c;i<n-1;++i){
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    int start=get_centroid(1);
    //marked[start]=1;
    solve(start);
    for (int i=1;i<=n;++i){
        printans(prob[i]);
    }

}