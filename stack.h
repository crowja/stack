/**
 *  @file stack.h
 *  @version 0.3.0-dev0
 *  @date Sun Feb 16, 2020 05:06:33 PM CST
 *  @copyright 2020 John A. Crow <crowja@gmail.com>
 *  @license Unlicense <http://unlicense.org/>
 */

#ifndef STACK_H
#define STACK_H

struct stack;

/**
 *  @brief Constructor.
 *  @details Create and return a new stack object.
 *  @returns New stack object.
 */
struct stack *stack_new(void);

/**
 *  @brief Destructor.
 *  @details Clean up and free a stack structure.
 *  @param[in, out] p.
 */
void        stack_free(struct stack **pp);

/**
 *  @brief Return the version of this package.
 *  @returns Version string.
 */
const char *stack_version(void);

int         stack_is_empty(struct stack *p);
int         stack_peek(struct stack *p, void **x);
int         stack_pop(struct stack *p, void **x);
int         stack_push(struct stack *p, void *x);

#endif
