/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pieces.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayfiel <nmayfiel@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 16:44:09 by nmayfiel          #+#    #+#             */
/*   Updated: 2016/12/18 15:12:19 by nmayfiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <libft.h>

static t_piece		*new_piece(int num)
{
	t_piece		*piece;

	piece = (t_piece *)malloc(sizeof(t_piece));
	piece->c = 'A' + num;
	piece->used = 0;
	return (piece);
}

static char			*get_alphabet(void)
{
	char	*alpha_str;
	int		i;

	i = 0;
	alpha_str = (char *)malloc(sizeof(char) * 27);
	while (i < 26)
	{
		alpha_str[i] = 'A' + i;
		i++;
	}
	alpha_str[i] = '\0';
	return (alpha_str);
}

t_piece				**get_pieces(const char *buf, int num_pieces)
{
	t_piece		**pieces;
	char		*alphabet;
	int			i;
	int			j;
	int			hash;

	i = -1;
	alphabet = get_alphabet();
	pieces = (t_piece **)malloc(sizeof(t_piece *) * num_pieces);
	while (++i < num_pieces && *buf != '\0')
	{
		pieces[i] = new_piece(i);
		hash = -1;
		j = 0;
		while (++hash < 4)
		{
			while (buf[j] != '#')
				j++;
			pieces[i]->coords[hash].x = j % 5;
			pieces[i]->coords[hash].y = j / 5;
			j++;
		}
		buf += 21;
	}
	return (pieces);
}
