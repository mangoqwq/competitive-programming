#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;
struct Cow{int x; bool i;};

bool cmp(Cow a, Cow b){return a.x<b.x;}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n; cin >> n;
    vector<Cow> arr;
    for (int i=0,a,b;i<n;++i){
        cin >> a >> b;
        arr.push_back({a,b});
    }
    if (n==1){
        cout << 1 << '\n';
        return 0;
    }
    sort(arr.begin(),arr.end(),cmp);
    int r=0x3f3f3f3f;
    if (arr[0].i&&!arr[1].i) r=min(r,arr[1].x-arr[0].x-1);
    for (int i=1;i<arr.size()-1;++i){
        if (arr[i].i&&!arr[i+1].i){
            r=min(r,arr[i+1].x-arr[i].x-1);
        }
        if (arr[i].i&&!arr[i-1].i){
            r=min(r,arr[i].x-arr[i-1].x-1);
        }
    }
    if (arr[arr.size()-1].i&&!arr[arr.size()-2].i) r=min(r,arr[arr.size()-1].x-arr[arr.size()-2].x-1);
    //cout << '\n';
    int prev=-0x3f3f3f3f; int cnt=1;
    for (int i=0;i<arr.size();++i){
        if (!arr[i].i) continue;
        if (prev==-0x3f3f3f3f){
            prev=arr[i].x;
            continue;
        }
        if (arr[i].x-prev>r){
            //cout << prev << " " << arr[i].x << '\n';
            cnt++;
        }
        prev=arr[i].x;
    }
    cout << cnt << '\n';


}