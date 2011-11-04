#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <curl/curl.h>
#include "crawler.h"
#include "parser.h"
#include "task.h"
#include "config.h"

int sendReq(int count)
{
    CURL *curl;
    CURLcode res;
    char url[100];

    curl = curl_easy_init();
    if(curl)
    {
        sprintf(url, "http://www.shiaima.com/cgc/saveCount.php?count=%d", count);
        printf("to send to %s\n", url);
        curl_easy_setopt(curl, CURLOPT_URL, url);
        res = curl_easy_perform(curl);

        /* always cleanup */
        curl_easy_cleanup(curl);
    }
    return 0;
}

int getCount()
{
    int res;
    int count;
    Boundary pre;
    Boundary post;
    HtmlContent h;
    char url[100] = "http://www.google.com.hk/search?q=";
    char ex[100];
    int len;

    h.content = (char*)malloc(1);
    h.size = 0;
//              res = crawl("http://www.google.com.hk/search?q=chenguangcheng", &h);
//              res = crawl("http://www.google.com.hk/#hl=en&source=hp&q=%E9%99&btnG=Google+Search", &h);
    res = crawl("http://www.google.com.hk/search?q=%E9%99%88%E5%85%89%E8%AF%9A", &h);
    //printf("content-----------------\n%s", h.content);
    //res = crawl("http://www.baidu.com", &h);

    pre.prefix = 1;
    pre.s = "resultStats>";
    pre.offset = 5;

    post.prefix = 0;
    post.s = "<nobr>";
    post.offset = 7;
    count = getResultCount(&h, &pre, &post);
    printf("count=%d\n",count);
    return count;
}

void save_to_db(int i)
{
    struct itimerval to;
    int count;

    //get search result count through fetching & parsing
    count = getCount();
    sendReq(count);

    signal(SIGALRM, save_to_db);

    to.it_interval.tv_sec = 0;
    to.it_interval.tv_usec = 0;
    to.it_value.tv_sec = config.interval;
    to.it_value.tv_usec = 0;

    setitimer(ITIMER_REAL, &to, 0);

    printf("time flies\n");
}
