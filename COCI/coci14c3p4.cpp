#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=700;

int arr[MAXN][MAXN];
int cnt[MAXN][MAXN];
struct Uwu{int a,b;}; vector<Uwu> uwu;

int Less(Uwu x){
    int a=x.a,b=x.b;
    return arr[a-1][b-1]; 
}
int More(Uwu x){ 
    int a=x.a,b=x.b;
    return arr[651][651]-arr[651][b]-arr[a][651]+arr[a][b];
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    int edge=0,edge2=0;
    ms(arr,0);
    for (int i=1,a,b;i<=n;++i){
        cin >> a >> b; a++; b++;
        uwu.push_back({a,b});
        if (min(a,b)==1&&max(a,b)==651) edge++;
        if (a==651&&b==651) edge2++;
        cnt[a][b]++;
    }

    for (int i=1;i<=651;++i){
        for (int j=1;j<=651;++j){
            arr[i][j]=cnt[i][j]+arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1];
        }
    }
    for (Uwu x:uwu){
        int temp=0;
        if (x.a==651) temp+=cnt[1][x.b];
        if (x.b==651) temp+=cnt[x.a][1];
        cout << 1+More(x) << " " << n-Less(x)-temp << '\n';
    }
}