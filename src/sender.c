#include "sender.h"

#include <curl/curl.h>

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
