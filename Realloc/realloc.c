#include "specific.h"

/* Creates the empty array */
arr *arr_init(void)
{
   arr *a = ncalloc(1, sizeof(arr));
   if (a == NULL)
   {
      on_error("Array is null. Bye bye~");
   }
   a->data = NULL;
   a->size = 0;
   return a;
}

/* Similar to l[n] = i, safely resizing if required */
void arr_set(arr *l, int n, int i)
{
   if (n < 0)
   {
      on_error("Index can't be negative.");
   }
   if (n >= l->size)
   {
      int old_bytes = l->size * sizeof(int);
      int new_size = n + 1;
      int new_bytes = new_size * sizeof(int);

      l->data = nrecalloc(l->data, old_bytes, new_bytes);
      l->size = new_size;
   }
   l->data[n] = i;
}

// /* Similar to = l[n] */
int arr_get(arr *l, int n)
{
   if (n < 0)
   {
      on_error("Index can't be negative.");
   }
   if (n >= l->size)
   {
      return 0;
   }
   return l->data[n];
}

// /* Clears all space used, and sets pointer to NULL */
void arr_free(arr **l)
{
   if (*l == NULL)
   {
      return;
   }
   free((*l)->data);
   free(*l);
   *l = NULL;
}
