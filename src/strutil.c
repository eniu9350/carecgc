#include "strutil.h"

int removePeriods(char* s)
{
    int offset;

    while(*s!='\0'&&*s!=',')
    {
        s++;
    }
    if(s=='\0')
    {
        return 0;
    }
    offset = 1;
    while(1)
    {
        while(*(s+offset)!='\0'&&*(s+offset)!=',')
        {
            *s = *(s+offset);
            s++;
        }
        if(*(s+offset)=='\0')
        {
            *s = '\0';
            return 0;
        }
        else
        {
            offset ++;
        }
    }
}
