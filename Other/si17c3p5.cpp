#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<pair<int,int>> tree[100001];
bool marked[100001];
int subsize[100001];
bool centroids[100001];

int dfs2(int node, int prev){
    subsize[node]=1;
    for (auto&&x:tree[node]){
        if (marked[x.first]||x.first==prev) continue;
        subsize[node]+=dfs2(x.first,node);
    }
    return subsize[node];
}

int find_centroid(int node, int prev, int size){
    for (auto&&x:tree[node]){
        if (marked[x.first]||x.first==prev) continue;
        if (subsize[x.first]>size/2) return find_centroid(x.first,node,size);
    }
    return node;
}

int get_centroid(int node){
    dfs2(node,0);
    int centroid = find_centroid(node,0,subsize[node]);
    marked[centroid]=true;
    return centroid;
}

void dfs(int node, int prev, int edges, int balance, map<int,int> &m,ll &total){
    m[balance]++;
    if (abs(balance)==1&&edges!=1){total++;}
    for (auto&&x:tree[node]){
        if (x.first==prev||centroids[x.first]) continue;
        dfs(x.first,node,edges+1,balance+x.second,m,total);
    }
}
ll uwu(int node){
    map<int,int> owo;
    map<int,int> m;
    ll total=0;
    for (auto&&x:tree[node]){
        if (centroids[x.first]) continue;
        m.clear();
        dfs(x.first,0,1,x.second,m,total);
        for (auto&&y:m){
            total+=y.second*owo[1-y.first];
            total+=y.second*owo[-1-y.first];
        }
        for (auto&&y:m){
            owo[y.first]+=y.second;
        }
    }
    return total;
}
ll solve(int node){
    int temp;
    ll ans=0;
    for (auto&&x:tree[node]){
        if (centroids[x.first]) continue;
        temp=get_centroid(x.first);
        centroids[temp]=1;
        ans+=solve(temp);
        centroids[temp]=0;
    }
    ans+=uwu(node);
    return ans;
}
int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n; cin >> n;
    int a,b; char c;
    for (int i=0;i<n-1;++i){
        cin >> a >> b >> c;
        tree[a].push_back({b,(c=='r')*2-1}); //red=1, blue=-1
        tree[b].push_back({a,(c=='r')*2-1});
    }
    int start=get_centroid(1);
    centroids[start]=true;
    cout << solve(start) << '\n';
}