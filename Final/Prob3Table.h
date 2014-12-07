/* 
 * File:   Prob3Table.h
 * Author: Hamza Khan
 *
 * Created on December 7, 2014, 1:01 PM
 */

#ifndef PROB3TABLE_H
#define	PROB3TABLE_H

#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

template<class T>
class Prob3Table
{
    protected:
        int rows;                                 //Number of rows in the table
        int cols;                                 //Number of cols in the table
        T *rowSum;                                //RowSum array
        T *colSum;                                //ColSum array
        T *table;                                 //Table array
        T grandTotal;                             //Grand total
        void calcTable(void);                     //Calculate all the sums
    public:
        Prob3Table(char *,int,int);               //Constructor then Destructor
        ~Prob3Table(){delete [] table;delete [] rowSum;delete [] colSum;};
        const T *getTable(void){return table;};
        const T *getRowSum(void){return rowSum;};
        const T *getColSum(void){return colSum;};
        T getGrandTotal(void){return grandTotal;};
};
template<class T>
Prob3Table<T>::Prob3Table(char *f, int row, int col)
{
  //Set rows and columns
    rows = row;
    cols = col;
  //Instantiate pointers
    T* tab = new T[rows*cols];
  //Declare Variables
    fstream file;
    string hold;
  //Extract information
    file.open(f,ios::in);
    for(int i = 0; i < rows; i++)
    {
        getline(file,hold);
        int temp = 0;
      //Extract the ints
        for(int j = 0; j < cols; j++)
        {
            tab[i*cols+j] = atoi(hold.c_str());
            hold.erase(hold.begin(),hold.begin()+6);
            //cout<<"  "<<tab[i*cols+j];
        }
        //cout<<endl;
      
    }
  //Copy values to table
    table = tab;
  //Close file
    file.close();
  //Make Row/column Sums
    T* rowAdd = new T[cols];
    for(int i=0; i<cols; i++)
    {
        int foo = 0;
        for(int j=0; j<rows; j++)
        {
            foo += table[j*cols+i];
        }
        rowAdd[i]=foo;
    }
    rowSum = rowAdd;
    T* colAdd = new T[rows];
    for(int i=0; i<rows; i++)
    {
        int foo = 0;
        for(int j=0; j<cols; j++)
        {
            foo += table[i*cols+j];
        }
        colAdd[i]=foo;
    }
    colSum = colAdd; 
  //Finish with the grandtotal
    int total = 0;
    for(int i = 0; i<cols*rows; i++){
        total += table[i];
    }
    grandTotal = total;
    
}


#endif	/* PROB3TABLE_H */
