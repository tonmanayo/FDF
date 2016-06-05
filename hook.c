/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmack <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 15:24:51 by tmack             #+#    #+#             */
/*   Updated: 2016/06/05 15:24:53 by tmack            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		expose_hook(t_win *win)
{
		calcule_coord(win);
		mlx_put_image_to_window(win->init, win->win, win->img, 0, 0);
	return (0);
}

int		key_hook(int keycode, t_win *win)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 124)
		rotate_left(win);
	if (keycode == 123)
		rotate_right(win);
	if (keycode == 126)
		zoom_in(win);
	if (keycode == 125)
		zoom_out(win);
	if (keycode == 13)
		increase_pike(win);
	if (keycode == 1)
		decrease_pike(win);
	ft_putstr(ft_itoa(keycode));
		ft_putchar('\n');
	return (0);
}
