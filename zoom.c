/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 14:23:06 by akaplyar          #+#    #+#             */
/*   Updated: 2017/02/27 17:03:57 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		zoom_up(t_mlx *mlx)
{
	mlx->zoom++;
	expose_hook(mlx);
}

void		zoom_down(t_mlx *mlx)
{
	if (mlx->zoom > 0)
	{
		mlx->zoom--;
		expose_hook(mlx);
	}
}
