#ifndef _CARECGC_CRAWLER_
#define _CARECGC_CRAWLER_
typedef struct
{
    char* content;
    size_t size;
} HtmlContent;

int crawl(char* url, HtmlContent* h);
#endif
