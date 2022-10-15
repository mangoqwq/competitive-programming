#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

struct BigInteger{
    struct Item{ bool d; int cnt; };
    vector<Item> a;
    void flip(){
        assert(!a.empty());
        bool tmp=a.back().d;
        a.back().cnt--;
        if (a.back().cnt==0) a.pop_back();
        a.push_back({!tmp,1}); fix();
    }
    void fix(){
        if (a.empty()) return;
        Item tmp=a.back(); a.pop_back();
        if (!a.empty()&&tmp.d==a.back().d) a.back().cnt+=tmp.cnt;
        else a.push_back(tmp);
    }
    BigInteger& operator++(){
        if (a.back().d==1){
            int tmp=a.back().cnt; a.pop_back();
            flip(); a.push_back({0,tmp});
        }
        else flip();
        return *this;
    }
    BigInteger& operator--(){
        if (a.back().d==0){
            int tmp=a.back().cnt; a.pop_back();
            flip(); a.push_back({1,tmp});
        }
        else flip();
        return *this;
    }
    BigInteger operator++(int){
        BigInteger old=*this;
        operator++();
        return old;
    }
    BigInteger operator--(int){
        BigInteger old=*this;
        operator--();
        return old;
    }
    BigInteger& operator>>=(const int x){
        for (int i=1;i<=x;++i){
            a.push_back({0,1}); fix();
        }
        return *this;
    }
    BigInteger& operator<<=(const int x){
        for (int i=1;i<=x;++i){
            a.back().cnt--;
            if (a.back().cnt==0) a.pop_back();
        }
        return *this;
    }
    bool operator<(const BigInteger &x) const{
        string s1=to_string(), s2=x.to_string();
        for (int i=0;i<min(s1.size(),s2.size());++i){
            if (s1[i]==s2[i]) continue;
            return s1[i]<s2[i];
        }
        return 0;
    }
    string to_string() const{
        string ret="";
        for (auto [d,cnt]:a){
            for (int i=1;i<=cnt;++i) ret+=(d+'0');
        }
        return ret;
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    BigInteger a, b;
    string s, t; cin >> s >> t;
    for (int i=1;i<=2;++i){
        for (char c:s){
            if (c=='1') a>>=1;
            if (c=='2') a>>=1, a++;
            if (c=='U') a<<=1;
            if (c=='L') a--;
            if (c=='R') a++;
        }
        swap(a,b), swap(s,t);
    }
    string sa=a.to_string(), sb=b.to_string();
    if (sb<sa) swap(sa,sb);
    int sza=sa.size(), szb=sb.size();
    ll ans=sza+szb, curr=0;
    for (int i=0;i<min(sza,szb);++i){
        curr*=2;
        if (sa[i]=='1') curr--;
        if (sb[i]=='1') curr++;
        ans=min(ans,curr+sza+szb-2*(i+1));
        if (curr>=1e9) break;
    }
    cout << ans << '\n';
}
