/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:10:12 by mvicente          #+#    #+#             */
/*   Updated: 2023/01/11 19:03:32 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_fractal(t_data *data, double c1, double c2)
{
	int	n;

	n = 0;
	if (data->set_type == MANDELBROT)
		n = mandelbrot(c1, c2);
	if (data->set_type == JULIA)
		n = julia(c1, c2, 0.26, -0.002);
	return (n);
}

int	render(t_data *data)
{
	double	x;
	double	y;
	double	c1;
	double	c2;
	int		n;

	y = 0;
	mlx_clear_window(data->mlx, data->win);
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		c2 = (-2 * (y / WINDOW_HEIGHT) + data->img.offset_i) * data->img.scale;
		while (x < WINDOW_WIDTH)
		{
			c1 = (3 * (x / WINDOW_WIDTH) + data->img.offset_r)
				* data->img.scale;
			n = get_fractal(data, c1, c2);
			color(n, x, y, data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.mlx_img, 0, 0);
	return (1);
}

void	check_arguments(char **argv, t_data *data)
{
	if (!ft_strcmp(argv[1], "mandelbrot") || !ft_strcmp(argv[1], "1"))
		data->set_type = MANDELBROT;
	if (!ft_strcmp(argv[1], "julia") || !ft_strcmp(argv[1], "2"))
	{
		data->set_type = JULIA;
		data->julia_r = ft_atoi(argv[2]);
		data->julia_i = ft_atoi(argv[3]);
	}
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 2)
		return (0);
	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	vars_init(data);
	check_arguments(argv, data);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT,
			"Fract'ol");
	data->img.mlx_img = mlx_new_image(data->mlx, WINDOW_WIDTH,
			WINDOW_HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	mlx_loop_hook(data->mlx, render, data);
	mlx_key_hook(data->win, handle_key, data);
	mlx_mouse_hook(data->win, handle_mouse, data);
	mlx_hook(data->win, 17, 1L << 17, destroy, data);
	mlx_loop(data->mlx);
//	mlx_destroy_image(data->mlx, data->img.mlx_img);
//	mlx_destroy_display(data->mlx);
//	free(data->mlx);
}
