#include <stdio.h>
#include <stdlib.h>
#include "crawler.h"
#include "parser.h"
#include "strutil.h"
#include "task.h"
#include "config.h"

int main(int argc, char* argv[])
{

    
//printf("wwww%d\n", argc);
    printf("argc=%d\n", argc);
    if(argc>1)
    {
        config.interval = atoi(argv[1]);
    }
    else
    {
        config.interval=300;
    }
    /*
        int res;
        int count;
        Boundary pre;
        Boundary post;
        HtmlContent h;


        h.content = (char*)malloc(1);
        h.size = 0;
        res = crawl("http://www.google.com.hk/search?q=chenguangcheng", &h);
        //res = crawl("http://www.baidu.com", &h);

        pre.prefix = 1;
        pre.s = "<div id=resultStats>";
        pre.offset = 5;

        post.prefix = 0;
        post.s = "<nobr>";
        post.offset = 7;
        count = getResultCount(&h, &pre, &post);

        printf("\nCount=%d\n", count);
    */
    save_to_db(0);
    while(1);

}