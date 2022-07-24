#include<iostream>
#include<chrono>// clock 
#include<fstream>//for file 
int sizeofarray1 = 0,sizeofarray1_2 = 0,sizeofarray1_3 =0;
using namespace std;
using namespace std::chrono;
void bubbleshort(int a[],int s) //algotithm function
{
  int i,j;
  for (i = 0; i < s - 1; i++)
  {
    for (j = 0; j < s - i - 1; j++)
    {
      if (a[j] > a[j + 1])
      {
        int temp = a[j];
        a[j] = a[j+1];
        a[j+1] = temp;
      }
    }      
  }           
}

int main()
{
  {//bubble short 
    cout<<"Working on bubble sort avg case ....";
    for(sizeofarray1 =10000;sizeofarray1<=50000;sizeofarray1=sizeofarray1+10000)
    {
      ofstream bf("file_out/bsa.txt",ios::app);
      int bubbleshortarray[sizeofarray1];
      for (int i = 0; i < sizeofarray1; i++)   // Loop for bubbleshortarray
      {
        bubbleshortarray[i] =rand() % 1000;
      }
      auto start = high_resolution_clock::now();
      ios_base::sync_with_stdio(false);
      bubbleshort(bubbleshortarray,sizeofarray1);
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
      ofstream bc("file_out/bsb.txt",ios::app);
      int bubbleshortarray[sizeofarray1_1];
      for (int i = 0; i < sizeofarray1_1; i++)   // Loop for bubbleshortarray
      {
        bubbleshortarray[i] =worstCase;
        worstCase = worstCase+1;
      }
      auto start = high_resolution_clock::now();
      ios_base::sync_with_stdio(false);
      bubbleshort(bubbleshortarray,sizeofarray1_1);
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
      ofstream bc("file_out/bsw.txt",ios::app);
      int bubbleshortarray[sizeofarray1_1];
      for (int i = 0; i < sizeofarray1_1; i++)   // Loop for bubbleshortarray
      {
        bubbleshortarray[i] =worstCase;
        worstCase = worstCase - 1;
      }
      auto start = high_resolution_clock::now();
      ios_base::sync_with_stdio(false);
      bubbleshort(bubbleshortarray,sizeofarray1_1);
      auto stop = high_resolution_clock::now();
      auto duration = duration_cast<chrono::milliseconds>(stop - start);
      bc<<sizeofarray1_1<<" "<<fixed<<duration.count()<<endl;
      cout<<endl<<sizeofarray1_1<<" "<<fixed<<duration.count();
      bc.close();    
    }
    
  }
    cout<<".... "<<"Done";
  cout<<endl<<"Ploting the graph...";
  system(" gnuplot -p -e \"set ylabel 'mileseconds' ; set xlabel 'data set' ; p 'G:/Sem_5/DAA/file_out/bsb.txt' using 1:2 w lp lc rgb 'green' lw 2 pt 7 title 'bubble short best case','G:/Sem_5/DAA/file_out/bsa.txt' using 1:2 w lp lc rgb 'red' lw 2 pt 7 title 'bubble short worst case','G:/Sem_5/DAA/file_out/bsw.txt' using 1:2 w lp lc rgb 'yellow' lw 2 pt 7 title 'bubble short avg case'\"");
  return 0;
}