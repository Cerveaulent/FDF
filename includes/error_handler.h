/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   error_handler.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/19 15:34:41 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/01 20:13:05 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef ERROR_HANDLER_H
# define ERROR_HANDLER_H

# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"

int		check_args(int argc, char *argv);
int		check_parsing(int ret);

#endif
