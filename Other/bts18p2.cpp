#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1000001;
int freq[27][MAXN];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    string uwu; getline(cin,uwu);
    uwu=" "+uwu;
    for (int i=1;i<uwu.size();++i){
        for (int k=0;k<=25;++k){
            freq[k][i]=freq[k][i-1];
        }
        if (uwu[i]==' ') continue;
        freq[uwu[i]-'a'][i]++;
    }
    int q;
    cin >> q;
    int a,b; char c;
    for (int i=0;i<q;++i){
        cin >> a >> b >> c;
        cout << freq[c-'a'][b]-freq[c-'a'][a-1] << '\n';
    }
}