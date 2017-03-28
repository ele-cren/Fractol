/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 11:33:50 by ele-cren          #+#    #+#             */
/*   Updated: 2017/03/10 16:31:53 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		main(int ac, char **av)
{
	t_algo	al;
	t_rgb	rgb;

	if (ac != 2)
	{
		ft_putendl("Usage : ./fractol [mandelbrot][julia][bship]");
		exit(1);
	}
	ft_init(&al, &rgb);
	ft_init_colors(&al);
	ft_check_args(av, &al);
	ft_ml(al, rgb);
	return (0);
}

void	ft_ml(t_algo al, t_rgb rgb)
{
	t_mlx	ml;
	t_ev	ev;

	ml.mlx = mlx_init();
	ml.win = mlx_new_window(ml.mlx, al.image_x, al.image_y, "Fractol");
	ft_draw(al, rgb, &ml);
	ev.al = al;
	ev.ml = ml;
	ev.rgb = rgb;
	mlx_expose_hook(ml.win, ft_expose, &ev);
	mlx_mouse_hook(ml.win, ft_zoom, &ev);
	mlx_hook(ml.win, MOTION_NOTIFY_EVENT, MOTION_NOTIFY_MASK, ft_move, &ev);
	mlx_hook(ml.win, KEY_PRESS_EVENT, KEY_PRESS_MASK, ft_key, &ev);
	mlx_loop(ml.mlx);
}
