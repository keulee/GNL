# GET_NEXT_LINE
_42 get_next_line project (2019)_

## MANDATORY PART
```
* Function name : get_next_line
* Prototype : int get_next_line(int fd, char **line);
* Turn in files : get_next_line.c, get_next_line_utils.c, get_next_line.h
* Parameters :
  # 1. file descriptor for reading
  # 2. The value of what has been read
* Return value
  # 1 : A line has been read
  # 0 : EOF has been reached
  # -1 : An error happened
* External functs. : read, malloc, free
* Description : Write a function which returns a line read from a file descriptor, without the newline.
```

### Reference
* Calling your function get_next_line in a loop will then allow you to read the text available on a file descriptor one line at a time until the EOF.
* Make sure that your function behaves well when it reads from a file and when it reads from the standard input.
* libft is not allowed for this project. You must add a get_next_line_utils.c file which will contain the functions that are needed for your get_next_line to work.
* Your program must compile with the flag -D BUFFER_SIZE=xx. which will be used as the buffer size for the read calls in your get_next_line. This value will be modified by your evaluators and by moulinette.
* Compilation will be done this way : gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c
* Your read must use the BUFFER_SIZE defined during compilation to read from a file or from stdin.
* In the header file get_next_line.h you must have at least the prototype of the function get_next_line.
* We consider that get_next_line has an undefined behavior if, between two calls, the same file descriptor switches to a different file before EOF has been reached on the first fd.
* lseek is not an allowed function. File reading must be done only once.
* Finally we consider that get_next_line has an undefined behavior when reading from a binary file. However, if you wish, you can make this behavior coherent.
* Global variables are forbidden.

#### Take a look
  1. Does your function still work if the BUFFER_SIZE value is 9999? And if the BUFFER_SIZE value is 1? And 10000000? Do you know why?
  2. You should try to read as little as possible each time get_next_line is called. If you encounter a newline, you have to return the current line. Don’t read the whole file and then process each line.
  3. Don’t turn in your project without testing. There are many tests to run, cover your bases. Try to read from a file, from a redirection, from standard input. How does your program behave when you send a newline to the standard output? And CTRL-D?

## BONUS PART
```
The project get_next_line is straightforward and leaves very little room for bonuses, but I am sure that you have a lot of imagination. 
If you aced perfectly the mandatory part, then by all means complete this bonus part to go further.
I repeat, no bonus will be taken into consideration if the mandatory part isn’t perfect. 
Turn-in all 3 initial files with _bonus for this part.
```
* To succeed get_next_line with a single static variable.
* To be able to manage multiple file descriptor with your get_next_line. For example, if the file descriptors 3, 4 and 5 are accessible for reading, then you can call get_next_line once on 3, once on 4, once again on 3 then once on 5 etc. without losing the reading thread on each of the descriptors.


* * *


_to do_ (updated 22.02.2020)
_what I've finished_
1. EOF 이후 str free해주기 (leaks 해결)
2. ft_rest 함수 재작성하기
1. BUFFER_SIZE = 1 및 10000000 segfault 해결 ㅇㅋㄷㅋ
2. BUFFER_SIZE = 3 일때 무한 반복 해결 ㅇㅋㄷㅋ
-> read 조건 고쳐서 해결
3. (later) leaks 해결(valgrind)
