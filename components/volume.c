/* See LICENSE file for copyright and license details. */
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include "../util.h"

FILE *fp;

const char *
vol_perc()
{
	fp=popen("amixer sget Master | awk -F\"[][]\" '/]/ { print $4,$2 }' | head -n 1 | xargs -n1","r");
        if(fp!=NULL)
        {
	   char * line = NULL;
           size_t len = 0;
	   getline(&line, &len, fp);
	   if(strcmp(line,"off") == 10)
	   {
		return "Mute\0";
           }
	   getline(&line, &len, fp);
	   line[5]="\0";
           pclose(fp);
        return line;
        }
	return "n\\a";
}
