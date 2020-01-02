/**
 *  @file stack.h
 *  @version 0.2.0-dev0
 *  @date Thu Dec 19 14:27:27 CST 2019
 *  @copyright 2020 John A. Crow <crowja@gmail.com>
 *  @license Unlicense <http://unlicense.org/>
 */

#ifndef _STACK_H_
#define _STACK_H_

#ifdef  _PACKAGE_NAME
#undef  _PACKAGE_NAME
#endif
#define _PACKAGE_NAME "stack"

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
