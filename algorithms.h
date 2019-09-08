//
// Created by osama on 07/09/19.
//
#include <fstream>
#ifndef TRABALHO02_ALGORITHMS_H
#define TRABALHO02_ALGORITHMS_H

int check_iterator(int i);
int quickSort(int arr[], int low, int high, std::ofstream &output);
void printArray(int arr[], int size);
int Sequential(int arr[], int val, int size);
int binarySearch(int arr[], int l, int r, int x, std::ofstream &output);
#endif //TRABALHO02_ALGORITHMS_H
