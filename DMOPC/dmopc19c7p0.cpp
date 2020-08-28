#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    double a,b,c,d;
    cin >> a >> b >> c >> d;
    cout << setprecision(10) << (a+b)/2 << '\n';
    cout << setprecision(10) << (a+c)/2 << '\n';
    cout << setprecision(10) << (a+d)/2 << '\n';
    cout << setprecision(10) << (b+c)/2 << '\n';
    cout << setprecision(10) << (b+d)/2 << '\n';
    cout << setprecision(10) << (c+d)/2 << '\n';
    cout << setprecision(10) << (a+b+c)/3 << '\n';
    cout << setprecision(10) << (a+b+d)/3 << '\n';
    cout << setprecision(10) << (a+c+d)/3 << '\n';
    cout << setprecision(10) << (b+c+d)/3 << '\n';
    cout << setprecision(10) << (a+b+c+d)/4 << '\n';
}