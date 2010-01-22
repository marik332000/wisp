#include <stdio.h>
#include "common.h"
#include "cons.h"
#include "symtab.h"
#include "object.h"
#include "eval.h"
#include "lisp.h"

/* Initilize all the systems. */
void init ()
{
  /* These *must* be called in this order. */
  object_init ();
  symtab_init ();
  cons_init ();
  eval_init ();
  lisp_init ();
}

object_t *setq (object_t * lst)
{
  object_t *v = CAR (lst);
  if (v->type != SYMBOL)
    {
      printf ("error: setq: not a symbol!\n");
      return NIL;
    }
  SET (v, CAR (CDR (lst)));
  return NIL;
}

int main (int argc, char **argv)
{
  (void) argc;
  (void) argv;
  init ();

  obj_print (c_cons
	     (c_sym ("defun"),
	      c_cons (c_str ("hello"), c_cons (c_int (10), NIL))));
  printf ("\n");

  object_t *lst =
    c_cons (c_sym ("+"), c_cons (c_int (10), c_cons (c_int (34), NIL)));
  object_t *sexp = c_cons (c_sym ("+"), c_cons (lst, CDR (lst)));
  obj_print (sexp);
  printf ("\n");
  obj_print (eval (sexp));
  printf ("\n");
}
