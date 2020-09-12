#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

// Binary indexed tree with coordinate compression

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e5+1;

int bit[MAXN]; map<int,int> m;

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n; cin >> n;
    vector<int> arr(n);
    priority_queue<int> pq;
    for (int i=0;i<n;++i){
        cin >> arr[i];
        pq.push(arr[i]);
    }
    int temp=1;
    while (!pq.empty()){
        m[pq.top()]=temp++;
        pq.pop();
    }
    double ave=n;
    for (int x:arr){
        for (int i=m[x];i<MAXN;i+=i&-i){bit[i]++;}
        for (int i=m[x]-1;i>0;i-=i&-i){ave+=bit[i];}
    }
    printf("%.2f",ave/n);

}