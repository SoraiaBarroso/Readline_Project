# Welcome to My Readline
***

## Task
If you already played with another higher-level programming language, you know how easy it is to read a line from a file. For example in Python, you can even iterate through the file like for line in file:.

Unfortunately for you, this project will bring you back in the 1970s (again) when no such super power was available.
## Description
The readline function reads a line from the strean represented by fd and returns it into an allocated string.
It stops when either the newline character is read or when the end-of-file is reached, whichever comes first. 
The newline character is not copied to the string.

On success, a pointer to the string is returned. On error, a null pointer is returned. 
If the end-of-file occurs before any characters have been read, the string remains unchanged.
## Installation
Theres no Installation.

Run 'make' to compile the program.

./my_readline [FILE_TO_READ] to execute the program.
## Usage
```
After compiling:

./my_readline [FILE_TO_READ]

It will read the file provided and print line per line, 
if the file doesn't exist and error will be printed.
```

### The Core Team


<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px'></span>
