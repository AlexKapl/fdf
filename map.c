/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 13:48:58 by akaplyar          #+#    #+#             */
/*   Updated: 2017/02/28 15:46:40 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_crds		*map_in_list(t_mlx *mlx, char *buff, size_t i)
{
	char			**tab;
	size_t			x;
	t_crds			*crds;

	if (!(tab = ft_strsplit(buff, ' ')))
		exit(1);
	if (!(crds = (t_crds*)malloc(sizeof(t_crds) * mlx->width)))
		exit(1);
	x = 0;
	while (x < mlx->width)
	{
		crds[x].x3d = x;
		crds[x].y3d = i;
		crds[x].z3d = ft_atoi(tab[x]);
		if (mlx->max_z < crds[x].z3d)
			mlx->max_z = crds[x].z3d;
		x++;
	}
	ft_memdel((void**)tab);
	return (crds);
}

static void			get_size(int fd, t_mlx *mlx)
{
	int				ret;
	char			*buff;
	char			**tab;
	size_t			height;
	size_t			width;

	if (get_next_line(fd, &buff) < 0 || !(tab = ft_strsplit(buff, ' ')))
		exit(1);
	height = 1;
	width = 0;
	while (tab[width])
		width++;
	free(buff);
	ft_memdel((void**)tab);
	while ((ret = get_next_line(fd, &buff)) != 0)
	{
		if (ret < 0)
			exit(1);
		free(buff);
		height++;
	}
	mlx->height = height;
	mlx->width = width;
	mlx->max_z = 0;
}

t_crds				**make_map(char *str, t_mlx *mlx)
{
	int				fd;
	int				ret;
	char			*buff;
	size_t			i;
	t_crds			**crds;

	i = 0;
	if ((fd = open(str, O_RDONLY)) < 0)
		exit(1);
	get_size(fd, mlx);
	close(fd);
	fd = open(str, O_RDONLY);
	if (!(crds = (t_crds**)malloc(sizeof(t_crds*) * mlx->height)))
		exit(1);
	while ((ret = get_next_line(fd, &buff)) != 0)
	{
		crds[i] = map_in_list(mlx, buff, i);
		free(buff);
		i++;
	}
	close(fd);
	return (crds);
}
