/**
 *  @file stack.c
 *  @version 0.0.0
 *  @date Wed Dec 18 15:59:10 CST 2019
 *  @copyright %COPYRIGHT%
 *  @brief FIXME
 *  @details FIXME
 */

#include <stdlib.h>
#include <stdio.h>                               /* FIXME */
#include <string.h>                              /* FIXME */
#include "stack.h"

#ifdef  _IS_NULL
#undef  _IS_NULL
#endif
#define _IS_NULL(p)   ((NULL == (p)) ? (1) : (0))

#ifdef  _FREE
#undef  _FREE
#endif
#define _FREE(p)      ((NULL == (p)) ? (0) : (free((p)), (p) = NULL))

struct stnode {
   void *x;
   struct stnode *next;
};

static struct stnode *
stnode_new(void)
{
   struct stnode *tp;

   tp = (struct stnode *) malloc(sizeof(struct stnode));
   if (_IS_NULL(tp))
      return NULL;

   tp->x = NULL;
   tp->next = NULL;

   return tp;
}

static void
stnode_free(struct stnode **pp)
{
   _FREE(*pp);
   *pp = NULL;
}

struct stack {
   void       *x;
   struct stnode *head;
};

struct stack *
stack_new(void)
{
   struct stack *tp;

   tp = (struct stack *) malloc(sizeof(struct stack));
   if (_IS_NULL(tp))
      return NULL;

   tp->x = NULL;
   tp->head = NULL;

   return tp;
}

void
stack_free(struct stack **pp)
{

   /* Do some magic here ... */

   _FREE(*pp);
   *pp = NULL;
}

int
stack_init(struct stack *p, void *x)
{

   /* Do some magic here ... */
   p->x = x;                                     /* FIXME */

   return 0;
}

const char *
stack_version(void)
{
   return "0.0.0";
}

#undef  _IS_NULL
#undef  _FREE
