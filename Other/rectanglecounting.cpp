#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

// Main ideas: Binary indexed tree, line sweep

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=200001,YMAX=1000010;
struct Line{
    int l,u,x,id; bool end;
};
vector<Line> arr;
int bit[2][YMAX]; //0 for low, 1 for high
void update(int index,int uwu,int val){
    for (int i=index;i<YMAX;i+=(i&-i)){
        bit[uwu][i]+=val;
    }
}
int query(int index,int uwu){
    int ans=0;
    for (int i=index;i>0;i-=(i&-i)){
        ans+=bit[uwu][i];
    }
    return ans;
}
int disjoint(Line &x){
    int ans=0;
    ans+=(query(x.l,1));
    ans+=(query(YMAX,0)-query(x.u-1,0));
    //cout << x.id << " " << ans << '\n';
    return ans;
}
bool cmp(Line a, Line b){
    return make_pair(a.x,!a.end)<make_pair(b.x,!b.end);
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1,a,b,c,d;i<=n;++i){
        cin >> a >> b >> c >> d;
        arr.push_back({b,d,a,i,0});
        arr.push_back({b,d,c,i,1});
    }
    sort(arr.begin(),arr.end(),cmp);
    ll count=0; int active=0;
    for (Line curr:arr){
        if (curr.end){
            active--;
            update(curr.l,0,-1);
            update(curr.u,1,-1);
            continue;
        }
        count+=active-disjoint(curr);
        update(curr.l,0,1);
        update(curr.u,1,1);
        active++;
    }
    cout << count << '\n';

}