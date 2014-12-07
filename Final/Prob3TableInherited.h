/* 
 * File:   Prob3TableInherited.h
 * Author: Hamza Khan
 *
 * Created on December 7, 2014, 1:02 PM
 */

#ifndef PROB3TABLEINHERITED_H
#define	PROB3TABLEINHERITED_H

#include "Prob3Table.h"

template<class T>
class Prob3TableInherited : public Prob3Table<T>
{
	protected:
            T *augTable; 
	public:
          //Constructor
            Prob3TableInherited<T>(char *file,int row, int col) : Prob3Table<T>(file,row,col)
            { 
                T* sumTable = new T[(Prob3Table<T>::rows+1)*(Prob3Table<T>::cols+1)];
              //Place table data
                for(int i=0; i < Prob3Table<T>::rows; i++)
                {
                    for(int j=0; j < Prob3Table<T>::cols; j++)
                    {
                        sumTable[i*(Prob3Table<T>::cols+1)+j] = Prob3Table<T>::table[i*Prob3Table<T>::cols+j];
                    }
                }
              //Place summation data
                for(int i=0; i<Prob3Table<T>::cols; i++)
                {
                    sumTable[((Prob3Table<T>::cols+1)*Prob3Table<T>::rows)+ i] = Prob3Table<T>::rowSum[i];
                }
                for(int i=0; i<Prob3Table<T>::rows; i++)
                {
                    sumTable[(Prob3Table<T>::cols+1)*(i+1)-1] = Prob3Table<T>::colSum[i];
                }
              //Place Grandtotal
                sumTable[(Prob3Table<T>::rows+1)*(Prob3Table<T>::cols+1)-1] = Prob3Table<T>::grandTotal;
              //Set pointer
                augTable = sumTable;
            }//Constructor
            ~Prob3TableInherited<T>()
            {
                delete [] augTable;
            }  //Destructor
            const T *getAugTable(void){return augTable;}; 
};

#endif	/* PROB3TABLEINHERITED_H */

