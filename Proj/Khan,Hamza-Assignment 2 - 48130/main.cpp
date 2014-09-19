/* 
 * File:   Khan, Hamza - Assignment 2 - 48130
 * Author: Hamza Khan
 *
 * Created on September 19, 2014, 2:50 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

//Function Prototypes
int *fillArray(int,int);
void printArray(int *,int,int);
int *sort(int *,int);
int *mode(int *,int);
float avg(int *,int);
float median(int *,int);

//Execution begins here
int main(int argc, char** argv) 
{
    //Create the array
    int size=100;
    int *a=fillArray(size,5);
    
    //Sort the array
    int *b=sort(a,size);
    
    //Print the result
    printArray(a,size,10);
    printArray(b,size,10);
    
    //Show the average of the function
    cout << fixed << setprecision(2) << endl;
    cout << "The mean or the average of the function is: "<< avg(a,size) << endl;
    
    //Show the median of the function
    cout << fixed << setprecision(2) << endl;
    cout << "The median of the function is: " << median(a,size) << endl;
    //Deallocate memory and exit
    delete []a;
    delete []b;
    return 0;
    
}

int *sort(int *a,int n)
{
    //Allocate a sortable array
    int *b=new int[n];
    //Copy the array
    for(int i=0;i<n;i++)
    {
        b[i]=a[i];
    }
    //Sort the array
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(b[i]>b[j])
            {
                b[i]=b[i]^b[j];
                b[j]=b[i]^b[j];
                b[i]=b[i]^b[j];
            }
        }
    }
    return b;
}

void printArray(int *a,int n,int perLine)
{
    cout << endl;
    for(int i=0;i<n;i++)
    {
        cout << a[i]<<" ";
        if(i%perLine==(perLine-1)) cout << endl;
    }
    cout << endl;
}

int *fillArray(int n,int mod)
{
    //Allocate memory
    int *array=new int[n];
    
    //Initialize with 
    for(int i=0;i<n;i++)
    {
        array[i]=i%mod;
    }
    return array;
}


float avg(int *a,int size)
{
    float total = 0;
    
    //Does the calculations for the average
    for(int i=0;i<size;i++)
    {
        total += a[i];
    }
    
    return total/size;
}

float median(int *a,int size)
{
    float median;
    
    //Find out if the system is even or odd
    for (int i=0; i<size; i++)
    {
        if(size % 2 != 0) //Decides if the function is odd
        {
            median = a[(size+1/2)-1];
        }
        else
        {
            median = a[(size/2) - 1];
            median = a [size/2];
        }
    }
 
    return median;
}
