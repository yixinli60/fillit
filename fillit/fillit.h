/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmayfiel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 18:03:46 by nmayfiel          #+#    #+#             */
/*   Updated: 2016/12/18 16:14:36 by nmayfiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFFER_SIZE 1024
# define USAGE "usage: fillit input_file"

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct	s_piece
{
	t_coord		coords[4];
	char		c;
}				t_piece;

void			fillit(int fd);
int				verify_input(const char *buf);
void			exit_with_error(const char *err_str);
int				all_pieces_used(t_piece **pieces, int num_pieces);
int				coords_to_index(int x, int y, int width);
t_piece			**get_pieces(const char *buf, int num_pieces);
void			fix_piece_offset(t_piece **pieces, int num_pieces);
void			solve_fillit(t_piece **pieces, int num_pieces);

#endif
