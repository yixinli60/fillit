/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pieces.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayfiel <nmayfiel@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 16:44:09 by nmayfiel          #+#    #+#             */
/*   Updated: 2016/12/18 16:47:52 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <libft.h>

static t_piece		*new_piece(int num)
{
	t_piece		*piece;

	piece = (t_piece *)malloc(sizeof(t_piece));
	piece->c = 'A' + num;
	return (piece);
}

t_piece				**get_pieces(const char *buf, int num_pieces)
{
	t_piece		**pieces;
	int			i;
	int			j;
	int			hash;

	i = 0;
	pieces = (t_piece **)malloc(sizeof(t_piece *) * num_pieces);
	while (i < num_pieces && *buf != '\0')
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
		i++;
	}
	return (pieces);
}
