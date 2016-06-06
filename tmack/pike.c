/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/07 10:48:19 by juschaef          #+#    #+#             */
/*   Updated: 2016/06/05 13:19:08 by tmack            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		increase_pike(t_win *win)
{
	win->pad_h = (win->pad_h + 1.2 <= 0) ? win->pad_h : win->pad_h + 1.2;
	erase(win);
}

void		decrease_pike(t_win *win)
{
	win->pad_h = (win->pad_h - 1.2 <= 0) ? win->pad_h : win->pad_h - 1.2;
	erase(win);
}
