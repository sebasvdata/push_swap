/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoben-ch <yoben-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 19:37:49 by yoben-ch          #+#    #+#             */
/*   Updated: 2026/06/12 00:46:17 by yoben-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	len_string(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

static void	ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	if (!src)
		return ;
	while (src[i] && src[i] != '\n')
	{
		dest[i] = src[i];
		i++;
	}
	if (src[i])
		dest[i++] = '\n';
	dest[i] = '\0';
}

static void	ft_shift(char *buffer)
{
	int	skip;
	int	i;

	i = 0;
	skip = len_string(buffer);
	if (buffer[skip])
		skip++;
	while (buffer[skip])
		buffer[i++] = buffer[skip++];
	while (i < 64)
		buffer[i++] = '\0';
}

static char	*ft_strjoin(char *line, char *buffer)
{
	char	*joined;
	int		ll;
	int		bl;

	bl = len_string(buffer);
	ll = len_string(line);
	if (buffer[bl])
		bl++;
	joined = malloc((bl + ll + 1) * sizeof(char));
	if (!joined)
		return (free(line), NULL);
	ft_strcpy(joined, line);
	ft_strcpy(joined + ll, buffer);
	if (line)
		free(line);
	return (joined);
}

char	*get_next_line(int fd)
{
	static char	buffer[64 + 1];
	char		*line;
	int			bytes;

	line = NULL;
	bytes = 1;
	if (!buffer[0])
		bytes = read(fd, buffer, 64);
	while (bytes > 0)
	{
		line = ft_strjoin(line, buffer);
		ft_shift(buffer);
		if (!line)
			return (NULL);
		if (line[len_string(line)])
			break ;
		bytes = read(fd, buffer, 64);
	}
	if (bytes <= -1)
		return (free(line), "erorr");
	return (line);
}
