/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 11:42:19 by ele-cren          #+#    #+#             */
/*   Updated: 2017/03/10 16:32:25 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <libft.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# define KEY_RIGHT 124
# define KEY_LEFT 123
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_ESC 53
# define KEY_PLUS 24
# define KEY_LESS 27
# define KEY_P 35
# define KEY_E 14
# define KEY_PRESS_EVENT 2
# define KEY_PRESS_MASK (1L<<0)
# define MOTION_NOTIFY_EVENT 6
# define MOTION_NOTIFY_MASK (1L<<6)
# define ABS(value) (value > 0 ? value : -value)

typedef struct		s_algo
{
	double			x;
	double			x1;
	double			x2;
	double			y;
	double			y1;
	double			y2;
	double			zoom;
	double			image_x;
	double			image_y;
	double			z_r;
	double			z_i;
	double			z_ri;
	double			z_ii;
	double			c_r;
	double			c_i;
	int				i;
	int				it_max;
	double			posx;
	double			posy;
	double			tmp;
	int				form;
	int				p;
	int				*tab;
	int				e;
	int				hide;
	int				r;
}					t_algo;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	int				*data;
	int				bpp;
	int				sizeline;
	int				endian;
}					t_mlx;

typedef struct		s_ev
{
	t_algo			al;
	t_mlx			ml;
	t_rgb			rgb;
}					t_ev;

typedef struct		s_args
{
	int				m;
	int				j;
}					t_args;

void				ft_ml(t_algo al, t_rgb rgb);
void				ft_mandel(t_algo al, t_rgb rgb, t_mlx *ml);
void				ft_color(t_algo al, t_mlx *ml, t_rgb rgb);
int					ft_move(int x, int y, t_ev *ev);
int					ft_key(int keycode, t_ev *ev);
int					ft_zoom(int button, int x, int y, t_ev *ev);
void				ft_init(t_algo *al, t_rgb *rgb);
void				ft_julia(t_algo al, t_rgb rgb, t_mlx *ml);
void				ft_check_args(char **av, t_algo *al);
void				ft_draw(t_algo al, t_rgb rgb, t_mlx *ml);
void				ft_burn(t_algo al, t_rgb rgb, t_mlx *ml);
void				ft_init_colors(t_algo *al);
int					ft_expose(t_ev *ev);
void				ft_key2(int keycode, t_ev *ev);
void				ft_strings(t_mlx *ml);
void				ft_put_string(char *s, int x, int y, t_mlx *ml);

#endif
