/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhullen <rhullen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 21:23:07 by rhullen           #+#    #+#             */
/*   Updated: 2020/08/13 18:04:43 by rhullen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define HEX_LOW "0123456789abcdef"
# define HEX_UPP "0123456789ABCDEF"
# define MAX_FD 1024
# define TYPES "cspdiuxX%"
# define BUFFER_SIZE 32

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct		s_flags
{
	int				left_align;
	int				add_zeros;
	int				width;
	int				is_precision;
	int				precision;
}					t_flags;

size_t				ft_strlen(const char *str);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_isprint(int c);
int					ft_isascii(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_putstr_free(char *s);
int					ft_putstrn(char *str, size_t len);
int					ft_atoi(const char *nptr);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_endwith(char *str, char *suffix);
char				*ft_strchr(const char *str, int c);
char				*ft_strrchr(const char *str, int c);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strdup(const char *s);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strnstr(const char *str1, const char *str2, size_t len);
char				*ft_itoa(int n);
char				*ft_utoa(unsigned int n);
char				*to_hex(unsigned long n, char mode);
char				**ft_split(char const *s, char c);
void				ft_bzero(void *s, size_t n);
int					ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);
void				*ft_calloc(size_t nmemb, size_t size);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);
t_list				*ft_lstnew(void *content);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *), void\
					(*del)(void *));
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
int					ft_arraylen(char **array);
int					ft_strisnum(char *str);

int					get_next_line(int fd, char **line);
int					get_line(char **temp_line, char **line);
int					read_fd(int fd, char **line, char **temp_line, char *buf);

int					ft_printf(const char *format, ...);
int					check_arg_s(va_list arg, t_flags *flags);
int					check_arg_p(va_list arg, t_flags *flags);
int					print_di(char *nbr, t_flags *flags);
int					print_u(char *nbr, t_flags *flags);
int					print_c(unsigned char c, t_flags *flags);
int					print_p(char *hex, t_flags *flags);
int					print_s(char *str, t_flags *flags);
int					print_x(char *hex, t_flags *flags);
const char			*parse_flags(const char *format, va_list arg,\
					t_flags *flags);
t_flags				*new_t_flags(void);
void				reset_flags(t_flags *flags);
char				*add_zeros(char *str, int total_len, int *hex_len);
char				*get_spaces_str(int size);
char				*get_zeros_str(int len);
char				*empty_str(char *str, int *len);

#endif
