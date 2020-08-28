#include <bits/stdc++.h>
#include <queue>
#include <string>
#include <set>
using namespace std;

bool inorder(const vector<int> &x){
    bool ok=true;
    for (int i=1;i<=x.size();++i){
        if (x[i-1]!=i){
            ok=false;
        }
    }
    return ok;
}

int first(int x){
    return to_string(x).at(0)-'0';
}

int add(int x,int y){
    if (y==0){
        return first(x);
    }
    return stoi(to_string(first(x))+to_string(y));
}

int remove(int x){
    if (to_string(x).length()==1){
        return 0;
    }
    string s=to_string(x);
    s.erase(s.begin());
    return stoi(s);
}

int bfs(queue<vector<int>> &q, set<vector<int>> &s){
    int temp=q.size();
    if (temp==0){
        return -9999999;
    }
    for (int k=0;k<temp;++k){
        vector<int> uwu=q.front();
        q.pop();
        if (s.find(uwu)!=s.end()){continue;}
        s.insert(uwu);
        if (inorder(uwu)){
            return 0;
        }
        vector<int> a=uwu;
        //first
        if ((first(uwu[0])<first(uwu[1]) || uwu[1]==0)&&uwu[0]!=0){
            a[1]=add(uwu[0],uwu[1]);
            a[0]=remove(a[0]);
            if (s.find(a)==s.end()){q.push(a);}
        }
        a=uwu;
        //first+1,last-1
        for (int i=1;i<uwu.size()-1;++i){
            if ((first(uwu[i])<first(uwu[i+1]) || uwu[i+1]==0)&&uwu[i]!=0){
                a[i+1]=add(uwu[i],uwu[i+1]);
                a[i]=remove(a[i]);
                if (s.find(a)==s.end()){q.push(a);}
            }
            a=uwu;
            if ((first(uwu[i])<first(uwu[i-1]) || uwu[i-1]==0)&&uwu[i]!=0){
                a[i-1]=add(uwu[i],uwu[i-1]);
                a[i]=remove(a[i]);
                if (s.find(a)==s.end()){q.push(a);}
            }
            a=uwu;
        }
        //last
        int i=uwu.size()-1;
        if ((first(uwu[i])<first(uwu[i-1]) || uwu[i-1]==0)&&uwu[i]!=0){
            a[i-1]=add(uwu[i],uwu[i-1]);
            a[i]=remove(a[i]);
            if (s.find(a)==s.end()){q.push(a);}
        }
        a=uwu;
        
    }
    return bfs(q,s)+1;
}

int main(){
    while (true){
        int n,x,result;
        cin >> n;
        if (n==0){
            break;
        }
        vector<int> uwu;
        queue<vector<int>> q;
        for (int i=0;i<n;++i){
            cin >> x;
            uwu.push_back(x);
        }
        q.push(uwu);
        set<vector<int>> s;
        result=bfs(q,s);
        
        if (result>=0){
            cout << result << '\n';
        }
        else{
            cout << "IMPOSSIBLE" << '\n';
        }
    }
}