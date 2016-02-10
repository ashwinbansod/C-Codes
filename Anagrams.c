#include <stdio.h>
#include <limits.h> /* for UCHAR_MAX (usually 255) */

int find_anagrams (char *word, char *text) {
    int len = 0;           /* length of search word */
    int bin[UCHAR_MAX+1];  /* excess count of each char in last len chars of text */
    int mismatch = 0;      /* count of nonzero values in bins[] */
    int found = 0;         /* number of anagrams found */
    int i;                 /* generic loop counter */

    /* initialize bins */
    for (i = 0; i <= UCHAR_MAX; i++) bin[i] = 0;
    
    for (i = 0; word[i] != '\0'; i++) 
    {
        unsigned char c = (unsigned char) word[i];
        if (bin[c] == 0) mismatch++;
        bin[c]--;
        len++;  /* who needs strlen()? */
    }

    /* iterate through text */
    for (i = 0; text[i] != '\0'; i++) 
    {
        /* add next char in text to bins, keep track of mismatch count */
        unsigned char c = (unsigned char) text[i];
        if (bin[c] == 0) mismatch++;
        if (bin[c] == -1) mismatch--;
        bin[c]++;

        /* remove len-th previous char from bins, keep track of mismatch count */
        if (i >= len) {
            unsigned char d = (unsigned char) text[i - len];
            if (bin[d] == 0) mismatch++;
            if (bin[d] == 1) mismatch--;
            bin[d]--;
        }

        /* if mismatch count is zero, we've found an anagram */
        if (mismatch == 0) {
            found++;
//#ifdef DEBUG
            /* optional: print each anagram found */
            printf("Anagram found at position %d: \"", i-len+1);
            fwrite(text+i-len+1, 1, len, stdout);
            printf("\"\n");
//#endif
        }
    }
    return found;
}


int main (int argc, char *argv[]) 
{
    if (argc == 3) 
    {
        int n = find_anagrams(argv[1], argv[2]);
        printf("Found %d anagrams of \"%s\" in \"%s\".\n", n, argv[1], argv[2]);
        return 0;
    } 
    else 
    {
        fprintf(stderr, "Usage: %s <word> <text>\n", (argc ? argv[0] : "countanagrams"));
        return 1;
    }
}

