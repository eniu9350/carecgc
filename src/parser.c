#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "crawler.h"
#include "strutil.h"

/*
     -1: prefix not found
     -2: postfix not found
     -3: other errors
 */
int getResultCount(HtmlContent* h, Boundary* pre, Boundary* post)
{
    char* start;
    char* end;
    char strCount[20];

    char tmp[1000];
    printf("getResultCount 1\n");
    if(!pre || !post)
    {
        return -3;
    }

    start = strstr(h->content, pre->s);

    if(!start)
    {
        return -1;
    }
    printf("getResultCount 2\n");
    start += strlen(pre->s)+pre->offset;

    end = strstr(start, post->s);
    end -= post->offset;
    if(!end)
    {
        return -2;
    }
//for debug
    memcpy(tmp, start, 300);
    tmp[300]='\0';
//printf("getResultCount 3, start=%d, end=%d, tmp=%s\n",start, end, tmp);
    printf("getResultCount 3, tmp=%s", tmp);

    memcpy(strCount, start, end-start);
    strCount[end-start] = '\0';
    removePeriods(strCount);
    printf("getResultCount 4\n");
    //printf("strCount=%s", strCount);

    return atoi(strCount);
}
