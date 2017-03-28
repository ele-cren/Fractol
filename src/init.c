/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 14:00:33 by ele-cren          #+#    #+#             */
/*   Updated: 2017/03/10 15:31:11 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	ft_init(t_algo *al, t_rgb *rgb)
{
	al->x1 = -2;
	al->x2 = 2;
	al->y1 = -2;
	al->y2 = 2;
	al->zoom = 150;
	al->image_x = (al->x2 - al->x1) * al->zoom;
	al->image_y = (al->y2 - al->y1) * al->zoom;
	al->it_max = 80;
	al->z_ri = 0;
	al->z_ii = 0;
	rgb->r = 0;
	rgb->g = 0;
	al->posx = 0;
	al->posy = 0;
	al->c_r = 0.3;
	al->c_i = 0.5;
	al->p = 1;
	al->e = 0;
	al->hide = 0;
	al->r = 0;
}

void	ft_init_colors(t_algo *al)
{
	if ((al->tab = (int *)malloc(sizeof(int) * 7)) == NULL)
		exit(1);
	al->tab[0] = 0x660099;
	al->tab[1] = 0x22427C;
	al->tab[2] = 0x26C4EC;
	al->tab[3] = 0x34C924;
	al->tab[4] = 0xF7FF3C;
	al->tab[5] = 0xED7F10;
	al->tab[6] = 0xFE1B00;
}

void	ft_check_args(char **av, t_algo *al)
{
	int		i;

	i = 0;
	while (av[++i])
	{
		if (ft_strcmp(av[i], "mandelbrot") == 0)
			al->form = 1;
		else if (ft_strcmp(av[i], "julia") == 0)
			al->form = 2;
		else if (ft_strcmp(av[i], "bship") == 0)
			al->form = 3;
		else
		{
			ft_putendl("Usage : ./fractol [mandelbrot][julia][bship]");
			exit(1);
		}
	}
}
