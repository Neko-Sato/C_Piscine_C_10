/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:56:39 by hshimizu          #+#    #+#             */
/*   Updated: 2023/03/23 20:20:34 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#define BUF_SIZE 1024

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

int	display_file(char file_path[])
{
	int		file;
	int		size;
	char	buf[BUF_SIZE];

	file = open(file_path, O_RDONLY);
	if (file == -1)
		return (-1);
	while (1)
	{
		size = read(file, buf, BUF_SIZE * sizeof(char));
		write(STDOUT_FILENO, buf, size);
		if (size < BUF_SIZE)
			break ;
	}
	close(file);
	return (0);
}

int	main(int argc, char *argv[])
{
	if (argc < 2)
		write(STDERR_FILENO, "File name missing.\n", 19);
	else if (2 < argc)
		write(STDERR_FILENO, "Too many arguments.\n", 20);
	else if (display_file(argv[1]))
		write(STDERR_FILENO, "Cannot read file.\n", 18);
	return (1);
}
