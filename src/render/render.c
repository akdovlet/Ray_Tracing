/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:22:01 by akdovlet          #+#    #+#             */
/*   Updated: 2025/03/09 16:36:47 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "shapes.h"

void	render(t_camera cam, t_world world, t_img *img, t_mlx *mlx)
{
	int	y;
	int	x;
	t_ray	*ray;
	t_tuple	color;

	y = 0;
	ray = malloc(sizeof(t_ray) * (cam.vsize * cam.hsize));
	if (!ray)
		return ;
	cache_ray(ray, &cam);
	while (y < cam.vsize)
	{
		x = 0;
		while (x < cam.hsize)
		{
			color = color_at(&world, ray[x + y * cam.hsize], 5);
			ak_mlx_pixel_put(img, x, y, tuple_tocolor(color));
			x++;
		}
		y++;
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img->img_ptr, 0, 0);
	}
	free(ray);
}

void	path_tracing(t_data *data)
{
	int		y;
	int		x;
	t_tuple	color;
	t_tuple	final_color;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			color = trace_rays(&data->world, data->rays[x + y * WIDTH], (x + y * WIDTH) * data->frame_index, data->frame_index);
			if (data->frame_index == 1)
				data->accumulation[x + y * WIDTH] = color;
			else
				data->accumulation[x + y * WIDTH] = tuple_add(data->accumulation[x + y * WIDTH], color);
			final_color = data->accumulation[x + y * WIDTH];
			final_color = tuple_divide(final_color, data->frame_index);
			ak_mlx_pixel_put(&data->img, x, y, tuple_tocolor(final_color));
			x+= 1;
		}
		y += 1;
	}
	mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr, data->img.img_ptr, 0, 0);
}

void	background(t_img *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			ak_mlx_pixel_put(img, i, j, 0);
			j++;
		}
		i++;
	}
}

int	render_accumulation(t_data *data)
{
	clock_t				start;
	clock_t				end;
	double				cpu_time;

	if (data->moved)
	{
		data->skip = 5;
		data->frame_index = 1;
		cache_ray(data->rays, &data->cam);
		data->moved = false;
	}
	start = clock();
	path_tracing(data);
	end = clock();
	cpu_time = ((double) (end - start)) / CLOCKS_PER_SEC;
	data->ts = cpu_time;
	printf("\rframe %d time: %.f ms",data->frame_index, data->ts * 1000);
	fflush(stdout);
	data->frame_index++;
	return (0);
}

int	render_and_move(t_data *data)
{
	int		y;
	int		x;
	t_tuple	color;
	clock_t	start;
	clock_t	end;

	y = 0;
	start = clock();
	cache_ray(data->rays, &data->cam);
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			color = color_at(&data->world, data->rays[x + y * WIDTH], 5);
			ak_mlx_pixel_put(&data->img, x, y, tuple_tocolor(color));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr, data->img.img_ptr, 0, 0);
	end = clock();
	data->ts = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("\rframe %d time: %.f ms",data->frame_index, data->ts * 1000);
	fflush(stdout);
	return (0);
}

