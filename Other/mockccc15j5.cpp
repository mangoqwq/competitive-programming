#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

pair<int,int> x[100001],y[100001];

int path(int x1, int y1, int x2, int y2){
    int start=0,end=0;
    if (x1==x2){
        int bot=0,top=100001,mid;
        while (bot<=top){
            mid=(bot+top)/2;
            if (x[mid].first == x1 && x[mid].second>=min(y1,y2)&&x[mid].second<=max(y1,y2)){
                if (x[mid-1].first!=x1||x[mid-1].second<min(y1,y2)||x[mid-1].second>max(y1,y2)){
                    start=mid;
                    break;
                }
                else{
                    top=mid-1;
                }
            }
            else if (x[mid].first<x1||(x[mid].first==x1&&x[mid].second<min(y1,y2))){
                bot=mid+1;
            }
            else if (x[mid].first>x1||(x[mid].first==x1&&x[mid].second>max(y1,y2))){
                top=mid-1;
            }
        }
        bot=0;top=100001;
        while (bot<=top){
            mid=(bot+top)/2;
            if (x[mid].first == x1 && x[mid].second>=min(y1,y2)&&x[mid].second<=max(y1,y2)){
                if (x[mid+1].first!=x1||x[mid+1].second<min(y1,y2)||x[mid+1].second>max(y1,y2)){
                    end=mid;
                    break;
                }
                else{
                    bot=mid+1;
                }
            }
            else if (x[mid].first<x1||(x[mid].first==x1&&x[mid].second<min(y1,y2))){
                bot=mid+1;
            }
            else if (x[mid].first>x1||(x[mid].first==x1&&x[mid].second>max(y1,y2))){
                top=mid-1;
            }
        }
        if (start==end&&start==0){
            return 0;
        }
        return end-start+1;
        
    }
    if (y1==y2){
        int bot=0,top=100001,mid;
        while (bot<=top){
            mid=(bot+top)/2;
            if (y[mid].first == y1 && y[mid].second>=min(x1,x2)&&y[mid].second<=max(x1,x2)){
                if (y[mid-1].first!=y1||y[mid-1].second<min(x1,x2)||y[mid-1].second>max(x1,x2)){
                    start=mid;
                    break;
                }
                else{
                    top=mid-1;
                }
            }
            else if (y[mid].first<y1||(y[mid].first==y1&&y[mid].second<min(x1,x2))){
                bot=mid+1;
            }
            else if (y[mid].first>y1||(y[mid].first==y1&&y[mid].second>max(x1,x2))){
                top=mid-1;
            }
        }
        bot=0;top=100001;
        while (bot<=top){
            mid=(bot+top)/2;
            if (y[mid].first == y1 && y[mid].second>=min(x1,x2)&&y[mid].second<=max(x1,x2)){
                if (y[mid+1].first!=y1||y[mid+1].second<min(x1,x2)||y[mid+1].second>max(x1,x2)){
                    
                    end=mid;
                    break;
                }
                else{
                    bot=mid+1;
                }
            }
            else if (y[mid].first<y1||(y[mid].first==y1&&y[mid].second<min(x1,x2))){
                bot=mid+1;
            }
            else if (y[mid].first>y1||(y[mid].first==y1&&y[mid].second>max(x1,x2))){
                top=mid-1;
            }
        }
        if (start==end&&start==0){
            return 0;
        }
        return end-start+1;
    }
    return 0;
}

int main(){
    int buildings,points,a,b,lastx,lasty; cin >> buildings;
    for (int i=0;i<buildings;++i){
        cin >> a >> b;
        x[i]={a,b};
        y[i]={b,a};
    }
    x[100001]={0x3f3f3f3f,0x3f3f3f3f}; y[100001]={0x3f3f3f3f,0x3f3f3f3f};
    sort(begin(x),end(x)); sort(begin(y),end(y));
    cin >> points; cin>>lastx>>lasty;
    ll t=0;
    for (int i=0;i<points-1;++i){
        cin >> a >> b;
        t+=path(lastx,lasty,a,b);
        lastx=a;lasty=b;
    }
    cout << t << '\n';
}