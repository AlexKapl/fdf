/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 16:29:50 by akaplyar          #+#    #+#             */
/*   Updated: 2017/02/27 17:03:40 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_bres	*make_bresenham(t_crds *p1, t_crds *p2)
{
	t_bres		*bres;

	if (!(bres = (t_bres*)malloc(sizeof(t_bres))))
		exit(1);
	bres->delta_x = abs(p2->x2d - p1->x2d);
	bres->delta_y = abs(p2->y2d - p1->y2d);
	bres->sign_x = p2->x2d > p1->x2d ? 1 : -1;
	bres->sign_y = p2->y2d > p1->y2d ? 1 : -1;
	bres->delta_error = (bres->delta_x > bres->delta_y ? bres->delta_x :
		-bres->delta_y) / 2;
	return (bres);
}

static void		draw_point(t_mlx *mlx, int x, int y)
{
//	x += mlx->move_x;
//	y += mlx->move_y;
	if (x < 1900 && x > 0 && y < 1200 && y > 0)
		mlx_pixel_put(mlx->mlx, mlx->win, x, y, 0xFFFFFF);
}

static void		draw_line(t_mlx *mlx, t_crds *p1, t_crds *p2)
{
	int			x;
	int			y;
	int			error;
	t_bres		*bres;
	
	bres = make_bresenham(p1, p2);
	x = p1->x2d;
	y = p1->y2d;
	while (x != p2->x2d && y != p2->y2d)
	{
		draw_point(mlx, x, y);
		error = bres->delta_error;
		if (error > -bres->delta_x)
		{
			bres->delta_error -= bres->delta_y;
			x += bres->sign_x;
		}
		if (error < bres->delta_y)
		{
			bres->delta_error += bres->delta_x;
			y += bres->sign_y;
		}
	}
}

void			draw(t_mlx *mlx)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (i < mlx->height)
	{
		j = 0;
		while (j < mlx->width)
		{
			if (i + 1 < mlx->height)
				draw_line(mlx, &mlx->crds[i][j], &mlx->crds[i + 1][j]);
			if (j + 1 < mlx->width)
				draw_line(mlx, &mlx->crds[i][j], &mlx->crds[i][j + 1]);
			j++;
		}
		i++;
	}
}
