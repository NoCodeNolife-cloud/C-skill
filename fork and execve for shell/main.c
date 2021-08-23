#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

extern char **environ;
#define MAXARGS 128
#define MAXLINE 128

/**
 * parse the command line and build the argv array
 * @param buf
 * @param argv
 * @return
 */
int parseline(char *buf, char **argv) {
    char *delim;/*points to first spaec delimiter*/
    int argc;/*Number of args*/
    int bg;/*Background job?*/

    buf[strlen(buf) - 1] = ' ';/*replace trailing '\n' with space*/
    while (*buf && (*buf == ' ')) {/*ignore leading spaces*/
        buf++;
    }

    /*
     * build the argv list
     */
    argc = 0;
    while ((delim = strchr(buf, ' '))) {
        argv[argc++] = buf;
        *delim = '\0';
        buf = delim + 1;
        while (*buf & (*buf == ' ')) {/*ignore spaces*/
            buf++;
        }
    }
    argv[argc] = NULL;

    if (argc == 0) {/*ignore blank line*/
        return 1;
    }

    /*
     * should the job run the background?
     */
    if ((bg = (*argv[argc - 1] == '&')) != 0) {
        argv[--argc] = NULL;
    }

    return bg;
}

/**
 * if first arg is builtin command, run it and return true
 * @param argv
 * @return
 */
int builtim_command(char **argv) {
    if (!strcmp(argv[0], "quit")) {/*quit command*/
        exit(0);
    }
    if (!strcmp(argv[0], "&")) {/*ignore singleton*/
        return 1;
    }
    return 0;/*not a builtin command*/
}

/**
 * evaluate a command line
 * @param cmdline
 */
void eval(char *cmdline) {
    char *argv[MAXARGS];/*argument list execve()*/
    char buf[MAXLINE];/*holds modified command line*/
    int bg;/*should the job run in bg or fg?*/
    pid_t pid;/*process id*/

    strcpy(buf, cmdline);
    bg = parseline(buf, argv);
    if (argv[0] == NULL) {
        return;/*ignore empty lines*/
    }

    if (!builtim_command(argv)) {
        if ((pid = fork()) == 0) {
            if (execve(argv[0], argv, environ) < 0) {
                printf("%s: Command not find.\n", argv[0]);
                exit(0);
            }
        }

        /*
         * parent waits for foreground job to terminate
         */
        if (!bg) {
            int status;
            if (waitpid(pid, &status, 0)) {
                printf("waitfg: waitpid error\n");
            }
        } else {
            printf("%d %s", pid, cmdline);
        }
    }
    return;
}

int main() {
    char cmdline[MAXLINE];/*command line*/

    while (1) {
        /*
         * read
         */
        printf("> ");
        fgets(cmdline, MAXLINE, stdin);
        if (feof(stdin)) {
            exit(0);
        }
        /*
         * evaluate
         */
        eval(cmdline);
    }
}