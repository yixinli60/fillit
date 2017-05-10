/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayfiel <nmayfiel@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 14:27:51 by nmayfiel          #+#    #+#             */
/*   Updated: 2016/12/17 10:01:15 by nmayfiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <libft.h>

static int		num_touches(const char *str, int i)
{
	int		num_touches;

	num_touches = 0;
	if (i < 19)
		if (str[i + 1] == '#')
			num_touches++;
	if (i > 0)
		if (str[i - 1] == '#')
			num_touches++;
	if (i < 14)
		if (str[i + 5] == '#')
			num_touches++;
	if (i > 4)
		if (str[i - 5] == '#')
			num_touches++;
	return (num_touches);
}

static int		count_hashes(const char *str)
{
	int		hashes;
	int		i;

	i = 0;
	hashes = 0;
	while (i < 21)
	{
		if (str[i] == '#')
			hashes++;
		i++;
	}
	return (hashes);
}

static int		validate_pieces(const char *str)
{
	int		i;
	int		touches_one;
	int		touches_two;

	while (*str != '\0')
	{
		i = 0;
		touches_one = 0;
		touches_two = 0;
		while (str[i] != '\0' && i < 21)
		{
			if (str[i] == '#')
			{
				touches_two += num_touches(str, i) >= 2 ? 1 : 0;
				touches_one += num_touches(str, i) >= 1 ? 1 : 0;
				if (num_touches(str, i) == 0)
					return (0);
			}
			i++;
		}
		if (touches_two == 0 || touches_one < 4 || count_hashes(str) != 4)
			return (0);
		str += 21;
	}
	return (1);
}

int				verify_input(const char *buf)
{
	int		i;
	int		num_pieces;

	i = 0;
	num_pieces = 0;
	while (buf[i] != '\0')
	{
		if ((i + 1) % 21 == 0 && buf[i] == '\n')
			num_pieces++;
		else if (((i + 1) % 21 == 0 || (i + 1) % 5 == num_pieces % 5)
				&& buf[i] != '\n')
			return (0);
		else if ((i + 1) % 5 != num_pieces % 5
				&& buf[i] != '#' && buf[i] != '.')
			return (0);
		i++;
	}
	if (i % 21 != 20 || !validate_pieces(buf))
		return (0);
	return (num_pieces + 1);
}
