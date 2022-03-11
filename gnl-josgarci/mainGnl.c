/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainGnl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 11:53:01 by potero-d          #+#    #+#             */
/*   Updated: 2022/02/24 14:21:13 by vcollazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"get_next_line.h"
#include <fcntl.h>

int	ft_nbrlines(void)
{   
	int nbr_lines;
	char chr;
	FILE *fp;

	nbr_lines = 0;
	fp = fopen(FILEPATH, "r");

	chr = getc(fp);
	while (chr != EOF)
	{
		if (chr == '\n')
			nbr_lines++;
		chr = getc(fp);
	}
	fclose(fp);
	printf("There are %d lines in %s\n", nbr_lines, FILEPATH);
	return (0);
}


int	main(void) //int argc, char **argv)
{
	int	fd;
	char	*line;
	int	i;

	i = 0;
	ft_nbrlines();
	fd = open(FILEPATH, O_RDONLY);
	while ((line = get_next_line(fd)) && i < 10)
	{
		printf("\033[0;36m");
		printf("line %i ===> ", i + 1);
		printf("\033[0m");
		printf("%s", line);
		free(line);
		i++;
	}
	close (fd);
	return (0);
}
