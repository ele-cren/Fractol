/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 15:23:10 by ele-cren          #+#    #+#             */
/*   Updated: 2017/03/09 15:24:37 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	ft_julia(t_algo al, t_rgb rgb, t_mlx *ml)
{
	al.x = -1;
	while (++al.x < al.image_x)
	{
		al.y = -1;
		while (++al.y < al.image_y)
		{
			al.z_r = al.x / al.zoom + al.x1;
			al.z_i = al.y / al.zoom + al.y1;
			al.tmp = al.z_r;
			al.i = 0;
			al.z_r = al.z_r * al.z_r - al.z_i * al.z_i + al.c_r;
			al.z_i = 2 * al.z_i * al.tmp + al.c_i;
			while (al.z_r * al.z_r + al.z_i * al.z_i < 4 && ++al.i < al.it_max)
			{
				al.tmp = al.z_r;
				al.z_r = al.z_r * al.z_r - al.z_i * al.z_i + al.c_r;
				al.z_i = 2 * al.z_i * al.tmp + al.c_i;
			}
			ft_color(al, ml, rgb);
		}
	}
}

void	ft_mandel(t_algo al, t_rgb rgb, t_mlx *ml)
{
	al.x = -1;
	while (++al.x < al.image_x)
	{
		al.y = -1;
		while (++al.y < al.image_y)
		{
			al.i = 0;
			al.z_r = al.z_ri * al.z_ri - al.z_ii * al.z_ii + \
			(al.x / al.zoom + al.x1);
			al.z_i = 2 * al.z_ii * al.z_ri + (al.y / al.zoom + al.y1);
			while (al.z_r * al.z_r + al.z_i * al.z_i < 4 && ++al.i < al.it_max)
			{
				al.tmp = al.z_r;
				al.z_r = al.z_r * al.z_r - al.z_i * al.z_i + \
				(al.x / al.zoom + al.x1);
				al.z_i = 2 * al.z_i * al.tmp + (al.y / al.zoom + al.y1);
			}
			ft_color(al, ml, rgb);
		}
	}
}

void	ft_burn(t_algo al, t_rgb rgb, t_mlx *ml)
{
	al.x = -1;
	while (++al.x < al.image_x)
	{
		al.y = -1;
		while (++al.y < al.image_y)
		{
			al.i = 0;
			al.z_r = al.z_ri * al.z_ri - al.z_ii * al.z_ii + \
			(al.x / al.zoom + al.x1);
			al.z_i = 2 * ABS(al.z_ri * al.z_ii) + (al.y / al.zoom + al.y1);
			while (al.z_r * al.z_r + al.z_i * al.z_i < 4 && ++al.i < al.it_max)
			{
				al.tmp = al.z_r;
				al.z_r = al.z_r * al.z_r - al.z_i * al.z_i + \
				(al.x / al.zoom + al.x1);
				al.z_i = 2 * ABS(al.z_i * al.tmp) + (al.y / al.zoom + al.y1);
			}
			ft_color(al, ml, rgb);
		}
	}
}
