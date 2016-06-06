/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmack <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 15:23:43 by tmack             #+#    #+#             */
/*   Updated: 2016/06/06 06:53:27 by tmack            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		calcule_coord(t_win *win)
{
	int	i;
	int	j;

	j = 0;
	while (j < win->map_h)
	{
		i = 0;
		while (i < win->map_w)
		{
			calculate(win, &(win->map[j][i]));
			i++;
		}
		j++;
	}
	draw_map(win);
}

/*
** isometric calculations
*/

void		rotate_w(t_win *win, t_rp *rp)
{
	rp->px = rp->act_px * cos(win->angle) - rp->act_py * sin(win->angle);
	rp->py = rp->act_px * sin(win->angle) + rp->act_py * cos(win->angle);
	rp->pz = rp->act_pz;
}

void		calculate(t_win *win, t_point *pt)
{
	t_rp	*rp;

	rp = (t_rp *)malloc(sizeof(t_rp));
	rp->act_px = pt->d3x * win->pad - (sqrt((win->map_h) ^ 2
				+ (win->map_w) ^ 2));
	rp->act_py = pt->d3y * win->pad - (sqrt((win->map_h) ^ 2
				+ (win->map_w) ^ 2));
	rp->act_pz = pt->d3z * win->pad_h;
	rotate_w(win, rp);
	pt->d2x = rp->px - rp->py + WIN_W * 0.5;
	pt->d2y = -rp->pz + rp->px * 0.5 + rp->py * 0.5 + WIN_H * 0.3;
}
