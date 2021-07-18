#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s, meow="meow"; cin >> s;
    s="     "+s+"     ";
    int ans=4;
    for (int i=0;i<s.size();++i){
        int cur=0;
        for (int j=0;j<4;++j){
            if (i+j>=s.size()) continue;
            if (s[i+j]==meow[j]) cur++;
        }
        ans=min(ans,4-cur);
        if (i+4<s.size()){
            if (s[i+0]=='m'&&s[i+2]=='e'&&s[i+4]=='w') ans=min(ans,2);
            if (s[i+0]=='m'&&s[i+2]=='o'&&s[i+4]=='w') ans=min(ans,2);
        }
    }
    for (char j='a';j<='z';++j){
        string e=string("me")+j+"ow";
        if (s.find(e)!=-1) ans=min(ans,1);
        e=string("m")+j+"w";
        if (s.find(e)!=-1) ans=min(ans,2);
    }
    if (s.find("mow")!=-1) ans=min(ans,1);
    if (s.find("moew")!=-1) ans=min(ans,1);
    if (s.find("mew")!=-1) ans=min(ans,1);
    if (s.find("mo")!=-1) ans=min(ans,2);
    if (s.find("ew")!=-1) ans=min(ans,2);
    if (s.find("mw")!=-1) ans=min(ans,2);
    cout << ans << '\n';
}
