/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lpoints_handler.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/19 16:17:23 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/13 12:45:07 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

t_lpoints	*lpoints_create(t_lpoints point)
{
	t_lpoints *new_lpoints;

	new_lpoints = NULL;
	if (!(new_lpoints = malloc(sizeof(t_lpoints))))
		perror("new_lpoints() -> malloc = failed ");
	else
	{
		new_lpoints->height = point.height;
		new_lpoints->color = point.color;
		new_lpoints->x = point.x;
		new_lpoints->y = point.y;
		new_lpoints->alpha = 1;
		new_lpoints->next = NULL;
	}
	return (new_lpoints);
}

t_lpoints 		*lpoints_pushfront(t_lpoints *list, t_lpoints new_point)
{
	t_lpoints *new_node;
	
	new_node = NULL;
	if (!(new_node = lpoints_create(new_point)))
	{
		perror("lpoints_pushfront() -> lpoints_create() = failed");
		return (NULL);
	}
	new_node->next = list;
	return (new_node);
}

void		lpoints_delete(t_lpoints **list)
{
	t_lpoints *tmp;

	while ((*list) != NULL)
	{
		
		tmp = *list;
		*list = (*list)->next;
		free(tmp);
		tmp = NULL;
	}
	free(*list);
	*list = NULL;
}
