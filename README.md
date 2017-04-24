:cn:# cregex 
## NAME
cregex - regex match in c

## SYNOPSIS
```c
#include "cregex.h"
char *cregex(const char *regex, const char *string, char *result);
```
## DESCRIPTION
The **cregex()** function obtain regular expression from `regex`, strings from `string`, 
then **cregex()** print regular expression's matches. The entire match is printed first,
the other subexpression then printed one by one. the max match number is Ten. At last, It
will return the last match stored in `result`.

## RETURN VALUE
On success, return a pointer to the last match string in `result`. otherwise, NULL is 
returned and print the reason why it failed to stdout.

# COPYRIGHT
Copyright (C) 2017 francis_hao \<francis_hao@126.com>

This program is free software; you can redistribute it and/or modify 
it under the terms of the GNU General Public License as published by 
the Free Software Foundation; either version 2 of the License, 
or (at your option) any later version.

This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE, GOOD TITLE or
NON INFRINGEMENT.  See [LICENSE] for more details.




[LICENSE]:LICENSE




