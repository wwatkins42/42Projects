/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 15:28:05 by wwatkins          #+#    #+#             */
/*   Updated: 2015/12/22 17:56:25 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <libft.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>

# include <stdio.h> // TEMPORARY

# define ABS(x) (x < 0 ? -x : x)
# define TAB_SIZE 4096 // UGLY AS FUCK

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

typedef struct	s_ptcol
{
	int x;
	int y;
	int c;
}				t_ptcol;

typedef struct	s_env
{
	t_ptcol		**pts;
	t_point		move;
	void		*mlx;
	void		*win;
	int			gw;
	int			gh;
}				t_env;

typedef struct	s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}				t_color;

int		**ft_read(t_env *e, const char *argv);
void	ft_tabassign(t_env e, int **tab, const char *line);
void	ft_maperror(const char *line);
void	ft_error(int err);

void	ft_core(t_env *e, int **tab);
void	ft_assigncoor(t_env *e, int **tab);
void	ft_drawline(t_env e, t_ptcol p, t_point p1, int color);
t_point	ft_point(int x, int y);

#endif
