# libft

the first project at 42 asks you to rewrite parts of the C standard library yourself.
no `#include <string.h>`, no `#include <stdlib.h>` — just you, your logic, and a lot of
segfaults before things start working.

the point isn't the functions themselves. you already know what `strlen` does.
the point is understanding what actually happens under the hood when you call it —
and realizing it's not magic, it's just a loop.

---

## memory functions

these are the ones that will hurt you later if you don't understand them properly.

**ft_memset** — fills a block of memory with a single byte value. sounds simple until
you forget it works on bytes, not ints, and spend an hour wondering why your array
is full of garbage.

**ft_memcpy** — copies n bytes from src to dst. doesn't handle overlap between the two.
if they overlap, use memmove instead, or enjoy the undefined behavior.

**ft_memmove** — same as memcpy but handles overlapping memory correctly. it figures out
which direction to copy so it doesn't overwrite data before it reads it.

**ft_memchr** — scans memory for a byte. returns a pointer to the first occurrence,
or NULL if it's not there.

**ft_memcmp** — compares two memory blocks byte by byte. returns 0 if they're identical,
otherwise the difference between the first bytes that differ.

**ft_bzero** — sets n bytes to zero. basically `memset(s, 0, n)`. deprecated in POSIX
but 42 still wants it.

---

## string functions

most of these you've used a hundred times. writing them yourself makes you realize
how many edge cases exist in something as "simple" as copying a string.

**ft_strlen** — counts characters until the null terminator. nothing fancy.
the trap is passing it a NULL pointer — it will crash, and that's your problem, not the function's.

**ft_strchr / ft_strrchr** — find a character in a string. `strchr` finds the first occurrence,
`strrchr` finds the last. both return a pointer to it, not an index.

**ft_strncmp** — compares two strings up to n characters. returns 0 if equal.
the tricky part is when one string ends before n — you have to handle the null terminator
as part of the comparison.

**ft_strnstr** — finds a substring inside a string, but only looks in the first n characters.
a 42-specific function that barely exists outside of this school.

**ft_strdup** — allocates memory and copies a string into it. your first encounter with
"malloc inside a function" and all the questions that come with it — who frees this? when?

**ft_strlcpy / ft_strlcat** — safer versions of strcpy and strcat. they take a size parameter
so they don't write past the buffer. always null-terminate. always return the length
they *would* have written, even if they truncated. that return value is important.

**ft_substr** — extracts a substring starting at index `start` with max length `len`.
allocates the result. handles the case where start is past the end of the string.

**ft_strjoin** — concatenates two strings into a new allocated one.
simple but you will use this constantly in future projects.

**ft_strtrim** — removes characters from a given set at both ends of a string.
not just spaces — any character in the set you pass. people always get confused
that it's not "trim whitespace", it's "trim this specific set of characters."

**ft_split** — splits a string by a delimiter character and returns an array of strings.
the hardest function in the mandatory part. the edge cases are endless —
multiple consecutive delimiters, empty string input, malloc failure halfway through.
when this one compiles and passes all tests, you feel it.

**ft_strmapi / ft_striteri** — apply a function to each character of a string.
`strmapi` returns a new string with the results. `striteri` modifies in place.
these exist to give you a taste of functional-style programming in C.

---

## conversion functions

**ft_atoi** — converts a string like "42" into the integer 42. handles leading whitespace,
optional sign, and stops at the first non-digit. doesn't handle overflow — that's intentional,
the real atoi doesn't either.

**ft_itoa** — the reverse. takes an int, returns a string. the edge case everyone forgets
is INT_MIN, because its absolute value doesn't fit in a positive int.

**ft_tolower / ft_toupper** — convert a character's case. only affect alphabetic characters,
leave everything else untouched. the implementations are one-liners but they're in the
subject so here they are.

---

## character check functions

**ft_isalpha / ft_isdigit / ft_isalnum** — check if a character is a letter, a digit, or either.
**ft_isascii** — checks if the value is in the 0–127 ASCII range.
**ft_isprint** — checks if it's a printable character (32–126).

all of these return nonzero for true, 0 for false. not 1, not a bool — just nonzero.
that distinction matters when you start writing conditions based on these.

---

## output functions

these write to a file descriptor, not stdout specifically. that means you can
write to stderr (fd 2) just by changing the last argument.

**ft_putchar_fd** — writes a single character.
**ft_putstr_fd** — writes a string.
**ft_putendl_fd** — writes a string followed by a newline.
**ft_putnbr_fd** — writes an integer as its string representation.

you'll use the fd versions more than you expect once you start doing proper
error handling in later projects.
---

## build

```bash
make        # builds libft.a
make clean  # removes object files
make fclean # removes object files and the archive
make re     # fclean + make
```

to use it in another project:
```bash
gcc your_file.c -L. -lft -o your_program
```

---

## score

125 / 100
