#include <stdio.h>
#include <math.h>
int prime = 3;
int textLength(char *txt)
{
    int i = 0;
    while (txt[i] != '\0')
    {
        i++;
    }
    return i;
}
int firstHash(char *pat, int patLength)
{
    int h = 0;
    for (int i = 0; i < patLength; i++)
    {
        h += (pat[i] - 'a' + 1) * pow(prime, i);
    }
    return h;
}
int rabinKarp(char *txt, char *pat)
{
    int txtLength = textLength(txt);
    int patLength = textLength(pat);
    int i = 0;
    int hash = firstHash(pat, patLength);
    while (i <= (txtLength - patLength))
    {
        int j = 0, h = 0;
        while (j < patLength)
        {
            h += (txt[i + j] - 'a' + 1) * pow(prime, j);
            j++;
        }
        if (hash == h)
            return i;
        i++;
    }
    return -1;
}
int main()
{
    char *txt = "iremkcabcbabekser";
    char *pat = "ekser";
    int hash = rabinKarp(txt, pat);
    printf("%d", hash);
    return 0;
}