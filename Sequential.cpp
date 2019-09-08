//
// Created by osama on 07/09/19.
//
#include <bits/stdc++.h>
#include "algorithms.h"
using namespace std;

int Sequential(int arr[], int val, int size)
{

    bool found = false;

    for (int i = 0; i < size; i++) {
        if (val == arr[i]) {
            found = true;
           // cout << "\nThe value "<< val <<" is found at index arr[" << i << "]\n";
            return i;
        }
    }
    if (!found) {
        //cout << "Key not found!\n";
        return -1;
    }
}