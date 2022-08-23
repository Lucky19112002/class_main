#include <bits/stdc++.h>
using namespace std;

void knapsack(int n,float weight[],float profit[],float capacity)
{
    float x[20],tp =0; //tp--->Total Profit
    int i,j,u;
    u = capacity;
    for(i =0 ; i<n ; i++)
    {
        x[i] = 0.0;
    }
    for(i =0 ; i<n ; i++)
    {
        if(weight[i]> u)
        {
            break;
        }
        else
        {
            x[i] = 1.0; // object is accepted
            tp = tp + profit[i]; // adding profit
            u = u - weight[i]; // remob\ving weigth in capiicity
        }
    }
    if(i<n)
        x[i] = u / weight[i]; //get int capecity of boj in 0.---
    tp = tp +(x[i] * profit[i]);
    cout<<"\nThe Result Vectoe is :- ";
    for(i =0 ; i<n ; i++){
        cout<<x[i]<<"\t";
    }
    cout<<"\nMaxinum Profit is :- "<<tp;
}

int main()
{
    float weight[20], profit[20] , capacity;
    int num ,i ,j ,w = 0 ,p = 0;
    float ratio[20],temp;
    cout<<"\nEnter the number of objects :-";
    cin>>num;
    cout<<"\nEnter the weight and profit of each object :-\n";
    cout<<"Weight"<<"\t"<<"Profit"<<endl;
    for( i =0;i<num;i++)
    {
        cout<<i+1<<"-\n";
        cin>>weight[i];cout<<"\t";cin>>profit[i];
    }
    cout<<"\nTotal amouth of weigth :- ";
    for(i =0 ; i<num ; i++){
        w = w + weight[i];
    }
    cout<<w;
    cout<<"\nTotal amouth of profit :- ";
    for(i =0 ; i<num ; i++){
        p = p + profit[i];
    }
    cout<<p;
    cout<<"\nEnter the capacity of kanpsack:- ";
    cin>>capacity;

    for( i =0;i<num;i++)
    {
        ratio[i] = profit[i]/weight[i];
    }

    for( i =0 ;i<num;i++)
    {
        for(j =1+i;j<num; j++)
        {
            if(ratio[i]<ratio[j])
            {
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;

                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;

                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;
            }
        }
    }
    cout<<"\nThe V / W  ratios is :- ";
    for(i =0 ; i<num ; i++){
        cout<<ratio[i]<<"\t";
    }
    knapsack(num,weight,profit,capacity);
    return 0;
}





















