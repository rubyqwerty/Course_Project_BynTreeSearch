#include "pch.h"
#include "Sorting.h"

int SortByBynaryTreeSearch(vector<int>& Array, int Size)
{
    vector<int> SortArray;

    unsigned int start_time = clock();
    
	BynaryTreeSearch bts;
    
    for (int i = 0; i < Size; ++i)
        bts.push(Array[i]);

	bts.bypassing(SortArray);

    unsigned int end_time = clock(); 
    unsigned int sort_time = end_time - start_time; 

    return sort_time;
}

int BubbleSorting(vector<int>& Array, int size)
{
    vector<int> CopyArray(size);
    for (int i = 0; i < size; ++i) CopyArray[i] = Array[i];

    unsigned int start_time = clock(); 

    for (int i = 0; i < size - 1; i++)
        for (int j = (size - 1); j > i; j--) 
            if (CopyArray[j - 1] > CopyArray[j])
            {
                int temp = CopyArray[j - 1];
                CopyArray[j - 1] = CopyArray[j];
                CopyArray[j] = temp;
            }

    unsigned int end_time = clock(); 
    unsigned int sort_time = end_time - start_time; 

    return sort_time;
}