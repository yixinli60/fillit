/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_fillit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayfiel <nmayfiel@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 09:58:06 by nmayfiel          #+#    #+#             */
/*   Updated: 2016/12/18 17:14:19 by nmayfiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "fillit.h"
#include <stdlib.h>

static char				*get_board_of_size(int side)
{
	char	*board;
	int		str_size;
	int		i;

	str_size = (side * side) + side - 1;
	board = (char *)malloc(sizeof(char) * (str_size + 1));
	if (!board)
		return (NULL);
	ft_memset(board, '.', str_size);
	board[str_size] = '\0';
	i = 0;
	while (board[i] != '\0')
	{
		if ((i + 1) % (side + 1) == 0)
			board[i] = '\n';
		i++;
	}
	return (board);
}

static void				remove_piece(char *board, int pos, t_piece *piece)
{
	int		i;
	int		bsize;

	i = 0;
	bsize = 0;
	while (board[bsize] != '\n')
		bsize++;
	while (i < 4)
	{
		board[pos + coords_to_index(piece->coords[i].x,
				piece->coords[i].y, bsize)] = '.';
		i++;
	}
}

static int				fill_with_piece(char *board, int pos, t_piece *piece)
{
	int		i;
	int		bsize;
	int		coord;

	i = 0;
	bsize = 0;
	while (board[bsize] != '\n')
		bsize++;
	while (i < 4)
	{
		coord = coords_to_index(piece->coords[i].x, piece->coords[i].y, bsize);
		if (coord + pos >= (bsize * (bsize + 1)))
			return (0);
		if (board[pos + coord] != '.')
			return (0);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		board[pos + coords_to_index(piece->coords[i].x,
				piece->coords[i].y, bsize)] = piece->c;
		i++;
	}
	return (1);
}

static int				recursively_fillit(t_piece **pieces, int num_pieces,
		char *board, int piece_pos)
{
	int		i;

	i = 0;
	if (piece_pos == num_pieces)
		return (1);
	else
		while ((size_t)i < ft_strlen(board))
		{
			if (board[i] != '\n')
				if (fill_with_piece(board, i, pieces[piece_pos]) == 1)
				{
					if (recursively_fillit(pieces, num_pieces,
								board, piece_pos + 1))
						return (1);
					else
						remove_piece(board, i, pieces[piece_pos]);
				}
			i++;
		}
	return (0);
}

void					solve_fillit(t_piece **pieces, int num_pieces)
{
	int		sidelen;
	char	*board;

	sidelen = 2;
	while (sidelen * sidelen < num_pieces * 4 && sidelen < 11)
		sidelen++;
	board = get_board_of_size(sidelen);
	while (!recursively_fillit(pieces, num_pieces, board, 0) && sidelen < 15)
	{
		sidelen++;
		free(board);
		board = get_board_of_size(sidelen);
	}
	ft_putendl(board);
}
