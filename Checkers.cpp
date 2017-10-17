//  Copyright © 2017 Dougy Ouyang. All rights reserved.

#include <iostream>

using namespace std;
typedef pair<int, int> pii;
pii step[10000];
char board[35][35], board2[35][35];
int n, o=0, s;
bool fi=false, posi;

void DFS(int row, int col, int x, int st)
{
    
    //base case
    if(!posi || fi)
        return;
    if(row==0 || row>n || col==0 || col>n){
        posi=false;
        return;
    }
    if(x==o){
        fi=true, s=st;
        return;
    }
    //transition
    if(board2[row-1][col-1]=='o'){
        board2[row-1][col-1]='+';
        step[st].first=row-2, step[st].second=col-2;
        DFS(row-2, col-2, x+1, st+1);
    }
    if(board2[row-1][col+1]=='o'){
        board2[row-1][col+1]='+';
        step[st].first=row-2, step[st].second=col+2;
        DFS(row-2, col+2, x+1, st+1);
    }
    if(board2[row+1][col-1]=='o'){
        board2[row+1][col-1]='+';
        step[st].first=row+2, step[st].second=col-2;
        DFS(row+2, col-2, x+1, st+1);
    }
    if(board2[row+1][col+1]=='o'){
        board2[row+1][col+1]='+';
        step[st].first=row+2, step[st].second=col+2;
        DFS(row+2, col+2, x+1, st+1);
    }
}

int main()
{
    int i, j, ii, jj;
    
    cin >> n;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cin >> board[i][j];
            if(board[i][j]=='o')
                o++;
        }
    }
    
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(board[i][j]=='K'){
                for(ii=0;ii<n;ii++){
                    for(jj=0;jj<n;jj++){
                        board2[ii][jj]=board[ii][jj];
                    }
                }
                posi=true;
                DFS(i, j, 0, 0);
                if(fi)
                    break;
            }
        }
        if(fi)
            break;
    }
    
    if(!fi){
        cout << "impossible" << endl;
        return 0;
    }
    cout << i << " " << j << endl;
    for(i=0;i<s;i++)
        cout << step[i].first << " " << step[i].second << endl;
    
    return 0;
}
