#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static const char alphabet[] =
"abcdefghijklmnopqrstuvwxyz"
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"0123456789";

static const int alphabetSize = sizeof(alphabet) - 1;

void bruteImpl(char* str, int index, int maxDepth)
{
    for (int i = 0; i < alphabetSize; ++i)
    {
        str[index] = alphabet[i];

        if (index == maxDepth - 1) printf("%s\n", str);
        else bruteImpl(str, index + 1, maxDepth);
    }
}
