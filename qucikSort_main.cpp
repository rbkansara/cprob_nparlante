/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>

using namespace std;

void quickSort(int *data, int low, int high);
int partion(int *data, int low, int high);
void swap(int *d1, int *d2);
int main()
{
    int i, n, *arr_data;
    printf("Enter no. of data to be sorted : ");
    cin >> n;
    
    // Input array for Sort 
    // ToDo: Check for valid Input
    arr_data = new int[n];
    for(i=0; i<n; i++)
    {
        cout <<"Enter " <<i << "th element : ";
        cin >> arr_data[i];
    }
    
    // Call quickSort
    quickSort(arr_data,0,n-1);
    
    // Sorted array
    printf("Sorted array: ");
    for(i=0; i<n; i++)
    {
        cout << arr_data[i] <<",";
    }
    
    delete[] arr_data;

    return 0;
}

void quickSort(int *data, int low, int high)
{
    if(low<high)
    {
        // pi partioning index
        int pi=partion(data, low, high);
        
        quickSort(data, low, pi-1);
        quickSort(data, pi+1, high);
    }
}

int partion(int *data, int low, int high)
{
    int pivot, i, j;
    pivot = data[high];  // pivot as last element of array
    i=low-1;    // i holds partition index, this is needed incase of sorted array
    
    for(j=low; j<high; j++)
    {
        if(data[j]<=pivot)
        {
            i++;
            swap(data[i],data[j]);
        }
    }
    swap(data[i+1],data[high]);
    return (i+1);
}
void swap(int *d1, int *d2)
{
    int *temp = d1;
    d1 = d2;
    d2 = temp;
}