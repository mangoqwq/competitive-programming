#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN=200001;
vector<int> graph[MAXN];
int n,k,colours[MAXN],subsize[MAXN],answer=0;
bool marked[MAXN],centroids[MAXN];

int getsubsize(int node, int prev){
    subsize[node]=1;
    for (auto&&x:graph[node]){
        if (x==prev||marked[node]) continue;
        subsize[node]+=getsubsize(x,node);
    }
    return subsize[node];
}

int find_centroid(int node,int prev,int size){
    for (auto&&x:graph[node]){
        if (x==prev||marked[x]) continue;
        if (subsize[x]*2>size) return find_centroid(x,node,size);
    }
    return node;
}

int get_centroid(int node){
    getsubsize(node,0);
    int centroid=find_centroid(node,0,subsize[node]);
    marked[centroid]=true;
    return centroid;
}

void dfs(int node, int prev, int prev2, int dist, int stripel, int currl, bool check, map<int,int> &owo){
    if (colours[node]==colours[prev2]){
        if (check) stripel++;
        currl++;
    }else{
        check=false;
        currl=1;
    }
    if (currl>=k){
        
        return;
    }
    owo[stripel]=max(owo[stripel],dist);
    for (auto&&x:graph[node]){
        if (x==prev||centroids[x]) continue;
        dfs(x,node,prev,dist+1,stripel,currl,check,owo);
    }

}

void solve(int node){
    int temp;
    for (auto&&x:graph[node]){
        if (centroids[x]) continue;
        temp=get_centroid(x);
        centroids[temp]=1;
        solve(temp);
        centroids[temp]=0;
    }
    map<int,int> d;
    map<int,map<int,int>> s;
    for (auto&&x:graph[node]){
        s[colours[x]][MAXN+1]=-1;
        if (centroids[x]) continue;
        map<int,int> owo;
        dfs(x,node,x,1,0,0,true,owo);
        vector<pii> arr;
        for (auto&&y:owo){
            arr.push_back(y);
        }
        int index=arr.size()-1,maximum=0;
        for (auto&&y:s[colours[x]]){
            while (index>=0){
                if (arr[index].first+y.first>=k){
                    answer=max(answer,maximum+arr[index].second);
                    index--;
                }else{break;}
            }
            maximum=max(maximum,y.second);
            if (index<0) break;
        }
        for (auto&&y:arr){
            s[colours[x]][y.first]=max(s[colours[x]][y.first],y.second);
            d[colours[x]]=max(d[colours[x]],y.second);
        }
    }
    priority_queue<int> pq;
    for (auto&&x:d){
        pq.push(x.second);
    }
    if (pq.size()<2){
        return;
    }
    temp=pq.top(); pq.pop(); temp+=pq.top();
    answer=max(answer,temp);
}


int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> k; k--;
    for (int i=1;i<=n;++i) cin >> colours[i];
    for (int i=1,a,b;i<n;++i){
        cin >> a >> b;
        graph[a].push_back(b); graph[b].push_back(a);
    }
    int start=get_centroid(1);
    centroids[start]=1;
    solve(start);
    cout << answer+1 << '\n';
}