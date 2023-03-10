/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:46:53 by ogorfti           #+#    #+#             */
/*   Updated: 2023/02/13 16:26:33 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../get_next_line/get_next_line.h"
# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <mlx.h>

typedef struct s_idx
{
	int	i;
	int	j;
	int	k;
}	t_idx;

typedef struct s_img
{
	void	*img;
	int		img_width;
	int		img_height;
}	t_img;

typedef struct s_coins
{
	void	*img[7];
	int		img_width;
	int		img_height;
}	t_coins;

typedef struct s_enemy
{
	int	x;
	int	y;
}	t_enemy;

typedef struct s_cpex
{
	int	c;
	int	p;
	int	e;
	int	x;
}	t_cpex;

typedef struct s_map
{
	t_cpex	cpex;
	t_coins	anim;
	char	**map;
	char	**coins;
	int		rows;
	int		columns;
	int		ppos_x;
	int		ppos_y;
	int		epos_x;
	int		epos_y;
	void	*mlx;
	void	*win;
	t_img	w;
	t_img	p;
	t_img	b;
	t_img	c;
	t_img	e;
	t_img	x;
	t_img	p_d;
	t_img	p_a;
	t_img	p_w;
	t_img	open;
	t_img	grave;
	int		check;
	int		nbrx;
	t_enemy	*enemies;
	int		new_x;
	int		new_y;
	t_idx	idx;
}			t_map;

void	allocate_map(char *av, t_map *map);
void	check_map(t_map *map);
void	free_map(char **map);
void	check_walls(t_map *map);
void	check_path(t_map *map);
void	put_assests(t_map *map);
void	handle_keys(t_map *map);
void	free_2d(t_map *map, int x);
int		handle_animation(t_map *map);
void	get_name(t_map *map);
void	init_coins(t_map *map);
void	position_of_enemies(t_map *map);
int		check_move(t_map *map, int new_x, int new_y, int a);
int		check_lose(t_map *map);
int		close_window(void *param);
void	fbi_open_up(t_map *map);
void	write_pm(t_map *map, int a, int b, int *nbr);
void	winner_msg(char c, t_map *map);
void	init_xpm(t_map *map);
int		check_open_door(t_map *map);
void	free_all(t_map *map, int x, int e);
void	free_coins(t_map *map);

#endif