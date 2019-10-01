/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   error_handler.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/03 19:57:27 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/01 20:22:02 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "error_handler.h"

/*
** This files is filled check functions to raise errors
*/

static int	check_file_extension(char *argv)
{
	if (!ft_strstr(argv, ".fdf"))
	{
		ft_putendl("Error : wrong file extension");
		ft_putendl("Usage : ./fdf file.fdf");
		exit(EXIT_FAILURE);
		return (-1);
	}
	return (0);
}

int			check_args(int argc, char *argv)
{
	int	fd;

	fd = 0;
	if (argc != 2)
	{
		ft_putendl("Usage : ./fdf file.fdf");
		exit(EXIT_FAILURE);
		return (-1);
	}
	check_file_extension(argv);
	if ((fd = open(argv, O_RDONLY)) == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
		return (-1);
	}
	return (fd);
}

int			check_parsing(int ret)
{
	if (ret != 0)
	{
		ft_putendl("Error parsing");
		exit(EXIT_FAILURE);
	}
	else
		return (0);
}
