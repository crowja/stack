#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

int
main(int argc, char *argv[])
{
   unsigned    i;
   unsigned   *jp;
   struct stack *z = stack_new();

   for (i = 0; i < 100; i++) {
      jp = malloc(sizeof(unsigned));
      *jp = i;
      stack_push(z, jp);
   }

   while (stack_pop(z, (void **) &jp)) {
      printf("Popped %d\n", *jp);
      free(jp);
   }

   stack_free(&z);

   return 0;
}
