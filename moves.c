/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 14:38:46 by akaplyar          #+#    #+#             */
/*   Updated: 2017/02/27 15:45:37 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		move_left(t_mlx *mlx)
{
	mlx->move_x -= 10;
	expose_hook(mlx);
}

void		move_down(t_mlx *mlx)
{
	mlx->move_y -= 10;
	expose_hook(mlx);
}

void		move_right(t_mlx *mlx)
{
	mlx->move_x += 10;
	expose_hook(mlx);
}

void		move_up(t_mlx *mlx)
{
	mlx->move_y += 10;
	expose_hook(mlx);
}
