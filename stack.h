/**
 *  @file stack.h
 *  @version 0.0.0
 *  @date Wed Dec 18 15:59:10 CST 2019
 *  @copyright %COPYRIGHT%
 *  @brief FIXME
 *  @details FIXME
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
 *  @brief Initialize a stack object.
 *  @details FIXME longer description here ...
 *  @param[in,out] p Pointer to a stack object
 *  @param[in] x FIXME
    @returns FIXME
 */
int         stack_init(struct stack *p, void *x);

/**
 *  @brief Return the version of this package.
 *  @returns Version string.
 */
const char *stack_version(void);

int stack_is_empty(struct stack *p);
int stack_peek(struct stack *p, void **x);
int stack_pop(struct stack *p, void **x);

#endif
