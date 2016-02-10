#include <stdio.h>

#define MAX_ARRAY_LNGTH 100000

void FindMaxSubArr( int iaIpArr[], 
                    int iArrSize, 
                    int *piStartPos, 
                    int *piEndPos, 
                    int *piResult)
{
    int iSum = 0;
    int iCounter = 0;
    int iStart = 0;
    
    for (iCounter = 0; iCounter < iArrSize; iCounter++)
    {
        if (iSum + iaIpArr[iCounter] > 0)
        {
            if (iStart == 0)
            {
                iStart = iCounter;
            }

            iSum += iaIpArr[iCounter];
        }
        else
        {
            iSum = 0;
            iStart = 0;
        }
        
        if (*piResult < iSum)
        {
            *piResult = iSum;
            *piEndPos = iCounter;
            *piStartPos = iStart;
        }
    }
}

int main()
{
    int iaInputArr[MAX_ARRAY_LNGTH] = {1,-4,5,-2,6,3,-8,-20,11,7};
    int iResult = 0;
    int iCounter = 0;
    int iArrSize = 10;
    int iStartPos = 0, iEndPos = 0;
    
    FindMaxSubArr(iaInputArr, iArrSize, &iStartPos, &iEndPos, &iResult);
    
    printf("Max sum Sub Array is :");
    for (iCounter = iStartPos; iCounter <= iEndPos; iCounter++)
    {
        printf("%d ", iaInputArr[iCounter]);
    }
    printf("\nSum is: [%d]\n", iResult);

    return 0;
}

