/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmack <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 15:24:03 by tmack             #+#    #+#             */
/*   Updated: 2016/06/06 06:54:17 by tmack            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_info_to_windows(t_win *win)
{
	put_black_screen(win);
}

void	put_black_screen(t_win *win)
{
	int i;
	int j;

	j = 0;
	while (j < 200)
	{
		i = 1680;
		while (i < WIN_W)
		{
			mlx_pixel_put(win->init, win->win, i, j, 0x000000);
			i++;
		}
		j++;
	}
}
