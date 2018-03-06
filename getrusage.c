#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>
#include <stdio.h>

int
main()
{
  struct rusage usage;
  int i, j;

  j = 1;
  for (i = 1; i <= 100000; i++) {
    chdir(".");
    j *= i;
  }

  if (getrusage(RUSAGE_SELF, &usage) < 0) {
    perror("getrusage");
    return 1;
  }

  printf(
    "user time = %ld.%06ld\n"
    "system time = %ld.%06ld\n",
    usage.ru_utime.tv_sec, usage.ru_utime.tv_usec,
    usage.ru_stime.tv_sec, usage.ru_stime.tv_usec
  );

  return 0;
}