*This project has been created as part of the 42 curriculum by andmigue.*

# ft_printf

## Description

`ft_printf` is a partial reimplementation of the C standard library function `printf`. The goal is to reproduce the core formatting behavior of the original function, handling the most common conversion specifiers while managing a variable number of arguments using the `stdarg.h` macros.

Supported specifiers:
- `%c`  — prints a single character
- `%s` — prints a string
- `%p` — prints a pointer address
- `%d` — prints a decimal number
- `%i` — prints an integer
- `%u` — prints an unsigned integer number
- `%x` — prints a hexadecimal number in lowercase
- `%X` — prints a hexadecimal number in uppercase
- `%%` — prints a percent sign

## Instructions

### Compilation


To compile the library:

```bash
make
```

This will generate:

```bash
libftprintf.a
```

### Available Makefile rules
make        — compile the library
make clean  — remove object files
make fclean — remove object files and the library
make re     — fclean + make

## Algorithm and Data Structure

### Parsing approach

`ft_printf` iterates over the format string character by character. When it encounters a `%`, it advances one character and dispatches to `ft_specifier`, which matches the specifier and calls the appropriate output function. There is no intermediate buffer — each character or formatted value is written directly to `stdout` via `write(1, ...)`.

This is a **dispatch table approach** implemented as a chain of `if/else if` conditions. It was chosen for its simplicity and readability at this project's scale, where the number of specifiers is fixed and small.

### Return value tracking

Every output function (`ft_putchar`, `ft_putstr`, `ft_putnbr`, etc.) returns the number of characters written. These counts are accumulated in a single `count` variable in `ft_printf`, which is returned at the end, matching the behavior of the original `printf`.

### Hexadecimal printing

Hexadecimal conversion is handled recursively in `ft_printhex`. The function divides the number by 16 recursively until the quotient is less than 16, then indexes into a base string (`"0123456789abcdef"` or uppercase) on the way back up the call stack. This naturally produces the correct digit order without needing a reverse step.

For pointer printing (`%p`), a dedicated wrapper `ft_printptr` handles the `(nil)` special case before calling `ft_printhex` with an `unsigned long` argument to preserve full 64-bit address width.

## Resources

- [printf(3) — Linux man page](https://man7.org/linux/man-pages/man3/printf.3.html)
- [stdarg.h — variable argument lists](https://en.cppreference.com/w/c/variadic)
- [cplusplus printf Reference](https://cplusplus.com/reference/cstdio/printf/)

### AI usage

AI tools were used during the development of this project for:

    Understanding variadic functions
    Clarifying recursion concepts
    Reviewing edge cases
    Improving documentation and README structure
    Debugging certain logical issues

The implementation logic, coding, testing, and final behavior validation were completed manually.