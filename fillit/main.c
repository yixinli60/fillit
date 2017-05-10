/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 17:10:52 by yli               #+#    #+#             */
/*   Updated: 2016/12/18 15:12:34 by nmayfiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <libft.h>
#include <fcntl.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int fd;

	fd = 0;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			exit_with_error("error");
		fillit(fd);
		close(fd);
	}
	else
		exit_with_error(USAGE);
	return (0);
}
