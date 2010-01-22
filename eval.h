#ifndef EVAL_H
#define EVAL_H

#include "cons.h"
#include "object.h"

/* Must be called before calling any other functions. */
void eval_init ();

object_t *eval (object_t * o);

extern object_t *lambda;	/* the lambda symbol */

#define IS_FUNC(o) \
  ((o->type == CONS && CAR(o)->type == SYMBOL && sym_eq(CAR(o), lambda)) \
   || (o->type == CFUNC))

#endif /* EVAL_H */
