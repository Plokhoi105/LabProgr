#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE (8)

static int cmp(const void *p1, const void *p2)
{
    return strcmp(* (char * const *) p1, * (char * const *) p2);
}

int main(int argc, char *argv[])
{
    char *str[] = {"pave", "dEvotion", "Milk", "booK", "University", "Alphabet", "MIcroprocessor", "eGg"};
    printf("Before sort:\n\t");
    for(int n = 0; n < SIZE; ++n)
        printf("%s ", str[n]);

    qsort(str, SIZE, sizeof(char *), cmp);

    printf("\nAfter sort:\n\t");
    for(int n = 0; n < SIZE; ++n)
        printf("%s ", str[n]);

    return 0;
}
