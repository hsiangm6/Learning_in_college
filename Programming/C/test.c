#include <stdlib.h>
#include <stdio.h>

typedef struct List
{
    char c;
    struct List *next;
} List;

static List *stringToList(char s[])
{
    List *prev_node = NULL;
    if (*(s+1))
        prev_node = stringToList(s + 1);

    List *this_node = malloc(sizeof(List));
    this_node->c = *s;
    this_node->next = prev_node;

    return this_node;
}

static void printList(List *l)
{
    static const char *arrow[2] = {"", "-->"};
    if (l)
    {
        printf("%c%s", l->c, arrow[!!l->next]);
        printList(l->next);
    }
}

static void free_list(List *l)
{
    if (l)
        free_list(l->next);
    free(l);
}

int main(void)
{
    List *l = stringToList("abc test");
    printList(l);
    free_list(l);
    return 0;
}
