#include <stdio.h>
#include <curl/curl.h>
#include "crawler.h"

int main()
{
    int res;
    int count;
    HtmlContent h;
    char url[100] = "http://www.google.com.hk/search?q=";
    char ex[100];
    int len;

    h.content = (char*)malloc(1);
    h.size = 0;
    res = crawl("http://www.google.com.hk/search?q=chenguangcheng", &h);
//              res = crawl("http://www.google.com.hk/#hl=en&source=hp&q=%E9%99&btnG=Google+Search", &h);
//              res = crawl("http://www.google.com.hk/search?q=%E9%99%88%E5%85%89%E8%AF%9A", &h);
    printf("%s\n", h.content);
}
