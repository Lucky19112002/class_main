#include<bits/stdc++.h>
#include<time.h>
using namespace std;
const int N = 1000;
bool vis[N];
vector<int> adj[N];
using namespace std::chrono;


int main()
{
    auto start = high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    for(int i = 0; i<10000 ; i++)
    { 
        for(int i =0; i<N; i++)
            vis[i] = 0;
        int n,m;
        n =7;
        m =7;
        //Edge input
        int a[7] = {1,1,2,2,2,2,3};
        int b[7] = {2,3,4,5,6,7,7};
        int x = 0,y = 0;
        for (int i = 0; i < m; i++)
        {
            adj[x].push_back(a[i]);
            x++;
            adj[y].push_back(b[i]);
            y++;
        }
        queue<int> q;
        q.push(1);
        vis[1] = true;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            //cout<< node << " ";
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