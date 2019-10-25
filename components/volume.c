/* See LICENSE file for copyright and license details. */
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include "../util.h"

FILE *fp;
char volume_percent[5]="n\\a\0";
const char *
vol_perc()
{
	fp=popen("amixer sget Master | awk -F\"[][]\" '/dB/ { print $2 }'","r");
        if(fp!=NULL)
        {
           fgets(volume_percent,4,fp);
           pclose(fp);           	
        return volume_percent;
        }
	return "n\\a";
}
