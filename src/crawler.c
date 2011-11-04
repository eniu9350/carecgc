#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include "crawler.h"

static size_t WriteMemoryCallBack(void* contents, size_t size, size_t nmemb, void* userp)
{
    size_t realsize = size * nmemb;
    HtmlContent* h = (HtmlContent*)userp;
    h->content = (char*)realloc(h->content, h->size+realsize+1);
    if(h->content == NULL)
    {
        printf("not enough memory (realloc returned NULL)\n");
        exit(EXIT_FAILURE);
    }

    memcpy(&(h->content[h->size]), contents, realsize);
    h->size += realsize;
    h->content[h->size] = 0;

	printf("realsize=%d, lenofcontet=%d\n", realsize, strlen(h->content));

    return realsize;
}



int crawl(char* url, HtmlContent* h)
{
//printf("crawl 1\n");
    CURL* curl;

    //temp
    char* strDisplay;

    //struct MemoryStruct chunk;
    //chunk.memory = malloc(1);
    //chunk.size = 0;


//printf("crawl 2\n");

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallBack);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)h);
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "libcurl-agent/1.0");
//printf("crawl 3\n");
    if(curl)
    {
        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
    printf("%lu bytes retrieved\n", (long)h->size);

    //just for display
    strDisplay = (char*)malloc(111201);
    memcpy(strDisplay, h->content, 111200);
    strDisplay[111200] = '\0';
//              printf("\n%s", strDisplay);

    //if(h->content)
    //{
     //   free(h->content);
    //}

    curl_global_cleanup();
    return 0;
}
