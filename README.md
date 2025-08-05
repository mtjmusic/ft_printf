# ft_printf Project

This project involves creating a C library, `libftprintf.a`, that reimplements the `printf` function from the C standard library. It focuses on handling variadic arguments and formatting various data types, providing a versatile tool for formatted output in C programs.

## Overview

### Objective
Develop a library with a custom `ft_printf` function that mimics the behavior of the standard `printf`, supporting a range of format specifiers and ensuring robust, extensible code.

### Structure
- **Mandatory Part**: Implements `ft_printf` with core format specifiers for character, string, pointer, integer, unsigned integer, hexadecimal, and percent sign.

### Constraints
- Global variables are not explicitly prohibited but should be avoided for clean design.
- Must compile with `-Wall`, `-Wextra`, `-Werror` flags.
- No memory leaks allowed in user-written code.
- Library created using `ar`, not `libtool`.
- Buffer management of the original `printf` is not required.

## Features

### Mandatory Program (`libftprintf.a`)
- Function: `int ft_printf(const char *, ...);`
- Handles conversions:
  - `%c`: Prints a single character.
  - `%s`: Prints a string.
  - `%p`: Prints a void pointer in hexadecimal format.
  - `%d`, `%i`: Prints a decimal (base 10) integer.
  - `%u`: Prints an unsigned decimal (base 10) number.
  - `%x`: Prints a number in lowercase hexadecimal (base 16).
  - `%X`: Prints a number in uppercase hexadecimal (base 16).
  - `%%`: Prints a percent sign.
- Matches the behavior of the standard `printf` for these conversions.

## Technical Details

- **Language**: C
- **Allowed Functions**: `malloc`, `free`, `write`, `va_start`, `va_arg`, `va_copy`, `va_end`.
- **Libft**: Authorized for use, compiled via a `libft` folder and Makefile.
- **Files**: `Makefile`, `*.h`, `*.c`, and optional subdirectories for headers/source files.
- **Makefile**: Includes rules for `NAME`, `all`, `clean`, `fclean`, `re`.
- **Directory Structure**: Files at the root or in subdirectories, with `libftprintf.a` created at the root.
- **Output**: Creates `libftprintf.a` using the `ar` command.

## Learning Outcomes

- Mastery of variadic functions and argument handling in C.
- Experience with formatted output and string manipulation.
- Building a reusable library for formatted printing in future projects.
