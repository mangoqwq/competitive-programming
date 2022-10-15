#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e5+1;

int slen;
struct Query{ int typ, i, x, val; };
vector<Query> qs;
struct SAM{
    struct Node{
        int link=-1, len=0;
        unordered_map<char,int> nxt;
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
    vector<int> mndep, mxdep;
    vector<bool> terminal;
    void dfs(int v){
        if (mndep[v]!=-1) return;
        if (terminal[v]) mndep[v]=mxdep[v]=0;
        else mndep[v]=inf, mxdep[v]=0;
        for (auto [c,to]:a[v].nxt){
            dfs(to);
            mndep[v]=min(mndep[v],mndep[to]+1);
            mxdep[v]=max(mxdep[v],mxdep[to]+1);
        }
    }
    void getterminals(){
        int p=last;
        while (p){
            terminal[p]=1;
            p=a[p].link;
        }
    }
    void init(){
        int n=a.size();
        terminal.resize(n);
        getterminals();
        mndep.resize(n,-1);
        mxdep.resize(n,-1);
        dfs(0);
    }
    void process(string s){
        init();
        int p=0;
        for (int i=0;i<s.size();++i){
            char c=s[i];
            if (!a[p].nxt.count(c)) return;
            p=a[p].nxt[c];
            qs.push_back({1,mndep[p],mndep[p]+i,i+1});
        }
    }
    void solve(string s){
        init();
        int p=0;
        for (int i=0;i<s.size();++i){
            char c=s[i];
            if (!a[p].nxt.count(c)) return;
            p=a[p].nxt[c];
            qs.push_back({2,slen-1-mndep[p]-i,slen-1-mndep[p],i+1});
        }
    }
};
struct Fenwick{
    int a[MAXN];
    void ins(int i, int v){ for (++i;i<MAXN;i+=i&-i) a[i]=max(a[i],v); }
    int qry(int i){
        int ret=0;
        for (++i;i;i-=i&-i) ret=max(ret,a[i]);
        return ret;
    }
} bit;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string a, b, c; cin >> a >> b >> c;
    slen=b.size();
    string rb=b;
    reverse(rb.begin(),rb.end());
    reverse(a.begin(),a.end());
    SAM sam(b), rsam(rb);
    rsam.process(a);
    sam.solve(c);
    sort(qs.begin(),qs.end(),[](Query a, Query b){ return a.x<b.x; });
    int ans=0;
    for (auto [typ,l,r,val]:qs){
        if (typ==1) bit.ins(l,val);
        else if (typ==2) ans=max(ans,val+bit.qry(l)); 
    }
    ans=max(ans,bit.qry(MAXN-2));
    cout << ans << '\n';
}