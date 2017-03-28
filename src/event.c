/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 14:37:14 by ele-cren          #+#    #+#             */
/*   Updated: 2017/03/10 16:31:40 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		ft_move(int x, int y, t_ev *ev)
{
	if (ev->al.p == 1)
	{
		if (x >= 0 && x <= ev->al.image_x && y >= 0 && y <= ev->al.image_y)
		{
			if (ev->al.form == 1)
			{
				ev->al.z_ri = ev->al.posx + ((x - ev->al.image_x / 2) / \
						ev->al.zoom);
				ev->al.z_ii = ev->al.posy + ((y - ev->al.image_y / 2) / \
						ev->al.zoom);
				ft_draw(ev->al, ev->rgb, &ev->ml);
			}
			if (ev->al.form == 2)
			{
				ev->al.c_r = ev->al.posx + ((x - ev->al.image_x / 2) / \
						ev->al.zoom);
				ev->al.c_i = ev->al.posy + ((y - ev->al.image_y / 2) / \
						ev->al.zoom);
				ft_draw(ev->al, ev->rgb, &ev->ml);
			}
		}
	}
	return (1);
}

int		ft_key(int keycode, t_ev *ev)
{
	int		tmp;
	int		i;

	i = -1;
	ft_key2(keycode, ev);
	if (keycode == KEY_PLUS || keycode == KEY_LESS)
	{
		ev->al.it_max += (keycode == KEY_PLUS) ? 10 : -10;
	}
	if (keycode == KEY_E)
	{
		while (++i < 6)
		{
			tmp = ev->al.tab[i];
			ev->al.tab[i] = ev->al.tab[i + 1];
			ev->al.tab[i + 1] = tmp;
		}
	}
	if (keycode == 4)
		ev->al.hide = (ev->al.hide == 0) ? 1 : 0;
	ft_draw(ev->al, ev->rgb, &ev->ml);
	return (1);
}

void	ft_key2(int keycode, t_ev *ev)
{
	if (keycode == KEY_ESC)
	{
		free(ev->al.tab);
		exit(0);
	}
	if (keycode == KEY_P)
		ev->al.p = (ev->al.p == 1) ? 0 : 1;
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
	{
		ev->al.x1 += (keycode == KEY_LEFT) ? 10 / ev->al.zoom : -10 / \
		ev->al.zoom;
		ev->al.posx += (keycode == KEY_LEFT) ? 10 / ev->al.zoom : -10 / \
		ev->al.zoom;
	}
	if (keycode == KEY_UP || keycode == KEY_DOWN)
	{
		ev->al.y1 += (keycode == KEY_UP) ? 10 / ev->al.zoom : -10 / ev->al.zoom;
		ev->al.posy += (keycode == KEY_UP) ? 10 / ev->al.zoom : -10 / \
		ev->al.zoom;
	}
	if (keycode == 15)
	{
		ft_init(&ev->al, &ev->rgb);
		ev->al.r = 1;
	}
}

int		ft_zoom(int button, int x, int y, t_ev *ev)
{
	static long double t = 1;

	t = (ev->al.r == 1) ? 1 : t;
	ev->al.r = 0;
	if (x >= 0 && x <= ev->al.image_x && y >= 0 && y <= ev->al.image_y)
	{
		if (button == 1 || button == 2 || button == 4 || button == 5)
		{
			t = (button == 1 || button == 4) ? t * 2 : t / 2;
			ev->al.zoom *= (button == 1 || button == 4) ? 2 : 1;
			ev->al.posx += (button == 1 || button == 4) ? (x - ev->al.image_x /\
			2) / ev->al.zoom : -((x - ev->al.image_x / 2) / ev->al.zoom);
			ev->al.posy += (button == 1 || button == 4) ? (y - ev->al.image_y /\
			2) / ev->al.zoom : -((y - ev->al.image_y / 2) / ev->al.zoom);
			ev->al.x1 = ev->al.posx - (2 / t);
			ev->al.y1 = ev->al.posy - (2 / t);
			ev->al.zoom /= (button == 2 || button == 5) ? 2 : 1;
		}
		ft_draw(ev->al, ev->rgb, &ev->ml);
	}
	return (1);
}

int		ft_expose(t_ev *ev)
{
	ft_draw(ev->al, ev->rgb, &ev->ml);
	return (1);
}
