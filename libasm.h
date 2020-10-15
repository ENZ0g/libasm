/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhullen <rhullen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 14:09:06 by rhullen           #+#    #+#             */
/*   Updated: 2020/10/15 10:21:50 by rhullen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>

# define LONG_TEXT	"Many instructions assign specific registers to hold operands."\
					" For example, string instructions use the contents of the ECX,"\
					" ESI, and EDI registers as operands. When using a segmented "\
					"memory model, some instructions assume that pointers in certain "\
					"registers are relative to specific segments. For instance, some "\
					"instructions assume that a pointer in the EBX register points to "\
					"a memory location in the DS segment.\n"

# define COLGREEN	"\x1b[32m"
# define COLRESET	"\x1b[0m"

size_t	ft_strlen(const char *str);
char	*ft_strcpy(char *dst, const char *str);
int		ft_strcmp(const char *str1, const char *str2);
ssize_t	ft_write(int fd, const void *str, size_t len);
ssize_t	ft_read(int fd, void *buf, size_t len);
char	*ft_strdup(const char *str);

#endif
