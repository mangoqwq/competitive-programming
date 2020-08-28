#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll seed=31;
set<ll> seen;
string needle;
string haystack;
int n[26];
int h[26];
ll exponent[200001];
ll hashuwu[200001];

bool equals(){
    for (int i=0;i<26;++i){
        if (n[i]!=h[i]){
            return false;
        }
    }
    return true;
}

int main(){
    exponent[0]=1;
    for (int i=1;i<200001;++i){
        exponent[i]=exponent[i-1]*seed;
    }
    cin >> needle >> haystack;
    if (needle.size()>haystack.size()){
        cout << 0 << '\n';
        return 0;
    }
    for (int i=0;i<haystack.size();++i){
        hashuwu[i+1]=hashuwu[i]*seed+haystack[i];
    }
    int permu=0;

    
    for (int i=0;i<needle.size();++i){
        n[needle[i]-'a']++;
        h[haystack[i]-'a']++;
    }
    if (equals()){
        seen.insert(hashuwu[needle.size()]);
        permu++;
    }
    ll hash;
    //cout << hashuwu[needle.size()] << '\n';
    for (int index=needle.size();index<haystack.size();++index){
        h[haystack[index-needle.size()]-'a']--;
        h[haystack[index]-'a']++;
        hash=hashuwu[index+1]-hashuwu[index-needle.size()+1]*exponent[needle.size()];
        //cout << hash << '\n';
        if (equals()){
            if(seen.find(hash)==seen.end()){
                seen.insert(hash);
                permu++;
            }
        }
        cout << haystack.substr(index-needle.size()+1,needle.size()) << " " << hash << '\n';
    }
    cout << permu << '\n';


}