/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glass_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:38:04 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/20 19:41:44 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "test.h"

t_material	glass_material(void)
{
	return ((t_material){
		.pattern.exists = 0,
		.color = color_new(1, 1, 1),
		.ambient = 0.1,
		.diffuse = 0.9,
		.specular = 0.9,
		.shininess = 200,
		.reflective = 0.0,
		.transparency = 1.0,
		.refractive_index = 1.5,
	});
}

t_shape	glass_sphere(void)
{
	t_shape	new;

	new = (t_shape){
		.coordinates = point_new(0, 0, 0),
		.radius = 1,
		.id = new_id(),
		.type = SPHERE,
		.transform = identity(),
		.matter = glass_material(),
		.local_interesct = &sphere_intersect,
		.local_normalat = &sphere_normal_at,
	};
	return (new);
}

/*


In the C Standard there is written (6.7.9 Initialization)

    17 Each brace-enclosed initializer list has an associated current object. When no designations are present, 
	subobjects of the current object are initialized in order according to the type of the current object: 
	array elements in increasing subscript order, structure members in declaration order, and the first named 
	member of a union.148) In contrast, a designation causes the following initializer to begin initialization 
	of the subobject described by the designator. Initialization then continues forward in order, beginning 
	with the next subobject after that described by the designator

And

    19 The initialization shall occur in initializer list order, 
	each initializer provided for a particular subobject overriding any previously listed initializer for 
	the same subobject;151) all subobjects that are not initialized explicitly shall be initialized implicitly 
	the same as objects that have static storage duration.

This footnote is important

    148) If the initializer list for a subaggregate or contained union does not begin with a left brace,
	 its subobjects are initialized as usual, but the subaggregate or contained union does not become the current
	  object: current objects are associated only with brace-enclosed initializer lists.

Thus I see neither undefined nor unspecified behavior.

In my opinion the result should look like { 1, 5, 3 }.

If to leave aside the Standard then it is reasonable at first to initialize the memory
 with the default initializes and then overwrite it with the explicit initializers.

*/
