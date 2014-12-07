#include <cstdlib>
#include "Prob1Random.h"


int* Prob1Random::getFreq() const{
    return freq;
}
int Prob1Random::getNumRand() const{
    return numRand;
}
char* Prob1Random::getSet() const{
    return set;
}
char Prob1Random::randFromSet(int rand){
  //Increment the frequency of the picked element number
    freq[rand]++;
  //Increment total calls to this function
    numRand++;
  //Return the value accessed
    return set[rand];
    
}
Prob1Random::~Prob1Random(){
  //deallocate memory stored by dynamic pointers
    delete [] set;
    delete [] freq;
}
Prob1Random::Prob1Random(const char n, const char *a){
  //Assign Numbers in the data set
    nset = n;
  //Make an array in the object to match the random numbers array
    char* randSet = new char[n];
    for(int i=0;i<n;i++)
        randSet[i] = a[i];
    set = randSet;
  //Make an array to store the frequencies
    int* frequency = new int[n];
    for(int i=0;i<n;i++)
        frequency[i] = 0;
    freq = frequency;
  //Clear memory at numRand
    numRand = 0;
    
}
