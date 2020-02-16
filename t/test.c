#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include <math.h>
#include <string.h>
#include "stack.h"
#include "t/tinytest.h"

#ifdef  COLOR_CODE
#undef  COLOR_CODE
#endif
#define COLOR_CODE       0x1B

#ifdef  COLOR_RED
#undef  COLOR_RED
#endif
#define COLOR_RED        "[1;31m"

#ifdef  COLOR_GREEN
#undef  COLOR_GREEN
#endif
#define COLOR_GREEN      "[1;32m"

#ifdef  COLOR_YELLOW
#undef  COLOR_YELLOW
#endif
#define COLOR_YELLOW     "[1;33m"

#ifdef  COLOR_RESET
#undef  COLOR_RESET
#endif
#define COLOR_RESET      "[0m"


static void
printf_test_name(char *name, char *info)
{
   printf("%c%s%s%c%s", COLOR_CODE, COLOR_YELLOW, name, COLOR_CODE, COLOR_RESET);

   if (NULL != info)
      printf(" [%s]\n", info);
   else
      printf("\n");
}


static int
two_doubles_equal(double x, double y)
{
   double      t = fabs(x) + fabs(y);
   return fabs(x - y) < 4 * DBL_EPSILON * t ? 1 : 0;
}


static void
test_constr(void)
{
   struct stack *z;

   printf_test_name("test_constr", "stack_new, stack_free");

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

   printf_test_name("test_push_pop_1", "stack_push, stack_pop");

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

   printf_test_name("test_push_pop_2", "stack_push, stack_pop");

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

   printf_test_name("test_stub", NULL);

   z = stack_new();
   ASSERT("Constructor test, pt 1", z);
   ASSERT("Here's a test ...", two_doubles_equal(x, 1.23));
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
