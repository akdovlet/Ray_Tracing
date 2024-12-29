/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 09:59:31 by akdovlet          #+#    #+#             */
/*   Updated: 2024/12/29 10:26:47 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_H
# define MLX_UTILS_H

# include "matrix.h"
#include "data_struct.h"

typedef struct s_img {
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_mlx {
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx;

/*	colors	*/



/*	mlx	*/

int			init_mlx(t_mlx *mlx, t_img *img);
void		mlx_clear(t_mlx *mlx, t_img *img);
void		ak_mlx_pixel_put(t_img *data, float dx, float dy, unsigned int color);
int			key_manager(int keysym, t_mlx *mlx);

#endif
