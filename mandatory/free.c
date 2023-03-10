/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:17:15 by ogorfti           #+#    #+#             */
/*   Updated: 2023/02/10 16:44:10 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free (map[i]);
		i++;
	}
	free (map);
}

void	free_2d(t_map *map, int x)
{
	mlx_destroy_image(map->mlx, map->w.img);
	mlx_destroy_image(map->mlx, map->b.img);
	mlx_destroy_image(map->mlx, map->c.img);
	mlx_destroy_image(map->mlx, map->e.img);
	mlx_destroy_image(map->mlx, map->p.img);
	if (x == 0)
	{
		mlx_destroy_image(map->mlx, map->p_a.img);
		mlx_destroy_image(map->mlx, map->p_d.img);
		mlx_destroy_image(map->mlx, map->p_w.img);
	}
	mlx_destroy_window(map->mlx, map->win);
}
