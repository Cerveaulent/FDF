/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   transfo_iso.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/13 18:48:06 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/14 00:29:58 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

// static void	apply_iso(t_hook *hook)
// {

// }

void static	calc_iso(t_hook *hook)
{
	int i;

	i = -1;
	while (++i < hook->map_info->map_size)
	{
		hook->tab_pts[i].x = (int)((hook->tab_pts[i].x + hook->tab_pts[i].y)* 0.58);
		hook->tab_pts[i].y = (int)(hook->tab_pts[i].y  - (hook->tab_pts[i].height + hook->tab_pts[i].x)*0.15);
	}
}

void		transform(t_hook *hook, int key)
{
	if (key == I)
	{
		clear_img(hook);
		calc_iso(hook);
		// apply_iso(hook);

		print_map(hook);
	}
}