/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 12:31:18 by akdovlet          #+#    #+#             */
/*   Updated: 2025/03/19 11:59:55 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

int		parse_scene(char *str, t_world *world, t_parse *parse);
int		ambient_light(char *str, t_world *world, int line);
void	skip_whitespace(char *str, int *i);
int		is_valid(char c);
int		camera(char *str, t_camera *cam, int line);
int		get_camera_fov(double *f, char *str, int *i, int line);
int		bad_syntax(int line, char *str, int err);
int		get_position(t_tuple *t, char *str, int *i, int line);
int		get_color(t_tuple *t, char *str, int *i, int line);
int		light(char *str, t_parse *parse, int line);
int		get_light_color(t_tuple *t, char *str, int *i, int line);
void	clear_lights(t_lightlst **lst);
int		sphere(char *str, t_parse *parse, int line);
int		add_object(t_objlst **lst, t_shape *obj);
void	clear_objects(t_objlst **lst);

#endif
