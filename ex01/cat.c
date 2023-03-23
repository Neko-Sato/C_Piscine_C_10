/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:51:55 by hshimizu          #+#    #+#             */
/*   Updated: 2023/03/23 22:26:11 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define BUF_SIZE 1024

int	stream_stdout(int stream)
{
	int		size;
	char	buf[BUF_SIZE];

	while (1)
	{
		size = read(stream, buf, BUF_SIZE);
		write(STDOUT_FILENO, buf, size);
		if (size < BUF_SIZE)
			break ;
	}
	return (size != 0);
}

int	main(int argc, char *argv[])
{
	int	i;
	int	stream;

	stream = STDIN_FILENO;
	i = 1;
	while (argc == 1 || i < argc)
	{
		if (1 < argc)
			stream = open(argv[i], O_RDONLY);
		if (stream == -1)
			printf("%s: %s: %s\n", argv[0], argv[i], strerror(errno));
		else
		{
			if (!stream_stdout(stream))
				break ;
			if (1 < argc)
				close(stream);
		}
		i++;
	}
	return (0);
}
