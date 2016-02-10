/*
 * Description: This program calculates the sum of all the even numbers of terms
 * that appear in the fibonacci series till the number n mentioned.
 * e.g. If n=20, result=2+8=10.
 * Time Complexity - O(n)
 * Space Complexity = O(n)
 */
#include <iostream>

using namespace std;

long fibEven(long lNum) {
    long lSum = 2;
    long lFirst = 1;
    long lSecond = 2;
    long lTempNum;

    while (true) {
        lTempNum = lFirst + lSecond;
        if (!(lTempNum < lNum))
            break;
        lFirst = lSecond;
        lSecond = lTempNum;

        if (lTempNum % 2 == 0)
            lSum += lTempNum;
    }
    return lSum;
}

int main() {
    int iCount = 0;
    cin >> iCount;

    long lNum;

    for (int i = 0; i < iCount; i++) {
        cin >> lNum;
        cout << fibEven(lNum) << endl;
    }
    return 0;
}