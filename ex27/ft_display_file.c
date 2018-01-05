/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtual <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 17:03:07 by chtual            #+#    #+#             */
/*   Updated: 2017/12/04 18:52:30 by chtual           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_display_file(int fd)
{
	char	buf;

	while (read(fd, &buf, 1) != 0)
		write(1, &buf, 1);
}

int		main(int argc, char **argv)
{
	int		fd;

	if (argc > 2)
	{
		write(1, "Too many arguments.\n", 20);
		return (1);
	}
	if (argc < 2)
	{
		write(1, "File name missing.\n", 19);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	ft_display_file(fd);
	close(fd);
	return (0);
}
