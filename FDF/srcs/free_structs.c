/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free_structs.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/11 19:02:13 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/01 20:24:18 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"
#include "array_handler.h"
#include "lpoints_handler.h"

void			free_hook(t_hook *hook)
{
	if (hook != NULL)
	{
		if (hook->rdr != NULL)
			mlx_destroy_image(hook->mlx->mlx_ptr, hook->rdr->img_ptr);
		if (hook->rdr != NULL)
			mlx_destroy_window(hook->mlx->mlx_ptr, hook->mlx->win_ptr);
		free(hook->mlx);
		free(hook->map_info);
		free(hook->rdr);
		lpoints_delete(&(hook->lpoints));
		array_delete(&(hook->tab_pts));
		free(hook);
		hook = NULL;
	}
	else
		return ;
}
