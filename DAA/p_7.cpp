#include<bits/stdc++.h>
#include<chrono>
#include<fstream>
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
    ofstream bf("file_out/KAMST.txt",ios::app);
    int n = 0 ,E =0, g=0 ,X =0;
    
    for(n=10;n<=50;n=n+10)
    {
        int E = n-1;
        Edge *input = new Edge[E];
      for (int i = 0; i < E; i++,g++)   // Loop for bubbleshortarray
      {
        int s,d,w;

        s = rand() % 1000;
        d = rand() % 1000;
        w = rand() % 1000;

        input[i].source= s;
        input[i].dest = d;
        input[i].weight = w;
        cout<<g<<"-";
      }
      cout<<endl<<"Out of loop";
    auto start = high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    keuskals(input,n ,E);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<chrono::milliseconds>(stop - start);
    bf<<n<<" "<<fixed<<duration.count()<<endl;
    }
    bf.close();
    cout<<".... "<<"Done";
    system("C:/MinGW/bin/gnuplot.exe -p -e \"set ylabel 'mileseconds' ; set xlabel 'data set' ; p 'C:/Users/Lckpa/Desktop/Lucky/DAA/file_out/KAMST.txt' using 1:2 w lp lc rgb 'red' lw 2 pt 7\"");
}


