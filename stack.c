/**
 *  @file stack.c
 *  @version 0.3.0-dev0
 *  @date Thu Dec 19 14:27:27 CST 2019
 *  @copyright 2020 John A. Crow <crowja@gmail.com>
 *  @license Unlicense <http://unlicense.org/>
 */

#include <stdlib.h>
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
   void       *x;
   struct stnode *next;
};

static struct stnode *
stnode_new(void)
{
   struct stnode *tp = (struct stnode *) malloc(sizeof(struct stnode));

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
   struct stack *tp = (struct stack *) malloc(sizeof(struct stack));

   if (_IS_NULL(tp))
      return NULL;

   tp->x = NULL;
   tp->head = NULL;

   return tp;
}

void
stack_free(struct stack **pp)
{
   while (!_IS_NULL((*pp)->head)) {
      struct stnode *tmp = (*pp)->head->next;
      stnode_free(&((*pp)->head));
      (*pp)->head = tmp;
   }

   _FREE(*pp);
   *pp = NULL;
}

const char *
stack_version(void)
{
   return "0.3.0-dev0";
}

int
stack_is_empty(struct stack *p)
{
   return _IS_NULL(p->head) ? 1 : 0;
}

int
stack_peek(struct stack *p, void **x)
{
   if (_IS_NULL(p->head))
      return 0;

   *x = p->head->x;

   return 1;
}

int
stack_pop(struct stack *p, void **x)
{
   if (_IS_NULL(p->head))
      return 0;

   else {
      struct stnode *tmp = p->head->next;
      *x = p->head->x;
      stnode_free(&(p->head));
      p->head = tmp;
      return 1;
   }
}

int
stack_push(struct stack *p, void *x)
{
   struct stnode *n = stnode_new();

   if (_IS_NULL(n))
      return 1;

   if (_IS_NULL(p->head))                        /* list is empty */
      n->next = NULL;

   else
      n->next = p->head;

   n->x = x;
   p->head = n;

   return 0;
}

#undef  _IS_NULL
#undef  _FREE
