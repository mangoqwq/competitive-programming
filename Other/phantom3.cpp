#include <bits/stdc++.h>

using namespace std;
bool simple[100001],segment[20000001];

void simplesieve(){
    for (int i=2;i<=318;++i){
        if (simple[i]){
            for (int index=pow(i,2)+0.5;index<100001;index+=i){
                simple[index]=false;
            }
        }
    }
}

void segmentedsieve(long long x, long long y){
    for (int index=2;index<100001;++index){
        if (simple[index]){
            long long bot=(((x/index)+1)*index)-x;
            if (bot-index==0){
                bot-=index;
            }
            if (bot+x==index){
                bot+=index;
            }
            for (int i=bot;i<y-x+1;i+=index){
                segment[i]=false;
            }
        }
    }
}

int main(){
    memset(simple, 1, sizeof simple); simple[0]=false; simple[1]=false;
    memset(segment, 1, sizeof segment);
    simplesieve();
    long long N, M; cin >> N >> M;
    segmentedsieve(N,M);
    //i=0:N, i=1:N+1, i=2:N+2 ... 
    long long primes=0;
    for (int i=0;i<M-N;++i){
        if (segment[i]){
            //cout << i+N << " ";
            primes++;
        }
    }
    cout << primes << '\n';
}