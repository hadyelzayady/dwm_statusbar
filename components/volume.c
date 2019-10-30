/* See LICENSE file for copyright and license details. */
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include "../util.h"

FILE *fp;
char* line = NULL;

const char *
vol_perc()
{
	fp=popen("amixer sget Master | awk -F\"[][]\" '/]/ { print $4,$2 }' | head -n 1 | xargs -n1","r");
        if(fp!=NULL)
        {
           size_t len = 0;
	   getline(&line, &len, fp);
	   if(strcmp(line,"off") == 10)
	   {
		return "Mute\0";
           }
	   getline(&line, &len, fp);
		if(line[3] == '%')
	    		return "100%";
	   line[3]=' ';
	   line[4]='\0';
           pclose(fp);
        return line;
	}
}
