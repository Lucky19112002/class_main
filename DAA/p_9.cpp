#include<bits/stdc++.h>
#include<chrono>// clock 
#include<fstream>//for file 
using namespace std;
using namespace std::chrono;
const int N = 1000;
bool vis[N];
vector<int> adj[N];

void dfs(int node)
{
    //preorder
    vis[node] = 1;
    // inorder
    vector<int> :: iterator it;
    for(it = adj[node].begin(); it != adj[node].end(); it++)
    {
        if(vis[*it]);
        else
        {
            dfs(*it);
        }
    } 
    //  For postorder remove from above
    // cout<< node << " ";
}

int main()
{
    {   
        ofstream bf("file_out/bfs.txt",ios::trunc);
        bf<<"#BFS in milliseconds"<<endl;
        auto start = high_resolution_clock::now();ios_base::sync_with_stdio(false);


        vector<int> adj[N];
        cout<<"\nFor BFS :\n";
        for(int i =0; i<N; i++)
        vis[i] = 0;
        int n,m;
        n = 7;
        m = 7;
        //Edge input
        int x,y;
        for (int i = 0; i < m; i++)
        {
            cin >> x  >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        queue<int> q;
        q.push(1);
        vis[1] = true;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            vector<int> :: iterator it;
            for(it= adj[node].begin() ; it != adj[node].end();it++)
            {
                if(!vis[*it])
                {
                    vis[*it] = 1;
                    q.push(*it);
                }
            }
        }
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<chrono::milliseconds>(stop - start);
        int start1=0,start2=0;
        bf<<start1<<" "<<start2<<endl;
        int size = 7;
        bf<<size<<" "<<fixed<<duration.count()<<endl;
        cout<<".";


    }
    {
        ofstream bf("file_out/dfs.txt",ios::trunc);
        bf<<"#DFS in milliseconds"<<endl;
        auto start = high_resolution_clock::now();ios_base::sync_with_stdio(false);
        cout<<"\nFor DFS :\n";
        int n,m;
        n = 7;
        m = 7;
        for(int i =0 ; i<=n ; i++)
            vis[i] = false;
        int x,y;
        for (int i = 0; i < m; i++)
        {
            cin >> x  >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        dfs(1);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<chrono::milliseconds>(stop - start);
        int start1=0,start2=0;
        bf<<start1<<" "<<start2<<endl;
        int size = 7;
        bf<<size<<" "<<fixed<<duration.count()<<endl;
        cout<<".";
    }
    system("gnuplot -p -e \"set ylabel 'mileseconds' ; set xlabel 'data set' ; p 'C:/Users/Lckpa/Desktop/Lucky/DAA/file_out/BFS.txt' using 1:2 w lp lc rgb 'red' lw 2 pt 7 title 'BFS','C:/Users/Lckpa/Desktop/Lucky/DAA/file_out/dfs.txt' using 1:2 w lp lc rgb 'blue' lw 2 pt 7 title 'DFS'\"");
}
/*
1 2
1 3
2 4
2 5
2 6
2 7
3 7
*/