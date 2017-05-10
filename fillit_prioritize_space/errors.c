/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayfiel <nmayfiel@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 14:54:23 by nmayfiel          #+#    #+#             */
/*   Updated: 2016/12/18 15:24:11 by nmayfiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <libft.h>
#include <stdlib.h>

void	exit_with_error(const char *err_str)
{
	ft_putendl_fd(err_str, 2);
	exit(1);
}
