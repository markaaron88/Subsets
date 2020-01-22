/*
 Abstract: Write a C++ program called all_subsets.cpp which displays all subsets of a set. In the problem,
 your program should read n characters from a user and display all subsets of the characters.
 In the program, you can assume that the number of input characters is less than or equal to 15.
 Your program should ask a user to enter the number of input characters. After that, it should read the characters. For the problem,
 you can assume that the input characters are always distinct.
 Author: Mark Mariscal
 ID: 7198
 Date: 01/21/2020
 */

#include <iostream>
#include <string>
#include <math.h>
#include <cstring>

using namespace std;

void subsets(char *array, char *sub ,int index){

    if(index == strlen(array))
    {
        cout << "{";

        for(int i = 0; i < strlen(sub); i++){
            cout << sub[i];
            if (i < strlen(sub) - 1){
                cout << ",";
            }
        }

        cout << "}";
    } else {
        sub[index] = ' ';
        subsets(array, sub, index + 1);
        sub[index] = array[index];
        subsets(array, sub, index+1);
    }
}


int main()
{
    char *array;
    int number;
    int k;
    char character;


    cout << "Number of input characters: ";
    cin >> number;

    array = new char [number];
    cout << "\nEnter " << number << " characters: " <<  endl ;

    while (k < number){
        cin >> character;
        array[k] = character;
        k++;
    }

    int power = pow(2,number);
    char *set = new char[power];

    cout << "===== All Subsets =====" << endl;
    subsets(array, set ,0);
    delete[] array;
    delete[] set;
    return 0;
}