/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 12:31:18 by akdovlet          #+#    #+#             */
/*   Updated: 2025/04/02 20:48:32 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

int		parse_scene(char *str, t_world *world, t_parse *parse);
void	skip_whitespace(char *str, int *i);
int		is_valid(char c);
int		get_camera_fov(double *f, char *str, int *i, int line);
int		bad_syntax(int line, char *str, int err);
int		get_position(t_tuple *t, char *str, int *i, int line);
int		get_color(t_tuple *t, char *str, int *i, int line);
int		get_light_color(t_tuple *t, char *str, int *i, int line);
void	clear_lights(t_lightlst **lst);
int		add_object(t_objlst **lst, t_shape *obj);
void	clear_objects(t_objlst **lst);
int		get_normalv(t_tuple *t, char *str, int *i, int line);
int		get_radius(double *f, char *str, int *i, int line);
int		get_rotation(t_tuple *t, char *str, int *i, int line);
int		build_world(char *str, t_world *world);

int		ambient_light(char *str, t_world *world, int line);
int		camera(char *str, t_camera *cam, int line);
int		light(char *str, t_parse *parse, int line);
int		cube(char *str, t_parse *parse, int line);
int		cylinder(char *str, t_parse *parse, int line);
int		plane(char *str, t_parse *parse, int line);
int		sphere(char *str, t_parse *parse, int line);
int		cone(char *str, t_parse *parse, int line);

#endif
