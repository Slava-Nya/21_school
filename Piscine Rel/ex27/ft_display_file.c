/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 21:45:53 by hlorrine          #+#    #+#             */
/*   Updated: 2019/09/06 22:40:00 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	display(int fd)
{
	char buffer;

	while (read(fd, &buffer, 1) != 0)
		write(1, &buffer, 1);
}

int		main(int argc, char **argv)
{
	int fd;

	if (argc != 2)
	{
		if (argc > 2)
			write(2, "Too many arguments.\n", 20);
		if (argc < 2)
			write(2, "File name missing.\n", 19);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (0);
	display(fd);
	close(fd);
	return (0);
}
