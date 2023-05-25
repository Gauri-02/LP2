#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int> > &graph, vector<bool> &dist1, queue<int> &q)
{
    if (q.empty())
        return;
    int x = q.front();
    q.pop();
    cout << x << " ";
    for (int itr : graph[x])
    {
        if (!dist1[itr])
        {
            q.push(itr);
            dist1[itr] = true;
        }
    }
    bfs(graph, dist1, q);
}

void dfs(vector<vector<int> > &graph, vector<bool> &dis2,int start){
        cout<<start<<" ";

        for(int itr:graph[start]){
            if(!dis2[itr]){
                dis2[itr]=true;
                dfs(graph,dis2,itr);
            }
        }
}

int main()
{
    int edge, node;
    cout << "edge & node" << endl;
    cin >> edge >> node;
    vector<vector<int> > graph(node+ 1);

    int s, d;
    for (int i = 0; i < edge; i++)
    {
        cout << "souce node :" << endl;
        cin >> s;
        cout << "Destination node:" << endl;
        cin >> d;
        graph[s].push_back(d);
        graph[d].push_back(s);
    }

    vector<bool> dis1(node, false);
    int start = 0;
    cout << "starting vertex: " << endl;
    cin >> start;
    queue<int> q;
    q.push(start);
    dis1[start] = true;

    bfs(graph, dis1, q);
    cout<<endl;
    vector<bool>dis2(node,false);
    dis2[start]=true;
    dfs(graph,dis2,start);
}