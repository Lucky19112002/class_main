#include <iostream>
#include <sstream>
using namespace std;
int count = 0,stack[4] , n = 4 , top=-1 , c[5] , d[5] , x = 0 , h = 0 , z = 0 ;
string srt = " ",srt1 = " ",srt2 =" ";
void cheakloop()
{
    cout<<"Loop that we gunerate in this is : "<<endl;
    srt = to_string(c[0]);
    int ax = 0; 
    ax = count;
    ax = ax+1;
    for (int i = 0; i < ax ; i++) //Conver from int arr ay to string array
    {
        srt2 = to_string(c[i+1]);
        srt1 = to_string(d[i]);
        cout<<"["<<srt2<<"]["<<srt1<<"]"<<"\t";
    }
    if(srt == srt1){
        cout<<endl<<"Circle Present : "<<endl<<" Starting node :["<<srt<<"] "<<" Ending node :["<<srt1<<"]"<<endl;
    }
    else
    {
        cout<<endl<<"Non cliculer"<<"["<<srt<<"]"<<"["<<srt1<<"]"<<endl;
    }
    
}
void push(int val) 
{
   if(top>=n-1)
   cout<<"Stack Overflow"<<endl;
   else {
      top++;
      stack[top]=val;
   }
}
void pop() 
{
   if(top<=-1)
   cout<<"Stack Underflow"<<endl;
   else {
      cout<<"The popped element is "<< stack[top] <<endl;
      top--;
   }
}
void display() 
{
   if(top>=0) {
      cout<< "pushing value in stack"<<endl;
      for(int i=top; i>=0; i--)
      cout<<stack[i]<<" ";
      cout<<endl;
   } else
   cout<<"Stack is empty";
}
int main() 
{
    
    
    int test[4][4] = {{0,1,0,0},{0,0,1,0},{1,0,0,1},{1,0,0,0}};
    cout<<"Stack representactios:"<<endl;
    /*for (int i = 0; i < 4; ++i)  // Show the 2-D matrix
    {
        for (int j = 0; j < 4; ++j) 
        {
            cout<<test[i][j]<<"\t";
        }
        cout << endl;
    }*/
    cout<<"Adding all items been trivals and shoing all pints with connections:"<<endl;
    for (int i = 0; i < 4; ++i) //Push it on stack and seeing all the values
    {
        //push(i);
        for (int j = 0; j < 4; ++j) 
        {
            
            if(test[i][j] == 1)
            {   
                count = count + 1;
                x = x + 1 ;
                c[x] = i;
                //cout << c[x] <<"\t";
                z = z +1 ;
                d[z] = j; 
                //cout << d[x] <<"\t";
                cout<<"["<<i<<"]["<<j<<"]"<<"\t";
            }
        }
        cout << endl;
    }
    cheakloop();
    //cout << endl;
    //cout<<"path from 0 uses:"<<count<<endl;
    //cout << endl;
    //display();
    {
        /*
        cout << endl; 
        cout<<"poping elements:"<<endl;
        pop();
        pop();
        pop();
        pop();
        */        
    }// Testing by poping all elemets
    return 0;
}