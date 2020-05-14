/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   array_handler.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/19 23:51:08 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/13 16:56:51 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef ARRAY_HANDLER_H
# define ARRAY_HANDLER_H

t_lpoints	*array_alloc(int nb_row, int nb_col);
void		array_delete(t_lpoints **array);
void		array_fill(t_lpoints *lpoints, t_lpoints **array, \
				int nb_row, int nb_col);
#endif
