#include <iostream>

using namespace std;

int dp[251][251][251];

int pieways (int piesleft, int ppl, int last)
{
    if (piesleft < last) return 0;
    if (ppl == 1) return 1;
    int ways = 0;
    if (dp[piesleft][ppl][last]>-1){
            ways = dp[piesleft][ppl][last];
    }else{
        for (int i = last; i < piesleft; ++i){
            
            ways += pieways(piesleft - i, ppl - 1, i);
            }   
    }
    return dp[piesleft][ppl][last] = ways;
}
int main()
{
    for (int i=0;i<251;++i){
        for (int a=0; a<251; ++a){
            for (int b=0; b<251; ++b){
                dp[i][a][b] = -1;
            }
        }
    }
    int pies, people;
    cin>>pies;
    cin>>people;
    cout << pieways(pies,people,1);
    return 0;
}