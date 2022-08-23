#include<iostream>
#include<cstdlib>
#include<time.h>
int count = 0,// count bubble veriable
count1 = 0 , // count selection veriable
count2 = 0 , // count inserction veriable
sizeofarray1 = 0 , // buubleshort size of array for loop
sizeofarray2 = 0 ,// selectionsort size of array for loop
sizeofarray3 = 0; // user define six\ze for array
using namespace std;
void swap(int *xp, int *yp)// swap function
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void bubbleshort(int a[]) //algotithm function
{
  for (int i = 0; i < sizeofarray1 ; i++ ,count = count+1)  // outer or loop
  {
        for (int  j = 0; j < (sizeofarray1-i-1); j++,count = count+1) 
    {
      
      if (a[j]>a[j+1],count = count+1) // swap Loop
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
    int i, j, min_idx;
 
    // One by one move boundary of
    // unsorted subarray
    for (i = 0; i < sizeofarray2-1; i++, count1 = count1+1)
    {
       
        // Find the minimum element in
        // unsorted array
        min_idx = i;
        for (j = i+1; j < sizeofarray2; j++,count1 = count1+1)
        {
          if (arr[j] < arr[min_idx])
           { min_idx = j;}
        // Swap the found minimum element
        // with the first element
        swap(&arr[min_idx], &arr[i]),count1 = count1+1;
        }
    }
}
void insertionsort(int arr[])
{
    int i, key, j;
    for (i = 1; i < sizeofarray3; i++,count2 = count2+1)
    {
        key = arr[i];
        j = i - 1;
 
        // Move elements of arr[0..i-1], 
        // that are greater than key, to one
        // position ahead of their
        // current position
        while (j >= 0 && arr[j] > key )
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        count2 = count2+1;
        arr[j + 1] = key;
    }
}
int main()
{
  int it = 0 ;
  // double t1[10],t2[10],t3[10];// Store time variables
  // clock_t start,end;
  cout<<"Enter BubbleShort size of array: ";
  cin>>sizeofarray1;
  // cout<<"Enter SelectionSort size of array: ";
  // //cin>>sizeofarray2;
  // cout<<"Enter InserctionSort size of array: ";
  //cin>>sizeofarray3;

  int bubbleshortarray[sizeofarray1];
  // int Selectionshortarray[sizeofarray2];
  // int Inserctionshortarray[sizeofarray3];
   for (int i = 0; i < sizeofarray1; i++)   // Loop for bubbleshortarray
  {
    bubbleshortarray[i] = rand();
  }
  // for (int i = 0; i < sizeofarray2; i++)   // Loop for Selectionshort
  // {
  //   Selectionshortarray[i] = rand();
  // }
  // for (int i = 0; i < sizeofarray3; i++)   // Loop for Inserctionshort
  // {
  //   Inserctionshortarray[i] = rand();
  // }
  // t1[it] = ((double)(end - start));
  // start = clock();
  // bubbleshort(bubbleshortarray);
  // end = clock();
  // start = 0;
  // end = 0;
  // start = clock();
  // selectionsort(Selectionshortarray); 
  // end = clock();
  // t2[it] = ((double)(end - start));
  // t3[it] = ((double)(end - start));
  // start = 0.0;
  // start = clock();
  // insertionsort(Inserctionshortarray);
  // end = clock();
  // output stream line
  cout<<"Time complexcity for bubbleshort  size of "<<sizeofarray1<<" will be O ["<<count<<"]" <<endl;
  //cout<<"Time complexcity for bubbleshort  ["<<(int long)t1[it]<<"]" <<endl;
  // cout<<"Time complexcity for selectionsort a size of "<<sizeofarray2<<" will be O ["<<count1<<"]" <<endl;
  // //cout<<"Time complexcity for selectionsort  ["<<(int long)t2[it]<<"]" <<endl;
  // cout<<"Time complexcity for inserctionsort a size of "<<sizeofarray3<<" will be O ["<<count2<<"]" <<endl;
  //cout<<"Time complexcity for inserctionsort  ["<<(int long)t3[it]<<"]" <<endl;
  /* for normal user input code
   for (int i = 0; i < x; i++)   // Loop for getting user inputs in aarray
  {
    cout<<"Enter data set array["<<i<<"]: ";
    cin>>myarray[i];
  }
  cout<<"Before shotting"<<endl; 
  for (int i = 0; i < x; i++)   // Loop before shotting
  {
    cout<<"Data in set array["<<i<<"]:"<<myarray[i]<<endl;
    
  } 
  
  bubbleshort(myarray); // Calling function on myarray  
  cout<<"After shotting"<<endl; 
  for (int i = 0; i < x; i++)   // Loop after shotting
  {
    cout<<"Data in set array["<<i<<"]:"<<myarray[i]<<endl;
    
  }
  */
  return 0;
}