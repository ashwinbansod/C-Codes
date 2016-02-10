#include <stdio.h>

int main()
{
    int iRetVal = 0;
    int a, b, c;
    int n, i;
    int temp;
    
    i = 3;
    a = 0;
    b = 0;
    c = 1;

    printf("Enter the value of n :");
    scanf("%d",&n);
    
    if (n < i)
    {
        printf("Invalid value of n.\n");
        iRetVal = 1;
    }
    else
    {
        while (i < n)
        {
            temp = a + b + c;
            a = b;
            b = c;
            c = temp;
            
            i++;
            
            //printf("%d :  a=[%d]  b=[%d]  c=[%d]\n",i,a,b,c);
        }
        
        printf("%dth element is : [%d]\n",n,c);
    }

    return 0;
}

