#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

int n,h,w;
string uwu;
deque<string> q;

bool padding(string x){
    for (char e:x){
        if (e=='*') return false;
    }
    return true;
}

int cnt(string x){
    int ans=0;
    for (char e:x){
        ans+=e=='*';
    }
    return ans;
}

void info(int &l,int &r){
    l=10000; r=-1;
    for (int i=0;i<q.front().size();++i){
        if (q[0][i]=='*'){
            l=min(l,i); r=max(r,i);
        }
    }
    l--; r++;
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        cin >> n;
        for (int _=0;_<n;++_){
            cin >> h >> w;
            q.clear();
            for (int i=0;i<h;++i){cin >> uwu; q.push_back(uwu);}
            while (padding(q.front())) q.pop_front();
            while (padding(q.back())) q.pop_back();
            int last=q.size()-1;
            int l,r;
            info(l,r);
            bool high,mid,low,hori;
            high=cnt(q[0]);
            mid=cnt(q[q.size()/2]);
            low=cnt(q[last]);
            bool c1,c2,c3,c4;
            c1=q[1][l]=='*';
            c2=q[last-1][l]=='*';
            c3=q[1][r]=='*';
            c4=q[last-1][r]=='*';
            if (cnt(q[0])==2&&cnt(q.back())==1&&mid){
                cout << 4;
                continue;
            }
            if (cnt(q[last])==1&&q[1][r]=='*'&&c3&&!c1&&!mid){
                cout << 7;
                continue;
            }
            if (cnt(q[0])==1&&cnt(q[1])==1&&!mid){
                cout << 1;
                continue;
            }
            if (c1&&c2&&c3&&c4&&high&&!mid&&low){
                cout << 0;
                continue;
            }
            if (c1&&c2&&c3&&c4&&high&&mid&&low){
                cout << 8;
                continue;
            }
            if (!c1&&c2&&c3&&!c4&&high&&mid&&low){
                cout << 2;
                continue;
            }
            if (!c1&&!c2&&c3&&c4&&high&&mid&&low){
                cout << 3;
                continue;
            }
            if (c1&&!c2&&!c3&&c4&&high&&mid&&low){
                cout << 5;
                continue;
            }
            if (c1&&c2&&!c3&&c4&&high&&mid&&low){
                cout << 6;
                continue;
            }
            if (c1&&!c2&&c3&&c4&&high&&mid&&low){
                cout << 9;
                continue;
            }
            if (c3){
                cout << 7;
                continue;
            }
            cout << 1;
        }
        cout << '\n';
    }
}