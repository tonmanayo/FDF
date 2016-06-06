/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 17:33:43 by juschaef          #+#    #+#             */
/*   Updated: 2016/06/06 07:00:17 by tmack            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			count_map_height(t_point **grid)
{
	int	count;

	count = 0;
	while (grid[count] != NULL)
		count++;
	return (count);
}

t_point		**create_map(t_win *win)
{
	t_point	**grid;
	int		i;
	int		fd;
	char	*temp;

	i = 0;
	win->map_w = 0;
	grid = (t_point **)malloc(sizeof(t_point *) * len_tab(win->path));
	fd = open(win->path, O_RDONLY);
	while (ft_get_next_line(fd, &temp) == 1)
	{
		grid[i] = create_int_table(win, temp, i);
		i++;
	}
	grid[i] = create_int_table(win, temp, i);
	close(fd);
	win->map_h = count_map_height(grid);
	return (grid);
}

t_point		ft_create_point(char *str, int x, int y)
{
	t_point point;

	point.d3x = x;
	point.d3y = y;
	point.d3z = ft_atoi(str);
	return (point);
}

t_point		*create_int_table(t_win *win, char *str, int pos)
{
	t_point	*list;
	char	**str_lst;
	int		i;
	int		size;

	i = 0;
	str_lst = ft_strsplit(str, ' ');
	size = count_map_length(str_lst);
	win->map_w = (size > win->map_w) ? size : win->map_w;
	list = (t_point *)malloc(sizeof(t_point) * (win->map_w + 1));
	while (str_lst[i] != NULL)
	{
		win->max_z = ((ft_atoi(str_lst[i])) > win->max_z) ? ft_atoi(str_lst[i])
			: win->max_z;
		list[i] = ft_create_point(str_lst[i], i, pos);
		i++;
	}
	while (i < win->map_w)
	{
		list[i] = ft_create_point("0", i, pos);
		i++;
	}
	return (list);
}
