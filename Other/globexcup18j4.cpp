#include <iostream>
#include <cmath>

using namespace std;

long long a,b,c,d,e;
long long N;
long mod=1000000007;


long long function(long N){
    if (N==0){
        return e;
    }
    else{
        return ( (a*function(floor(N/b)))%mod + (c*function(floor(N/d)))%mod )%mod;
    }
}
int main(){
    cin >> a >> b >> c >> d >> e >> N;
    cout << function(N)%mod;

}