/* 
 * File:   Prob2Sort.h
 * Author: Hamza Khan
 *
 * Created on December 7, 2014, 12:59 PM
 */

#ifndef PROB2SORT_H
#define	PROB2SORT_H

#include <cstdio>

template<class T>
class Prob2Sort
{
	private:
		int *index;                                   //Index that is utilized in the sort
	public:
		Prob2Sort(){index = NULL;};                   //Constructor
		~Prob2Sort(){delete []index;};                //Destructor
		T* sortArray(const T* t,int length, int pos, bool ascend)
                {
                  //Set index array
                    int *ind = new int[length];
                    index = ind;
                  //Copy T array t
                    T *toSort = new T[length];
                    for(int i=0; i<length; i++)
                    {
                        toSort[i]=t[i];
                    }
                  //Sort array
                    
                    for(int i=0; i<length-1; i++)
                    {
                        T placeHolder;
                        for(int j=i; j<length; j++)
                        {
                            if(((toSort[j][pos] < toSort[i][pos])&&ascend)
                               ||(toSort[j][pos] > toSort[i][pos])&&!ascend)
                            {
                                placeHolder = toSort[i];
                                toSort[i] = toSort[j];
                                toSort[j] = placeHolder;
                            }
                        }                        
                    }
                  //Return Sorted Array
                    return toSort;
                }                                             //Sorts a single column array
}; 


#endif	/* PROB2SORT_H */
