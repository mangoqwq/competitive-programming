#include <bits/stdc++.h>

using namespace std;
int owo[1001], berries[1001];

int main(){
    int trees,baskets,a; cin >> trees >> baskets;
    for (int _=0;_<trees;++_){
        cin >> a;
        berries[_]=a;
        for (int i=1000;i>0;--i){
            owo[i]+=(int)floor(a/i);
        }
    }
    priority_queue<int> uwu;
    int elsie;
    for (int i=1000;i>1;--i){
        if (owo[i]>=(baskets/2)){
            elsie=i;
            int tree[1001]; copy(begin(berries),end(berries),begin(tree));
            sort(begin(tree),end(tree));
            reverse(begin(tree),end(tree));
            int index=0, temp=baskets/2;
            while (temp!=0){
                if (tree[index]>elsie){
                    tree[index]-=elsie;
                    temp=temp-1;
                }
                else{
                    index++;
                }
            }
            if (index>1000){
                continue;
            }
            index=0; temp=baskets/2;
            int total=0;
            sort(begin(tree),end(tree)); reverse(begin(tree),end(tree)); priority_queue<int> pq;
            for (int i=0;i<trees+1;++i){
                pq.push(tree[i]);
            }
            for (int i=0;i<baskets/2;++i){
                if (pq.top()>elsie){
                    total+=elsie;
                    pq.push(pq.top()-elsie);
                    pq.pop();
                }
                else{
                    total+=pq.top();
                    pq.pop();
                }
            }
            uwu.push(total);
        }
    }
    cout << uwu.top() << '\n';
}