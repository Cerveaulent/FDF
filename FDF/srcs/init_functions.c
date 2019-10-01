/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init_functions.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/18 23:18:16 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/01 16:32:10 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"


static void				init_map_info(t_map_info *map_info)
{
	map_info->nb_col = 0;
	map_info->nb_row = 0;
	map_info->map_size = 0;
	map_info->map_scale = 0;
}

/*
** Initialising all the pointers by the mlx functions
** They are stored in a structure define in fdf.h
*/

static t_mlx			*init_mlx(void)
{
	t_mlx	*mlx_struct;

	mlx_struct = NULL;
	if (!(mlx_struct = malloc(sizeof(t_mlx))))
		return (NULL);
	mlx_struct->mlx_ptr = mlx_init();
	mlx_struct->win_ptr = mlx_new_window(mlx_struct->mlx_ptr, W_WIDTH, W_HEIGHT,
		"fdf");
	return (mlx_struct);
}

/*
** Initialising all the pointers used by the mlx functions
** They are stored in a structure define in fdf.h
*/

t_hook					*init_hook(void)
{
	t_hook *m_hook;

	m_hook = NULL;
	if(!(m_hook = malloc(sizeof(t_hook))))
		return (NULL);
	if(!(m_hook->map_info = malloc(sizeof(t_map_info))))
		return (NULL);
	init_map_info(m_hook->map_info);
	m_hook->tab_pts = NULL;
	m_hook->lpoints = NULL;
	m_hook->mlx = init_mlx();
	m_hook->rdr = init_rdr(m_hook->mlx, W_WIDTH, W_HEIGHT);
	return (m_hook);
}

/*
** Initialising renderer to make easier display and have better
** perfs
*/

t_renderer				*init_rdr(t_mlx *mlx, int width, int height)
{
	t_renderer	*rdr;

	rdr = NULL;
	if (mlx == NULL)
		return (NULL);
	if (!(rdr = malloc(sizeof(t_renderer))))
		return (NULL);
	rdr->r_width = width;
	rdr->r_height = height;
	rdr->img.size_l = 0;
	rdr->img.bpp = 0;
	rdr->img.endian = 0;
	rdr->img_ptr = mlx_new_image(mlx->mlx_ptr, width, height);
	rdr->img_data = (unsigned int *)mlx_get_data_addr(rdr->img_ptr, &rdr->img.bpp,
		&rdr->img.size_l, &rdr->img.endian);
	return (rdr);
}	
