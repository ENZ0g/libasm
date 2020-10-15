/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhullen <rhullen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 14:08:51 by rhullen           #+#    #+#             */
/*   Updated: 2020/10/15 12:38:17 by rhullen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_BONUS_H
# define LIBASM_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include "libft.h"

# define COLGREEN	"\x1b[32m"
# define COLRESET	"\x1b[0m"
# define COLBLUE	"\x1b[34m"

int		ft_list_size(t_list *list);
void	ft_list_push_front(t_list **list, void *content);

#endif
