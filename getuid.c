#include <stdio.h>
#include <unistd.h>

int
main()
{
  uid_t uid, euid;
  gid_t gid, egid;

  uid = getuid();
  euid = geteuid();
  gid = getgid();
  egid = getegid();

  printf("uid = %u, euid = %u, gid = %u, egid = %u\n", uid, euid, gid, egid);

  return 0;
}
