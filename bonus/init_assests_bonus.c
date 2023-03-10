/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_assests_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:35:30 by ogorfti           #+#    #+#             */
/*   Updated: 2023/02/13 16:21:46 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	help_assests(t_map *map, int i, int j, int *nbrx)
{
	if (map->map[i][j] == '1')
		mlx_put_image_to_window(map->mlx,
			map->win, map->w.img, j * 50, i * 50);
	if (map->map[i][j] == 'P')
	{
		mlx_put_image_to_window(map->mlx,
			map->win, map->p.img, j * 50, i * 50);
		map->ppos_x = i;
		map->ppos_y = j;
	}
	if (map->map[i][j] == 'E')
	{
		mlx_put_image_to_window(map->mlx,
			map->win, map->e.img, j * 50, i * 50);
		map->epos_x = i;
		map->epos_y = j;
	}	
	if (map->map[i][j] == 'X')
	{
		mlx_put_image_to_window(map->mlx,
			map->win, map->x.img, j * 50, i * 50);
		(*nbrx)++;
	}
}

void	assests_norm(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	map->nbrx = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->columns)
		{
			help_assests(map, i, j, &map->nbrx);
			j++;
		}
		i++;
	}	
}

void	put_floor(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	map->cpex.c = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->columns)
		{
			if (map->map[i][j] == 'C')
				map->cpex.c++;
			mlx_put_image_to_window(map->mlx, map->win,
				map->b.img, j * 50, i * 50);
			j++;
		}
		i++;
	}
}

void	put_assests(t_map *map)
{
	map->mlx = mlx_init();
	map->w.img = mlx_xpm_file_to_image(map->mlx, "textures/w.xpm",
			&map->w.img_width, &map->w.img_height);
	map->p.img = mlx_xpm_file_to_image(map->mlx, "textures/p.xpm",
			&map->p.img_width, &map->p.img_height);
	map->b.img = mlx_xpm_file_to_image(map->mlx, "textures/b.xpm",
			&map->b.img_width, &map->b.img_height);
	map->e.img = mlx_xpm_file_to_image(map->mlx, "textures/e.xpm",
			&map->e.img_width, &map->e.img_height);
	map->x.img = mlx_xpm_file_to_image(map->mlx, "textures/x.xpm",
			&map->x.img_width, &map->x.img_height);
	map->win = mlx_new_window(map->mlx, map->columns * 50,
			map->rows * 50, "So Long");
	if (!map->w.img || !map->p.img || !map->b.img || !map->e.img || !map->x.img)
	{
		ft_printf ("Invalid XPM file!\n");
		free_map (map->map);
		exit(1);
	}
	put_floor(map);
	assests_norm(map);
}
