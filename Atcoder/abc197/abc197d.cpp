#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define PI 3.14159265358979323846
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    double a, b; cin >> a >> b;
    double c, d; cin >> c >> d;
    double ang=(n-2)*180.0/n/2/180*PI;
    double len=cos(ang)*sqrt((c-a)*(c-a)+(d-b)*(d-b));
    ang=atan2(d-b,c-a)-ang;
    printf("%.11f %.11f\n",a+len*cos(ang),b+len*sin(ang));
}