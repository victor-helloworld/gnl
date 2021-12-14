/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainGnl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 11:53:01 by potero-d          #+#    #+#             */
/*   Updated: 2021/11/25 13:50:14 by josgarci         ###   ########.fr       */
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
	printf("hola\n");
	while (chr != EOF)
	{
		if (chr == '\n')
			nbr_lines++;
		chr = getc(fp);
	}
	fclose(fp);
	printf("There are %d lines in %s  in a file\n", nbr_lines, FILEPATH);
	return 0;
}


int	main(void) //int argc, char **argv)
{
	int	fd;
	char	*line;
	int	i;

	i = 0;
	ft_nbrlines();
	fd = open(FILEPATH, O_RDONLY);
	while ((line = get_next_line(fd)) && i < 1)
	{
		printf("line %i=>%s", i + 1, line);
		free(line);
		i++;
	}
	//line = get_next_line(fd);
	//printf("%s",line);
	//free (line);
	close (fd);
	return (0);
}
