#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

// Line sweep

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=200'001;

struct Point{int x,y,c,id;};
vector<Point> arr;

bool cmp(Point a, Point b){
    return make_pair(a.x,a.y)<make_pair(b.x,b.y);
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1,a,b,c;i<=n;++i){
        cin >> a >> b >> c;
        arr.push_back({a,b,c,i});
    }
    sort(arr.begin(),arr.end(),cmp);
    for (int i=0;i<n-2;++i){
        if (arr[i].c!=arr[i+1].c||arr[i+1].c!=arr[i+2].c){
            cout << arr[i].id << " " << arr[i+1].id << " " << arr[i+2].id << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
}