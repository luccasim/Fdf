/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 09:52:42 by luccasim          #+#    #+#             */
/*   Updated: 2016/11/25 09:52:45 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int			usage(int format)
{
	if (format == FDF_ERROR_FORMAT)
		return (PERROR("File format [n][m]:\n0 0 0 0\n0 1 2 0\n0 0 0 0"));
	else if (format == FDF_ERROR_INPUT)
		return (PERROR("./fdf [path_file]"));
	else if (format == FDF_ERROR_INIT)
		return (PERROR("fdf environement allocation fail!"));
	else if (format == FDF_ERROR_WINDOW)
		return (PERROR("Window allocation failed!"));
	else if (format == FDF_ERROR_IMAGE)
		return (PERROR("Image allocation failed!"));
	return (format);
}

int					fdf_exit(int error)
{
	if (error)
		return (usage(ERROR));
	return (error);
}
