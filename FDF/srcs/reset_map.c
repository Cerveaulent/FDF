/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   reset_map.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/13 16:47:42 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/13 21:17:58 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"
#include "array_handler.h"

void		reset_map(t_hook *hook)
{
	array_fill(hook->lpoints, &hook->tab_pts, hook->map_info->nb_row, 
		hook->map_info->nb_col);
	hook->map_info->map_scale = 10;
	clear_img(hook);
	print_map(hook);
}