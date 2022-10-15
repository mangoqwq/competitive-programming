#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll ans=0; int nodes; 
int degree[2001];
vector<int> graph[2001];

ll choose(int n, int k)  
{  
    ll res = 1;  
  
    // Since C(n, k) = C(n, n-k)  
    if ( k > n - k )  
        k = n - k;  
  
    // Calculate value of  
    // [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]  
    for (int i = 0; i < k; ++i)  
    {  
        res *= (n - i);  
        res /= (i + 1);  
    }  
  
    return res;  
}  
  
ll valid(int node, int children, int depth, int prev){
    if (depth==1){
        //cout << ": " << choose(degree[node]-1,children) << " " << children << degree[node]-1 << '\n';
        return choose(degree[node]-1,children);
    }
    if (depth==0){
        return 1;
    }
    int count=0;
    ll result=1;
    for (auto&&x:graph[node]){
        if (x!=prev && degree[x]>children){
            result*=valid(x,children,depth-1,node);
            count++;
        }
    }
    if (count<children){
        return 0;
    }
    return result;


}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> nodes;
    for (int i=0,a,b;i<nodes-1;++i){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        degree[a]++; degree[b]++;
    }
    for (int i=1;i<nodes+1;++i){
        ans+=pow(2,degree[i])-degree[i];
    }
    for (int node=1;node<nodes+1;++node){
        for (int children=2;children<=degree[node];++children){
            for (int depth=2;depth<11;++depth){
                ans+=valid(node,children,depth,0);
                ans%=mod;
            }
        }
    }
    cout << ans << '\n';
    
}