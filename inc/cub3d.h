/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 14:28:07 by thgillai          #+#    #+#             */
/*   Updated: 2021/09/16 15:10:35 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "../lib/libft/inc/libft.h"
# include "../lib/minilibx/mlx.h"
# include "../lib/libft/get_next_line/get_next_line.h"

# define MS 0.1
# define RS 0.1
# define TXW 64
# define TXH 64

# define XEVENT_KEYPRESS 2
# define XEVENT_KEYRELEASE 3
# define XEVENT_EXIT 17

# define INT_MAX 2148473647
# define KEYCODE_ESC 53
# define KEYCODE_UPARROW 126
# define KEYCODE_DOWNARROW 125
# define KEYCODE_RIGHTARROW 124
# define KEYCODE_LEFTARROW 123
# define KEYCODE_W 13
# define KEYCODE_A 0
# define KEYCODE_S 1
# define KEYCODE_D 2

typedef struct s_data
{
	int				ce_r;
	int				ce_g;
	int				ce_b;
	int				fl_r;
	int				fl_g;
	int				fl_b;
	int				map_argnb;
	int				nb_line;
	int				line_place;
	char			*NO;
	char			*SO;
	char			*WE;
	char			*EA;
	char			**map;
	char			position;
	void			*mlx_ptr;
	int				nb_map;
}				t_data;

void	parsing(t_data *data, char *line);
void	parsing2(t_data *data, char *line);
void	parsing3(t_data *data, char *line);
void	resolution(char *line);
void	exit_error(char *error_string);
void	res(char *line, t_data *data);
void	*ft_calloc2(size_t size);
void	north(char *line, t_data *data);
void	south(char *line, t_data *data);
void	west(char *line, t_data *data);
void	east(char *line, t_data *data);
void	sprite(char *line, t_data *data);
void	parsemap(char *line, t_data *data);
void	allocmap(t_data *data, int fd);
void	fl(char *line, t_data *data);
void	ce(char *line, t_data *data);
int		ft_atoi2(const char *str);
void	check_data(t_data *data);
void	check_cefl(char *line);
void	check_comma(char *line);
void	checkifmap(char *line, t_data *data);
int		checkifmap2(char *line);
void	verifmapline(char *line);
void	checkifhole(t_data *data);
void	check_data2(t_data *data);
int		ft_visible(t_list *list);
int		ft_esc(t_list *list);

#endif

// /!\ probleme trou map
// /!\ probleme map ligne vide au milieu