/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>

using namespace std;
void mergeSort(int *data, int start_i, int end_i);
void merge(int *data, int l, int m, int r);

int main()
{
    int n;
    int *array_data;
    cout << "Enter number of data to be sorted: ";
    cin >> n;
    array_data = new int[n];
    for(int i=0; i<n; i++)
    {
        cout <<"Input "<< i <<"th element:";
        cin >> array_data[i];
    }
    
    mergeSort(array_data, 0, n-1);
    
    // Sorted array_data
    cout << "Sorted array :";
    for(int i=0; i<n; i++)
    {
        cout <<array_data[i] <<",";
    }
    
    
    delete[] array_data;
    
    return 0;
}

void mergeSort(int *data, int start_i, int end_i)
{
    if(start_i < end_i)
    {
        int mid = (start_i+end_i)/2;
        
        // Sort both the parts
        mergeSort(data, start_i,mid);
        mergeSort(data, mid+1, end_i);
        
        // Merge both parts
        merge(data, start_i, mid, end_i);
    }
}
void merge(int *data, int l, int m, int r)
{
    int i, j, k;
    int n_left=m-l+1;
    int n_right=r-m;
    int left_arr[n_left], right_arr[n_right];
    
    // Fill two temp arrays
    for(i=0; i<n_left; i++)
        left_arr[i]=data[i+l];
    for(j=0; j<n_right; j++)
        right_arr[j]=data[j+m+1];
        
    i=0; // Index for left_arr[]
    j=0; // Index for right_arr[]
    k=l; // Index for data
    // Sort both array to data
    while(i<n_left && j<n_right)
    {
        if(left_arr[i]<=right_arr[j])
        {
            data[k]=left_arr[i];
            i++;
        }
        else
        {
            data[k]=right_arr[j];
            j++;
        }
        k++;
    }
    while(i<n_left)
    {
        data[k]=left_arr[i];
        k++;
        i++;
    }
    while(j<n_right)
    {
        data[k]=right_arr[j];
        k++;
        j++;
    }
}
