/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lpoints_handler.h                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/19 21:41:57 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/13 10:39:11 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LPOINTS_HANDLER_H
# define LPOINTS_HANDLER_H

t_lpoints	*lpoints_create(t_lpoints *point);
t_lpoints	*lpoints_pushfront(t_lpoints *list, t_lpoints new_point);
void		lpoints_delete(t_lpoints **list);

#endif
