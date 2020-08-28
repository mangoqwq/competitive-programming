#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1001;

bool grid[MAXN][MAXN];
bool rhas[MAXN];
bool chas[MAXN];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    // 1 is black, 0 is white
    int row,col; cin >> row >> col;
    char temp;
    for (int i=1;i<=row;++i){
        for (int k=1;k<=col;++k){
            cin >> temp;
            grid[i][k]=(temp=='#');
            chas[k]|=(temp=='#');
            rhas[i]|=(temp=='#');
        }
    }
    for (int r=1;r<=row;++r){
        
    }
    for (int c=1;c<=col;++c){

    }

}