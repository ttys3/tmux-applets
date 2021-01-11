/*
 * tmux-ping.c - a little tmux "applet" for showing whether we can ping hosts
 *
 * by Lucas Martin-King
 *
 * [ Licenced under the GPLv2 ]
 */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define TRANS_TIMEOUT "1" /* must be a string! */
#define CURL_PROG "/usr/bin/curl"

#define DEFAULT_METHOD "GET"
#define DEFAULT_URL "http://192.168.0.1"

#define WEB_OKAY "🆗"
#define WEB_ERROR "⛔"

int main(int argc, char **argv) {
  char *method;
  char *url;
  int status;
  pid_t pid;

  if (argc > 2) {
    method = argv[1];
    url = argv[2];
  } else if (argc > 1) {
    url = argv[1];
  } else {
    url = DEFAULT_URL;
  }

  char *method_param = "-XGET";
  if (strcmp(method, "HEAD") == 0) {
    method_param = "-I";
  } else if (strcmp(method, "POST") == 0) {
    method_param = "-XPOST";
  }

  pid = fork();

  if (pid == 0) {
    int nullfd = open("/dev/null", O_RDWR);

    dup2(nullfd, 0);
    dup2(nullfd, 1);
    dup2(nullfd, 2);
    execl(CURL_PROG, CURL_PROG, method_param, "-sSf", "-m", TRANS_TIMEOUT, url,
          NULL);
  } else if (pid < 0) {
    printf("ER\n");
    return 1;
  } else {
    int retval;
    char *result_emoji = NULL;

    waitpid(pid, &status, 0);
    retval = WEXITSTATUS(status);

    if (retval == 0) {
      result_emoji = WEB_OKAY;
    } else {
      result_emoji = WEB_ERROR;
    }

    printf("%s\n", result_emoji);
  }

  fflush(stdout);

  return 0;
}
