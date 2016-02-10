#include <iostream>

using namespace std;
/*! QUESTION:
 *  Given an array of numbers, return an array of numbers with the
 *  product of all the numbers in the array except the number itself
 *  WITHOUT using division.
 */

int main();

int MultiplyElements(int iaInputArr[], int iSize) {
    int iaProductArr[iSize];
    int iaProductLeft[iSize];
    int iaProductRight[iSize];
    int iIntrmdtProduct = 1;

    // The Multiplication of all the digits to the left of the number will be stored in this array.
    // The loop will run till iSize-2 as we have to skip one number in our product
    for (int i = 0; i < iSize-1 ; i++)
    {
        iaProductLeft[i] = iIntrmdtProduct;
        iIntrmdtProduct *= iaInputArr[i];
    }

    //Resetting the intermediate variable.
    iIntrmdtProduct = 1;

    // The Multiplication of all the digits to the Right of the number will be stored in this array.
    // For this we will run the loop in reverse direction and update the ProductRight array.
    for (int i = iSize-1; i >= 0; i-- )
    {
        iaProductRight[i] = iIntrmdtProduct;
        iIntrmdtProduct *= iaInputArr[i];
    }

    for (int i = 0; i < iSize; i++)
    {
        iaProductArr[i] = iaProductLeft[i] * iaProductRight[i];
        cout << iaProductArr[i] << "  " ;
    }

    return 0;
}

int main() {
    int iaInputArr[] = {1, 3, 1, 4, 2, 5};
    int iArrSize = 6;

    // Evaluation the product array.
    MultiplyElements(iaInputArr, iArrSize);

    return 0;
}