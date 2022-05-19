
INTERCONTACT@DESKTOP-LB7BKBP MINGW64 ~
$ ssh ef415b2af939@ef415b2af939.4b4dbd09.alx-cod.online
ef415b2af939@ef415b2af939.4b4dbd09.alx-cod.online's password:
root@ef415b2af939:/# cd root
root@ef415b2af939:~# ls
0x01_emacs  alx-low_level_programming      Betty       school_is_amazing
0x02_emacs  alx-pre_course                 new_school  so_cool
0x02_vi     alx-system_engineering-devops  README.md   tmp
0x03_vi     alx-zero_day                   school
root@ef415b2af939:~# cd alx-low_level_programming
root@ef415b2af939:~/alx-low_level_programming# mkdir 0x12-singly_linked_lists
root@ef415b2af939:~/alx-low_level_programming# cd 0x12-singly_linked_lists
root@ef415b2af939:~/alx-low_level_programming/0x12-singly_linked_lists# echo "My 0x12-singly_linked_lists" >> README.md
root@ef415b2af939:~/alx-low_level_programming/0x12-singly_linked_lists# cat > _putchar.c
#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
        return (write(1, &c, 1));
}
^C
root@ef415b2af939:~/alx-low_level_programming/0x12-singly_linked_lists# cat > 0-print_list.c
#include <stdio.h>
#include "lists.h"

/**
 * print_list - prints all the elements of a linked list
 * @h: pointer to the list_t list to print
 *
 * Return: the number of nodes printed
 */
size_t print_list(const list_t *h)
{
        size_t n = 0;

        while (h)
        {
                if (!h->str)
                        printf("[0] (nil)\n");
                else
                        printf("[%u] %s\n", h->len, h->str);
                h = h->next;
                n++;
        }

        return (n);
}
^C
root@ef415b2af939:~/alx-low_level_programming/0x12-singly_linked_lists# cat > 1-list_len.c
#include "lists.h"

/**
 * list_len - Calculate the number of elements.
 * @h: Pointer to a list.
 * Return: Integer.
 **/

size_t list_len(const list_t *h)
{
        const list_t *temp;
        unsigned int counter = 0;

        temp = h;
        while (temp)
        {
                counter++;
                temp = temp->next;
        }
        return (counter);
}
^C
root@ef415b2af939:~/alx-low_level_programming/0x12-singly_linked_lists# cat > 2-add_node.c
#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node - adds a new node at the beginning of a linked list
 * @head: double pointer to the list_t list
 * @str: new string to add in the node
 *
 * Return: the address of the new element, or NULL if it fails
 */
list_t *add_node(list_t **head, const char *str)
{
        list_t *new;
        unsigned int len = 0;

        while (str[len])
                len++;

        new = malloc(sizeof(list_t));
        if (!new)
                return (NULL);

        new->str = strdup(str);
        new->len = len;
        new->next = (*head);
        (*head) = new;

        return (*head);
}
^C
root@ef415b2af939:~/alx-low_level_programming/0x12-singly_linked_lists# cat > 3-add_node_end.c
#include "lists.h"
/**
 * add_node_end - Add a new node at the end of a list.
 * @head: Address of the first node of a list.
 * @str: Address of the string to insert into the new node.
 * Return: Address of the new node.
 **/

list_t *add_node_end(list_t **head, const char *str)
{
        list_t *temp, *temp2;
        unsigned int length = 0;

        if (str == NULL)
                return (NULL);

        temp = malloc(sizeof(list_t));
        if (temp == NULL)
                return (NULL);

        temp->str = strdup(str);
        if (temp->str == NULL)
        {
                free(temp);
                return (NULL);
        }
        while (str[length])
                length++;
        temp->len = length;
        temp->next = NULL;

        if (*head == NULL)
        {
                *head = temp;
                return (temp);
        }

        temp2 = *head;
        while (temp2->next)
                temp2 = temp2->next;
        temp2->next = temp;
        return (temp);
}
^C
root@ef415b2af939:~/alx-low_level_programming/0x12-singly_linked_lists# cat > 4-free_list.c
#include <stdlib.h>
#include "lists.h"

/**
 * free_list - frees a linked list
 * @head: list_t list to be freed
 */
void free_list(list_t *head)
{
        list_t *tmp;

        while (head)
        {
                tmp = head->next;
                free(head->str);
                free(head);
                head = tmp;
        }
}
^C
root@ef415b2af939:~/alx-low_level_programming/0x12-singly_linked_lists# cat > 0-main.c
