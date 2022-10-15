#include <bits/stdc++.h>

using namespace std;
int owo[1000001];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    long long n,k; cin >> n >> k;
    long long subarrays=0; int unique=0,curr=0;
    queue<int> q;
    for (int i=0,a;i<n;++i){
        cin >> a;
        if (owo[a]==0){
            unique++;
        }
        q.push(a);
        curr++;
        owo[a]++;
        while (unique==k){
            owo[q.front()]--;
            curr--;
            if (owo[q.front()]==0){
                unique--;
            }
            q.pop();
        }
        subarrays+=curr;
    }
    cout << (((n*n+n)/2) - subarrays) << '\n';
    
}