#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int lim=100001,len=317;
bool sq[2001][len];
int s[len];
int arr[lim];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n,k,q; cin >> n >> k >> q;
    for (int i=1;i<=n;++i){
        cin >> arr[i];
        s[i/len]+=arr[i];
        sq[arr[i]+1000][i/len]=true;
    }
    int a,b,l,r;
    while (q--){
        cin >> a >> b >> l >> r;
        bool aa=false;
        bool bb=false;
        int total=0;
        for (int i=l;i<=r;){
            if (i%len==0&&i+len-1<r){
                total+=s[i/len];
                if (sq[a+1000][i/len]) aa=true;
                if (sq[b+1000][i/len]) bb=true;
                i+=len;
            }
            else{
                if (arr[i]==a) aa=true;
                if (arr[i]==b) bb=true;
                total+=arr[i];
                ++i;
            }
        }
        if (aa&&bb&&total>k) cout << "Yes\n";
        else cout << "No\n";
    }
}