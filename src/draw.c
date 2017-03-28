/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 13:28:27 by ele-cren          #+#    #+#             */
/*   Updated: 2017/03/10 16:13:06 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	ft_draw(t_algo al, t_rgb rgb, t_mlx *ml)
{
	ml->img = mlx_new_image(ml->mlx, al.image_x, al.image_y);
	ml->data = (int *)mlx_get_data_addr(ml->img, &ml->bpp, \
	&ml->sizeline, &ml->endian);
	if (al.form == 1)
		ft_mandel(al, rgb, ml);
	if (al.form == 2)
		ft_julia(al, rgb, ml);
	if (al.form == 3)
		ft_burn(al, rgb, ml);
	mlx_put_image_to_window(ml->mlx, ml->win, ml->img, 0, 0);
	(al.hide == 0) ? ft_strings(ml) : "";
	mlx_destroy_image(ml->mlx, ml->img);
}

void	ft_color(t_algo al, t_mlx *ml, t_rgb rgb)
{
	int		it_maxb;
	int		i;

	i = 0;
	it_maxb = 50;
	if (al.i == al.it_max)
		ml->data[(int)al.x + (int)(al.y * al.image_x)] = \
								(al.form == 3) ? 0xFFFFFF : 0;
	else if (al.form == 3)
	{
		rgb.g = (al.i * 255 / al.it_max);
		rgb.b = (al.i * 255 / al.it_max);
		ml->data[(int)al.x + (int)(al.y * al.image_x)] = ft_rgb_to_dec(rgb);
	}
	else
	{
		al.i %= it_maxb;
		while ((al.i -= it_maxb / 7) > 0)
			i++;
		ml->data[(int)al.x + (int)(al.y * al.image_x)] = al.tab[i];
	}
}

void	ft_strings(t_mlx *ml)
{
	ft_put_string("Move Right = >", 0, 0, ml);
	ft_put_string("Move Left = <", 0, 1, ml);
	ft_put_string("Move Up = ^", 0, 2, ml);
	ft_put_string("Move Down = v", 0, 3, ml);
	ft_put_string("Psychiedelic = e", 0, 4, ml);
	ft_put_string("Stop move  = P", 0, 5, ml);
	ft_put_string("Iteration + = +", 0, 6, ml);
	ft_put_string("Iteration - = -", 0, 7, ml);
	ft_put_string("Hide commands = h", 0, 8, ml);
}

void	ft_put_string(char *s, int x, int y, t_mlx *ml)
{
	mlx_string_put(ml->mlx, ml->win, x, 18 * y, 0, s);
}
