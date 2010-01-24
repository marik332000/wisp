#ifndef COMMON_H
#define COMMON_H

#include <stdlib.h>

/* Wrapper for malloc() and realloc(). Will exit() the program on error. */
void *xmalloc (size_t size);
void *xrealloc (void *p, size_t size);

/* Define a strdup() since it's not always there. */
char *xstrdup (char *str);

/* Handle strings from the lexer. The returned string is from xmalloc(). */
char *process_str (char *str);

/* Create a new string that can be read back in again by the lexer. */
char *unprocess_str (char *str);

void error (char *str);

#endif /* COMMON_H */
