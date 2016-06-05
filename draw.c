/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmack <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 15:24:17 by tmack             #+#    #+#             */
/*   Updated: 2016/06/05 15:38:05 by tmack            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_map(t_win *win)
{
	int i;
	int j;

	j = 0;
	while (j < win->map_h)
	{
		i = 0;
		while (i < win->map_w)
		{
			if (i < win->map_w - 1)
				draw_line(win, &(win->map[j][i]), &(win->map[j][i + 1]));
			if (j < win->map_h - 1)
				draw_line(win, &(win->map[j][i]), &(win->map[j + 1][i]));
			i++;
		}
		j++;
	}
}

void		draw_line(t_win *win, t_point *p1, t_point *p2)
{
	int		x;
	int		y;
	int		temp;
	t_bres	*bres;

	bres = bres_construct(p1, p2, (win->max_z));
	x = p1->d2x;
	y = p1->d2y;
	while (1)
	{
		draw_point(win, x, y, p1->colour);
		if (x == p2->d2x && y == p2->d2y)
			break ;
		if ((temp = bres->dline) > -(bres->dx))
		{
			bres->dline -= bres->dy;
			x += bres->sx;
		}
		if (temp < bres->dy)
		{
			bres->dline += bres->dx;
			y += bres->sy;
		}
	}
}

void		draw_point(t_win *win, int x, int y, int colour)
{
	if (win->draw_type == PUT)
		ft_memcpy(&win->data[(x * 4) + (y * win->size)], &(colour),
			(size_t)(sizeof(int)));
	if (win->draw_type == DRAW)
	{
		mlx_pixel_put(win->init, win->win, x, y, colour);
	}
}

int			choose_colour(int p1, int p2, int max)
{
	if (((p1 + p2) / 2) > (max * 0.8))
		return (WHITE);
	else if (((p1 + p2) / 2) == 0)
		return (GREEN);
	else if (((p1 + p2) / 2) < 0)
		return (BLUE);
	else
		return (BROWN);
}
/*
** bresenhams line drawing function calc
*/
t_bres		*bres_construct(t_point *p1, t_point *p2, int max)
{
	t_bres *bres;

	bres = (t_bres *)malloc(sizeof(t_bres));
	bres->dx = abs(p2->d2x - p1->d2x);
	bres->sx = p1->d2x < p2->d2x ? 1 : -1;
	bres->dy = abs(p2->d2y - p1->d2y);
	bres->sy = p1->d2y < p2->d2y ? 1 : -1;
	bres->dline = (bres->dx > bres->dy ? bres->dx : -(bres->dy)) / 2;
	p1->colour = choose_colour(p1->d3z, p2->d3z, max);
	return (bres);
}
