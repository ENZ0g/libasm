#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

#define LONG_TEXT   "Many instructions assign specific registers to hold operands."\
                    " For example, string instructions use the contents of the ECX,"\
                    " ESI, and EDI registers as operands. When using a segmented "\
                    "memory model, some instructions assume that pointers in certain "\
                    "registers are relative to specific segments. For instance, some "\
                    "instructions assume that a pointer in the EBX register points to "\
                    "a memory location in the DS segment.\n"

size_t  ft_strlen(const char *str);
char    *ft_strcpy(char *dst, const char *str);
int     ft_strcmp(const char *str1, const char *str2);
ssize_t ft_write(int fd, const void *str, size_t len);
ssize_t ft_read(int fd, void *buf, size_t len);
char    *ft_strdup(const char *str);

void    ft_strlen_test(void)
{
    int     len;
    char    *str;

    puts("\n**** ft_strlen test ****\n");

    str = "test string";
    len = ft_strlen(str);
    printf("|%s| --- std: %lu --- my: %d\n", str, strlen(str), len);

    str = "";
    len = ft_strlen(str);
    printf("|%s| --- std: %lu --- my: %d\n", str, strlen(str), len);

    str = "123";
    len = ft_strlen(str);
    printf("|%s| --- std: %lu --- my: %d\n", str, strlen(str), len);

    str = "test\t\nstring";
    len = ft_strlen(str);
    printf("|%s| --- std: %lu --- my: %d\n", str, strlen(str), len);

    str = LONG_TEXT;
    len = ft_strlen(str);
    printf("|%s| --- std: %lu --- my: %d\n", str, strlen(str), len);
}

void    ft_strcpy_test(void)
{
    char    *str;
    char    *dst;

    puts("\n**** ft_strcpy test ****\n");

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

    str = "test\t.\nstring";
    dst = (char *)malloc(sizeof(char) * (strlen(str) + 1));
    if (!dst)
        exit(1);
    printf("std: |%s| --- my: |%s|\n", strcpy(dst, str), ft_strcpy(dst, str));
    free(dst);
}

void    ft_strcmp_test()
{
    char    *str1;
    char    *str2;

    puts("\n**** ft_strcmp test ****\n");

    str1 = "test";
    str2 = "test";
    printf("cmp: %s -- %s\n", str1, str2);
    printf("std: %d --- my: %d\n\n", strcmp(str1, str2), ft_strcmp(str1, str2));

    str1 = "test1";
    str2 = "test";
    printf("cmp: %s -- %s\n", str1, str2);
    printf("std: %d --- my: %d\n\n", strcmp(str1, str2), ft_strcmp(str1, str2));

    str1 = "";
    str2 = "test1";
    printf("cmp: %s -- %s\n", str1, str2);
    printf("std: %d --- my: %d\n\n", strcmp(str1, str2), ft_strcmp(str1, str2));

    str1 = "test";
    str2 = "test string";
    printf("cmp: %s -- %s\n", str1, str2);
    printf("std: %d --- my: %d\n\n", strcmp(str1, str2), ft_strcmp(str1, str2));
}

void    ft_write_test(void)
{
    char    *string;
    int     std;
    int     my;
    int     fd;

    puts("\n**** ft_write test ****\n");

    string = "test\n";
    std = write(1, string, strlen(string));
    my = ft_write(1, string, ft_strlen(string));
    printf("std: %d --- my: %d\n\n", std, my);

    string = "";
    std = write(1, string, strlen(string));
    my = ft_write(1, string, ft_strlen(string));
    printf("std: %d --- my: %d\n\n", std, my);

    string = "test string\n";
    std = write(1, string, strlen(string));
    my = ft_write(1, string, ft_strlen(string));
    printf("std: %d --- my: %d\n\n", std, my);

    string = LONG_TEXT;
    std = write(1, string, strlen(string));
    my = ft_write(1, string, ft_strlen(string));
    printf("std: %d --- my: %d\n\n", std, my);

    string = "test string\n";
    std = write(2, string, strlen(string));
    my = ft_write(2, string, ft_strlen(string));
    printf("std: %d --- my: %d\n\n", std, my);

    string = "test string\n";
    printf("erno before open - %d\n", errno);   
    fd = open("test.txt", O_RDONLY);
    printf("erno before ft_write - %d\n", errno);
    my = ft_write(fd, string, 0);
    printf("erno after - %d\n", errno);
    close(fd);

    printf("erno before open - %d\n", errno);   
    fd = open("test.txt", O_RDONLY); 
    printf("erno before write - %d\n", errno);
    std = write(fd, string, 0);
    printf("erno after - %d\n", errno);
    close(fd);

    printf("std: %d --- my: %d\n\n", std, my);

}

void    ft_read_test(void)
{
    int     fd;
    int     std_read;
    int     my_read;
    char    buf[1000];

    puts("\n**** ft_read test ****\n");

    fd = open("read_test_1.txt", O_RDONLY);
    std_read = read(fd, buf, 12);
    printf("std read: len - %d\n|%s|\n", std_read, buf);
    close(fd);

    fd = open("read_test_1.txt", O_RDONLY);
    my_read = ft_read(fd, buf, 12);
    printf("my read: len - %d\n|%s|\n", my_read, buf);
    close(fd);

    fd = open("read_test_2.txt", O_RDONLY);
    std_read = read(fd, buf, 200);
    printf("std read: len - %d\n|%s|\n", std_read, buf);
    close(fd);

    fd = open("read_test_2.txt", O_RDONLY);
    my_read = ft_read(fd, buf, 200);
    printf("my read: len - %d\n|%s|\n\n", my_read, buf);
    close(fd);

    printf("ERRNO before open - %d\n", errno);
    fd = open("read_test_3.txt", O_RDONLY);
    printf("ERRNO before read - %d\n", errno);
    std_read = read(fd, buf, 200);
    printf("ERRNO after read - %d\n", errno);
    printf("std read: len - %d\n\n", std_read);
    close(fd);

    printf("ERRNO before open - %d\n", errno);
    fd = open("read_test_3.txt", O_RDONLY);
    printf("ERRNO before ft_read - %d\n", errno);
    my_read = ft_read(fd, buf, 200);
    printf("ERRNO ft_after read - %d\n", errno);
    printf("my read: len - %d\n\n", my_read);
    close(fd);
}

void    ft_strdup_test(void)
{
    char    *str;
    char    *new_str;
    char    *my_new_str;

    puts("\n**** ft_strdup test ****\n");

    str = "test";
    new_str = strdup(str);
    my_new_str = ft_strdup(str);
    printf("str: |%s| --- std: |%s| --- my: |%s|\n\n", str, new_str, my_new_str);
    free(new_str);
    free(my_new_str);

    str = "!--21--!";
    new_str = strdup(str);
    my_new_str = ft_strdup(str);
    printf("std: |%s| --- my: |%s|\n\n", new_str, my_new_str);
    free(new_str);
    free(my_new_str);

    str = "";
    new_str = strdup(str);
    my_new_str = ft_strdup(str);
    printf("str: |%s| --- std: |%s| --- my: |%s|\n\n", str, new_str, my_new_str);
    free(new_str);
    free(my_new_str);

    str = LONG_TEXT;
    new_str = strdup(str);
    my_new_str = ft_strdup(str);
    printf("str: |%s|\nstd: |%s|\nmy : |%s|\n\n", str, new_str, my_new_str);
    free(new_str);
    free(my_new_str);
}

int     main(void)
{
    ft_strlen_test();
    ft_strcpy_test();
    ft_strcmp_test();
    ft_write_test();
    ft_read_test();
    ft_strdup_test();
    return (0);
}