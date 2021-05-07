#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=5001;

struct SAM{
    struct Node{
        unordered_map<char,int> nxt;
        int link, len;
        Node(){ len=0, link=-1; }
    };
    int last;
    vector<Node> a;
    SAM(string s){
        last=0;
        a.push_back(Node());
        for (char c:s) extend(c);
    }
    void extend(char c){
        int n=a.size(), p=last; a.push_back(Node());
        last=n;
        a[n].len=a[p].len+1;
        for (;p!=-1&&!a[p].nxt.count(c);p=a[p].link) a[p].nxt[c]=n;
        if (p==-1) return void(a[n].link=0);
        int q=a[p].nxt[c];
        if (a[q].len-a[p].len==1) a[n].link=q;
        else{
            int cl=a.size(); a.push_back(a[q]);
            a[cl].len=a[p].len+1;
            a[q].link=a[n].link=cl;
            for (;p!=-1&&a[p].nxt[c]==q;p=a[p].link) a[p].nxt[c]=cl;
        }
    }
    int count_substr(){
        int ans=0;
        for (int i=1;i<a.size();++i) ans+=a[i].len-a[a[i].link].len;
        return ans+1;
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        string s; cin >> s;
        SAM sam(s);
        cout << sam.count_substr() << '\n';
    }
}