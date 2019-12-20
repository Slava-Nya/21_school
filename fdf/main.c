/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 15:54:22 by hlorrine          #+#    #+#             */
/*   Updated: 2019/12/20 14:55:42 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    ft_get_net(t_ls *ls)
{
    float   x0;
    float   y0;
    int     color_1;
    int     color_2;

    color_1 = 0x006400;
    color_2 = 0xDC143C;
    ls->k = WIDTH / sqrt((ls->y1 * ls->y1) + (ls->x1 * ls->x1));
    y0 = 0;
    while (++y0 <= ls->y1)
    {
        x0 = 0;
        while (++x0 + 1 <= ls->x1)
        {
            // ft_x_os(ls, x0, y0, 0);
            // ls->color = ((ls->map)[(int)y0 - 1][(int)x0 - 1] == 0) ? color_1 : color_2;
            // if (ls->x > 0 && ls->y > 0 && ls->x_nex > 0 && ls->y_nexj
                // f(ls, ls->x, ls->y ,(ls->x_nex), (ls->y_nex));
                f(ls, x0 * ls->k, y0 * ls->k,(x0 + 1) * ls->k, (y0) * ls->k);
            // }
        }  
    }
    x0 = 0;
    while (++x0 <= ls->x1)
    {
        y0 = 0;
        while (++y0 + 1 <= ls->y1)
        {
            // ft_x_os(ls, x0, y0, 1);
            // ls->color = ((ls->map)[(int)y0 - 1][(int)x0 - 1] == 0) ? color_1 : color_2;
            // if (ls->x > 0 && ls->y > 0 && ls->x_nex > 0 && ls->y_nex > 0)
            // {
                // f(ls, ls->x, ls->y ,(ls->x_nex), (ls->y_nex));
                f(ls, x0 * ls->k, y0 * ls->k,x0 * ls->k, (y0 + 1) * ls->k);
            // }
        }
            // ft_putchar('\n');
    // ft_putstr("sukarabotaiuze\n");
    }
}

void    ft_save_maps(int **map, char **line)
{
    
}

ft_read_maps(t_ls *ls, char **argv)
{
    int     fd;
    char    **line;
    char    **str;
    int     i;

    fd = open(argv[1], O_RDONLY);
    while (get_next_line(fd, &str) != 0)
    {
        free(str);
        i++;
    }
    close(fd);
    if(!(line = (char **)malloc(sizeof(char *) * (i + 1))))
        return ;
    line[i] = NULL;
    i = 0;
    fd = open(argv[1], O_RDONLY);
    while (get_next_line(fd, &line[i]) != 0)
    {      
        if (!((ls->map)[i] = (int *)malloc(sizeof(int) * ft_wordcount(line[i], ' '))))
            return ;
        i++;
    }
    close(fd);
    ft_save_maps(ls->map, line);
    ls->x1 = ft_wordcount(line[0], ' ');
    ls->y1 = i;
    ft_get_net(ls);
}

int     main(int argc, char **argv)
{
    t_ls    *ls;
    int     i;

    i = -1;
    if (!(ls = malloc(sizeof(t_ls))))
        return (0);
    ls->mlx_ptr = mlx_init();
    ls->win_ptr = mlx_new_window(ls->mlx_ptr, WIDTH, HEIGHT, "FDF");
    ls->img_ptr = mlx_new_image(ls->mlx_ptr, WIDTH, HEIGHT);
    ls->data = (int *)mlx_get_data_addr(ls->img_ptr,
        &(ls->n0), &(ls->n1), &(ls->n2));
    while (++i < WIDTH * HEIGHT)
        ls->data[i] = 0xFFDAB9;
    mlx_hook(ls->win_ptr, 2, 0, key, (void*)ls);
    ft_read_maps(ls, argv);
    // f(ls, 100, 100, 600, 100);
    // f(ls, 100, 100, 100, 600);
    // f(ls, 600, 100, 600, 600);
    // f(ls, 600, 600, 100, 600);
    // f(ls, 100, 100, 350, 20);
    // f(ls, 600, 100, 350, 20);
    mlx_put_image_to_window(ls->mlx_ptr, ls->win_ptr, ls->img_ptr, 0, 0);
    mlx_loop(ls->mlx_ptr);
    return 0;
}


void    ft_get_net(t_ls *ls)
{
    float   x0;
    float   y0;
    int     color_1;
    int     color_2;

    color_1 = 0x006400;
    color_2 = 0xDC143C;
    y0 = 0;
    int i = 0;
    while (++y0 < (ls->y1))
    {
        x0 = 0;
        while (++x0 < (ls->x1 - 1))
        {
            ft_x_os(ls, x0, y0, 0);
            ls->color = ((ls->map)[(int)y0][(int)x0] == 0) ? color_1 : color_2;
            if (ls->x > 0 && ls->y > 0 && ls->x_nex > 0 && ls->y_nex)
                f(ls, ls->x, ls->y ,ls->x_nex , (ls->y_nex));
                // f(ls, x0 * ls->k, y0 * ls->k,(x0 + 1) * ls->k, (y0) * ls->k);
        }  
    }
    x0 = 0;
    while (++x0 < (ls->x1))
    {
        y0 = 0;
        while (++y0 < (ls->y1 - 1))
        {
            ft_x_os(ls, x0, y0, 1);
            ls->color = ((ls->map)[(int)y0][(int)x0] == 0) ? color_1 : color_2;
            if (ls->x > 0 && ls->y > 0 && ls->x_nex > 0 && ls->y_nex > 0)
            {
                f(ls, ls->x, ls->y ,(ls->x_nex), (ls->y_nex));
                // f(ls, x0 * ls->k, y0 * ls->k,x0 * ls->k, (y0 + 1) * ls->k);
            }
        }
            // ft_putchar('\n');
    // ft_putstr("sukarabotaiuze\n");
    }
}
