/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   get2.c											 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: bolmos-o <bolmos-o@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/11/20 22:16:03 by bolmos-o		  #+#	#+#			 */
/*   Updated: 2020/11/28 17:15:16 by bolmos-o		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

static int copy(char **line, char **buf)
{
	char	*tmp;

	tmp = 0;
	if (!(*line))
		*line =ft_strdup(*buf);
	else
	{
		tmp	= ft_strjoin(*line, *buf);
		free(*line);
		*line = tmp;
	}
	return (0);
}

static	int	search(char **line, char **buf)
{
	int	pos;
	char	*tmp;

	if (!*buf)
		return (0);
	if (ft_strchr(*buf, '\n'))
	{
		pos = ft_strchr(*buf, '\n') - *buf;
		tmp = ft_substr(*buf, 0, pos);
		copy(line, &tmp);
		free(tmp);
		ft_memmove(*buf, (*buf + pos + 1), ft_strlen((*buf + pos)));
		return (1);
	}
	return (copy(line, buf));
}	

int get_next_line(int fd, char **line)
{
	static char	*buf;
	int			ret;

	if (BUFFER_SIZE <= 0 || !line || fd < 0)
		return (-1);	
	*line = NULL;
	if (search(line, &buf) == 1)
		return (1);
	if (!buf && !(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
			return (-1);
	while ((ret = read(fd, buf, BUFFER_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		if (search(line, &buf) == 1)
			return (1);
	}
	return (0);
}
