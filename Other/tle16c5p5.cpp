#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7,seed=131,MAXN=2e5+1;

random_device rd;
mt19937 gen(rd()); uniform_int_distribution<int> dis(1,1e9);
double arr[MAXN], pows[MAXN], r;
int n;
struct Node{
    double v, tot; int p, sz;
    Node *c[2];
    Node(double x){
        v=x, tot=x, p=dis(gen), sz=1;
        c[0]=c[1]=0;
    }
} *tr;

int sz(Node *t){ return (t?t->sz:0); }
double tot(Node *t){ return (t?t->tot:0); }

void upd(Node *t){
    if (!t) return;
    t->sz=sz(t->c[0])+sz(t->c[1])+1;
    t->tot=tot(t->c[1])+t->v*pows[sz(t->c[1])]+tot(t->c[0])*pows[sz(t->c[1])+1];
}

void rot(Node *&t, int dir){ // 0 left, 1 right
    Node *c=t->c[dir^1];
    t->c[dir^1]=c->c[dir]; c->c[dir]=t; t=c;
    upd(t->c[dir]); upd(t);
}

void ins(Node *&t, Node *x){
    if (!t) return void(t=x);
    int dir=x->v>t->v; ins(t->c[dir],x);
    if (t->c[dir]->p<t->p) rot(t,dir^1);
    upd(t);
}

void rem(Node *&t, double x){
    if (!t) return;
    if (std::abs(t->v-x)<0.00000001){
        if (!t->c[0]||!t->c[1]) t=(t->c[0]?t->c[0]:t->c[1]);
        else{
            int dir=t->c[0]->p>t->c[1]->p; rot(t,dir^1);
            rem(t->c[dir^1],x);
        }
    } else rem(t->c[t->v<x],x);
    upd(t);
}

void print(Node *t){
    if (!t) return;
    print(t->c[0]);
    cout << t->v << " ";
    print(t->c[1]);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    double r; cin >> r;
    int n; cin >> n; pows[0]=1;
    for (int i=1;i<=n;++i) pows[i]=pows[i-1]*r;
    int idx; double a;
    for (int i=1;i<=n;++i){
        cin >> idx >> a;
        if (a>arr[idx]){
            rem(tr,arr[idx]);
            ins(tr,new Node(a));
            arr[idx]=a;
        }
        cout << setprecision(9) << tot(tr) << '\n';
        // print(tr); cout << '\n';
    }
}