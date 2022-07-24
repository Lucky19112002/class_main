#include<iostream>
#include<chrono>// clock 
#include<fstream>//for file 
int sizeofarray1 = 0,sizeofarray1_2 = 0,sizeofarray1_3 =0;
using namespace std;
using namespace std::chrono;
void merg(int arr[],int l,int mid,int r){
  int n1 =mid-l+1;
  int n2=r-mid;
  int a[n1];
  int b[n2];

  for (int i = 0; i < n1; i++)
  {
    a[i] = arr[l+i];
  }
  
  for (int i = 0; i < n2; i++)
  {
    b[i] = arr[mid+1+i];
  }
  int i=0;
  int j=0;
  int k = l;
  while (i<n1 && j<n2)
  {
    if(a[i]<b[j])
    {
      arr[k] =a[i];
      k++;i++;
    }
    else
    {
      arr[k] =b[j];
      k++;j++;
    }
  }
  while(i<n1)
  {
      arr[k] =a[i];
      k++;i++;
  }
  while (j<n2)
  {
      arr[k] =b[j];
      k++;j++;
  }
  
  
}
void mergShort(int arr[],int l,int r){
  if(l<r){
    int mid = (l+r)/2;
    mergShort(arr,l,mid);
    mergShort(arr,mid+1,r);

    merg(arr,l,mid,r);
  }
}
int main()
{
  {//bubble short 
    cout<<"Working on bubble sort avg case ....";
    for(sizeofarray1 =10000;sizeofarray1<=50000;sizeofarray1=sizeofarray1+10000)
    {
      ofstream bf("file_out/msa.txt",ios::app);
      int bubbleshortarray[sizeofarray1];
      for (int i = 0; i < sizeofarray1; i++)   // Loop for bubbleshortarray
      {
        bubbleshortarray[i] =rand() % 1000;
      }
      auto start = high_resolution_clock::now();
      ios_base::sync_with_stdio(false);
      mergShort(bubbleshortarray,0,sizeofarray1);
      auto stop = high_resolution_clock::now();
      auto duration = duration_cast<chrono::milliseconds>(stop - start);
      bf<<sizeofarray1<<" "<<fixed<<duration.count()<<endl;
      cout<<endl<<sizeofarray1<<" "<<fixed<<duration.count();
      bf.close();
    }
  }
  //bubble short 
  {
    cout<<endl<<"Working on bubble sort worst case  ....";
    int worstCase = 0,sizeofarray1_1 = 0;
    for(sizeofarray1_1 =10000;sizeofarray1_1<=50000;sizeofarray1_1=sizeofarray1_1+10000)
    {
      ofstream bc("file_out/msb.txt",ios::app);
      int bubbleshortarray[sizeofarray1_1];
      for (int i = 0; i < sizeofarray1_1; i++)   // Loop for bubbleshortarray
      {
        bubbleshortarray[i] =worstCase;
        worstCase = worstCase+1;
      }
      auto start = high_resolution_clock::now();
      ios_base::sync_with_stdio(false);
      mergShort(bubbleshortarray,0,sizeofarray1_1);
      auto stop = high_resolution_clock::now();
      auto duration = duration_cast<chrono::milliseconds>(stop - start);
      bc<<sizeofarray1_1<<" "<<fixed<<duration.count()<<endl;
      cout<<endl<<sizeofarray1_1<<" "<<fixed<<duration.count();
      bc.close();    
    }
    
  }
  cout<<".... "<<"Done";
    {
    cout<<endl<<"Working on bubble sort worst case  ....";
    int worstCase = 999999,sizeofarray1_1 = 0;
    for(sizeofarray1_1 =10000;sizeofarray1_1<=50000;sizeofarray1_1=sizeofarray1_1+10000)
    {
      ofstream bc("file_out/msw.txt",ios::app);
      int bubbleshortarray[sizeofarray1_1];
      for (int i = 0; i < sizeofarray1_1; i++)   // Loop for bubbleshortarray
      {
        bubbleshortarray[i] =worstCase;
        worstCase = worstCase - 1;
      }
      auto start = high_resolution_clock::now();
      ios_base::sync_with_stdio(false);
      mergShort(bubbleshortarray,0,sizeofarray1_1);
      auto stop = high_resolution_clock::now();
      auto duration = duration_cast<chrono::milliseconds>(stop - start);
      bc<<sizeofarray1_1<<" "<<fixed<<duration.count()<<endl;
      cout<<endl<<sizeofarray1_1<<" "<<fixed<<duration.count();
      bc.close();    
    }
    
  }
    cout<<".... "<<"Done";
  cout<<endl<<"Ploting the graph...";
  system(" gnuplot -p -e \"set ylabel 'mileseconds' ; set xlabel 'data set' ; p 'G:/Sem_5/DAA/file_out/msb.txt' using 1:2 w lp lc rgb 'green' lw 2 pt 7 title 'merg short best case','G:/Sem_5/DAA/file_out/msa.txt' using 1:2 w lp lc rgb 'red' lw 2 pt 7 title 'merg short worst case','G:/Sem_5/DAA/file_out/msw.txt' using 1:2 w lp lc rgb 'yellow' lw 2 pt 7 title 'merg short avg case'\"");
  return 0;
}