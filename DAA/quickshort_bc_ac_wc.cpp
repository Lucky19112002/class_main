#include<iostream>
#include<chrono>// clock 
#include<fstream>//for file 
int sizeofarray1 = 0,sizeofarray1_2 = 0,sizeofarray1_1 =0,sizeofarray1_3 =0;
using namespace std;
using namespace std::chrono;
void swap(int arr[], int i,int j){
  int temp  = arr[i];
  arr[i]= arr[j];
  arr[j] = temp;
}
int partition(int arr[] ,int l,int r){
  int pivot = arr[r];
  int i=l-1;
  for(int j =l;j<r;j++){
    if(arr[i]<pivot){
      i++;
      swap(arr,i,j);
    }
  }
  swap(arr,i+1,r);
  return i+1;
}
void quickShort(int arr[],int l,int r){
  if(l<r){
    int pi=partition(arr,l,r);
    quickShort(arr,l,pi-1);
    quickShort(arr,pi+1,r);
  }
}
int main()
{
  {//bubble short 
    cout<<"Working on quick sort avg case ....";
    for(sizeofarray1 =10000;sizeofarray1<=50000;sizeofarray1=sizeofarray1+10000)
    {
      ofstream bf("file_out/qsa.txt",ios::app);
      int bubbleshortarray[sizeofarray1];
      for (int i = 0; i < sizeofarray1; i++)   // Loop for bubbleshortarray
      {
        bubbleshortarray[i] =rand() % 1000;
      }
      auto start = high_resolution_clock::now();
      ios_base::sync_with_stdio(false);
      quickShort(bubbleshortarray,0,sizeofarray1);
      auto stop = high_resolution_clock::now();
      auto duration = duration_cast<chrono::milliseconds>(stop - start);
      bf<<sizeofarray1<<" "<<fixed<<duration.count()<<endl;
      cout<<endl<<sizeofarray1<<" "<<fixed<<duration.count();
      bf.close();
    }
  }
  //bubble short 
  {
    cout<<endl<<"Working on quick sort best case  ....";
    int bestCase = 0;
    for(sizeofarray1_1 =10000;sizeofarray1_1<=50000;sizeofarray1_1=sizeofarray1_1+10000)
    {
      ofstream bc("file_out/qsb.txt",ios::app);
      int bubbleshortarray[sizeofarray1_1];
      for (int i = 0; i < sizeofarray1_1; i++)   // Loop for bubbleshortarray
      {
        bubbleshortarray[i] =rand()%100;
      }
      auto start = high_resolution_clock::now();
      ios_base::sync_with_stdio(false);
      quickShort(bubbleshortarray,0,sizeofarray1_1);
      auto stop = high_resolution_clock::now();
      auto duration = duration_cast<chrono::milliseconds>(stop - start);
      bc<<sizeofarray1_1<<" "<<fixed<<duration.count()<<endl;
      cout<<endl<<sizeofarray1_1<<" "<<fixed<<duration.count();
      bc.close();    
    }
    
  }
  cout<<".... "<<"Done";
    {
    cout<<endl<<"Working on quick sort worst case  ....";
    int worstCase = 999999,sizeofarray1_1 = 0;
    for(sizeofarray1_1 =10000;sizeofarray1_1<=50000;sizeofarray1_1=sizeofarray1_1+10000)
    {
      ofstream bc("file_out/qsw.txt",ios::app);
      int bubbleshortarray[sizeofarray1_1];
      for (int i = 0; i < sizeofarray1_1; i++)   // Loop for bubbleshortarray
      {
        bubbleshortarray[i] =worstCase;
        worstCase = worstCase - 1;
      }
      auto start = high_resolution_clock::now();
      ios_base::sync_with_stdio(false);
      quickShort(bubbleshortarray,999,sizeofarray1_1);
      auto stop = high_resolution_clock::now();
      auto duration = duration_cast<chrono::milliseconds>(stop - start);
      bc<<sizeofarray1_1<<" "<<fixed<<duration.count()<<endl;
      cout<<endl<<sizeofarray1_1<<" "<<fixed<<duration.count();
      bc.close();    
    }
    
  }
    cout<<".... "<<"Done";
  cout<<endl<<"Ploting the graph...";
  system(" gnuplot -p -e \"set ylabel 'mileseconds' ; set xlabel 'data set' ; p 'C:/Users/Lckpa/Desktop/Lucky/DAA/file_out/qsb.txt' using 1:2 w lp lc rgb 'green' lw 2 pt 7 title 'quick short best case','C:/Users/Lckpa/Desktop/Lucky/DAA/file_out/qsa.txt' using 1:2 w lp lc rgb 'yellow' lw 2 pt 7 title 'quick short avg case','C:/Users/Lckpa/Desktop/Lucky/DAA/file_out/qsw.txt' using 1:2 w lp lc rgb 'red' lw 2 pt 7 title 'quick short worst case'\"");
  return 0;
}