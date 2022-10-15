#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
bool simple[10000001];
bool segment[5001];
int tree[400001];
int lazy[400001];

void simplesieve(){
    memset(simple,true,sizeof simple); simple[0]=simple[1]=false;
    for (int i=2;i<3164;++i){
        for (int k=pow(i,2)+0.1;k<10000001;k+=i){
            simple[k]=false;
        }
    }
}

void segmentedsieve(ll x){
    memset(segment,true,sizeof segment);
    for (int prime=2;prime<10000001;++prime){
        if (simple[prime]){
            ll bot=(((x/prime)+1)*prime)-x;
            if (bot-prime==0){
                bot-=prime;
            }
            if (bot+x==prime){
                bot+=prime;
            }
            for (int i=bot;i<5001;i+=prime){
                segment[i]=false;
            }
        }
    }
}

int f(int x){
    if (x==-1){
        return -1;
    }
    if (segment[x]){
        return x;
    }
    else{
        return -1;
    }
}

void push(int node){
    tree[node*2]+=lazy[node];
    tree[node*2+1]+=lazy[node];
    lazy[node*2]+=lazy[node];
    lazy[node*2+1]+=lazy[node];
    lazy[node]=0;
}

void update(int node, int start, int end, int l, int r, int value){
    if (l>r||l>end||r<start){
        return;
    }
    if (start==l && end==r){
        tree[node]+=value;
        lazy[node]+=value;
        return;
    }
    push(node);
    int mid=(start+end)/2;
    update(node*2,start,mid,l,r,value);
    update(node*2+1,mid+1,end,l,r,value);
    tree[node]=max(f(tree[node*2]),f(tree[node*2+1]));
}

ll getmax(int node,int start, int end, int l, int r){
    if (l>r||l>end||r<start){
        return -2;
    }
    if (start>=l && end<=r){
        return f(tree[node]);
    }
    push(node);
    int mid=(start+end)/2;
    return max(f(getmax(node*2,start,mid,l,r)),f(getmax(node*2+1,mid+1,end,l,r)));
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cout.tie(0);
    cout.sync_with_stdio(0);
    ll N,Q,a,b,c; ll K; cin >> N >> Q >> K;
    simplesieve();
    segmentedsieve(K);
    for (int i=1;i<N+1;++i){
        cin >> a;
        update(1,1,N,i,i,a-K);
    }
    ll temp;
    for (int i=0;i<Q;++i){
        cin >> a;
        if (a==2){
            cin >> a >> b >> c;
            update(1,1,N,a,b,c);
        }
        else if (a==1){
            cin >> a >> b;
            temp=getmax(1,1,N,a,b);
            if (temp==-1){
                cout << -1 << '\n';
            }
            else{
                cout << temp+K << '\n';
            }
        }
    }
}