/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bad_syntax.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:52:26 by akdovlet          #+#    #+#             */
/*   Updated: 2025/03/18 14:54:20 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	bad_syntax(int line, char *str, int err)
{
	ft_dprintf(2, "Error: line %d: bad syntax: `%s'\n", line, str);
	return (err);
}
