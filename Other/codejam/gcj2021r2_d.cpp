#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define get(msk,i) (1&(msk>>i))
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=10;

int r, c; ll f, s; 
ll lst[1<<MAXN], dp[1<<MAXN];
int init[MAXN+1], goal[MAXN+1];
int state[MAXN], tmp[MAXN];

void readboard(){
    ms(init,0); ms(goal,0);
    for (int i=1;i<=r;++i){
        for (int j=0;j<c;++j){
            char a; cin >> a;
            if (a=='G') init[i]+=1<<j;
        }
    }
    for (int i=1;i<=r;++i){
        for (int j=0;j<c;++j){
            char a; cin >> a;
            if (a=='G') goal[i]+=1<<j;
        }
    }
}

void solve(){
    cin >> r >> c >> f >> s;
    readboard();
    // cout << '\n';
    for (int row=1;row<=r;++row){
        swap(lst,dp); ms(dp,inf);
        for (int ma=0;ma<(1<<c);++ma) for (int mb=0;mb<(1<<c);++mb){
            // 0 nothing
            // 1 flip
            // 2 swap with up
            // 3 swap with side
            for (int j=0;j<c;++j) state[j]=get(ma,j)*2+get(mb,j);
            bool valid=1; int flipw=-1, cost=0, ups=0;
            for (int i=0;i<c;++i){
                if (state[i]==0) tmp[i]=get(init[row],i);
                else if (state[i]==1) cost+=f, tmp[i]=get(init[row],i)^1;
                else if (state[i]==2){
                    ups++, cost+=s, tmp[i]=get(goal[row],i);
                    if (get(init[row],i)!=get(goal[row-1],i)){ valid=0; break; }
                }
                else if (state[i]==3){
                    if (flipw==-1) flipw=i;
                    else{
                        if (flipw!=i-1){ valid=0; break; }
                        flipw=-1;
                        cost+=s;
                        tmp[i]=get(init[row],i-1);
                        tmp[i-1]=get(init[row],i);
                    }
                }
            }
            if (flipw!=-1) valid=0;
            if (!valid) continue;
            int msk=0;
            for (int i=0;i<c;++i) if (tmp[i]) msk+=1<<i;
            int fixup=0;
            for (int i=0;i<c;++i){
                if (state[i]==2) fixup+=get(goal[row],i)?1<<i:0;
                else fixup+=get(goal[row-1],i)?1<<i:0;
            }
            if (row==1){
                if (ups) continue;
                // if (msk==goal[1]){
                //     cout << "1 -> ";
                //     for (int i=0;i<c;++i) cout << state[i] << " ";
                //     cout << cost << '\n';
                // }
                dp[msk]=min(dp[msk],(ll)cost);
            }
            else{
                // if (msk==goal[row]){
                //     cout << row << " -> ";
                //     for (int i=0;i<c;++i) cout << state[i] << " ";
                //     cout << " | " << dp[row-1][fixup] << " " << bitset<3>(fixup).to_string() << " " << cost << '\n';
                // }
                dp[msk]=min(dp[msk],lst[fixup]+cost);
            }
        }
    }
    cout << dp[goal[r]] << '\n';
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    for (int _=1;_<=t;++_){
        cout << "Case #" << _ << ": ";
        solve();
    }
}