/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   error_handler.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/19 15:34:41 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2019/08/19 01:16:52 by ccantin     ###    #+. /#+    ###.fr     */
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
int 	check_parsing(int ret);
//function freeing what needs to be freed
//will be using perror() and strerror() to handle errors
// I might still need some custom error handling, ENUM ?

#endif
