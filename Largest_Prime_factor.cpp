/*
 * Description: This program finds the largest prime factor of
 * the input. e.g. 13195 has the largest prime factor
 * as 29.
 * Time Complexity - O(n)
 * Space Complexity - O(n)
 */
#include <iostream>
#include <math.h>

using namespace std;

long IsLargetPrime(long lNum){
    long lResult = 0;
    long lDuplicate = lNum;
    int iCount = 0;
    while (lNum % 2 == 0){
        lResult = 2;
        lNum /= 2;
    }
    while (lNum % 3 == 0){
        lResult = 3;
        lNum /= 3;
    }
    int iCurrNum = 5;
    while (iCurrNum <= lNum){
        while (lNum % iCurrNum == 0){
            lResult = iCurrNum;
            lNum /= iCurrNum;
        }
        while (lNum % (iCurrNum + 2) == 0){
            lResult = iCurrNum + 2;
            lNum /= (iCurrNum + 2);
        }
        if ((lResult * lResult < lNum) && (iCurrNum > sqrt(lDuplicate))){
            iCount++;
            lResult = lNum;
            break;
        }
        iCurrNum +=6;
    }
    return lResult;
}

int main() {

    int iCount = 0;
    cin >> iCount;

    long lNum;
    for (int i = 0; i < iCount; i++){
        cin >> lNum;
        cout << IsLargetPrime(lNum) << endl;
    }

    return 0;
}