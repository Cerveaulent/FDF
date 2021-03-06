/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   zoom_handler.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/08 14:07:08 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/01 20:48:34 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "mouse_map.h"
#include "fdf.h"

void		zoom_in(t_hook *m_hook)
{
	clear_img(m_hook);
	scale(m_hook->tab_pts, m_hook->map_info);
	print_map(m_hook);
	return ;
}

void		zoom_out(t_hook *m_hook)
{
	clear_img(m_hook);
	scale(m_hook->tab_pts, m_hook->map_info);
	print_map(m_hook);
	return ;
}
