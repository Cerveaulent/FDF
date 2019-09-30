/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_map.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/19 00:05:17 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/21 18:53:06 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

static t_lpoints	apply_scale(t_lpoints pt, t_hook *m_hook)
{
	t_lpoints	result;

	if (m_hook->map_info->map_scale <= 0)
		m_hook->map_info->map_scale = 1;
	result.x = round(pt.x * (m_hook->map_info->map_scale + m_hook->map_info->map_scale));
	result.y = round(pt.y * (m_hook->map_info->map_scale + m_hook->map_info->map_scale));
	result.color = pt.color;
	return (result);
}

int			print_map(t_hook *m_hook)
{
	int i;

	i = 0;
	while (i < m_hook->map_info->map_size)
	{
		if (((i + 1)  % m_hook->map_info->nb_col))
			main_bresenham(apply_scale(m_hook->tab_pts[i], m_hook), apply_scale(m_hook->tab_pts[i + 1], m_hook), m_hook->rdr);
		if (i + m_hook->map_info->nb_col < m_hook->map_info->map_size)
			main_bresenham(apply_scale(m_hook->tab_pts[i], m_hook), 
			apply_scale(m_hook->tab_pts[i + m_hook->map_info->nb_col], m_hook), m_hook->rdr);
		i++;
	}
	mlx_put_image_to_window(m_hook->mlx->mlx_ptr, m_hook->mlx->win_ptr,
		m_hook->rdr->img_ptr,L_OFFSET, TOP_OFFSET);
	return (1);
}
