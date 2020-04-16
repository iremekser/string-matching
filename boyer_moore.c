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
int boyerMoore(char *txt, char *pat)
{
    int arr[26];
    int txtLength = textLength(txt);
    int patLength = textLength(pat);
    for (int i = 0; i < 26; i++)
    {
        arr[i] = patLength;
    }
    for (int i = 0; i < patLength; i++)
    {
        arr[pat[i] - 'a'] = patLength - i - 1;
    }
    int i = patLength - 1;
    while (i < txtLength)
    {
        int j = patLength - 1;
        while (j >= 0 && pat[j] == txt[i - patLength + j + 1])
        {
            j--;
        }
        if (j < 0)
            return i;
        else
            i += arr[txt[i] - 'a'];
    }
    return -1;
}
int main()
{
    char *txt = "iremkcabcbabekser";
    char *pat = "ekser";
    int result = boyerMoore(txt, pat);
    printf("%d\n", result);
    return 0;
}
