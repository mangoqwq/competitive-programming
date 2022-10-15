#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;
struct segment{double l,r;};
bool cmp(segment a, segment b){return a.l<b.l;}
vector<segment> arr;

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n; cin >> n;
    double l,r,x,y; cin >> l >> r >> x >> y;
    double int1,int2,x1,y1,temp; 
    for (int i=0;i<n;++i){
        cin >> x1 >> y1;
        temp=x+((x-x1)/-(y-y1))*y;
        int1=min(max(temp,l),r);

        cin >> x1 >> y1;
        temp=x+((x-x1)/-(y-y1))*y;
        int2=min(max(temp,l),r);
        arr.push_back({min(int1,int2),max(int1,int2)});

        //cout << int1 << " " << int2 << '\n';
    }
    sort(arr.begin(),arr.end(),cmp);
    double currl=arr[0].l,currr=arr[0].r;
    double ans=currl-l;
    for (int i=1;i<arr.size();++i){
        if (arr[i].l>currr){
            ans+=arr[i].l-currr;
            currr=arr[i].r;
            continue;
        }
        currr=max(currr,arr[i].r);
    }
    ans+=r-currr;
    cout << ans << '\n';
}