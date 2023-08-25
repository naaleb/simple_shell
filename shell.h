#ifndef _SHELL_H_
#define _SHELL_H_

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>

/**
 *Buffer sizes
 */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* chaining type commands */
#define CMD_NORM 0
#define CMD_OR 1
#define CMD_AND 2
#define CMD_CHAIN 3

/* Number convert type */
#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

/* system getline() flags*/
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE ".simple_shell_history"
#define HIST_MAX 4096

extern char **environ;

/**
 * struct liststr - Singly linked list function
 * @num: Number field
 * @str: String field
 * @next: Points to next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 * struct passinfo - Pseudo-arguments to pass to functions
 * @arg: Arguments generated from getline
 * @argv: Array of strings from args
 * @path: Path for the current command
 * @argc: Argument count
 * @line_count: Error count
 * @err_num: Error code for exit()
 * @linecount_flag: Count this input line
 * @fname: Program filename
 * @env: Linked list local copy of environ
 * @environ: Modified copy of environ
 * @history: History node
 * @alias: Alias node
 * @env_changed: Flag if environ was changed
 * @status: Return status of the last exec'd command
 * @cmd_buf: Pointer to cmd ; chain buffer
 * @cmd_buf_type: CMD_type ||, &&, ;
 * @readfd: File descriptor to read line input
 * @histcount: History line number count
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;
	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 * struct builtin - Builtin command structure
 * @type: Builtin command flag
 * @func: Function associated with the builtin
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;

/* Function prototypes */

#endif

