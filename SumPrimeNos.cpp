/*
 * Description: This program calculates the sum of primes
 * till the given Number
 * For e.g. if n=15, then output will be 2+3+5+7+11+13 = 41
 */

#include <iostream>
#include <math.h>

using namespace std;

long CalcSum(int iInput) {
    long lSum = 0;

    for (int iNum = 2; iNum < iInput; iNum++) {
        bool bIsPrimeNo = true;

        for (int j = 2; j <= sqrt(iNum); j++) {
            if (iNum % j == 0) {
                bIsPrimeNo = false;
                break;
            }
        }
        if (bIsPrimeNo) {
            //cout << iNum << "  ";
            lSum += iNum;
        }
    }
    return lSum;
}

int main() {

    int iNum;
    cout << "Enter the Number: ";
    cin >> iNum;
    cout << "\nSum is :" << CalcSum(iNum);

    return 0;
}