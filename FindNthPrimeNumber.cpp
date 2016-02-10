/*
 * Description: This program calculates the nth primes number
 * For e.g. if n=1000000, then output will be 15485863 which is nth Prime number
 */

#include <iostream>
#include <vector>
#include <sys/time.h>
#include <unistd.h>

using namespace std;

long GetCurrTimeInMicro()
{
    struct timeval tv;
    gettimeofday(&tv,NULL);
    return 1000000 * tv.tv_sec + tv.tv_usec;
}

class FindPrime {

public:

    vector<long> iaPrimes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

    bool IsPrime(long lVal) {
        bool bIsPrime = true;
/*
        if (lVal <= 1) {
            bIsPrime = false;
        } else if (lVal <= 3) {
            bIsPrime = true;
        } else if (lVal % 2 == 0 || lVal % 3 == 0) {
            bIsPrime = false;
        }

        int iCurrVal = 5;
        while (iCurrVal * iCurrVal <= lVal) {

            if (lVal % iCurrVal == 0 || lVal % (iCurrVal + 2) == 0) {
                bIsPrime = false;
                break;
            }
            iCurrVal += 6;
        }*/

        int i = 0;
        while (iaPrimes[i] * iaPrimes[i] <= lVal)
        {
            if (lVal % iaPrimes[i] == 0)
            {
                bIsPrime = false;
                break;
            }
            i++;
        }

        return bIsPrime;
    }

    long FindNthPrime(long lInput) {

        long lNum = 36;
        long lPrime = 0;
        long lCounter = 11;


        if (lInput < 12) {
            return (iaPrimes[(int) lInput - 1]);
        }

        long lNextNum;
        while (true) {
            lNextNum = lNum - 1;
            if (IsPrime(lNextNum)) {
                iaPrimes.push_back(lNextNum);
                lCounter++;
                if (lCounter == lInput)
                    return lNextNum;
            }
            lNextNum = lNum + 1;
            if (IsPrime(lNextNum)) {
                iaPrimes.push_back(lNextNum);
                lCounter++;
                if (lCounter == lInput)
                    return lNextNum;
            }
            lNum += 6;
        }
    }

};


int main() {

    int iCount;
    cout << "Enter the number of test cases: ";
    cin >> iCount;

    FindPrime F;
    int iNum;
    long lStartTime, lEndTime;

    for (int i = 0; i < iCount; i++) {
        cout << "\nEnter the Nth index: ";
        cin >> iNum;
        lStartTime = GetCurrTimeInMicro();
        cout << "\n" << iNum << "th Prime is :" << F.FindNthPrime(iNum) << endl;
        lEndTime = GetCurrTimeInMicro();
        cout << "Start Time " << lStartTime << " End Time " << lEndTime << " :: " << lEndTime-lStartTime << endl;
    }
    return 0;
}