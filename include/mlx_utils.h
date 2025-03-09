/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 09:59:31 by akdovlet          #+#    #+#             */
/*   Updated: 2025/03/09 12:46:16 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_H
# define MLX_UTILS_H

# include <stdint.h>

typedef struct s_img {
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_width;
	int		img_height;
}	t_img;

typedef struct s_mlx {
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx;

uint32_t	pixel_at(t_img *data, int dx, int dy);
int			init_mlx(t_mlx *mlx, t_img *img);
void		mlx_clear(t_mlx *mlx, t_img *img);
void		ak_mlx_pixel_put(t_img *data, int dx, int dy, uint32_t color);

#endif
