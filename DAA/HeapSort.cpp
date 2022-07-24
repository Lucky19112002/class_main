#include<iostream>
#include<chrono>
#include<fstream>
int sizeofarray1=0;
using namespace std;
using namespace std::chrono;


 void heapify(int arr[], int n, int i) {
    
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && arr[left] > arr[largest])
      largest = left;
  
    if (right < n && arr[right] > arr[largest])
      largest = right;
  
  
    if (largest != i) {
      swap(arr[i], arr[largest]);
      heapify(arr, n, largest);
    }
  }
  
  void heapSort(int arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--) {
      swap(arr[0], arr[i]);
      heapify(arr, i, 0);
    }
  }
  int main()
{
  {//bubble short 
    ofstream bf("file_out/heap.bat");
    bf<<"#Bubble sort in milliseconds"<<endl;
    cout<<endl<<"Working on bubble sort ....";
    for(sizeofarray1 =10000;sizeofarray1<=50000;sizeofarray1=sizeofarray1+10000)
    {
      int arr[sizeofarray1];
      for (int i = 0; i < sizeofarray1; i++)   // Loop for bubbleshortarray
      {
        arr[i] =rand() % 1000;
      }
      auto start = high_resolution_clock::now();
      ios_base::sync_with_stdio(false);
      heapSort(arr,sizeofarray1);
      auto stop = high_resolution_clock::now();
      auto duration = duration_cast<chrono::milliseconds>(stop - start);
      bf<<sizeofarray1<<" "<<fixed<<duration.count()<<endl;
      cout<<".";
    }
    bf.close();
    cout<<".... "<<"Done";
  }
 cout<<endl<<"Ploting the graph...";
  system("gnuplot -p -e \"set ylabel 'mileseconds' ; set xlabel 'data set' ; p 'G:\Sem_5/DAA/file_out/heap.bat' using 1:2 w lp lc rgb 'red' lw 2 pt 7 title 'heap'\"");
    return 0;
}