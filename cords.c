/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cords.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 13:01:46 by akaplyar          #+#    #+#             */
/*   Updated: 2017/02/28 18:17:13 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	calculate(t_mlx *mlx, t_crds *crds)
{
	float	x;
	float	y;
	float	z;

	x = crds->x3d * mlx->zoom - sqrt(pow(mlx->width, 2) + pow(mlx->height, 2));
	y = crds->y3d * mlx->zoom - sqrt(pow(mlx->width, 2) + pow(mlx->height, 2));
	z = crds->z3d;
	crds->x2d = x - y + 950;
	crds->y2d = (x + y) / 2 - z + 400;
}

void		get_crds(t_mlx *mlx)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < mlx->height)
	{
		j = 0;
		while (j < mlx->width)
		{
			calculate(mlx, &mlx->crds[i][j]);
			j++;
		}
		i++;
	}
}
