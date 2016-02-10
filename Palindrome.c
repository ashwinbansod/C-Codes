#include <stdio.h>

int IsPalindrome(int iNum);

int main()
{
    int iRetVal = 0;
    int iInputNum = 0;
    
    printf("Enter the number : ");
    scanf("%d",&iInputNum);
    
    iRetVal = IsPalindrome(iInputNum);
    
    if (iRetVal == 0)
    {
        printf("The number [%d] is palindrome.\n", iInputNum);
    }
    else
    {
        printf("The number [%d] is not palindrome.\n",iInputNum);
    }

    return 0;
}

int IsPalindrome(int iNum)
{
    int iRetVal = 0;
    int iReverseNum = 0;
    int iTempVal = 0;
    int iOrigNum = iNum;
    
    while (iNum > 0)
    {
        iTempVal = iNum % 10;
        iReverseNum = iReverseNum * 10 + iTempVal;
        iNum = iNum / 10;
    }
    
    if (iOrigNum == iReverseNum)
    {
        iRetVal = 0;
    }
    else
    {
        iRetVal = 1;
    }
    
    return iRetVal;
}

