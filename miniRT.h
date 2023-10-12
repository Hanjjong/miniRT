/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonhan <jonhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:32:19 by jonhan            #+#    #+#             */
/*   Updated: 2023/10/12 18:58:06 by jonhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>

typedef struct s_vec3
{
	double	e[3];
}	t_vec3;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
}	t_vars;

typedef struct s_point3
{
	double	x;
	double	y;
	double	z;
	int		color;
}	t_point3;

typedef struct s_ray
{
	t_vec3		dir;
	t_vec3	origin;
}	t_ray;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;


typedef struct s_map
{
	t_point3	**map;
	int			width;
	int			height;
	// int		img_width;
	// int		img_height;
}	t_map;

double	vec3_length_squared(t_vec3 v);
double	vec3_length(t_vec3 v);
t_vec3	vec3_init(void);
t_vec3	vec3_create(double e0, double e1, double e2);
t_vec3	vec3_negate(t_vec3 vec);
t_vec3	vec3_add(t_vec3 v1, t_vec3 v2);
t_vec3	vec3_multiply(t_vec3 v1, double t);
t_vec3	vec3_divide(t_vec3 v, double t);

t_vec3 multiply_scalar_vec3(double t, t_vec3* v);
t_vec3 multiply_vec3_scalar(t_vec3* v, double t);
double dot_product(t_vec3* u, t_vec3* v);
t_vec3 cross_product(t_vec3* u, t_vec3* v);
t_vec3 normalize_vec3(t_vec3* v);
#endif