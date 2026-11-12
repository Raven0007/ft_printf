*This project has been created as part of the 42 curriculum by ablaila.*

# ft_printf

## Description

**ft_printf** is a re-implementation of the standard C library function `printf`. The goal of the project is to learn how to write a **variadic function** in C, how to parse a format string, and how to organize code so that it stays clean, modular, and easy to extend.

The function is declared as:

```c
int ft_printf(const char *format, ...);
```

It writes formatted output to the standard output and returns the **number of characters printed** (or `-1` on error), just like the original `printf`.

The project is packaged as a static library, `libftprintf.a`, that can be linked to any other C program.

### Supported conversions

| Specifier | Description                                        |
|-----------|----------------------------------------------------|
| `%c`      | Prints a single character                          |
| `%s`      | Prints a string (prints `(null)` if the pointer is `NULL`) |
| `%p`      | Prints a pointer address in hexadecimal (`0x...`, or `(nil)` for `NULL`) |
| `%d`      | Prints a signed decimal integer                    |
| `%i`      | Prints a signed integer in base 10                 |
| `%u`      | Prints an unsigned decimal integer                 |
| `%x`      | Prints an unsigned integer in lowercase hexadecimal |
| `%X`      | Prints an unsigned integer in uppercase hexadecimal |
| `%%`      | Prints a literal percent sign                      |

### Bonus: supported flags

The bonus part adds support for the following flags, written between `%` and the conversion specifier (e.g. `%+d`, `% d`, `%#x`):

| Flag    | Applies to        | Effect                                                         |
|---------|-------------------|----------------------------------------------------------------|
| `+`     | `%d` `%i`         | Always prints the sign: `+42` for positive numbers, `-42` for negative ones |
| `space` | `%d` `%i`         | Prints a space before positive numbers (`" 42"`). Ignored if `+` is also set |
| `#`     | `%x` `%X`         | Prefixes non-zero values with `0x` (lowercase) or `0X` (uppercase) |

Examples:

```c
ft_printf("%+d\n", 42);   // +42
ft_printf("% d\n", 42);   //  42
ft_printf("%#x\n", 255);  // 0xff
ft_printf("%#X\n", 255);  // 0XFF
ft_printf("%#x\n", 0);    // 0   (no prefix for zero, like printf)
```

### Project structure

```
.
├── Makefile
├── README.md
├── ft_printf.h
├── ft_printf.c          # main function: format parsing and dispatching
├── ft_print_*.c         # one helper per conversion (char, str, nbr, hex, ptr...)
└── *_bonus.c / *_bonus.h # bonus: flag parsing and flag-aware handlers (+, space, #)
```

> Adjust the file names above to match your own repository.

## Instructions

### Requirements

- A C compiler (`cc`, `gcc` or `clang`)
- `make`
- A Unix-like system (Linux / macOS)

### Compilation

The project is compiled with the flags `-Wall -Wextra -Werror`.

```bash
make        # builds libftprintf.a (mandatory part)
make bonus  # builds libftprintf.a with the bonus flags (+, space, #)
make clean  # removes object files
make fclean # removes object files and libftprintf.a
make re     # rebuilds everything from scratch
```

### Usage

Include the header in your code and link against the library:

```c
#include "ft_printf.h"

int main(void)
{
    int len;

    len = ft_printf("Hello %s, you are %d years old! (hex: %x)\n", "42", 42, 42);
    ft_printf("Printed %d characters\n", len);
    return (0);
}
```

Compile your program with:

```bash
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o test
./test
```

### Testing

Compare the output and the return value of `ft_printf` with the real `printf`:

```c
int a = printf("Value: %p | %u | %X\n", ptr, 42u, 255);
int b = ft_printf("Value: %p | %u | %X\n", ptr, 42u, 255);
// a and b must be identical

printf("%+d|% d|%#x|%#X\n", 42, 42, 255, 255);
ft_printf("%+d|% d|%#x|%#X\n", 42, 42, 255, 255);
```

## Algorithm and data structure

### Overview

`ft_printf` reads the format string once, from left to right, and prints each part as it goes. The format string is read once, from left to right, using an index `i`:

1. Return `-1` immediately if the format string is `NULL`.
2. Initialize the `va_list` with `va_start`.
3. Loop until the end of the string (`'\0'`):
   - If the current character is **not** `%`, print it directly with `ft_putchar`.
   - If it is `%`, move to the next character (the conversion specifier) and send it to the dispatcher `ft_qualif`, together with the `va_list`. Then skip past the specifier.
4. Check the value returned by the print call. If it is `-1` (a `write` failure), stop and return `-1`.
5. Otherwise, add it to the running total of printed characters.
6. At the end, release the list with `va_end` and return the total.

### The dispatcher: `ft_qualif`

`ft_qualif` receives the specifier character and the `va_list`, and uses an `if / else if` chain to pick the right handler. It reads the argument with `va_arg` using the **correct type** for each conversion:

| Specifier   | `va_arg` type   | Handler          |
|-------------|-----------------|------------------|
| `c`         | `int`           | `ft_putchar`     |
| `s`         | `char *`        | `ft_putstr`      |
| `d`, `i`    | `int`           | `ft_putnb`       |
| `u`         | `unsigned int`  | `ft_putun_nb`    |
| `x`, `X`    | `unsigned int`  | `ft_put_hex`     |
| `p`         | `void *`        | `ft_putadd`      |
| anything else (including `%`) | none | prints `%` with `ft_putchar` |

Every handler **returns the number of characters it printed**, or `-1` if `write` failed. This is the key idea of the design: the dispatcher and the main loop never need to count characters themselves, they only add up the returned values.

