#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e4+1;

vector<int> arr[3];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1,a;i<=n;++i){
        cin >> a;
        arr[a%3].push_back(a);
    }
    if (n%2==0&&arr[0].size()*2>n) cout << "impossible\n";
    else if (n%2==1&&arr[0].size()>n/2+1) cout << "impossible\n";
    else if (arr[0].size()==0){
        if (arr[1].size()&&arr[2].size()) cout << "impossible\n";
        else{
            for (int x:arr[1]) cout << x << " ";
            for (int x:arr[2]) cout << x << " ";
            cout << '\n';
        }
    } 
    else{
        int temp=arr[0].back(); arr[0].pop_back();
        for (int x:arr[1]){
            if (!arr[0].empty()) cout << arr[0].back() << " ", arr[0].pop_back();
            cout << x << " ";
        }
        cout << temp << " ";
        for (int x:arr[2]){
            cout << x << " ";
            if (!arr[0].empty()) cout << arr[0].back() << " ", arr[0].pop_back();
        }
        cout << '\n';
    }
}