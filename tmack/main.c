/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmack <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 15:25:13 by tmack             #+#    #+#             */
/*   Updated: 2016/06/06 06:57:40 by tmack            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_win	win;

	win.path = argv[1];
	if (argc > 1 && argc < 3)
	{
		ft_import_map(&win);
	}
	else
		ft_putstr("Inser map here !");
	return (0);
}
