#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define is(x) (!op.count(x))
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e6+1;

set<char> op={'+','-','*','/','%'};
struct{ int val; bool num; } s[MAXN];

int calc(int a, int b, char op){
    //cout << a << " " << op << " " << b << '\n';
    if (op=='+') return a+b;
    if (op=='-') return a-b;
    if (op=='*') return a*b;
    if (op=='/') return a/b;
    return (a+b*MAXN)%b;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t=5;
    while (t--){
        string cmd; getline(cin,cmd);
        int p=0;
        if (!is(cmd[0])){ // prefix
            for (char x:cmd){
                if (x==' ') continue;
                if (!is(x)) s[++p]={x,0};
                else s[++p]={x-'0',1};
                while (p>=3&&s[p].num&&s[p-1].num&&!s[p-2].num){
                    s[p-2]={calc(s[p-1].val,s[p].val,s[p-2].val),1};
                    p-=2;
                }
            }
        }
        else{ // postfix
            for (char x:cmd){
                if (x==' ') continue;
                if (!is(x)) s[++p]={x,0};
                else s[++p]={x-'0',1};
                while (p>=3&&!s[p].num&&s[p-1].num&&s[p-2].num){
                    s[p-2]={calc(s[p-2].val,s[p-1].val,s[p].val),1};
                    p-=2;
                }
            }
        }
        cout << s[1].val << '\n';
    }
}