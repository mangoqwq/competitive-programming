#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        string uwu; cin >> uwu;
        for (int i=0;i<uwu.size();++i){
            if (uwu[i]=='a'||uwu[i]=='A'){
                cout << "Hi! ";
            }
            if (uwu[i]=='e'||uwu[i]=='E'){
                cout << "Bye! ";
            }
            if (uwu[i]=='i'||uwu[i]=='I'){
                cout << "How are you? ";
            }
            if (uwu[i]=='o'||uwu[i]=='O'){
                cout << "Follow me! ";
            }
            if (uwu[i]=='u'||uwu[i]=='U'){
                cout << "Help! ";
            }
            if (uwu[i]-'0'>=0&&uwu[i]-'0'<=9){
                cout << "Yes! ";
            }

        }
        cout << '\n';
    }
}