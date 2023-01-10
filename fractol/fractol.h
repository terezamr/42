/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:57:26 by mvicente          #+#    #+#             */
/*   Updated: 2023/01/10 18:12:35 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <X11/keysym.h>
# include <X11/X.h>

# define WINDOW_WIDTH 1400
# define WINDOW_HEIGHT 1000
# define MAX_ITER 30
# define RED_PIXEL 0xFF0000
# define YELLOW_PIXEL 0xffd700
# define ORANGE_PIXEL 0xFE5000
# define VIOLET_PIXEL 0x440099
# define PINK_PIXEL 0xFF3EB5
# define BLACK_PIXEL 0x000000
# define GREEN_PIXEL 0X44D62C

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		set_type;
	float	scale;
	int		r_min;
	int		r_max;
	int		i_min;
	int		i_max;
}	t_img;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_img	img;
}	t_data;

#endif