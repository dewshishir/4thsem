#include<bits/stdc++.h>
using namespace std;
int node,edge;
int visited_array[1000];

vector<int>a[1000];

void BFS(int src)
{
    queue<int>b;
    b.push(src);
    visited_array[src]=1;
    while(!b.empty())
    {
        int head=b.front();
        cout<<head<<" ";
        b.pop();
        // for(int child:a[head])
        // {
        //     if(visited_array[child]==0)
        //     {
        //         visited_array[child]=1;
        //         b.push(child);
        //     }
        // }
         for(int i=0;i<a[head].size();i++)
        {
            if(visited_array[a[head][i]]==0)
            {
                visited_array[a[head][i]]=1;
                b.push(a[head][i]);
            }
        }
    }

}


void DFS(int node)
{
    cout<<node<<" ";
    visited_array[node]=1;
    for(int child:a[node])
    {
        if(visited_array[child]==0)
        {
            DFS(child);
        }
    }
}

int main()
{
    cout<<"Enter the number of Nodes and Edges"<<endl;
    cin>>node>>edge;
    cout<<"Enter the value"<<endl;
    for(int i=0; i<edge; i++)
    {
        int u,v;
        cin>>u>>v;
        a[u].push_back(v);
       a[v].push_back(u);
    }
     int b,d;
     cout<<"Bfs and dfs:";
     cin>>b;
    cout<<"BFS:";
    BFS(b);
    cout<<endl;
     memset(visited_array, 0, sizeof(visited_array));
    cout<<"DFS:";
    DFS(b);
  cout<<"";
    return 0;
}
