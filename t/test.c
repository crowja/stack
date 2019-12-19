#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include <math.h>
#include <string.h>
#include "stack.h"
#include "t/tinytest.h"

#ifdef  _COLOR_CODE
#undef  _COLOR_CODE
#endif
#define _COLOR_CODE       0x1B

#ifdef  _COLOR_RED
#undef  _COLOR_RED
#endif
#define _COLOR_RED        "[1;31m"

#ifdef  _COLOR_GREEN
#undef  _COLOR_GREEN
#endif
#define _COLOR_GREEN      "[1;32m"

#ifdef  _COLOR_YELLOW
#undef  _COLOR_YELLOW
#endif
#define _COLOR_YELLOW     "[1;33m"

#ifdef  _COLOR_RESET
#undef  _COLOR_RESET
#endif
#define _COLOR_RESET      "[0m"


static void
_printf_test_name(char *name, char *info)
{
   printf("%c%s%s%c%s", _COLOR_CODE, _COLOR_YELLOW, name, _COLOR_CODE, _COLOR_RESET);

   if (NULL != info)
      printf(" [%s]\n", info);
   else
      printf("\n");
}


static int
_two_doubles_equal(double x, double y)
{
   double      t = fabs(x) + fabs(y);
   return fabs(x - y) < 4 * DBL_EPSILON * t ? 1 : 0;
}


static void
test_constr(void)
{
   struct stack *z;

   _printf_test_name("test_constr", "stack_new, stack_free");

   z = stack_new();
   ASSERT("Constructor test", z);
   stack_free(&z);
   ASSERT_EQUALS(NULL, z);

}

static void
test_push_pop_1(void)
{
   void       *s;
   struct stack *z;

   _printf_test_name("test_push_pop_1", "stack_push, stack_pop");

   z = stack_new();

   stack_push(z, "abc def ghi jkl mno pqr stu vwx yz");
   stack_pop(z, &s);
   printf("*** stack_pop() returns %s\n", (char *) s);
   ASSERT_STRING_EQUALS("abc def ghi jkl mno pqr stu vwx yz", (char *) s);

   stack_free(&z);
   ASSERT_EQUALS(NULL, z);
}

static void
test_push_pop_2(void)
{
   int         i, *jp, n = 85535;
   struct stack *z;

   _printf_test_name("test_push_pop_2", "stack_push, stack_pop");

   z = stack_new();

   for (i = 0; i < n; i++) {
      jp = malloc(sizeof(int));
      *jp = i;
      stack_push(z, jp);
   }

   i = n;

   while (stack_pop(z, (void **) &jp)) {
      i--;
      /* printf("%d\n", (int) *jp); */
      ASSERT_EQUALS(i, (int) *jp);
      free(jp);
   }

   stack_free(&z);
   ASSERT_EQUALS(NULL, z);
}

#if 0                                            /* 16 yy */
static void
test_stub(void)
{
   struct stack *z;
   double      x = 1.23;                    /* TODO */

   _printf_test_name("test_stub", NULL);

   z = stack_new();
   ASSERT("Constructor test, pt 1", z);
   ASSERT("Here's a test ...", _two_doubles_equal(x, 1.23));
   ASSERT_EQUALS(10, 10);

   stack_free(&z);
   ASSERT_EQUALS(NULL, z);
}
#endif


int
main(void)
{
   printf("%s\n", stack_version());

   RUN(test_constr);
   RUN(test_push_pop_1);
   RUN(test_push_pop_2);

   return TEST_REPORT();
}
