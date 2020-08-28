#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

// Centroid decomposition, Binary indexed tree, Line sweep

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=2000001;

int n,lk,lc,rk,rc; ll ans;
vector<int> graph[MAXN];
int ss[MAXN],bit[MAXN+1]; //1 is 0, 2 is 1...
bool marked[MAXN],centroids[MAXN];
char t[MAXN]; //kinako bread is 0, croissant is 1

bool eat(int k,int c){
    return ((lk<=k&&k<=rk)&&(lc<=c&&c<=rc));
}

bool cmp(pii &a, pii &b){return a>b;}

void update(int index,int val){
    index++;
    for (int i=index;i<MAXN;i+=(i&-i)){
        bit[i]+=val;
    }
}

int query(int index){
    int answer=0; index++;
    if (index<=0) return 0;
    for (int i=index;i>0;i-=(i&-i)){
        answer+=bit[i];
    }
    return answer;
}

int get_subsizes(int node,int prev){
    //cout << node << " ";
    ss[node]=1;
    for (int &x:graph[node]){
        if (x==prev||marked[x]) continue;
        ss[node]+=get_subsizes(x,node);
    }
    return ss[node];
}

int find_centroid(int node, int prev, int size){
    for (int &x:graph[node]){
        if (x==prev||marked[x]) continue;
        if (ss[x]*2>size) return find_centroid(x,node,size);
    }
    return node;
}

int get_centroid(int node){
    get_subsizes(node,0);
    int centroid=find_centroid(node,0,ss[node]);
    marked[centroid]=1;
    return centroid;
}

void dfs(int node, int prev, int k, int c, vector<pii> &a){
    if (t[node]=='K') k++;
    if (t[node]=='C') c++;
    if (k>rk||c>rc) return;
    if (eat(k,c)){ans++;}
    a.push_back({k,c});
    for (int &x:graph[node]){
        if (x==prev||centroids[x]) continue;
        dfs(x,node,k,c,a);
    }
}

void solve(int curr){
    //cout << curr << " ";
    int temp;
    for (int &x:graph[curr]){
        if (centroids[x]) continue;
        temp=get_centroid(x);
        centroids[temp]=1;
        solve(temp);
        centroids[temp]=0;
    }
    if (eat(t[curr]=='K',t[curr]=='C')) ans++;
    
    vector<pii> arr;
    vector<pii> a;
    ll tempans=0;
    for (int &x:graph[curr]){
        if (centroids[x]) continue;
        a.clear();
        dfs(x,curr,t[curr]=='K',t[curr]=='C',a);
        if (t[curr]=='K'){
            lk++; rk++;
        }
        else{
            lc++; rc++;
        }
        sort(a.begin(),a.end());
        int pl=0, pr=0;
        for (int i=a.size()-1;i>=0;--i){
            pii &p=a[i];
            while (pr<a.size()){
                
                if (a[pr].first+p.first<=rk){
                    update(a[pr].second,1); pr++;
                }else break;
            }
            while (pl<a.size()){
                
                if (a[pl].first+p.first<lk){
                    update(a[pl].second,-1); pl++;
                }else break;
            }
            tempans-=query(rc-p.second)-query(lc-p.second-1);
            // if (t[curr]=='K') p.first--;
            // else p.second--;
        }
        for (int i=pl;i<pr;++i){
            update(a[i].second,-1);
        }
        for (pii &p:a){
            arr.push_back(p);
        }
            if (t[curr]=='K'){
            lk--; rk--;
        }
        else{
            lc--; rc--;
        }
    }
    if (t[curr]=='K'){
        lk++; rk++;
    }
    else{
        lc++; rc++;
    }
    //arr.push_back({0,0});
    sort(arr.begin(),arr.end());
    int pl=0, pr=0;
    for (int i=arr.size()-1;i>=0;--i){
        pii &p=arr[i];
        while (pr<arr.size()){
            if (arr[pr].first+p.first<=rk){
                update(arr[pr].second,1); pr++;
            }else break;
        }
        while (pl<arr.size()){
            if (arr[pl].first+p.first<lk){
                update(arr[pl].second,-1); pl++;
            }else break;
        }
        tempans+=query(rc-p.second)-query(lc-p.second-1);
    }
    for (int i=pl;i<pr;++i){
        update(arr[i].second,-1);
    }
    ans+=(tempans/2);
    if (t[curr]=='K'){
        lk--; rk--;
    }
    else{
        lc--; rc--;
    }
}

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> lk >> rk >> lc >> rc;
    char temp;
    for (int i=1;i<=n;++i){
        cin >> temp;
        t[i]=temp;
    }
    for (int i=1,a,b;i<n;++i){
        cin >> a >> b;
        graph[a].push_back(b); graph[b].push_back(a);
    }
    int start=get_centroid(1);
    centroids[start]=1;
    solve(start);
    cout << ans << '\n';


}