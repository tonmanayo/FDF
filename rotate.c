/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmack <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 15:28:23 by tmack             #+#    #+#             */
/*   Updated: 2016/06/05 15:28:26 by tmack            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_left(t_win *win)
{
	win->angle += 0.05;
	erase(win);
}

void	rotate_right(t_win *win)
{
	win->angle -= 0.05;
	erase(win);
}
