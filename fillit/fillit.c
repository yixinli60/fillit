/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayfiel <nmayfiel@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 18:05:00 by nmayfiel          #+#    #+#             */
/*   Updated: 2016/12/18 16:30:04 by nmayfiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <libft.h>
#include <unistd.h>

void	fillit(int fd)
{
	char		buf[BUFFER_SIZE];
	int			num_read;
	int			num_pieces;
	t_piece		**pieces;

	if ((num_read = read(fd, buf, BUFFER_SIZE)) >= 0)
	{
		buf[num_read] = '\0';
		num_pieces = verify_input(buf);
		if (!num_pieces || num_read < 20 || num_read > 545)
			exit_with_error("error");
		pieces = get_pieces(buf, num_pieces);
		fix_piece_offset(pieces, num_pieces);
		solve_fillit(pieces, num_pieces);
	}
	else
		exit_with_error("error");
}
