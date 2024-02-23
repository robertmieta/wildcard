/*****************************************************************************
  Copyright (c) 2020, Robert J. Mieta.
  All rights reserved.

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright notice,
      this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of author nor the names of its contributors
      may be used to endorse or promote products derived from this software
      without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
  THE POSSIBILITY OF SUCH DAMAGE.
*****************************************************************************
* Contents: Wildcard compare function
* Author: Robert J. Mieta
*****************************************************************************/


/***************************************************************************************************************************************************
This algorithm traverses the string and pattern one character at a time seeing if they match
If there's a non-match at any point after a wildcard '*' in the pattern, jump the pattern index back to the first character after the '*' and repeat
If we reach the end of the string before reaching the end of the pattern, we don't have a match
If we have a non character match before the first '*' is reached, we don't have a match

This way the string is only ever traversed once for ultimate efficiency
and exits early without comparing rest of string if last character in pattern is a '*'
or exists early if there's a non match for a character before reaching a '*'
****************************************************************************************************************************************************/

#include "wildcard.h"

// Returns true if match, false if no-match
_Bool wildcard_strcmp(char *str, char *pattern)
{
    _Bool wildcard = 0;
    char *placeholder;

    do
    {
        if ((*pattern == *str) || (*pattern == '?'))
        {
            str++;
            pattern++;
        }
        else if (*pattern == '*')
        {
            if (*(++pattern) == '\0')
                return 1;
            else
            {
                placeholder = pattern;
                wildcard = 1;
            }
        }
        else if (wildcard)
        {
            if (pattern == placeholder)
                str++;
            else
                pattern = placeholder;
        }
        else
            return 0;
    } while (*str);

    if (*pattern == '\0')
        return 1;
    else
        return 0;
}
