#include<iostream>
#include<chrono>// clock 
#include<fstream>//for file 
int sizeofarray1 = 0,sizeofarray2 =0,sizeofarray3 =0,key =0;
using namespace std;
using namespace std::chrono;
void bubbleshort(int a[]) //algotithm function
{
  int i,j;
  for (i = 0; i < sizeofarray1 - 1; i++)
  {
    for (j = 0; j < sizeofarray1 - i - 1; j++)
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
void selectionsort(int arr[])
{
  int s2 = sizeofarray2 -1;
  for(int i =0; i<s2;i++)
  {
    int min = i;
    for (int j = 0; j < sizeofarray2; j++)
    {
      if(arr[j]<arr[min])
      {
        min =j;
      }
    }
    if (min!=i)
    {
      int temp = arr[min];
      arr[min] = arr[i];
      arr[i] = temp;
    }
  }
}
void insertsort(int arr[])
{
  int j =0;
  for (int i = 1; i < sizeofarray3; i++)
  {
    key = arr[i];  // picking the element 
    j = i-1;
    while (j>=0 && arr[j]>key)
    {
      arr[j+1] = arr[j];
      j = j-1;
    }
    arr[j+1] = key;
  }
}
int main()
{
  {//bubble short 
    ofstream bf("1.bat",ios::app);
    bf<<"#Bubble sort in milliseconds"<<endl;
    cout<<endl<<"Working on bubble sort ....";
    for(sizeofarray1 =10000;sizeofarray1<=50000;sizeofarray1=sizeofarray1+10000)
    {
      int bubbleshortarray[sizeofarray1];
      for (int i = 0; i < sizeofarray1; i++)   // Loop for bubbleshortarray
      {
        bubbleshortarray[i] =rand() % 1000;
      }
      auto start = high_resolution_clock::now();
      ios_base::sync_with_stdio(false);
      bubbleshort(bubbleshortarray);
      auto stop = high_resolution_clock::now();
      auto duration = duration_cast<chrono::milliseconds>(stop - start);
      bf<<sizeofarray1<<" "<<fixed<<duration.count()<<endl;
      cout<<".";
    }
    bf.close();
    cout<<".... "<<"Done";
  }
  {//selection sort 
    ofstream bf("2.bat",ios::app);
    bf<<"#selection sort in milliseconds"<<endl;
    cout<<endl<<"Working on selection sort ....";
    for(sizeofarray2 =10000;sizeofarray2<=50000;sizeofarray2=sizeofarray2+10000)
    {
      int selectshortarray[sizeofarray2];
      for (int i = 0; i < sizeofarray2; i++)   // Loop for bubbleshortarray
      {
        selectshortarray[i] =rand() % 10;
      }
      auto start = high_resolution_clock::now();
      ios_base::sync_with_stdio(false);
      selectionsort(selectshortarray);
      auto stop = high_resolution_clock::now();
      auto duration = duration_cast<chrono::milliseconds>(stop - start);
      bf<<sizeofarray2<<" "<<fixed<<duration.count()<<endl;
      cout<<".";
    }
    bf.close();
    cout<<".... "<<"Done";
  }
  {//insertion sort 
    ofstream bf("3.bat",ios::app);
    bf<<"#insertion sort in milliseconds"<<endl;
    cout<<endl<<"Working on insertion sort ....";
    for(sizeofarray3 =10000;sizeofarray3<=50000;sizeofarray3=sizeofarray3+10000)
    {
      int insertsortarray[sizeofarray3];
      for (int i = 0; i < sizeofarray3; i++)   // Loop for bubbleshortarray
      {
        insertsortarray[i] =rand() % 10;
      }
      auto start = high_resolution_clock::now();
      ios_base::sync_with_stdio(false);
      insertsort(insertsortarray);
      auto stop = high_resolution_clock::now();
      auto duration = duration_cast<chrono::milliseconds>(stop - start);
      bf<<sizeofarray3<<" "<<fixed<<duration.count()<<endl;
      cout<<".";
    }
    bf.close();
    cout<<".... "<<"Done";
  }
  cout<<endl<<"Ploting the graph...";
  system("gnuplot -p -e \"set ylabel 'mileseconds' ; set xlabel 'data set' ; p 'C:/Users/karim/Desktop/class/DAA/1.bat' using 1:2 w lp lc rgb 'red' lw 2 pt 7 title 'bubble','C:/Users/karim/Desktop/class/DAA/2.bat' using 1:2 w lp lc rgb 'blue' lw 2 pt 7 title 'selection short','C:/Users/karim/Desktop/class/DAA/3.bat' using 1:2 w lp lc rgb 'green' lw 2 pt 7 title 'insertion short'\"");
  return 0;
}