#include <sys/types.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

extern char* tzname[];

int main() {

	int err;
	time_t now;
	struct tm* la_time;

	now = time(NULL);

	if(now == -1){
		perror("time() caused an error");
		exit(-1);
	}

	err = setenv("TZ", "America/Los_Angeles", 1);

	if (err == -1){
		perror("setenv() caused an error");
		exit(-1);
	}

	la_time = localtime(&now);

	if (la_time == NULL){
		perror("localtime() caused an error");
		exit(-1);
	}

	printf("%d/%d/%d %d:%d %s\n",
		la_time->tm_mon + 1,
		la_time->tm_mday,
		la_time->tm_year + 1900,
		la_time->tm_hour,
		la_time->tm_min,
		tzname[la_time->tm_isdst]);

	return 0;
}
