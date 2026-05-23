*This project has been created as part of the 42 curriculum by fabde-ar.*

# ft_printf

"Because ft_putnbr() and ft_putstr() aren't enough".

---

## Description

**ft_printf** is the second project of the 42 School common core. The goal is to reimplement the standard C library function `printf()`, handling a subset of its format specifiers and returning the number of characters printed.

This project introduces two key concepts:

- **Variadic functions:** Functions that accept a variable number of arguments using `<stdarg.h>` macros (`va_list`, `va_start`, `va_arg`, `va_end`).
- **Format string parsing:** Iterating through a format string, detecting `%` specifiers and dispatching the correct printer for each conversion type.

The implementation produces a static library `libftprintf.a` that includes all functions from [Libft](https://github.com/fabioaraujow/Libft) plus the ft_printf function and its helpers.

---

## Supported Conversions

| Specifier | Description | Argument Type |
|:---------:|:------------|:--------------|
| `%c` | Single character | `int` (promoted from `char`) |
| `%s` | String of characters | `char *` |
| `%p` | Pointer address in hexadecimal | `void *` |
| `%d` | Signed decimal integer | `int` |
| `%i` | Signed decimal integer | `int` |
| `%u` | Unsigned decimal integer | `unsigned int` |
| `%x` | Unsigned hexadecimal (lowercase) | `unsigned int` |
| `%X` | Unsigned hexadecimal (uppercase) | `unsigned int` |
| `%%` | Literal percent sign | (none) |

---

## Instructions

### Compilation

```bash
make            # Compiles the library (libftprintf.a)
make clean      # Removes object files
make fclean     # Removes object files and the library
make re         # Full recompilation
```

### Usage

1. Include the header in your source file:

```c
#include "ft_printf.h"
```

2. Compile your program linking against the library:

```bash
cc -Wall -Wextra -Werror -I./Libft your_file.c libftprintf.a -o your_program
```

3. Use `ft_printf` just like the standard `printf`:

```c
ft_printf("Hello %s, you are %d years old!\n", "Fabio", 44);
ft_printf("Pointer: %p | Hex: %x | Unsigned: %u\n", ptr, 255, 42);
```

---

## Project Structure

```
ft_printf/
├── Libft/                  # Libft library (source files)
├── Makefile                # Compilation automation
├── ft_printf.h             # Header with prototypes
├── ft_printf.c             # Main function + dispatcher
├── ft_putchar_pf.c         # %c printer
├── ft_putstr_pf.c          # %s printer
├── ft_putnbr_pf.c          # %d / %i printer
├── ft_putunsigned_pf.c     # %u printer
├── ft_puthex_pf.c          # %x / %X printer
├── ft_putptr_pf.c          # %p printer
└── README.md               # This file
```

---

## Resources

- [man 3 printf](https://man7.org/linux/man-pages/man3/printf.3.html) - Official printf manual page
- [stdarg.h documentation](https://en.cppreference.com/w/c/variadic) - Variadic functions reference
- [Norminette](https://github.com/42School/norminette) - Official 42 code style checker
- 42 School ft_printf Project Subject (provided by 42)

### AI Usage

AI tools were used during the development of this project for:

- **Concept clarification:** Understanding variadic functions, type promotion rules, and format string parsing.
- **Code review:** Identifying logical errors, edge cases, and norm violations.

---

## Author

**Fábio Araújo** - [@fabioaraujow](https://github.com/fabioaraujow)

42 School student
