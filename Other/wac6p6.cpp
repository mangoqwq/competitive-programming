#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=0;

map<char,int> m={{'R',0},{'G',1},{'B',2}};
char C; int x;

void get(){ cin >> C; x=m[C]; }

int main(){
    // cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int a, b, c; cin >> a >> b >> c;

        int lock1=-1, lock2=-1;
        int cnt[3]={0};

        vector<int> tempsort = {a,b,c};
        sort(tempsort.begin(),tempsort.end());
        a=tempsort[0], b=tempsort[1], c=tempsort[2];

        if (a+b>=43){
            for (int i=1;i<=100;++i){
                get();
                if (C=='-') return 0;
                if (x==lock1) cout << "PLACE 1" << '\n';
                else if (x==lock2) cout << "PLACE 2" << '\n';
                else if (lock1==-1) cout << "PLACE 1" << '\n', lock1=x;
                else if (lock2==-1) cout << "PLACE 2" << '\n', lock2=x;
                else cout << "DISCARD" << '\n';
            }
        }
        else if (a<=19){
            for (int i=1;i<=100;++i){
                get();
                if (C=='-') return 0;
                cnt[x]++;
                if (x==lock1) cout << "PLACE 1" << '\n';
                else if (x==lock2) cout << "PLACE 2" << '\n';
                else{
                    if (cnt[x]>a){
                        if (lock1==-1) cout << "PLACE 1" << '\n', lock1=x;
                        else if (lock2==-1) cout << "PLACE 2" << '\n', lock2=x;
                        else cout << "DISCARD" << '\n';
                    }
                    else cout << "DISCARD" << '\n';
                }
            }    
        }
        else{
            lock1=0;
            lock2=1;
            bool changed=false;
            for (int i=1;i<=100;++i){
                get();
                if (C=='-') return 0;
                cnt[x]++;
                if (!changed&&cnt[x]>b){
                    changed=true;
                    cout << "EMPTY 1" << '\n';
                    lock1=x;
                }
                if (x==lock1) cout << "PLACE 1" << '\n';
                else if (x==lock2) cout << "PLACE 2" << '\n';
                else cout << "DISCARD" << '\n';
            }
        }
    }
}