/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   modif_height.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/01 17:34:12 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/01 20:32:43 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"
#include "key_map.h"

void	modif_height(t_hook *hook, int is_up)
{
	int i;

	i = -1;
	if (is_up == H)
	{
		while (++i < hook->map_info->map_size)
			hook->tab_pts[i].height += 1;
	}
	else
	{
		while (++i < hook->map_info->map_size)
			hook->tab_pts[i].height -= 1;
	}
	clear_img(hook);
	transform(hook);
}
