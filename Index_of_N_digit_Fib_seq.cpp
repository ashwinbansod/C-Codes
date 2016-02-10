/*
 * Description: This program returns the index of the term of
 * the fibonacci series with 'n' digits.
 * For e.g. if n=2, the term is 7. Term=13.
 */

#include <iostream>
#include <math.h>

using namespace std;

long indexOfTerm(long lDigits) {
    long lIdx = 2;
    long lCount = 0;
    long lFirst = 1;
    long lSecond = 1;
    long lTempVal;

    while (lCount < 1) {
        lTempVal = lFirst + lSecond;
        lFirst = lSecond;
        lSecond = lTempVal;

        //cout << lTempVal << "  ";

        lCount = lTempVal / (long) pow(10, lDigits - 1);
        lIdx++;
    }
    cout << " The Number is : " << lTempVal << endl;
    return lIdx;
}

int main() {

    int iNum;
    cout << "Enter the Number of Digits : ";
    cin >> iNum;
    cout << "" << indexOfTerm(iNum);

    return 0;
}