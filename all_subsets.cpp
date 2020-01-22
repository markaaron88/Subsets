/*
Write a C++ program called all_subsets.cpp which displays all subsets of a set.

Your program should read n characters from a user and display all subsets of the characters.

Your program should ask a user to enter the number of input characters.

After that, it should read the characters. For the problem, you can assume that the input characters are always distinct.


Number of input characters: 1
Enter 1 characters: a
===== All Subsets =====
empty
{a}
 */

#include <iostream>
#include <string>
#include <math.h>
#include <cstring>

using namespace std;

void subsets(char *arr, char *sub ,int index){
    if(index == strlen(arr)){
        cout << "{";
        for(int k = 0; k < strlen(sub); k++){
            cout << sub[k];
            if (k < strlen(sub) - 1){
                cout << ",";
            }
        }
        cout << "}";
    } else {
        sub[index] = ' ';
        subsets(arr, sub, index + 1);
        sub[index] = arr[index];
        subsets(arr, sub, index+1);
    }
}


int main()
{
    char *array; //pointer with array
    int num;
    int i;
    char word;


    cout << "Number of input Character: ";
    cin >> num;

    array = new char [num]; //array with num input
    cout << "\nEnter " << num << " characters: " <<  endl ;


    while (i < num){
        cin >> word;
        array[i] = word;
        i++;
    }

    int power = pow(2,num);
    char *sequel = new char[power];

    cout << "===== All Subsets =====" << endl;
    subsets(array, sequel ,0);
    delete[] array;
    delete[] sequel;
    return 0;
}