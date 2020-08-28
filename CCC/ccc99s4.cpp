#include <iostream>
#include <queue>

using namespace std;
int r,c,pr,pc,kr,kc;

int in(int x,int y){
    if (x<1 || x>r || y<1 || y>c){
        return false;
    }
    return true;
}

int main(){
    int games;
    cin >> games;
    for (int e=0;e<games;++e){
        cin >> r >> c >> pr >> pc >> kr >> kc;
        int board[r+1][c+1];
        for (int i=0;i<r+1;++i){
            for (int k=0;k<c+1;++k){
                board[i][k]=0;
            }
        }
        int moves=0;
        queue<pair<int,int>> q;
        q.push(make_pair(kr,kc));
        int x,y;
        while (!q.empty()){
            int qsize=q.size();
            moves++;
            for (int k=0;k<qsize;++k){
                x=q.front().first;y=q.front().second;
                //cout << x << " : " << y << " ";
                q.pop();

                if (in(x+2,y+1)&&board[x+2][y+1]==0){
                    q.push(make_pair(x+2,y+1));
                    board[x+2][y+1]=moves;
                }
                if (in(x-2,y+1)&&board[x-2][y+1]==0){
                    q.push(make_pair(x-2,y+1));
                    board[x-2][y+1]=moves;
                }
                if (in(x+2,y-1)&&board[x+2][y-1]==0){
                    q.push(make_pair(x+2,y-1));
                    board[x+2][y-1]=moves;
                }
                if (in(x-2,y-1)&&board[x-2][y-1]==0){
                    q.push(make_pair(x-2,y-1));
                    board[x-2][y-1]=moves;
                }
                if (in(x+1,y+2)&&board[x+1][y+2]==0){
                    q.push(make_pair(x+1,y+2));
                    board[x+1][y+2]=moves;
                }
                if (in(x-1,y+2)&&board[x-1][y+2]==0){
                    q.push(make_pair(x-1,y+2));
                    board[x-1][y+2]=moves;
                }
                if (in(x+1,y-2)&&board[x+1][y-2]==0){
                    q.push(make_pair(x+1,y-2));
                    board[x+1][y-2]=moves;
                }
                if (in(x-1,y-2)&&board[x-1][y-2]==0){
                    q.push(make_pair(x-1,y-2));
                    board[x-1][y-2]=moves;
                }
                
            }
        }
        board[kr][kc]=-2;
        int win=0,tie=0,lose=r-pr-1;
        for (int i=1; i<=r-pr-1;++i){
            if ((board[i+pr][pc]+i)%2==0 && board[i+pr][pc]<=i && board[i+pr][pc]!=0){
                win=i;
                cout << "Win in " << win << " knight move(s)." <<'\n';
                break;
            }
            else if (in(i+pr+1,pc) && (board[i+pr+1][pc]+i)%2==0 && board[i+pr+1][pc]<=i && tie==0){
                tie=i;
            }
        }
        if (pr+1==kr && pc==kc){
            tie=0;
            cout << "Stalemate in " << tie << " knight move(s)." <<'\n';
        }
        else if (win==0 && tie==0){
            cout << "Loss in " << lose << " knight move(s)." <<'\n';
        }
        else if (win==0){
            cout << "Stalemate in " << tie << " knight move(s)." <<'\n';
        }
        /*
        for (auto&&x:board){
            for (auto&&k:x){
                cout << k << " ";
            }
            cout << '\n';
        }
        */
        
    }
}