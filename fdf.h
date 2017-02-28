/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 16:42:44 by akaplyar          #+#    #+#             */
/*   Updated: 2017/02/28 18:17:13 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "./libft/libft.h"
# include <unistd.h>
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_cordinates
{
	int			x3d;
	int			y3d;
	int			z3d;
	int			x2d;
	int			y2d;
}				t_crds;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	size_t		height;
	size_t		width;
	int			max_z;
	int			zoom;
//	int			move_x;
//	int			move_y;
	t_crds		**crds;
}				t_mlx;

typedef struct s_bresenham
{
	int			delta_x;
	int			delta_y;
	int			sign_x;
	int			sign_y;
	int			delta_error;
}				t_bres;

t_crds			**make_map(char *str, t_mlx *mlx);
void			draw(t_mlx *mlx);
void			get_crds(t_mlx *mlx);
void			zoom_up(t_mlx *mlx);
void			zoom_down(t_mlx *mlx);
void			move_left(t_mlx *mlx);
void			move_down(t_mlx *mlx);
void			move_right(t_mlx *mlx);
void			move_up(t_mlx *mlx);
int				expose_hook(t_mlx *mlx);
int				key_hook(int keycode, void *mlx);
int				mouse_hook(int button, int x, int y, t_mlx *mlx);
#endif
