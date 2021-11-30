/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcollazo <vcollazo@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:44:51 by vcollazo          #+#    #+#             */
/*   Updated: 2021/11/30 18:50:14 by vcollazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# Archivo de Carlos

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

/*int	main(void)
{
	int		fd;
	char	*print;
	
	fd = open("ElQuijote.txt", O_RDONLY);
	if (fd == -1)
		return (write(1, "NULL\n", 5));
	print = get_next_line(fd);
	
//	system("leaks a.out");:w
//
	printf("%s\n", print);
	printf("------------------------------------------------\n");
	print = get_next_line(fd);
	printf("%s\n", print);
	printf("------------------------------------------------\n");
	print = get_next_line(fd);
	printf("%s\n", print);
	printf("------------------------------------------------\n");
	print = get_next_line(fd);
	printf("%s\n", print);
	close(fd);
}
*/
int				main()
{
	int			fd;
	char		*str;
	int			i;
	i = 0;
//	char hola[5];
//	hola[0] = 'h';
//	hola[1] = 'o';
//	hola[2] = '3';
//	hola[3] = '4';
	//hola[4] = '\n';
	
//	printf("%s%d,", hola, check(hola));
	fd = open("ElQuijote.txt", O_RDONLY);
 //	printf("%s",get_next_line(fd));
//	get_next_line(fd);
//	str = malloc(2 * sizeof(char));
//	i = read(fd, str, 43);
//	printf("%d", i);
//	printf("%s", str); 
	while ((str = get_next_line(fd)) && i < 1)
	{
		printf("line %i=>%s", i + 1, str);
		free(str);
		i++;
	}
//	printf("%s\n", str);
//system("leaks a.out");
	return (0);
}
