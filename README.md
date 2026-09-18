*This project has been created as part of the 42 curriculum by hcherif.*

# Get Next Line

## Description

Get Next Line is a C project that implements a function which reads and returns
one line at a time from a file descriptor.

The function prototype is:

```c
char *get_next_line(int fd);
```

Each call to `get_next_line()` returns the next line from the given file
descriptor.

The returned line includes the terminating newline character `\n` when one is
present. If there is nothing left to read, or if an error occurs, the function
returns `NULL`.

This project is an introduction to important C concepts such as:

- File descriptors
- The `read()` function
- Dynamic memory allocation
- Static variables
- Buffer management
- Memory management

## Instructions

The mandatory files are:

- `get_next_line.c`
- `get_next_line_utils.c`
- `get_next_line.h`

The project can be compiled with a chosen `BUFFER_SIZE`.

Example:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
get_next_line.c get_next_line_utils.c main.c -o gnl_test
```

Then run:

```bash
./gnl_test
```

Different buffer sizes can also be tested.

For example:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=1 \
get_next_line.c get_next_line_utils.c main.c -o gnl_test
```

The code can also be compiled without defining `BUFFER_SIZE`, because a default
value is defined inside `get_next_line.h`.

For my local testing, I also use the Makefile:

```bash
make
make mm
```

To remove generated object files:

```bash
make clean
```

To remove object files and generated files:

```bash
make fclean
```

To rebuild:

```bash
make re
```

## Algorithm

The main idea of the algorithm is to read from the file descriptor until a
complete line is available.

A static pointer called `leftover` is used to keep data that was read but does
not belong to the current line.

The algorithm works as follows:

1. Allocate a buffer with a size of `BUFFER_SIZE + 1`.
2. Start with any data saved inside `leftover` from the previous call.
3. Read data from the file descriptor using `read()`.
4. Add the newly read data to the previously stored data.
5. Continue reading until a newline is found or the end of the file is reached.
6. Extract the first line from the accumulated data.
7. Save anything after the newline inside `leftover`.
8. Free memory that is no longer needed.
9. Return the extracted line.

The static variable is important because `read()` may return more data than is
needed for one line. The extra data must be saved so that it can be used during
the next call to `get_next_line()`.

The helper functions are stored in `get_next_line_utils.c`.

### `find_char()`

Searches through a string until a requested character is found.

It is used to find newline characters and the end of strings.

### `join()`

Creates a new string containing the previously stored data followed by the new
data read from the file descriptor.

The old allocated string is freed after the new string is created.

### `extract_line()`

Creates and returns the first line from the accumulated string.

If a newline exists, the newline character is included in the returned line.

### `save_leftover()`

Stores the part of the accumulated string that comes after the first newline.

This data is used during the next call to `get_next_line()`.

### `read_until_line()`

Repeatedly calls `read()` until a newline is found, the end of the file is
reached, or an error occurs.

The function also handles read errors and memory cleanup.

## BUFFER_SIZE

`BUFFER_SIZE` determines how many bytes are read during each call to `read()`.

For example:

```bash
-D BUFFER_SIZE=1
```

reads one byte at a time.

```bash
-D BUFFER_SIZE=42
```

reads up to 42 bytes at a time.

The implementation is designed to work with different `BUFFER_SIZE` values.

## Testing

The project was tested with different buffer sizes, including:

- `BUFFER_SIZE=1`
- `BUFFER_SIZE=42`
- Large `BUFFER_SIZE` values
- Compilation without explicitly defining `BUFFER_SIZE`

The implementation was also checked using:

```bash
norminette get_next_line.c get_next_line_utils.c get_next_line.h
```

Memory was checked using Valgrind:

```bash
valgrind --leak-check=full --show-leak-kinds=all ./gnl_test
```

## Resources

Resources used while learning and developing this project:

- Get Next Line subject
- `man 2 read`
- `man 3 malloc`
- `man 3 free`
- Documentation about file descriptors
- Documentation about static variables in C

### How AI was used

Google Search AI Overview (used sometimes to understand a function before I started reproducing it, or to understand the difference between concepts while searching).