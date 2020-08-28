#include <bits/stdc++.h>
typedef long long ll;

// centroid decomp

using namespace std;
vector<int> graph[400001];
int subsize[400001];
bool marked[400001];
bool centroids[400001];
int len=-1;

int dfs2(int node, int prev){
    subsize[node]=1;
    for (auto&&x:graph[node]){
        if (marked[x]||x==prev) continue;
        subsize[node]+=dfs2(x,node);
    }
    return subsize[node];
}

int find_centroid(int node, int prev, int size){
    for (auto&&x:graph[node]){
        if (marked[x]||x==prev) continue;
        if (subsize[x]>size/2) return find_centroid(x,node,size);
    }
    return node;
}
int get_centroid(int node){
    dfs2(node,0);
    int centroid = find_centroid(node,0,subsize[node]);
    marked[centroid]=1;
    return centroid;
}

void dfs(int node, int prev, int length, map<int,ll> &m){
    bool leaf=true;
    for (auto&&x:graph[node]){
        if (x==prev||centroids[x]) continue; //can optimize
        leaf=false;
        dfs(x,node,length+1,m);
    }
    if (leaf){
        m[length]++;
    }
}

ll owo(int node){
    ll ans=0;
    map<int,ll> total;
    for (auto&&x:graph[node]){
        if (centroids[x]) continue;
        map<int,ll> m;
        dfs(x,node,1,m);
        for (auto&&y:m){
            ans+=m[y.first]*total[len-y.first];
        }
        for (auto&&y:m){
            total[y.first]+=y.second;
        }
    }
    return ans;
}

ll solve(int node){
    int temp;
    ll ans=0;
    for (auto&&x:graph[node]){
        if (centroids[x]) continue;
        temp=get_centroid(x);
        centroids[temp]=1;
        ans+=solve(temp);
        centroids[temp]=0;
    }
    ans+=owo(node);
    return ans;
}

int main(){
    int n; cin >> n;
    for (int i=0,a,b;i<n-1;++i){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    queue<int> q; q.push(1); bool visited[n+1]={0}; int uwu;
    while (!q.empty()){
        uwu=q.front(); q.pop();
        if (!visited[uwu]){
            visited[uwu]=1;
            for (auto&&x:graph[uwu]){
                q.push(x);
            }
        }
    }
    q.push(uwu); memset(visited,0,sizeof visited);
    while (!q.empty()){
        int qsize=q.size();
        len++;
        for (int i=0;i<qsize;++i){
            uwu=q.front(); q.pop();
            if (!visited[uwu]){
                visited[uwu]=1;
                for (auto&&x:graph[uwu]){
                    q.push(x);
                }
            }
        }
    }
    int centroid=get_centroid(1);
    centroids[centroid]=1;
    cout << len+1 << " " << solve(centroid) << '\n';

    
}