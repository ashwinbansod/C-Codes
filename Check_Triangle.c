#include <stdio.h>

int main()
{
    int iRetVal = 0;
    int a, b, c;
    int max, s1, s2;
    
    
    printf("Enter the value of 3 sides of triangle: ");
    scanf("%d %d %d",&a, &b, &c);
    
    if (a == b && b == c)
    {
        printf("Sides [%d] [%d] [%d] : Equilaterial Triangle.\n",a,b,c);
    }
    else
    {
        if (a < b)
        {
            if (b < c)
            {
                max = c;
                s1 = a;
                s2 = b;
            }
            else
            {
                max = b;
                s1 = a;
                s2 = c;
            }
        }
        else
        {
            if (a < c)
            {
                max = c;
                s1 = a;
                s2 = b;
            }
            else
            {
                max = a;
                s1 = b;
                s2 = c;
            }
        }
        
        if (((s1 * s1) + (s2 * s2)) == (max *max))
        {
            printf("Sides [%d] [%d] [%d] : Right Angled Triangle.\n",
                    max,s1,s2);
        }
        else if ((a == b) || (b == c) || (a == c))
        {
            printf("Sides [%d] [%d] [%d] : Isosceles Triangle.\n",a,b,c);
        }
        else
        {
            printf("Sides [%d] [%d] [%d] : Scalene Triangle.\n",a,b,c);
        }
    }

    return iRetVal;
}

