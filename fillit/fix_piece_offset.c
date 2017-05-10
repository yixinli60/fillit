/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_piece_offset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayfiel <nmayfiel@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 19:37:49 by nmayfiel          #+#    #+#             */
/*   Updated: 2016/12/16 19:38:14 by nmayfiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <libft.h>

void				fix_piece_offset(t_piece **pieces, int num_pieces)
{
	int			i;

	i = 0;
	while (i < num_pieces)
	{
		while (pieces[i]->coords[0].x != 0 && pieces[i]->coords[1].x != 0 &&
				pieces[i]->coords[2].x != 0 && pieces[i]->coords[3].x != 0)
		{
			pieces[i]->coords[0].x--;
			pieces[i]->coords[1].x--;
			pieces[i]->coords[2].x--;
			pieces[i]->coords[3].x--;
		}
		while (pieces[i]->coords[0].y != 0 && pieces[i]->coords[1].y != 0 &&
				pieces[i]->coords[2].y != 0 && pieces[i]->coords[3].y != 0)
		{
			pieces[i]->coords[0].y--;
			pieces[i]->coords[1].y--;
			pieces[i]->coords[2].y--;
			pieces[i]->coords[3].y--;
		}
		i++;
	}
}
