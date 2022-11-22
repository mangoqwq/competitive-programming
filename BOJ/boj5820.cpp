#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
vector<pii> tree[200001];
int subsize[200001];
bool marked[200001];
int ans=0x3f3f3f3f;
bool centroids[200001];

int aim;

int dfs2(int node, int prev){
    subsize[node]=1;
    for (auto&&x:tree[node]){
        if (x.first==prev||marked[x.first]) continue;
        subsize[node]+=dfs2(x.first,node);
    }
	return subsize[node];
}
int find_centroid(int node, int size, int prev){
    for (auto&&x:tree[node]){
        if (x.first==prev||marked[x.first]) continue;
        if (subsize[x.first]>size/2) return find_centroid(x.first,size,node);
    }
    return node;
}
int get_centroid(int node){
	
    dfs2(node,0);
    int centroid=find_centroid(node,subsize[node],-1);
    marked[centroid]=true;
    return centroid;
}
void dfs(int node, int length, int edges, int prev, map<int,int>&owo,map<int,int>&m){
    //cout << node << " ";
    if (length>aim) return;
    if (m.find(length)==m.end()) m[length]=edges;
    else m[length]=min(m[length],edges);
    if (owo.find(aim-length)!=owo.end()) owo[aim]=min(owo[aim-length]+edges,owo[aim]);
    for (auto&&x:tree[node]){
        if (x.first==prev||centroids[x.first]) continue;
        dfs(x.first,length+x.second,edges+1,node,owo,m);
    }
}
void dfsutil(int node,map<int,int> &owo){
    //cout << node << "->";
   
    for (auto&&x:tree[node]){
        if (centroids[x.first]) continue;
        map<int,int> m;
        dfs(x.first,x.second,1,node,owo,m);
        for (auto&&n:m){
            if (owo.find(n.first)==owo.end()) owo[n.first]=n.second;
            else owo[n.first]=min(owo[n.first],n.second);
        } 
    }
    //cout << '\n';
}

void solve(int node){
	int temp;
    for (auto&&x:tree[node]){
        if (centroids[x.first]) continue;
		temp=get_centroid(x.first);
        centroids[temp]=1;
        solve(temp);
        centroids[temp]=0;
    }
    map<int,int> owo;
    owo[aim]=0x3f3f3f3f;
    dfsutil(node,owo);
    ans=min(ans,owo[aim]);
}

int best_path(int n,int k,int h[][2],int l[]){
    aim=k;
    for (int i=0;i<n-1;++i){
        tree[h[i][0]].push_back({h[i][1],l[i]});
        tree[h[i][1]].push_back({h[i][0],l[i]});
    }
    int start=get_centroid(0);
    centroids[start]=1;
    solve(start);
    if (ans>=0x3f3f3f3f) return -1;
    return ans;
}


int main(){
	/*
    int n=11;
    int k=12;
    int h[n-1][2]={{0,1},{0,2},{2,3},{3,4},{4,5},{0,6},{6,7},{6,8},{8,9},{8,10}};
    int l[n-1]={3,4,5,4,6,3,2,5,6,7};
    cout << best_path(n,k,h,l) << '\n';
	*/

   int n; cin >> n;
   int k; cin >> k;
   int h[n-1][2];
   int l[n-1];
   for (int i=0;i<n-1;++i){
       cin >> h[i][0] >> h[i][1] >> l[i];
   }
   
   cout << best_path(n,k,h,l) << '\n';

}
