#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<char> >board){
    for(auto itr :board){
        for(auto it: itr){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}

void Nqueen(int n, vector<vector<char> >&board, vector<int>rows,vector<int>RightD,vector<int>LeftD,int col){
    if(col >= n){
        print(board);
        cout<<endl;
        return;
    }
    for(int i=0;i<n;i++){
        if(rows[i]==0 && LeftD[(i-col)+n-1]==0 && RightD[i+col]==0){
            rows[i]=1;
            RightD[i+col]=1;
            LeftD[(i-col)+n-1]=1;
            board[i][col]='Q';
            Nqueen(n,board,rows,RightD,LeftD,col+1);
            board[i][col]='.';
            rows[i]=0;
            RightD[i-col]=0;
            LeftD[(i-col)+n-1]=0;

        }
    }
}



int main(){
    int n;
    cout<<"Enter N of N*N grid"<<endl;
    cin>>n;
   
    vector<vector<char> >board(n,vector<char>(n,'.'));
    vector<int>rows(n,0);
    vector<int>RightD((n*2)-1,0);
    vector<int>LeftD((n*2)-1,0);
    Nqueen(n,board,rows,RightD,LeftD,0);

}

/Users/gaurivijaykar/Desktop/practical exam/LP2/N