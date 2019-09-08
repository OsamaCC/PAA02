#include <iostream>
#include "algorithms.h"
#include <fstream>
#include <string>
#include <iomanip>
#include <time.h>
#include <mutex>

using namespace std;

mutex mtx;


// Fucntion to convert a string to
// integer array
int * convertStrtoArr(string str, int amount, ofstream &output)
{
    int *arr;
    arr = (int *) calloc(amount, sizeof(int));
    int j = 0, i;
    // get length of string str
    //int str_length = str.length();
    // create an array with size as string
    // length and initialize with 0
    //int arr[str_length] = { 0 };
    // Traverse the string
    for (i = 0; str[i] != '\0'; i++) {

        // if str[i] is ', ' then split
        if (str[i] == ' ') {

            // Increment j to point to next
            // array location
            j++;
        }
        else {
            // subtract str[i] by 48 to convert it to int
            // Generate number by multiplying 10 and adding
            // (int)(str[i])
            arr[j] = arr[j] * 10 + (str[i] - 48);
        }
    }
    return arr;
}

void search(string str, int amount, ofstream &output, int *original, int flag)
{
    int *arr;
    arr = (int *) calloc(amount, sizeof(int));
    int idx = 0;
    int j = 0, i;
    int maxComp = 0;


    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') j++;
        else arr[j] = arr[j] * 10 + (str[i] - 48);
    }

    if (flag == 0)
    {
        for(i = 0; i < amount; i++){
            idx = Sequential(original, arr[i], amount);
            if(idx > maxComp)
            {
                maxComp = idx;
            }
            /*(idx == -1) ? cout << "Element is not present in array\n"
                           : output << arr[i] << " was found at index: "  << idx << endl;*/
        }
        output << ","  << "Sequential" << "," << maxComp + 1 << ",";

    }
    else if (flag == 1)
    {
        for(i = 0; i < amount; i++){
            int result = binarySearch(original, 0, amount - 1, arr[i], output);
/*             (result == -1) ? cout << "Element is not present in array\n"
                            : output << arr[i] << " was found at index: "  << result << endl; */
            if(result > maxComp)
            {
                maxComp = result;
            }
        }
        output << ","  << "Binary" << "," << maxComp << ",";
    }
}

int main()
{

    int count = 0, i;
    int amount = 0;
    string line;
    clock_t t;
    double time_taken;
    ofstream output;
    int it = 1;
    for(i = it; i <= it; i++)
   {
       output.open("/home/osama/CLionProjects/trabalho02/Saida.csv", std::ios::app); //LEMBRE DE USAR APP
       if (i == 1) output << "Iteration" << "," << "Method" << "," << "Swaps"  << "," << "Time taken" << endl;
       amount = check_iterator(i);
       string Result = static_cast<ostringstream *>( &(ostringstream() << i))->str();
       ifstream myfile ("/home/osama/CLionProjects/trabalho02/Proposta4/" + Result + ".txt");
       output << i;

       int *line1;
       line1 = (int *) calloc(amount, sizeof(int));
       if (myfile.is_open())
       {
           while ( getline (myfile,line) )
           {
               //cout << line << '\n';
               if(count == 0)
               {
                   t = clock();
                   line1 = convertStrtoArr(line, amount, output);
                   int swap = quickSort(line1, 0, amount - 1, output);
                   output << ","  << "QuickSort" << ","  << swap << ",";
                   t = clock() - t;
                   time_taken = ((double) t) / CLOCKS_PER_SEC;
                   output  << time_taken << endl;
                   /*cout << "\nSorted array: \n";
                   printArray(line1, amount);*/
                   count++;
               }
               else{
                   //output << "------------------- INITIALIZING SEQUENTIAL SEARCH... ------------------- " << endl << endl;
                   t = clock();
                   search(line, amount, output, line1, 0); // Busca sequencial
                   t = clock() - t;
                   time_taken = ((double) t) / CLOCKS_PER_SEC;
                   output << time_taken << endl;

                  // output << "------------------- INITIALIZING BINARY SEARCH... ------------------- " << endl << endl;
                   t = clock();
                   search(line, amount, output, line1, 1); // Busca sequencial
                   t = clock() - t;
                   time_taken = ((double) t) / CLOCKS_PER_SEC;
                   output << time_taken << endl << endl;
                   count = 0;
               }
           }
       }

       else cout << "Unable to open file: " << i << endl;
       myfile.clear();
       myfile.close();
       output.close();
   }

    return 0;
}