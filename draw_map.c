/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:16:28 by igvisera          #+#    #+#             */
/*   Updated: 2024/03/12 20:54:35 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>


// ################          Pinta cuadrados renderizado           ######################
/*
    ###  2D image the pixel ###
    line len is in byte.
    witdh 800 line_length 3200
    (can differ for aligment)
*/
void pixel_put(t_img *img, int x, int y, int color)
{
    int offset;

    offset = (img->line_length * y) + (x * (img->bits_per_pixel / 8));
    *((unsigned int *)(offset + img->img_pixel_ptr)) = color;
}

/*
    funcion q genera la malla de pixeles se tiene q indicar el tamaño color y la ventana
*/
// void screen_pixels(t_window *window, int width, int height, int color)
// {
//     // int cell_width = (WIDTH_WIN * 0.8 / width); // Ancho de cada celda
//     // int cell_height = (HEIGHT_WIN * 0.8 / height); // Altura de cada celda
//     // int start_x = WIDTH_WIN * 0.1;//donde inicia x
//     // int end_x = WIDTH_WIN * 0.9;//donde termina x
//     // int start_y = HEIGHT_WIN * 0.1;//donde inicia y
//     // int end_y = HEIGHT_WIN * 0.9;//donde termina y
//     //############# saca las celdas sin margen #############
//     int cell_width = WIDTH_WIN / width; // Ancho de cada celda
//     int cell_height = HEIGHT_WIN / height; // Altura de cada celda
//     int start_x = 0;//donde inicia x
//     int end_x = WIDTH_WIN;//donde termina x
//     int start_y = 0;//donde inicia y
//     int end_y = HEIGHT_WIN;//donde termina y

//     // Dibujar líneas horizontales
//     for (int y = start_y; y <= end_y; ++y) {
//         if (y == start_y || y == end_y || (y - start_y) % cell_height == 0) {
//             for (int x = start_x; x < end_x; ++x) {
//                 pixel_put(&window->img, x, y, color); // Dibujar líneas horizontales del marco o de la malla
//             }
//         }
//     }
//     // Dibujar líneas verticales
//     for (int x = start_x; x <= end_x; ++x) {
//         if (x == start_x || x == end_x || (x - start_x) % cell_width == 0) {
//             for (int y = start_y; y < end_y; ++y) {
//                 pixel_put(&window->img, x, y, color); // Dibujar líneas verticales del marco o de la malla
//             }
//         }
//     }
// }

# ifndef MAX_1
#  define MAX_1(a, b) (a > b ? a : b)
# endif

# ifndef MOD
#  define MOD(a) ((a < 0) ? -a : a)
# endif
float mod(float x)
{
    return (x < 0 ? -x : x);
}

/*
    *window -> estructura de la ventana
    width -> donde inicia
    height -> donde termina
    width_1 -> donde como de ancho es
    height_1 -> donde como de largo es
    color -> el color que tiene
*/
void bresenham(t_window *window, float width, float height, float width_1, float height_1)
{
    float width_step;
    float height_step;
    int max;
    // int z;
    // int z_1;
    // int color;
    
    //--- para meter el zoom multiplicams los valores por el zoom q queremos ---
    width *= window->zoom;
    height *= window->zoom;
    width_1 *= window->zoom;
    height_1 *= window->zoom;
    //--- tenemos que comprobar que hay color ---
    // z = window->map[(int)height][(int)width].value;
    // z_1 = window->map[(int)height_1][(int)width_1].color;
    // color = (z) ? 0xe80c0c : 0xffffff;

    width_step = width_1 - width;
    height_step = height_1 - height;
    max = MAX_1(MOD(width_step), MOD(height_step));
    width_step /= max;
    height_step /= max;
    while ((int)(width - width_1) || (int)(height - height_1))
    {
        pixel_put(&window->img, width, height, 0xffffff);
        width += width_step;
        height += height_step;
    }
}

void draw(t_window *window)
{
    
    int width_pixels;
    int height_pixels;
    height_pixels = 0;

    while (height_pixels < window->map[0]->number_row)
    {
        width_pixels = 0;
        while (width_pixels < window->map[0][0].number_col)
        {  
            if (width_pixels < window->map[0][0].number_col - 1)
                bresenham(window, width_pixels, height_pixels, width_pixels+1, height_pixels);
            if (height_pixels < window->map[0]->number_row - 1)
                bresenham(window, width_pixels, height_pixels, width_pixels, height_pixels + 1);
            width_pixels++;
        }
        height_pixels++;
    }
    mlx_put_image_to_window(window->mlx, window->win, window->img.img_ptr, 0, 0);//lanzamos lo generedo a la pantalla
}

/*
    funcion q siempre esta a la escucha de cualquier tecla q se pulsa
*/
int f(int keysym, t_window *window)
{
    // //ver q han pulsado y sacar color
    // if (keysym == N_1)//    inverido
    // else if (keysym == N_2)//    rosalige
    //     //screen_pixels(window, width, height, 0xec53a0);
    //     bresenham(window, width, height, 1000, 1000, 0xec53a0);


    // printf("tecla pulsada %i\n", keysym);
    if (keysym == ZOOM_IN)
        draw(window);
    if (keysym == ZOOM_OUT)
        draw(window);
    else if (keysym == ESC)//    salimos
        exit(1);
    mlx_put_image_to_window(window->mlx, window->win, window->img.img_ptr, 0, 0);
    return (0);
}

/*
    controlador de la ventana
*/
int open_window(t_pixel **map)
{
    t_window window;

    window.mlx = mlx_init();
    window.win = mlx_new_window(window.mlx, WIDTH_WIN, HEIGHT_WIN, "Fdf");
    window.img.img_ptr = mlx_new_image(window.mlx, WIDTH_WIN, HEIGHT_WIN);
	window.img.img_pixel_ptr = mlx_get_data_addr(
                                window.img.img_ptr, 
                                &window.img.bits_per_pixel, 
                                &window.img.line_length,
								&window.img.endian);
    window.map = map;
    window.zoom = 30;
    draw(&window);
    mlx_key_hook(window.win, f, &window);
    mlx_loop(window.mlx);
    return (0);
}

