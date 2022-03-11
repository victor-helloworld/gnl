/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcollazo <vcollazo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:24:39 by vcollazo          #+#    #+#             */
/*   Updated: 2022/03/03 01:54:38 by vcollazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int	ft_isin(char *str, int	c);
int	ft_strlen(char *str);
char	*ft_substr(char *s, int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char*	ft_readtext(int fd, char* rest);
char    *get_next_line(int fd);

int	main(void)
{	int	fd;
	char	*line;
	int	i;

	i = 0;
	fd = 1;
	char str[] = "Hello World";
	printf("str: %s\n", str);
	printf("str_len: %i\n", ft_strlen(str));
	printf("o is in str: %i\n", ft_isin(str, 111));
	fd = open(FILEPATH, O_RDONLY);
	printf("holaholahola");
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

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;
	int		index;
	size_t		len;

	printf("holaholahola");
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	index = ft_isin(rest, '\n');
	len = ft_strlen(rest);
	if (ft_isin(rest, '\n')) {
		line = ft_substr(rest, 0, index);
		rest = ft_substr(rest, index + 1, len - index);
		index = 0;
//		free(rest);
	}
	else
		rest = ft_readtext(fd, rest);
	return (rest);
}

char*	ft_readtext(int fd, char* rest)
{
	size_t	buflength;
	char*	buffer;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
//	buflength = read(int fd, void *buf, size_t cnt);
	buflength = read(fd, buffer, BUFFER_SIZE);
	printf("%s \n", buffer);
	sleep(5);
	rest = ft_strjoin(rest, buffer);
	return (rest);
}


int	ft_strlen(char *str)
{
	int len;
	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

int	ft_isin(char *str, int c)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		printf("str[i] = %c, c = %c\n", str[i], (unsigned char)c);
		if (str[i] == c)
			return (i);
	}
	return (0);
}

char	*ft_substr(char *s, int start, size_t len)
{
	int		i;
	char	*substr;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < (int)(len))
		len = ft_strlen(s) - start;
	substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (len--)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	int		len_s1;
	int		len_s2;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!s1 || !s2)
		return (NULL);
	len_s1 = (int)(ft_strlen(s1));
	len_s2 = (int)(ft_strlen(s2));
	ptr = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (++i < len_s1)
		ptr[i] = s1[i];
	while (++j + i < len_s1 + len_s2)
		ptr[j + i] = s2[j];
	ptr[i + j] = '\0';
	return (ptr);
}


