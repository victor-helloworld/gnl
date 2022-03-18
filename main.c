/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcollazo  marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 11:53:01 by vcollazo          #+#    #+#             */
/*   Updated: 2022/03/17 21:27:30 by vcollazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <fcntl.h>

int	ft_nbrlines(void)
{   
	int nbr_lines;
	char chr;
	FILE *fp;

	nbr_lines = 0;
	fp = fopen("lotr.txt", "r");

	chr = getc(fp);
	printf("hola\n");
	while (chr != EOF)
	{
		if (chr == '\n')
			nbr_lines++;
		chr = getc(fp);
	}
	fclose(fp);
	return (0);
}


int	main(void) //int argc, char **argv)
{
	int	fd;
	char	*line;
	int	i;

	i = 0;
	ft_nbrlines();
	fd = open("lotr.txt", O_RDONLY);
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
