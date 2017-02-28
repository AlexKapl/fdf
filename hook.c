/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 14:16:53 by akaplyar          #+#    #+#             */
/*   Updated: 2017/02/28 14:58:30 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_hook(int keycode, void *mlx)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 78)
		zoom_down(mlx);
	if (keycode == 69)
		zoom_up(mlx);
/*	if (keycode == 123)
		move_left(mlx);
	if (keycode == 124)
		move_down(mlx);
	if (keycode == 125)
		move_right(mlx);
	if (keycode == 126)
		move_up(mlx);*/
	return (0);
}

int		expose_hook(t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx, mlx->win);
	get_crds(mlx);
	draw(mlx);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_mlx *mlx)
{
	(void)mlx;
	x = y;
	if (button == 4)
		zoom_up(mlx);
	if (button == 5)
		zoom_down(mlx);
	printf("button: %d\n", button);
	return (0);
}
