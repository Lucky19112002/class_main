#include<bits/stdc++.h>
#include<time.h>
using namespace std;
using namespace std::chrono;
const int N = 1e5+2;
int lp = 500;
bool vis[N];
vector<int> adj[N];

void dfs(int node)
{
    //preorder
    vis[node] = 1;
    //cout<< node << " ";
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
    auto start = high_resolution_clock::now();
    ios_base::sync_with_stdio(false); 
    int n,m;
    n = 7 ;
    m = 7 ;
    for(int i = 0; i<500 ; i++)
    {
        for(int i =0 ; i<=n ; i++)
            vis[i] = false;
        int x,y;
        for (int i = 0; i < m; i++)
        {
            x = rand() % 20 ;
            y = rand() % 10 ;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        dfs(1);
    }    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<chrono::milliseconds>(stop - start);
    cout<<"Size  "<<"   Time"<<endl;
    cout<<"10000 \t"<<" "<<fixed<<duration.count()<<endl;
    return 0;
}
/*
7
7


1 2
1 3
2 4
2 5
2 6
2 7
3 7
*/

/*
        1
       / \
      2   3
    /|\ \  \ 
   / | \  \ \   
  /  |  \   \\    
 4   5   6    7  
*/  