/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 14:49:18 by akaplyar          #+#    #+#             */
/*   Updated: 2017/02/28 18:17:13 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				main(int ac, char **av)
{
	size_t		i;
	size_t		j;
	t_mlx		mlx;

	if (ac != 2)
	{
		write(1, "Usage: fdf <filename>\n", 22);
		return (1);
	}
	i = 0;
	mlx.crds = make_map(av[1], &mlx);
	mlx.zoom = 15;
	j = 0;
	while (i < mlx.height)
	{
		j = 0;
		while (j < mlx.width)
		{
			if (mlx.crds[i][j + 1].z3d < 10)
				printf("%d  ", mlx.crds[i][j].z3d);
			else
				printf("%d ", mlx.crds[i][j].z3d);
			j++;
		}
		printf("|%zu\n", i);
		i++;
	}
	write(1, "1done\n", 6);
	get_crds(&mlx);
	write(1, "2done\n", 6);
	mlx.mlx = mlx_init();
	write(1, "3done\n", 6);
	mlx.win = mlx_new_window(mlx.mlx, 1900, 1200, "FDF");
	write(1, "4done\n", 6);
	draw(&mlx);
	write(1, "5done\n", 6);
	mlx_mouse_hook(mlx.win, mouse_hook, &mlx);
	mlx_key_hook(mlx.win, key_hook, &mlx);
	mlx_loop(&mlx);
}
