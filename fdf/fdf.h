/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 18:16:23 by hlorrine          #+#    #+#             */
/*   Updated: 2019/12/20 15:45:38 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef     FDF_H
# define    FDF_H

# define    WIDTH 1000
# define    HEIGHT 1000
# include "mlx.h"
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct   s_ls
{
    void    *mlx_ptr;
    void    *img_ptr;
    void    *win_ptr;
    int     *data;
    int     n0;
    int     n1;
    int     n2;
    int     color;
    float   x1;
    float   y1;
    float   x;
    float   y;
    float   z;
    float   z_nex;
    float   x_nex;
    float   y_nex;
    float   k;
    int     **map;
    float   x_angle;
    float   y_angle;
    float   z_angle;
    char    os;
}               t_ls;


int     main(int argc, char **argv);
// void    f(t_ls *ls, float x0, float y0, float x1, float y1);
// void    ft_swap(float *a, float *b);
void    ft_read_maps(t_ls *ls, char **argv);
// void    ft_save_maps(int **map, char **line);

#endif