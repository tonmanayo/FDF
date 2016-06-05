/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmack <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 15:28:41 by tmack             #+#    #+#             */
/*   Updated: 2016/06/05 15:36:23 by tmack            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		len_tab(char *argv)
{
	int		fd;
	char	*buff;
	int		ret;
	int		size;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("FDF error");
		exit(1);
	}
	buff = (char *)ft_strnew(200);
	size = 0;
	while ((ret = read(fd, buff, 200)) > 0)
	{
		if (ret == -1)
		{
			ft_putstr("FDF error");
			exit(1);
		}
		size += ret;
	}
	close(fd);
	free(buff);
	return (size);
}

int		count_map_length(char **str)
{
	int		count;

	count = 0;
	while (str[count] != NULL)
		count++;
	return (count);
}

void	erase(t_win *win)
{
	ft_bzero(win->data, WIN_H * WIN_W * 4);
	if (win->draw_type == DRAW)
		mlx_clear_window(win->init, win->win);
	expose_hook(win);
}
