#include "fdf.h"

void	image_set_pixel(t_image *image, int x, int y, int color)
{
	if (x < 0 || x >= W || y < 0 || y >= H)
		return ;
	*(int *)(image->adr + ((x + y * W) * image->b_p_pix)) = color;
}

void	clear_image(t_image *image)
{
	ft_bzero(image->adr, W * H * image->b_p_pix);
}

t_image	*del_image(t_fdf *st, t_image *img)
{
	if (img != NULL)
	{
		if (img->image_cont != NULL)
			mlx_destroy_image(st->mlx_ptr, img->image_cont);
		ft_memdel((void **)&img);
	}
	return (NULL);
}

t_image	*new_image(t_fdf *st)
{
	t_image		*img;

	if ((img = ft_memalloc(sizeof(t_image))) == NULL)
		return (NULL);
	if (!(img->image_cont = mlx_new_image(st->mlx_ptr, W, H)))
		return (del_image(st, img));
	img->adr = mlx_get_data_addr(img->image_cont, &img->b_p_pix, NULL, NULL);
	img->b_p_pix /= 8;
	return (img);
}