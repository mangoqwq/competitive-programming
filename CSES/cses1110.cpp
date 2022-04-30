#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;
using ll = long long;

struct SAM{
    struct Node{
        vector<int> nxt = vector<int>(26);
        int link, len;
        Node(){ len=0, link=-1; }
    };
    int last;
    vector<Node> a;
    SAM(string s){
        last=0;
        a.push_back(Node());
        for (char c:s) extend(c - 'a');
    }
    void extend(char c){
        int n=a.size(), p=last; a.push_back(Node());
        last=n;
        a[n].len=a[p].len+1;
        for (;p!=-1&&!a[p].nxt[c];p=a[p].link) a[p].nxt[c]=n;
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
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    int N = s.size();
    s += s;
    SAM sam(s);
    int v = 0;
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < 26; ++j){
            if (sam.a[v].nxt[j]){
                cout << (char)(j + 'a');
                v = sam.a[v].nxt[j];
                break;
            }
        }
    }
    cout << '\n';
}
