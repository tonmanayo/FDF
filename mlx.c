/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmack <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 15:25:36 by tmack             #+#    #+#             */
/*   Updated: 2016/06/05 15:25:38 by tmack            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_import_map(t_win *win)
{
	win->init = mlx_init();
	win->win = mlx_new_window(win->init, WIN_W, WIN_H, "FdF");
	win->pad = 1;
	win->pad_h = 1;
	win->angle = 0;
	win->img = mlx_new_image(win->init, WIN_W, WIN_H);
	win->data = mlx_get_data_addr(win->img, &(win->color), &(win->size),
		&(win->end));
	win->map = create_map(win);
	mlx_key_hook(win->win, key_hook, win);
	mlx_expose_hook(win->win, expose_hook, win);
	mlx_loop(win->init);
}
