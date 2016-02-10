/* Description: Find longest plaindron substing in the given string.
 */
 
#include <iostream>
#include <string.h>
 
using namespace std;
 

// This function prints the longest palindrome substring
// of str[].
// It also returns the length of the longest palindrome
int FindLongestPalindrome( char *pcaStr )
{
    int iLen;
    int iMaxLen = 1;
    int iStart = 0;
    
    /* Length of input string  */
    iLen = strlen( pcaStr ); 
 
    bool M[iLen][iLen];
    memset(M, 0, sizeof(M));
 
    // All substrings of length 1 are palindromes
    
    for (int i = 0; i < iLen; ++i)
    {
        M[i][i] = true;
    }
 
    // check for sub-string of length 2.
    for (int i = 0; i < iLen-1; ++i)
    {
        if (pcaStr[i] == pcaStr[i+1])
        {
            M[i][i+1] = true;
            iStart = i;
            iMaxLen = 2;
        }
    }
 
    // Check for substring lengths greater than 2
    for (int iStrLen = 3; iStrLen <= iLen; ++iStrLen)
    {
        // Fix the starting index
        for (int i = 0; i < iLen-iStrLen+1 ; ++i)
        {
            // Get the ending index of substring from
            // starting index i and length iStrLen
            int iEnd = i + iStrLen - 1;
 
            // check if sub-string is palindrome
            if (M[i+1][iEnd-1] && pcaStr[i] == pcaStr[iEnd])
            {
                M[i][iEnd] = true;
 
                if (iStrLen > iMaxLen)
                {
                    iStart = i;
                    iMaxLen = iStrLen;
                }
            }
        }
    }
 
    cout << "Longest palindrome substring is: ";
    for( int i = iStart; i <= iStart + iMaxLen - 1; ++i )
        cout << pcaStr[i];
    
 
    return iMaxLen; 
}
 

int main()
{
    char caInput[] = "abbaaaabbaaa";
    
    cout << "\nLength is:" << FindLongestPalindrome( caInput ) << endl;
    
    return 0;
}