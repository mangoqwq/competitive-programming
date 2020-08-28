#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

// hard coding :(

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

map<char,string> m;

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    string uwu;
    getline(cin,uwu);
    m[' ']="......";
    m['A']="o.....";
    m['B']="o.o...";
    m['C']="oo....";
    m['D']="oo.o..";
    m['E']="o..o..";
    m['F']="ooo...";
    m['G']="oooo..";
    m['H']="o.oo..";
    m['I']=".oo...";
    m['J']=".ooo..";
    m['K']="o...o.";
    m['L']="o.o.o.";
    m['M']="oo..o.";
    m['N']="oo.oo.";
    m['O']="o..oo.";
    m['P']="ooo.o.";
    m['Q']="ooooo.";
    m['R']="o.ooo.";
    m['S']=".oo.o.";
    m['T']=".oooo.";
    m['U']="o...oo";
    m['V']="o.o.oo";
    m['W']=".ooo.o";
    m['X']="oo..oo";
    m['Y']="oo.ooo";
    m['Z']="o..ooo";
    string a;
    string b;
    string c;
    for (char x:uwu){
        a+=m[x].substr(0,2);
        b+=m[x].substr(2,2);
        c+=m[x].substr(4,2);
    }
    cout << a << '\n' << b << '\n' << c << '\n';


}