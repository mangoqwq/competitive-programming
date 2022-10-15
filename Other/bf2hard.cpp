#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

struct SAM{
    struct Node{
        int link=-1, len=0;
        map<char,int> nxt;
    };
    vector<Node> a;
    int last;
    SAM(string s){
        last=0;
        a.push_back(Node());
        for (char c:s) extend(c);
    }
    void extend(char c){
        int n=a.size(), p=last; a.push_back(Node());
        last=n;
        a[n].len=a[p].len+1;
        while (p!=-1&&!a[p].nxt.count(c)){
            a[p].nxt[c]=n;
            p=a[p].link;
        }
        if (p==-1) return void(a[n].link=0);
        int q=a[p].nxt[c];
        if (a[q].len==a[p].len+1) a[n].link=q;
        else{
            int cl=a.size(); a.push_back(a[q]);
            a[cl].len=a[p].len+1;
            while (p!=-1&&a[p].nxt[c]==q){
                a[p].nxt[c]=cl;
                p=a[p].link;
            }
            a[n].link=a[q].link=cl;
        }
    }
    bool found=0; string ans;
    vector<int> ord, dep;
    void dfs(int v, int k){
        if (ans.size()+dep[v]<k) return;
        if (ans.size()==k) return void(found=1);
        for (auto [c,to]:a[v].nxt){
            ans.push_back(c);
            dfs(to,k);
            if (found) return;
            ans.pop_back();
        }
    }
    void topsort(){
        int n=a.size();
        vector<int> deg(n);
        queue<int> q;
        for (int i=0;i<a.size();++i){
            for (auto [c,to]:a[i].nxt) deg[to]++; 
        }
        for (int i=0;i<a.size();++i) if (deg[i]==0) q.push(i);
        while (!q.empty()){
            int v=q.front(); q.pop();
            ord.push_back(v);
            for (auto [c,to]:a[v].nxt){
                deg[to]--;
                if (deg[to]==0) q.push(to);
            }
        }
        dep.resize(n);
        for (int i=n-1;i>=0;--i){
            int v=ord[i];
            dep[v]=0;
            for (auto [c,to]:a[v].nxt) dep[v]=max(dep[v],dep[to]+1);
        }
    }
    string solve(int k){
        topsort();
        dfs(0,k);
        return ans;
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s; int k; cin >> s >> k;
    SAM sam(s);
    cout << sam.solve(k) << '\n';
}