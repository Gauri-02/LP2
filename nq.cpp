#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<char> >board){
    for(auto itrs:board){
        for(auto itr:itrs){
            cout<<itr<<" ";
        }
        cout<<endl;
    }
}

void nqueen(vector<vector<char> >&board,vector<int>row,vector<int>right,vector<int>left,int n,int col){
   //cout<<"In queen"<<endl;
    if(col >=n){
        print(board);
        cout<<endl;
        return;
    }
    for(int i=0;i<n;i++){
        //cout<<"in for"<<endl;
        if(row[i]==0 && right[i+col]==0 && left[(i-col)+n-1]==0){
            row[i]=1;
            right[i+col]=1;
            left[(i-col)+n-1]=1;
            board[i][col]='Q';
            nqueen(board,row,right,left,n,col+1);
            row[i]=0;
            right[i+col]=0;
            left[(i-col)+n-1]=0;
            board[i][col]='.';
        }
    }
}

int main(){
    int n;
    cout<<"Enter n: "<<endl;
    cin>>n;

    vector<vector<char> >board(n,vector<char>(n,'.'));
    vector<int>row(n,0);
    vector<int>Right((n*2)-1,0);
    vector<int>Left((n*2)-1,0);
    nqueen(board,row,Right,Left,n,0);
    
}