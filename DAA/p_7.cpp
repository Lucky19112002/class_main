#include<bits/stdc++.h>
#include<chrono>
using namespace std;
using namespace std::chrono;
class Edge
{
    public:
    int source;
    int dest;
    int weight;
};
bool compare(Edge e1, Edge e2)
{
    return e1.weight<e2.weight; //Sort in assiding order
}
int findParent(int v, int *parent)
{
    if(parent[v] == v)
    {
        return v;
    }
    else
    return findParent(parent[v],parent);
}
void keuskals(Edge *input, int n, int E)
{
    sort(input,input+E,compare);
    Edge *output = new Edge[n-1];
    int *parent = new int[n];
    for(int i =0; i< n;i++)
    {
        parent[i] = i;
    }

    int count =0;
    int i =0;
    while(count != n-1)
    {
        Edge currentEdge = input[i];
        //cheak if we can add edge or not
        int sourceParent = findParent(currentEdge.source,parent);
        int destParent = findParent(currentEdge.dest,parent);

        if(sourceParent != destParent)
        {
            output[count] = currentEdge;
            count++;
            parent[sourceParent] = destParent;
        } 
        i++;
    }
    cout<<endl<<"Output-"<<endl;
    for (int i = 0; i < n-1; i++)
    {
        if(output[i].source<output[i].dest)
        {  
            cout<<output[i].source<<" "<<output[i].dest <<" "<<output[i].weight<< endl;
        }
        else
        {
            cout<<output[i].dest<<" "<<output[i].source <<" "<<output[i].weight<< endl;
        }
    }
}
int main()
{
    int n,E,a =0;
    cout<<"Enter number of vertices :- "<<endl;
    cin>>n;
    cout<<"Enter number of edges:- "<<endl;
    cin>>E;
    Edge *input = new Edge[E];
    cout<<"Source - Destination - Weight"<<endl;
    for (int i = 0; i < E; i++)   // Loop for bubbleshortarray
    {
        int s,d,w;
        cin>>s>>d>>w;
        input[i].source= s;
        input[i].dest = d;
        input[i].weight = w;
    }
    auto start = high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    keuskals(input,n ,E);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<chrono::milliseconds>(stop - start);
    cout<<"For "<<n<<" vertices "<<" and "<<E<<"  edgs "<<" time taken is"<<" "<<fixed<<duration.count()<<" milliseconds"<<endl;
}
/* Data to enter 
Enter number of vertices :- 
6
Enter number of edges:- 
11
Source - Destination - Weight
0 1 2
1 3 1
0 2 4
2 4 9
4 5 5
3 5 7
4 3 11
2 5 10
0 3 3
2 1 8
2 3 6
*/