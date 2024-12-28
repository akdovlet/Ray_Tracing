
# include "matrix.h"

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

t_tuple		color_new(float red, float green, float blue);
t_tuple		color_hadamard(t_tuple c1, t_tuple c2);

/*	mlx	*/

int			init_mlx(t_mlx *mlx, t_img *img);
void		mlx_clear(t_mlx *mlx, t_img *img);
void		ak_mlx_pixel_put(t_img *data, float dx, float dy, unsigned int color);
int			key_manager(int keysym, t_mlx *mlx);
