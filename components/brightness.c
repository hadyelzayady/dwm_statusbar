/* See LICENSE file for copyright and license details. */
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include "../util.h"
char percent[4]="n/a\0";
const char *
brightness_perc()
{
  FILE *fp;

  /* Open the command for reading. */
  fp = popen("light", "r");
  if (fp != NULL) {
  /* Read the output a line at a time - output it. */
  fgets(percent, 4, fp);
  /* close */
  pclose(fp);
  return percent;
  }
  return "n/a\0";
}
