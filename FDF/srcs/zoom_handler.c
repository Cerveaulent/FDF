/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   zoom_handler.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/08 14:07:08 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/11 17:14:10 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "mouse_map.h"
#include "fdf.h"

void		zoom_in(t_hook *m_hook)
{
	clear_img(m_hook);
	scale(m_hook->map_info->map_scale, m_hook->tab_pts, m_hook->map_info);
	print_map(m_hook);
	return ;
}

void		zoom_out(t_hook *m_hook)
{
	clear_img(m_hook);
	scale(m_hook->map_info->map_scale, m_hook->tab_pts, m_hook->map_info);
	print_map(m_hook);
	return ;
}