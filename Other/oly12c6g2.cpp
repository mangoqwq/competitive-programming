#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
vector<pii> tree[100001];
int subsize[100001];
bool marked[100001];
bool centroids[100001];
map<int,int> visited;

int dfs2(int node, int prev){
    subsize[node]=1;
    for (auto&&x:tree[node]){
        if (marked[x.first]||x.first==prev)continue;
        subsize[node]+=dfs2(x.first,node);
    }
    return subsize[node];
}

int find_centroid(int node,int prev, int size){
    for (auto&&x:tree[node]){
        if (marked[x.first]||x.first==prev) continue;
        if (subsize[x.first]>size/2) return find_centroid(x.first,node,size);
    }
    return node;
}

int get_centroid(int node){
    dfs2(node,0);
    int centroid=find_centroid(node,0,subsize[node]);
    marked[centroid]=1;
    return centroid;
}
void dfs(int node, int prev,int path,map<int,ll> &one,map<int,ll> &two){
    if (visited[path]==0){
        one[path]++;
    }else{
        two[path]++;
    }
    visited[path]++;
    for(auto&&x:tree[node]){
        if (centroids[x.first]||x.first==prev) continue;
        dfs(x.first,node,path+x.second,one,two);
    }
    visited[path]--;
}

ll owo(int node){
    ll total=0;
    map<int,ll> uwu1;
    map<int,ll> uwu2;
    for (auto&&x:tree[node]){
        if (centroids[x.first]) continue;
        map<int,ll> one;
        map<int,ll> two;
        dfs(x.first,node,x.second,one,two);
        total+=one[0]*uwu1[0];
        total+=two[0]*(uwu1[0]+1);
        uwu1[0]+=two[0]+one[0];
        one[0]=0;
        two[0]=0;
        for (auto&&y:one){
            total+=uwu2[-y.first]*y.second;   
        }
        for (auto&&y:two){
            total+=(uwu2[-y.first]+uwu1[-y.first])*y.second;
        }
        for (auto&&y:one){
            uwu1[y.first]+=y.second;
        }
        for (auto&&y:two){
            uwu2[y.first]+=y.second;
        }
    }
    //cout << uwu1[0] << " AA " << node << '\n';
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
    ans+=owo(node);
    return ans;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n; cin >>n;
    for (int i=0,a,b,c;i<n-1;++i){
        cin >> a >> b >> c;
        tree[a].push_back({b,c*2-1});
        tree[b].push_back({a,c*2-1});
    }
    int start=get_centroid(1);
    centroids[start]=1;
    cout << solve(start)<<'\n';
    
}