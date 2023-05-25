#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int> >&graph,queue<int>&q,vector<bool> &discovered){
    //cout<<"In fun"<<endl;
    if(q.empty())return;
    int x=q.front();
    q.pop();
    cout<<x<<" ";
    //discovered[x]=true;

    for(int itr : graph[x]){
        if(!discovered[itr]){
        q.push(itr);
        discovered[itr]=true;
        }
    }

    bfs(graph,q,discovered);

}

void dfs(vector<vector<int> >&graph,vector<bool>&dis,int start){

    cout<<start<<" ";

    for(int itr :graph[start]){
        if(!dis[itr]){
            dis[itr]=true;
            dfs(graph,dis,itr);
        }
    }
}




int  main(){
    int edge,node;
    cout<<"edge & node:"<<endl;
    cin>>edge>>node;
    vector<vector<int> >graph(node+1);
    //int n=edge;
    int s,d;
   for(int i=0;i<node;i++){
        cout<<"Enter source vertex :"<<endl;
        cin>>s;
        cout<<"Enter destination vertex:"<<endl;
        cin>>d;

        graph[s].push_back(d);
        graph[d].push_back(s);

    }
        bool l=true;

        queue<int>q;
       vector<bool>discovered(node,false);
        int start;
        cout<<"Enter starting node :"<<endl;
        cin>>start;
        q.push(start);
        //cout<<"push"<<endl;
        discovered[start]=true;
        //cout<<"After push"<<endl;
        //discovered[start]=true;
        cout<<"bfs :";
        bfs(graph,q,discovered);

        vector<bool>dis(node,false);
        dis[start]=true;
        cout<<"dfs :";
        dfs(graph,dis,start);

}