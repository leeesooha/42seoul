/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:35:41 by soohlee           #+#    #+#             */
/*   Updated: 2023/04/17 23:39:07 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

int	map_print(t_map_data *map_db, t_mlx_data *mlx_db)
{
	int	x;
	int	y;

	if (!new_mlx(map_db, mlx_db))
		ft_end (mlx_db, map_db->row_len, 1);
	if (!creat_filehash(mlx_db))
		ft_end (mlx_db, map_db->row_len, 1);
	y = -1;
	while (mlx_db->map[++y])
	{
		x = -1;
		while (mlx_db->map[y][++x] && mlx_db->map[y][x] != '\n')
		{
			mlx_db->img = mlx_xpm_file_to_image(mlx_db->mlx,
					mlx_db->file[(int)mlx_db->map[y][x]],
					&(mlx_db->width), &(mlx_db->height));
			mlx_db->addr = mlx_get_data_addr(mlx_db->img, &(mlx_db->bpp),
					&(mlx_db->line_len), &(mlx_db->endian));
			mlx_put_image_to_window(mlx_db->mlx, mlx_db->win,
				mlx_db->img, x * mlx_db->width, y * mlx_db->height);
		}
	}
	return (1);
}

int	new_mlx(t_map_data *map_db, t_mlx_data *mlx_db)
{
	mlx_db->mlx = mlx_init();
	if (!mlx_db->mlx)
		ft_end (mlx_db, map_db->row_len, 1);
	mlx_db->win = mlx_new_window(mlx_db->mlx, map_db->col_len * 64,
			map_db->row_len * 64, "SOOHA GAME");
	if (!mlx_db->win)
		ft_end (mlx_db, map_db->row_len, 1);
	mlx_db->xy[0] = map_db->start_xy[0];
	mlx_db->xy[1] = map_db->start_xy[1];
	mlx_db->width = 64;
	mlx_db->height = 64;
	return (1);
}
