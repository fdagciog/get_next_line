/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagciog <fdagciog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:32:36 by fdagciog          #+#    #+#             */
/*   Updated: 2023/06/06 18:32:39 by fdagciog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *readline)
{
	int		i;
	char	*str;

	i = 0;
	if (!readline[i])
		return (NULL);
	while (readline[i] && readline[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (readline[i] && readline[i] != '\n')
	{
		str[i] = readline[i];
		i++;
	}
	if (readline[i] == '\n')
	{
		str[i] = readline[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_new_readline(char *line)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(line) -i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (line[i])
		str[j++] = line[i++];
	str[j] = '\0';
	free(line);
	return (str);
}

char	*ft_read_n(int fd, char *readline)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (0);
	rd_bytes = 1;
	while (!ft_strchr(readline, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		readline = ft_strjoin(readline, buff);
	}
	free(buff);
	return (readline);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*readline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	readline = ft_read_n(fd, readline);
	if (!readline)
		return (NULL);
	str = ft_get_line(readline);
	readline = ft_new_readline(readline);
	return (str);
}
