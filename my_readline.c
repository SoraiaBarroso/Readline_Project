#include "my_readline.h"
#include <string.h>

/*Number os characters read and global storage*/
int READLINE_READ_SIZE = 20;
char storage[MAX_LINE];

void init_my_readline()
{
    READLINE_READ_SIZE = 20;
    storage[0] = '\0';
}

char* my_strcat(char* dest, char* src)
{ 
    char *ptr = dest;

    while (*dest != '\0')
        dest++;
    
    while (*src != '\0')
        *dest++ = *src++;
 
    *dest = '\0';
    
    return ptr;
}

char* my_strcpy(char *dest, char* src)
{
    char *ptr = dest;

    while (*src != '\0')
        *dest++ = *src++;

    *dest = '\0';

    return ptr;
}

char* my_strncpy(char *dest, char* src, int num)
{
    char *start = src;

    while (*src && num--)
        *dest++ = *src++;
    
    *dest = '\0';

    return start;
}

void *my_realloc(void *ptr, size_t size)
{
    if (size == 0)
    {
        free(ptr);
        return NULL;
    }

    void *new_ptr = malloc(size);

    if (new_ptr == NULL)
    {
        printf("Error: Unable to allocate memory");
        exit(EXIT_FAILURE);
    }

    if (ptr != NULL)
    {
        char *old_ptr = ptr;
        char *new_ptr_char = new_ptr;

        for (size_t i = 0; i < size; i++)
        {
            new_ptr_char[i] = old_ptr[i];
        }

        free(ptr);
    }

    return new_ptr;
}

char *my_readline(int fd)
{
    int bytes_read = 0, i = 0;
    char buf[READLINE_READ_SIZE + 1];
    char *line = NULL;

    line = (char*)malloc(MAX_LINE);

    line[0] = '\0';

    if (line == NULL)
    {
        printf("Error: Unable to allocate memory");
        exit(EXIT_FAILURE);
    }

    while ((bytes_read = read(fd, buf, READLINE_READ_SIZE)) > 0)
    {
        buf[bytes_read] = '\0';

        my_strcat(storage, buf);

        //loop until there is a new line character to get first line
        while (storage[i] != '\n' && storage[i] != '\0') 
            i++;

        //copy the first line
        if (storage[i] == '\n')
        {
            my_strcpy(line, storage);
            line[i] = '\0';

            // save in storage everyhting after the new line
            my_strncpy(storage, storage + i + 1, strlen(storage+i+1)+1);

            break;
        }

        // allocate more memory for bigger files
        if(strlen(storage) + bytes_read >= MAX_LINE)
        {
            READLINE_READ_SIZE += MAX_LINE;
            line = my_realloc(line, READLINE_READ_SIZE);
        }
    }

    // blank line 
    if (bytes_read <= 0 && strlen(storage) > 0)
    {
        my_strncpy(line, storage, strlen(storage));
        line[strlen(storage)] = '\0';
        storage[0] = '\0';
    }

    // end of file, free line
    else if (bytes_read <= 0)
    {
        free(line);
        return NULL;
    }

    // code was adding a new line at the end
    if (line[strlen(line) - 1] == '\n')
    {
        line[strlen(line) - 1] = '\0';
    }

    return line;
}

int main(int argc, char **argv)
{
    char *str = NULL;
    int fd;

    if(argc > 1)
    {
        fd = open(argv[1], O_RDONLY);
        if(fd == -1)
        {
            printf("Error: Unable to open %s", argv[1]);
            exit(EXIT_FAILURE);
        }
    }
    else{
        fd = STDIN_FILENO;
    }

    while ((str = my_readline(fd)) != NULL)
    {
        printf("%s\n", str);
        free(str);
    }

    close(fd);
    init_my_readline();

    return 0;
}