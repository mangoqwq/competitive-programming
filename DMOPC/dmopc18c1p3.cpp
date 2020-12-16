#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=101;

int arr[MAXN];
vector<int> one, two;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, loops=0; cin >> n;
    for (int i=1;i<=n;++i) cin >> arr[i];
    for (int i=1;i<=n;++i){
        if (arr[i]==i) arr[i]=0;
        if (arr[i]==0) continue;
        loops++;
        for (int j=i,a;arr[j]!=0;j=a){
            a=arr[j];
            arr[j]=0;
            one.push_back(j);
            if (a==i) two.push_back(i);
        }
    }
    reverse(two.begin(),two.end());
    cout << min(loops,2) << '\n';
    if (loops>=1){
        cout << one.size() << " ";
        for (int x:one) cout << x << " ";
        cout << '\n';
    }
    if (loops>=2){
        cout << two.size() << " ";
        for (int x:two) cout << x << " ";
        cout << '\n';
    }
}