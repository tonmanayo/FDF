/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmack <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 15:24:33 by tmack             #+#    #+#             */
/*   Updated: 2016/06/05 15:24:38 by tmack            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include "libft/includes/libft.h"
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

# define WIN_H 1200
# define WIN_W 1900

# define BLUE 0x0041FF
# define BROWN 0xAD4F09
# define GREEN 0x25FF50
# define WHITE 0xFFFFFF
# define OPTION int
# define ISO 1
# define PUT 0
# define DRAW 1
# define BET_X 0
# define BET_Y 1
# define BET_Z 2

typedef struct	s_point
{
	int			d3x;
	int			d3y;
	int			d3z;
	int			d2x;
	int			d2y;
	int			colour;
}				t_point;

typedef struct	s_win
{
	void		*init;
	void		*win;
	char		*data;
	void		*img;
	int			size;
	int			end;
	int			color;
	t_point		**map;
	char		*path;
	int			map_w;
	int			map_h;
	int			max_z;
	float		angle;
	int			pad;
	int			pad_h;
	OPTION		opt;
	int			draw_type;
}				t_win;

typedef struct	s_bresenham
{
	int			dx;
	int			sx;
	int			dy;
	int			sy;
	int			dline;
}				t_bres;

typedef struct	s_rotate_point
{
	float		act_px;
	float		act_py;
	float		act_pz;
	float		px;
	float		py;
	float		pz;
}			t_rp;

int				count_map_length(char **str);
int				len_tab(char *argv);
t_point			*create_int_table(t_win *win, char *str, int pos);
t_point			**create_map(t_win *win);
t_point			ft_create_point(char *str, int x, int y);
void			ft_import_map(t_win *win);
int				key_hook(int keycode, t_win *win);
int				expose_hook(t_win *win);
void			calcule_coord(t_win *win);
void			calculate(t_win *win, t_point *point);
int				choose_color(int p1, int p2, int max);
void			draw_map(t_win *win);
void			draw_line(t_win *win, t_point *point1, t_point *point2);
t_bres			*bres_construct(t_point *point1, t_point *point2, int max);
void			draw_point(t_win *win, int x, int y, int color);
void			zoom_in(t_win *win);
void			zoom_out(t_win *win);
void			move_image_up(t_win *win);
void			move_image_down(t_win *win);
void			move_image_left(t_win *win);
void			move_image_right(t_win *win);
void			iso_projection(t_win *win);
void			draw_method(t_win *win);
void			put_method(t_win *win);
void			erase(t_win *win);
void			increase_pike(t_win *win);
void			decrease_pike(t_win *win);
void			rotate_left(t_win *win);
void			rotate_right(t_win *win);
void			calcule_rotation(t_win *win, t_point *point);
void			pivote_z(t_win *win);
void			pivote_y(t_win *win);
void			pivote_x(t_win *win);
void			put_meta(t_win *win);
void			put_black_screen(t_win *win);

#endif
