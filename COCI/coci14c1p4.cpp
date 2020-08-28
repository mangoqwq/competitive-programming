#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MN = 5e5+5;
int N,res;
int arr [MN], freq[MN];
bool vis [MN];
void dfs(int x, bool civ){
    if(vis[x])return;
    vis[x]=true;
    freq[arr[x]]--;
    if(!civ)res++;
    if(freq[arr[x]]==0 || !civ){
        dfs(arr[x],!civ);
    }
}
int main() {
    cin >> N;
    for(int i = 1;i<=N;i++){
        cin >> arr[i];
        freq[arr[i]]++;
    }
    for(int i = 1;i<=N;i++){
        if(freq[i]==0){
            dfs(i,false);
        }
    }
    for(int i = 1;i<=N;i++){
        dfs(i,true);
    }
    cout << res << '\n';
}