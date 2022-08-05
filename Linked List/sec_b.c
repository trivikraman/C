#include <stdlib.h>
#include <stdio.h>
struct list_node
{
    char name[100];
    struct list_node *previous;
    struct list_node *next;
};
typedef struct list_node node;
int count(node *head)
{
    int count = 0;
    while (head)
    {
        count++;
        head = head->next;
    }
    return count;
}
node *add_first(char *name, node *head)
{
    int i;
    node *new_node;
    new_node = (node *)malloc(sizeof(node));
    for (i = 0; name[i] != '\0'; ++i)
        new_node->name[i] = name[i];
    new_node->next = head;
    if (head != NULL)
    {
        head->previous = new_node;
    }
    head = new_node;
    return head;
}
void add_last(char *name, node *current)
{
    int i;
    node *new_node;
    new_node = (node *)malloc(sizeof(node));
    while (current)
    {
        if (current->next == NULL)
        {
            current->next = new_node;
            for (i = 0; name[i] != '\0'; ++i)
                new_node->name[i] = name[i];
            new_node->previous = current;
            return;
        }
        current = current->next;
    }
}
void print_list(node *current)
{
    printf("HEAD: ");
    while (current)
    {
        printf("%s", current->name);
        printf(" -> ");
        current = current->next;
    }
    printf("\b\b\b\b :TAIL\n");
}
int main(void)
{
    node *head = NULL;
    node *tail = NULL;
    int number, i, choice;
    char name[100]="Start";
    head = add_first(name, head);
    do
    {
        printf("enter the word");
        scanf("%s", name);
        for (i = 0; name[i] != '\0'; ++i);
        if (i > 5)
        {
            add_last(name, head);
            printf("Word added");
        }
        else
            printf("\ninvalid input\n");
        printf("want to continue(1/0):\n");
        scanf("%d", &choice);
        i = 0;
    } while (choice == 1);
    printf("Original List:\n");
    print_list(head);
    return 0;
}
