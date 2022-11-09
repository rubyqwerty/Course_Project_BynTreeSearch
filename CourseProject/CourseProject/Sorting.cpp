#include "pch.h"
#include "Sorting.h"

int SortByBynaryTreeSearch(int* Array, int Size)
{
    int* CopyArray = new int[Size];
    for (int i = 0; i < Size; ++i) CopyArray[i] = Array[i];

    unsigned int start_time = clock();
    
	BynaryTreeSearch* bts = new BynaryTreeSearch;

	for (int i = 0; i < Size; ++i)
		bts->push(CopyArray[i]);
	bts->bypassing(CopyArray);

    unsigned int end_time = clock(); 
    unsigned int search_time = end_time - start_time; 

    delete[] CopyArray;

    return search_time;
}

int BubbleSorting(int* Array, int size)
{
    int* CopyArray = new int[size];
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
    unsigned int search_time = end_time - start_time; 

    delete[] CopyArray;

    return search_time;
}