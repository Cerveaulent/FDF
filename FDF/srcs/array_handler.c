/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   array_handler.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/19 21:38:19 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/01 16:35:50 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"
#include "lpoints_handler.h"
void		array_delete(t_lpoints **array)
{
	if (*array)
		free(*array);
	*array = NULL;
}

t_lpoints		*array_alloc(int nb_row, int nb_col)
{
	t_lpoints	*new_array;

	new_array = NULL;
	if (!(new_array = (t_lpoints *)malloc((sizeof(t_lpoints) * \
		nb_row * nb_col))))
	{
		perror("array_alloc() -> malloc() = failed");
		return (NULL);
	}
	return (new_array);
}


void	array_fill(t_lpoints *lpoints, t_lpoints **array, \
	int nb_row, int nb_col)
{
	t_lpoints *tmp;
	int reset_nb_col;
	int i;

	reset_nb_col = nb_col;
	tmp = lpoints;
	while (nb_row >= 0)
	{
		i = 1;
		while (i <= nb_col && tmp && (nb_row * nb_col - i) >= 0)
		{
			(*array)[nb_row * nb_col - i].height = tmp->height;
			(*array)[nb_row * nb_col - i].x = tmp->x;
			(*array)[nb_row * nb_col - i].y = tmp->y;
			(*array)[nb_row * nb_col - i].color = tmp->color;
			(*array)[nb_row * nb_col - i].alpha = 1;
			(*array)[nb_row * nb_col - i].next = NULL;
			tmp = tmp->next;
			i++;
		}
		nb_col = reset_nb_col;
		nb_row--;
	}
	tmp = NULL;
}
