#include <bits/stdc++.h>

using namespace std;
map<string,int> m;
int parent[100001];

int findparent(int x){
    if (x==parent[x]){
        return x;
    }
    return parent[x]=findparent(parent[x]);
}

void unionsets(int a, int b){
    parent[findparent(a)]=findparent(b);
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    for (int _=0;_<5;++_){
        int n; cin >> n;
        char q; string a,b; 
        for (int i=0;i<100001;++i){
            parent[i]=i;
        }
        m.clear();
        int index=1;
        for (int i=0;i<n;++i){
            cin >> q >> a >> b;
            if (m.find(a)==m.end()){
                m[a]=index; ++index;
            }
            if (m.find(b)==m.end()){
                m[b]=index; ++index;
            }
            if (q=='p'){
                unionsets(m[a],m[b]);
            }
            else if (q=='q'){
                if (findparent(m[a])==findparent(m[b])){
                    cout << "connected" << '\n';
                }
                else{
                    cout << "not connected" << '\n';
                }
            }
        }
    }
}