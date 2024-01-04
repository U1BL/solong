/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofaisal <mofaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 20:28:16 by mofaisal          #+#    #+#             */
/*   Updated: 2023/04/24 18:37:54 by mofaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "./ft_printf/ft_printf.h"
# include <fcntl.h>
# include "./libft/libft.h"
# include "./Get_Next_Line/get_next_line.h"

# define ESC_KEY 17
# define ARROWS 2

typedef struct s_solong
{
	char	**map;
	char	**dup_map;
	void	*player;
	void	*collect;
	void	*exit;
	void	*wall;
	void	*floor;
	void	*window;
	void	*mlx;
	int		x;
	int		y;
	int		py;
	int		px;
	int		exit_count;
	int		collectibles;
	int		move_count;
}t_solong;

typedef struct s_vars
{
	int	i;
	int	j;
	int	p;
	int	e;
	int	c;
	int	len;
}t_var;

int		map_len(t_solong *sl, int fd, char *argv);
int		check_file(char *file);
int		check_map(t_solong *map_line, int map_len);
int		moves(int key, t_solong *vars);
int		check_collectibles(t_solong *vars);
int		check_exit_r(t_solong *vars);
int		check_exit_d(t_solong *vars);
int		check_exit_l(t_solong *vars);
int		check_exit_up(t_solong *vars);
int		check_valid_path(t_solong *vars);
int		check_invalid_path(t_solong *tmp_map, int i, int j);
int		check(t_solong *tmp, char direction, int i, int j);
int		parse_check(int argc, char *argv[], t_solong *map);
void	map_draw(t_solong *coordinate);
int		exit_game(t_solong *vars);
void	map_area(t_solong *coordinate);
void	invalid(t_solong *tmp, int i, int j);
void	mlx(t_solong *map);
void	free_strings(char **str);

#endif