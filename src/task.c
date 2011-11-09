#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <curl/curl.h>
#include <string.h>
#include "crawler.h"
#include "parser.h"
#include "task.h"
#include "config.h"


void save_to_db(int i)
{
	struct itimerval to;
	int res;

	//send search http req and leave everything else (e.g. parsing job) in the callback function of curl_perform

	HtmlContent h;
	h.content = (char*)malloc(1);
	h.size = 0;
	h.processed = 0;
	res = crawl("http://www.google.com.hk/search?q=%E9%99%88%E5%85%89%E8%AF%9A", &h);
/*
	signal(SIGALRM, save_to_db);

	to.it_interval.tv_sec = 0;
	to.it_interval.tv_usec = 0;
	to.it_value.tv_sec = config.interval;
	to.it_value.tv_usec = 0;

	setitimer(ITIMER_REAL, &to, 0);
*/

	printf("time flies\n");
}

