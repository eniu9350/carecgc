#ifndef _CARECGC_PARSER_H_
#define _CARECGC_PARSER_H_
#include "crawler.h"
typedef struct
{
    int prefix;
    char* s;
    int offset;
} Boundary;

int getResultCount(HtmlContent* h, Boundary* pre, Boundary* post);
#endif
