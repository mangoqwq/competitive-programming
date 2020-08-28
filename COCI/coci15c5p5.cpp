#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int seed=131;
map<ll,int> m[3000001];
ll exponent[3000001];
ll substring;


int main(){
    exponent[0]=1;
    for (int i=0;i<3000001;++i){
        exponent[i+1]=exponent[i]*seed;
    }
    int n,q; cin >> n >> q;
    string uwu;
    for (int _=0;_<n;++_){
        cin >> uwu;
        substring=0;
        for (int i=1;i<=uwu.length();++i){
            substring=substring*seed+uwu[i-1];
            m[i][substring]++;
        }
    }
    int position,ans;
    for (int _=0;_<q;++_){
        cin >> uwu;
        substring=0;
        ans=0;
        for (int i=1;i<=uwu.length();++i){
            substring=substring*seed+uwu[i-1];
            if (uwu[i-1]=='*'){
                position=i-1;
            }
        }
        for (int i=97;i<=122;++i){
            ans+=m[uwu.length()][substring-'*'*exponent[position]+i*exponent[position]];
            cout << (char)i << ":" << ans << '\n';
        }
        for (int i=1;i<=uwu.length();++i){
            if (uwu[i-1]=='*'){
                i++;
            }
            substring=substring*seed+uwu[i-1];
        }
        ans+=m[uwu.length()-1][substring];
        cout << ans << '\n';
    }
}