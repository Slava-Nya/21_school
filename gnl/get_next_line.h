/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 17:47:34 by hlorrine          #+#    #+#             */
/*   Updated: 2019/10/06 21:12:12 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 21

# include "fcntl.h"
# include "unistd.h"
# include "stdlib.h"
# include "string.h"
# include "libft/libft.h"

typedef struct		s_lst
{
	struct s_lst	*next;
	char			*str;
	int				lst_fd;
}					t_lst;

int					get_next_line(const int fd, char **line);

#endif
