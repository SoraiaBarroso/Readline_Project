#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LINE 1024

void init_my_readline();
char* my_strcat(char* dest, char* src);
void *my_realloc(void *ptr, size_t size);
char* my_strcpy(char *dest, char* src);
char* my_strncpy(char *dest, char* src, int num);
char *my_readline(int fd);
int main(int argc, char **argv);
