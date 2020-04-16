#include <stdio.h>

int textLength(char *txt)
{
    int i = 0;
    while (txt[i] != '\0')
    {
        i++;
    }
    return i;
}
int bruteForce(char *txt, char *pat)
{
    int txtLength = textLength(txt);
    int patLength = textLength(pat);
    int i = 0;
    while (i <= (txtLength - patLength))
    {
        int j = 0;
        while (j < patLength && txt[i + j] == pat[j])
        {
            j++;
        }
        if (j == patLength)
            return i;
        i++;
    }
    return -1;
}
int main()
{
    char *txt = "iremkcabcbabekser";
    char *pat = "ekser";
    int res = bruteForce(txt, pat);
    printf("%d", res);
    return 0;
}