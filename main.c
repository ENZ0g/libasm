#include <stdio.h>
#include <stdlib.h>
#include <string.h>

u_int64_t   ft_strlen(char *str);
char        *ft_strcpy(char *dst, char *str);

void    ft_strlen_test(void)
{
    int     len;
    char    *str;

    puts("\n---- ft_strcpy test ----\n");

    str = "test string";
    len = ft_strlen(str);
    printf("std: %lu --- my: %d\n", strlen(str), len);

    str = "";
    len = ft_strlen(str);
    printf("std: %lu --- my: %d\n", strlen(str), len);

    str = "123";
    len = ft_strlen(str);
    printf("std: %lu --- my: %d\n", strlen(str), len);

    str = "test\t\nstring";
    len = ft_strlen(str);
    printf("std: %lu --- my: %d\n", strlen(str), len);
}

void    ft_strcpy_test(void)
{
    char    *str;
    char    *dst;

    puts("\n---- ft_strcpy test ----\n");

    str = "test string";
    dst = (char *)malloc(sizeof(char) * (strlen(str) + 1));
    if (!dst)
        exit(1);
    printf("std: |%s| --- my: |%s|\n", strcpy(dst, str), ft_strcpy(dst, str));
    free(dst);

    str = "";
    dst = (char *)malloc(sizeof(char) * (strlen(str) + 1));
    if (!dst)
        exit(1);
    printf("std: |%s| --- my: |%s|\n", strcpy(dst, str), ft_strcpy(dst, str));
    free(dst);

    str = "test\t\nstring";
    dst = (char *)malloc(sizeof(char) * (strlen(str) + 1));
    if (!dst)
        exit(1);
    printf("std: |%s| --- my: |%s|\n", strcpy(dst, str), ft_strcpy(dst, str));
    free(dst);
}

int     main(void)
{
    ft_strlen_test();
    ft_strcpy_test();
    return (0);
}