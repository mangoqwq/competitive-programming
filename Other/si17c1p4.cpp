#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e5+1;

struct SAM{
    struct Node{
        int len, link;
        unordered_map<char,int> nxt;
        Node(){ len=0, link=-1; }
    };
    int last;
    vector<Node> st;
    SAM(){ st.push_back(Node()); }
    SAM(string s){
        last=0;
        st.push_back(Node());
        for (char c:s) extend(c);
    }
    void extend(char c){
        int v=st.size(), p=last; st.push_back(Node());
        last=v;
        st[v].len=st[p].len+1;
        for (;p!=-1&&!st[p].nxt.count(c);p=st[p].link) st[p].nxt[c]=v;
        if (p==-1) return void(st[v].link=0);
        int q=st[p].nxt[c];
        if (st[p].len+1==st[q].len) st[v].link=q;
        else{
            int cl=st.size(); st.push_back(st[q]);
            st[cl].len=st[p].len+1;
            st[q].link=st[v].link=cl;
            for (;p!=-1&&st[p].nxt[c]==q;p=st[p].link) st[p].nxt[c]=cl;
        }
    }
    int solve(string s){
        int ans=1, curr=0;
        for (char c:s){
            if (!st[curr].nxt.count(c)){
                if (!st[0].nxt.count(c)) return -1;
                ans++, curr=0;
            }
            curr=st[curr].nxt[c];
        }
        return ans;
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string a, b; cin >> a >> b;
    SAM sam(a);
    cout << sam.solve(b) << '\n';
}