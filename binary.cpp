//
// Created by osama on 07/09/19.
//

// C++ program to implement recursive Binary Search
#include <iostream>
#include "algorithms.h"
using namespace std;

// A iterative binary search function. It returns
// location of x in given array arr[l..r] if present,
// otherwise -1
int binarySearch(int arr[], int l, int r, int x, ofstream &output)
{
    int count = 0;
    while (l <= r) {
        int m = l + (r - l) / 2;

        // Check if x is present at mid
        if (arr[m] == x)
        {
            //output << "Binary Search took " << count << " iteration(s) to find " << x << "." << endl;
            return count;
        }


        // If x greater, ignore left half
        if (arr[m] < x)
        {
            count++;
            l = m + 1;
        }

            // If x is smaller, ignore right half
        else
        {
            count++;
            r = m - 1;
        }
    }

    // if we reach here, then element was
    // not present
    return -1;
}
  