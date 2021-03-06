/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mlx_img_handler.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/20 15:44:55 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/01 20:41:26 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void		clear_img(t_hook *hook)
{
	int	i;

	i = 0;
	while (i < hook->rdr->r_width * hook->rdr->r_height)
		hook->rdr->img_data[i++] = 0x000000;
}
