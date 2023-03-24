/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:51:55 by hshimizu          #+#    #+#             */
/*   Updated: 2023/03/24 11:39:24 by hshimizu         ###   ########.fr       */
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

void	print_error(char *a, char *b, char *c)
{
 //  argv[0], argv[i], strerror(errno)
	printf("%s: %s: %s\n", a, b, c);
}

void	cat(int size, char *files_path[])
{
}

void	cat_no_args(void)
{
	while (1)
		if (!stream_stdout(STDIN_FILENO))
			break ;
}

int	main(int argc, char *argv[])
{
cat_no_args();
	// int		stream;
	// char	**_argv;

	// _argv = argv;
	// while (1)
	// 	stream = STDIN_FILENO;
	// {
	// 	if (1 < argc)
	// 		stream = open(argv[i], O_RDONLY);
	// 	if (stream == -1)
	// 		else
	// 		{
	// 			stream_stdout(stream);
	// 			close(stream);
	// 		}
	// 	if (1 < argc)
	// 		i++;
	// }
	return (0);
}
