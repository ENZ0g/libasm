#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

#define COLGREEN    "\x1b[32m"
#define COLRESET    "\x1b[0m"
#define COLBLUE     "\x1B[34m"

int     ft_list_size(t_list *list);
void	ft_list_push_front(t_list **list, void *content);

void    ft_atoi_test(void)
{
    char    *str;

    str = "123";
    printf("std: %d --- my: %d\n\n", atoi(str), ft_atoi(str));
}

void    print_list(void *content)
{
    printf(COLBLUE "list item - " COLRESET "%s\n" , content);
}

t_list  *get_new_list(int len)
{
    t_list  *list;
    int     i;

    if (len == 0)
        return (0);

    i = 1;
    list = ft_lstnew(ft_itoa(i));
    printf("size of t_list - %lu\n", sizeof(t_list));
    printf("offset - %ld\n", (void *)&list->next - (void *)list);
    while (i++ < len)
        ft_lstadd_back(&list, ft_lstnew(ft_itoa(i)));
    ft_lstiter(list, &print_list);
    return (list);
}

void    ft_list_size_test(int len)
{
    t_list  *list;

    puts("\n" COLGREEN "**** ft_list_size test ****" COLRESET "\n");

    list = get_new_list(len);
    printf("libft list size: - %d\n", ft_lstsize(list));
    printf("assmb list size: - %d\n", ft_list_size(list));
    ft_lstclear(&list, &free);
}

void    ft_list_push_front_test(int len)
{
    t_list  *list;
    t_list  *new_elem;

    puts("\n" COLGREEN "**** ft_list_push_front test ****" COLRESET "\n");

    list = get_new_list(len);
    new_elem = ft_lstnew(ft_strdup("new"));
    ft_lstadd_front(&list, new_elem);
    puts("\nnew list by ft_lstadd_front\n");
    ft_lstiter(list, &print_list);
    puts("\nnew list by ft_list_push_front\n");
    ft_list_push_front(&list, ft_strdup("one more"));
    ft_lstiter(list, &print_list);
    ft_lstclear(&list, &free);
}

int     main(int argc, char **argv)
{
    int len;

    if (argc == 1)
        len = 10;
    else
        len = ft_atoi(argv[1]);
    // ft_atoi_test();
    ft_list_size_test(len);
    ft_list_push_front_test(len);
    return (0);
}