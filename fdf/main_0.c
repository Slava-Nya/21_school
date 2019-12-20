/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 17:36:53 by hlorrine          #+#    #+#             */
/*   Updated: 2019/12/20 17:53:58 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
void    ft_swap(float *a, float *b)
{
    float tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

void    f(t_ls *ls, float x0, float y0, float x1, float y1)
{
    float   e;
    float   m;
    float   d;

    d = 1;
    if (fabsl(x1 - x0) > fabsl(y1 - y0))
    {
        if (x0 > x1)
        {
            ft_swap(&x0, &x1);
            ft_swap(&y0, &y1);
        }
        if (y0 > y1)
            d = -1;
        e = 0;
        ls->data[(int)y0 * WIDTH + (int)x0] = ls->color;
        while (x0 <= x1)
        {
            m = fabsl(y1 - y0) / fabsl(x1 - x0);
            e += m;
            x0 += 1;
            if (e < 0.5)
            {
                ls->data[(int)y0 * WIDTH + (int)x0] = ls->color;
            }
            else
            {
                e -= 1.0;
                y0 += d;
                ls->data[(int)y0 * WIDTH + (int)x0] = ls->color;
            }
        }
    }
    else
    {
        if (y0 > y1)
            {
            ft_swap(&x0, &x1);
            ft_swap(&y0, &y1);
            }
        if (x0 > x1)
            d = -1;
        e = 0;
        ls->data[(int)y0 * WIDTH + (int)x0] = ls->color;
        while (y0 <= y1)
        {
            m = fabsl(x1 - x0) / fabsl(y1 - y0);
            e += m;
            y0 += 1;
            if (e < 0.5)
            {
                ls->data[(int)y0 * WIDTH + (int)x0] = ls->color;
            }
            else
            {
                e -= 1.0;
                x0 += d;
                ls->data[(int)y0 * WIDTH + (int)x0] = ls->color;
            }
        }
    }
}

void    ft_y_os(t_ls *ls, float x0, float y0, int casek)
{
    if (casek == 0)
    {
        ls->x = ((x0  * cos(ls->y_angle)) + (ls->z  * sin(ls->y_angle))) * ls->k;
        ls->x_nex = (((x0 + 1) * cos(ls->y_angle)) + (ls->z_nex * sin(ls->y_angle))) * ls->k;
        ls->y = y0 * ls->k;
        ls->y_nex = y0 * ls->k;    
    }
    else
    {
        ls->x = ((x0  * cos(ls->y_angle)) + (ls->z  * sin(ls->y_angle))) * ls->k;
        ls->x_nex = ((x0  * cos(ls->y_angle)) + (ls->z_nex  * sin(ls->y_angle))) * ls->k;
        ls->y = y0 * ls->k;
        ls->y_nex = (y0 + 1) * ls->k;
    }
    ls->z = ls->z * cos(ls->y_angle) - ls->x * sin(ls->y_angle);
    ls->z_nex = ls->z_nex * cos(ls->y_angle) - ls->x_nex * sin(ls->y_angle);
    ls->x *= 100 / (100 - ls->z);
    ls->x_nex *= 100 / (100 - ls->z_nex);
    ls->y *= 100 / (100 - ls->z);
    ls->y_nex *= 100 / (100 - ls->z_nex);
}

void    ft_x_os(t_ls *ls, float x0, float y0, int casek)
{
    if (casek == 0)
    {
        ls->y = ((y0  * cos(ls->x_angle)) + (ls->z  * sin(ls->x_angle))) * ls->k;
        ls->y_nex = ((y0  * cos(ls->x_angle)) + (ls->z_nex  * sin(ls->x_angle))) * ls->k;
        ls->x = x0 * ls->k;
        ls->x_nex = (x0 + 1) * ls->k;
    }
    else
    {
        ls->y = ((y0  * cos(ls->x_angle)) + (ls->z * sin(ls->x_angle))) * ls->k;
        ls->y_nex = (((y0 + 1) * cos(ls->x_angle)) + (ls->z_nex * sin(ls->x_angle))) * ls->k;
        ls->x = x0 * ls->k;
        ls->x_nex = x0 * ls-> k;
    }
    ls->z = ls->z * cos(ls->x_angle) - ls->y * sin(ls->x_angle);
    ls->z_nex = ls->z_nex * cos(ls->x_angle) - ls->y_nex * sin(ls->x_angle);
    ls->x *= 800 / (800 - ls->z);
    ls->x_nex *= 800 / (800 - ls->z_nex);
    ls->y *= 800 / (800 - ls->z);
    ls->y_nex *= 800 / (800 - ls->z_nex);
}

void    ft_z_os(t_ls *ls, float x0, float y0, int casek)
{
    if (casek == 0)
    {
        ls->x = ((x0  * cos(ls->z_angle)) - (y0  * sin(ls->z_angle))) * ls->k;
        ls->y = ((x0  * sin(ls->z_angle)) + (y0  * cos(ls->z_angle))) * ls->k;
        ls->y_nex = (((x0 + 1)  * sin(ls->z_angle)) + (y0  * cos(ls->z_angle))) * ls->k;
        ls->x_nex = (((x0 + 1)  * cos(ls->z_angle)) - (y0  * sin(ls->z_angle))) * ls->k;
    }
    else
    {
        ls->x = ((x0  * cos(ls->z_angle)) - (y0  * sin(ls->z_angle))) * ls->k;
        ls->y = ((x0  * sin(ls->z_angle)) + (y0  * cos(ls->z_angle))) * ls->k;
        ls->x_nex = ((x0  * cos(ls->z_angle)) - ((y0 + 1)  * sin(ls->z_angle))) * ls->k;
        ls->y_nex = ((x0  * sin(ls->z_angle)) + ((y0 + 1)  * cos(ls->z_angle))) * ls->k;
    }
    ls->x *= 800 / (800 - ls->z);
    ls->x_nex *= 800 / (800 - ls->z_nex);
    ls->y *= 800 / (800 - ls->z);
    ls->y_nex *= 800 / (800 - ls->z_nex);
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
    while (++y0 < (ls->y1))
    {
        x0 = 0;
        while (++x0 < (ls->x1 - 1))
        {
            ls->z = (ls->map)[(int)y0][(int)x0];
            ls->z_nex = (ls->map)[(int)y0][(int)x0 + 1];
            // ft_x_os(ls, x0, y0, 0);
            ft_y_os(ls, x0, y0, 0);
            // ft_y_os(ls, x0, y0, 0)1
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
            ls->z = (ls->map[(int)y0])[(int)x0];
            ls->z_nex = (ls->map[(int)y0 + 1])[(int)x0];
            // ft_x_os(ls, x0, y0, 1);
            ft_y_os(ls, x0, y0, 1);
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

void    ft_save_maps(int **map, char **line)
{
    int     i;
    int     j;
    int     j_1;

    i = -1;
    while (line[++i])
    {
        j = 0;
        j_1 = -1;
        while (line[i][j])
        {
            map[i][++j_1] = ft_atoi(&line[i][j]);
            while (line[i][j] && line[i][j] == ' ')
                j++;
            if (line[i][j] == '-')
                j++;
            while(line[i][j] && (line[i][j] >= '0' && line[i][j] <= '9'))
                j++;
            while (line[i][j] && line[i][j] == ' ')
                j++;
        }    
    }
}

void    ft_read_maps(t_ls *ls, char **argv)
{
    int     fd;
    char    **line;
    char    *str;
    int     i;
    int j = 0;

    i = 0;
    fd = open(argv[1], O_RDONLY);
    while (get_next_line(fd, &str) != 0)
    {
        free(str);
        i++;
    }
    if(!(line = (char **)malloc(sizeof(char *) * (i + 1))))
        return ;
    line[i] = NULL;
    close(fd);
    if (!(ls->map = (int **)malloc(sizeof(int *) * i)))
        return;
    fd = open(argv[1], O_RDONLY);
    i = 0;
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
    ls->k = WIDTH / sqrt((ls->y1 * ls->y1) + (ls->x1 * ls->x1));
    i = 0;
    ls->x_angle = 0;
    ls->y_angle = 0;
    ls->z_angle = 0;
    ft_get_net(ls);
}

void    ft_fon(t_ls *ls)
{
    int i;

    i = -1;
    while (++i < WIDTH * HEIGHT)
        ls->data[i] = 0xFFDAB9;
}

int key(int key, void *f)
{
    t_ls *ls;
    ls = (t_ls*)f;
    printf("%d\n", key);
    if (key == 53)
        exit(0);
    if (key == 27)
        ls->k -= 0.3;
    if (key == 24)
        ls->k += 0.3;
    if (key == 33)
    {
        ls->y_angle -= 0.1;
    }
    if (key == 30)
    {
        ls->y_angle += 0.1;
    }
    // if (key == 13)
    // {
    //     ls->os = 'x';
    //     ls->angle += 0.1;
    // }
    // if (key == 1)
    // {
    //     ls->os = 'x';
    //     ls->angle -= 0.1;
    // }
    // if (key == 0)
    // {
    //     // ls->os = 'y';
    //     ls->angle -= 0.1;
    // }
    // if (key == 2)
    // {
    //     // ls->os = 'y';
    //     ls->angle += 0.1;
    // }
    ft_fon(ls);
    ft_get_net(ls);
    mlx_put_image_to_window(ls->mlx_ptr, ls->win_ptr, ls->img_ptr, 0, 0);
    return 0;
}

int     main(int argc, char **argv)
{
    t_ls   *ls;
    int i;

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
    // f(ls, 0, 100, 100, 100);
    // f(ls, 100, 100, 100, 600);
    // f(ls, 600, 100, 600, 600);
    // f(ls, 600, 600, 100, 600);
    // f(ls, 100, 100, 350, 20);
    // f(ls, 600, 100, 350, 20);
    mlx_put_image_to_window(ls->mlx_ptr, ls->win_ptr, ls->img_ptr, 0, 0);
    mlx_loop(ls->mlx_ptr);
    // ft_read_maps(ls, argv);
    return 0;
}