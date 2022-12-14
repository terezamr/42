/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:59:46 by mvicente          #+#    #+#             */
/*   Updated: 2023/01/11 19:00:41 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_mouse(int button, int x, int y, t_data *data)
{
	if (x && y)
	{
		if (button == MOUSE_UP)
			data->img.scale *= 0.8;
		else if (button == MOUSE_DOWN)
			data->img.scale *= 2;
	}
	return (0);
}

int	handle_key(int key, t_data *data)
{
	if (key == 65307)
		mlx_destroy_window(data->mlx, data->win);
	else if (key == KEY_LEFT)
		data->img.offset_r -= 0.5;
	else if (key == KEY_RIGHT)
		data->img.offset_r += 0.5;
	else if (key == KEY_UP)
		data->img.offset_i += 0.5;
	else if (key == KEY_DOWN)
		data->img.offset_i -= 0.5;
	else if (key == KEY_PLUS)
		data->img.scale *= 0.5;
	else if (key == KEY_MINUS)
		data->img.scale *= 2;
	return (0);
}

void	vars_init(t_data *data)
{
	data->mlx = 0;
	data->win = 0;
	data->img.scale = 1;
	data->img.offset_r = -2;
	data->img.offset_i = 1;
	data->julia_r = 0.26;
	data->julia_i = 0.0015;
}

int	destroy(int key, t_data *data)
{
	if (key)
		mlx_destroy_window(data->mlx, data->win);
	return (0);
}

void	color(int n, int x, int y, t_data *data)
{
	char	*index;

	index = data->img.addr + (y * data->img.line_len
			+ x * (data->img.bpp / 8));
	if (n == MAX_ITER)
		*(int *)index = BLACK_PIXEL;
	// else if (n > 0 && n < MAX_ITER / 5)
	// 	*(int *)index = GREEN1;
	// else if (n > MAX_ITER / 5 && n < MAX_ITER * 2 / 5)
	// 	*(int *)index = GREEN2;
	// else if (n > MAX_ITER * 2 / 5 && n < MAX_ITER * 3 / 5)
	// 	*(int *)index = GREEN3;
	// else if (n > MAX_ITER * 3 / 5 && n < MAX_ITER * 4 / 5)
	// 	*(int *)index = GREEN4;
	else
		*(int *)index = 7074240;
	// else
	// 	*(int *)index = MAX_ITER / (n * 7074240);
}
