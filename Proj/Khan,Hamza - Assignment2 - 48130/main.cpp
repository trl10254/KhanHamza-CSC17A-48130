//Khan, Hamza - Assignment 2 - 48130
//Created on September 17, 2014

//System Libraries
#include <cstdlib>
#include <iostream>
using namespace std;

//Function Prototypes
int *fillArray(int,int);
void printArray(int *,int,int);
int *sort(int *,int);
int *mode(int *,int);
float avg(int *,int);
float median(int *,int);


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
    
     //Find the mode
    mode(a,size);
    
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
        for(int j=i+1;j<n;j++){
            if(b[i]>b[j]){
                b[i]=b[i]^b[j];
                b[j]=b[i]^b[j];
                b[i]=b[i]^b[j];
            }
        }
    }
    
    return b;
}

void printArray(int *a,int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

int *fillArray(int n,int mod)
{
    //Allocate memory
    int *array=new int[n];
    
    //Initialize with 
    for(int i=0;i<n;i++){
        array[i]=i%mod;
    }
    return array;
}

int *mode (int *a, int)
{
    //Allocate memory
    int *array = new int;
    int countMode = 1;
    int count = 1;
    int mode = *array;
    
    //Initialize with
    if (array == *array[i])
    {
        //count occurrences of the current number
        countMode++;
    }
    else
    {
        //now this is a different number
        if (count > countMode)
        {
            countMode = count;
            mode = *array;
        }
        
        count = 1; //reset count for the new number
        mode = *array;
    }
    cout << "mode: " << mode << endl;
    
    return array;
}

float avg (int n, int)
{
    
}