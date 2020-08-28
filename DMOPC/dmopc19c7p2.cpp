#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define f first
#define s second
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1'000'001;

struct Ans{int a,b,c;};

vector<int> arr;
int idx,val,n,tot;

bool tryright(int x){
    int curr=0;
    for (int i=(idx+1+n)%n;i!=idx;++i,i=(i+n)%n){
        if (arr[i]-curr<0) return false;
        curr=arr[i]-curr;
    }
    if (curr==0){
        cout << "YES" << '\n' << tot/2 << '\n';
        for (int k=0;k<x;++k){
            cout << (idx-1+n)%n << " " << idx << '\n';
        }
        for (int k=0;k<val-x;++k){
            cout << (idx+1+n)%n << " " << idx << '\n';
        }
        for (int i=(idx+1+n)%n;i!=idx;++i,i=(i+n)%n){
            curr=arr[i]-curr;
            for (int k=0;k<curr;++k){
                cout << i << " " << (i+1+n)%n << '\n';
            }
        }
    }
    return (curr==0);
}

bool tryleft(int x){
    int curr=0;
    for (int i=(idx-1+n)%n;i!=idx;--i,i=(i+n)%n){
        if (arr[i]-curr<0) return false;
        curr=arr[i]-curr;
    }
    if (curr==0){
        cout << "YES" << '\n' << tot/2 << '\n';
        for (int k=0;k<x;++k){
            cout << (idx-1+n)%n << " " << idx << '\n';
        }
        for (int k=0;k<val-x;++k){
            cout << (idx+1+n)%n << " " << idx << '\n';
        }
        for (int i=(idx-1+n)%n;i!=idx;--i,i=(i+n)%n){
            curr=arr[i]-curr;
            for (int k=0;k<curr;++k){
                cout << i << " " << (i-1+n)%n << '\n';
            }
        }
    }
    return (curr==0);
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    pii t={0x3f3f3f3f,0x3f3f3f3f};
    for (int i=1,a;i<=n;++i){
        cin >> a;
        arr.push_back(a);
        tot+=a; t=min(t,make_pair(a,i-1));
    }
    idx=t.s, val=t.f;
    arr[idx]=0;
    int &l=arr[(idx-1+n)%n],&r=arr[(idx+1+n)%n];
    r-=val;
    for (int i=0;i<=val;++i,--l,++r){
        if (tryright(i)){
            return 0;
        }
        if (tryleft(i)){
            return 0;
        }
    }
    cout << "NO" << '\n';
}