#include<bits/stdc++.h>
using namespace std;


void prims(vector<vector<int> >adj,int n){
    vector<bool>visited(n,false);
    visited[0]=true;
    int edge,x,y;
    edge=0;
    //cout<<"in prims"<<endl;
    while(edge < n-1){
        //cout<<"in while "<<endl;
        x=0;
        y=0;
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            if(visited[i]){
                for(int j=0;j<n;j++){
                    if(!visited[j] && adj[i][j]){
                        if(mini > adj[i][j]){
                            mini=adj[i][j];
                            x=i;
                            y=j;
                        }
                    }
                }
            }

        }
        cout<<x<<" -->  "<<y<<"      "<<adj[x][y]<<endl;
        edge++;
        visited[y]=true;

    }
}



int main(){
    int n;
    cout<<"Enter no of nodes"<<endl;
    cin>>n;
    vector<vector<int> >adj;
    for(int i=0;i<n;i++){
        vector<int>temp;
        for(int j=0;j<n;j++){
            int x;
            cout<<"Edge between "<<i<<" "<<j<<endl;
            cin>>x;
            temp.push_back(x);
        }
        adj.push_back(temp);
    }

    prims(adj,n);
}