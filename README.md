Wildcard
========

A quick, minimal and efficient wildcard algorithm in C

Overview
========

- For efficiency the string is only ever traversed once
- The function exits early without comparing rest of string if last character in pattern is a '*'
- The function also exits early if there's a non match for a character before reaching a '*'

Use
===

example:
```
#include <stdio.h>
#include "wildcard.h"

int main()
{
    char str[200] = "foobarfoobar";
    char pattern[200] = "fo?*barfoo*";

    if (wildcard_strcmp(str, pattern))
        printf("Match\n");
    else
        printf("No Match\n");

    return 0;
}
```