The `va_list` is passed to `ft_qualif` by value, but `va_list` is designed so that `va_arg` still advances the caller's position in practice, so each conversion consumes the next argument in order.

### Why this algorithm?

- **Single pass, O(n)**: the format string is read exactly once, with no backtracking and no pre-processing. The total cost is linear in the length of the format string plus the size of the printed values.
- **Separation of parsing and printing**: `ft_printf` only walks the string, `ft_qualif` only chooses the handler, and each handler only prints one kind of value. Each function stays short (42 Norm), is easy to test alone, and adding a new conversion means adding one handler and one `else if`.
- **Return-value propagation**: since `printf` must return the number of printed characters, every handler returns its own count and the main function accumulates them. This avoids global variables and keeps all functions independent.
- **Early exit on error**: a `-1` from any handler is propagated straight to the caller, as the real `printf` does when output fails.
- **Direct writing with `write`**: output goes straight to the file descriptor with no intermediate buffer. This is simple and predictable: no buffer to flush and no dynamic allocation to free. The trade-off is more system calls than a buffered design, which is acceptable for this project.

### Number conversion

Numbers are printed **recursively**: the number is divided by the base until it fits in one digit, then digits are written on the way back up the recursion. This prints the most significant digit first without needing a temporary array or a reversal.

- `%d` / `%i` use `ft_putnb`, which handles the sign (and the special case of `INT_MIN`).
- `%u` uses `ft_putun_nb`, which works on an `unsigned int` so there is no sign to handle.
- `%x` / `%X` use `ft_put_hex`, with base 16 and lowercase or uppercase digits depending on the specifier.
- `%p` uses `ft_putadd`, which prints the `void *` address as an unsigned long in hexadecimal after the `0x` prefix.

Digits are looked up in a constant base string (`"0123456789"`, `"0123456789abcdef"`, `"0123456789ABCDEF"`), which is simpler than testing `if (n < 10)` for each digit.

### Data structures

No complex data structure is needed. The project uses only:

- **`va_list`** (from `<stdarg.h>`): the standard mechanism for reading a variable number of arguments in C.
- **`int flg[2]`**: a tiny array that holds the two counters of the main function:
  - `flg[0]`: the **total** number of characters printed so far (the final return value).
  - `flg[1]`: the value **returned by the last print call**, kept so it can be checked for `-1` before being added to the total.

  Using a two-element array keeps the function within the Norm's limit on the number of variables while still separating "the running total" from "the last result".

### Flag handling (bonus)

Flags are parsed in a small loop right after the `%`, so any number of them can be combined and in any order (`%+ d`, `%# x`, `%++d`...). Each flag simply turns a field on in a structure:

```c
typedef struct s_flag
{
	int	alt;
	int	sign;
	int	space;
}		t_flag;
```

The flags are then applied only where they make sense, exactly like the original `printf`:

- **`+` and space (`%d`, `%i`)**: after reading the integer, if it is non-negative, the handler first prints `+` (if `plus` is set) or a space (if only `space` is set), and adds 1 to the returned count. When both are given, `+` takes priority and the space is ignored. Negative numbers already print their own `-`.
- **`#` (`%x`, `%X`)**: if the value is **different from 0**, the handler prints the `0x` / `0X` prefix before the digits and adds 2 to the count. For `0`, no prefix is printed.
- Flags that do not apply to a conversion (for example `#` with `%d`) are simply ignored.

**Why this design?** Parsing the flags *before* the dispatch keeps the dispatcher unchanged: it still switches on the specifier only. The flag logic stays inside the handlers that need it, and the character count remains correct because the handlers keep returning how many characters they wrote, prefix and sign included.

### Data structures

No complex data structure is needed for this project. The only structures used are:

- **`va_list`** (from `<stdarg.h>`): the standard mechanism for walking through a variable number of arguments. It is the natural and only way to implement a variadic function in C.
- **Constant strings for bases** (`"0123456789"`, `"0123456789abcdef"`, `"0123456789ABCDEF"`): a lookup table that maps a digit value to its character. It is simpler and faster than conditionals such as `if (n < 10) ... else ...`.
- **`t_flags` structure** (bonus): a tiny struct of integer booleans that stores the flags found for the current conversion. It is passed by value or by pointer to the handlers, so no global variable is needed, and it is reset for each new `%`.
- **Plain `int` counter**: stores the number of printed characters.

Choosing the simplest structures keeps memory usage constant (no `malloc`, so no leaks possible) and the code easy to maintain.

## Resources

### References

- `man 3 printf` — the official description of `printf` and its conversions
- `man 3 stdarg` — variadic functions (`va_start`, `va_arg`, `va_end`, `va_copy`)
- `man 2 write` — the system call used to output characters
- [GNU C Library — Formatted Output](https://www.gnu.org/software/libc/manual/html_node/Formatted-Output.html)
- [cppreference — printf, fprintf, sprintf](https://en.cppreference.com/w/c/io/fprintf)
- [cppreference — Variadic arguments](https://en.cppreference.com/w/c/variadic)
- The 42 Norm and the ft_printf subject (PDF)

### Use of AI

AI (Claude) was used as a **support tool** only, for the following tasks:

- **Finding resources:** searching for documentation, articles, and tutorials about the concepts studied during the project (variadic functions, `va_list`, `write`, number base conversion, `printf` conversions and flags).
- **Understanding flag behavior (bonus):** asking how `printf` behaves when several flags are combined in the same conversion (for example `+` with space, or `#` with the value `0`), then looking for reliable resources to confirm that the information was correct.

All the source code of the project was **written, tested, and understood by me**. AI was not used to write the implementation of `ft_printf`.
