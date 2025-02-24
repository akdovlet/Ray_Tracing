/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:04:47 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/24 12:08:55 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

time_t	convert_miliseconds(time_t sec, time_t usec)
{
	time_t	time_ms;

	time_ms = sec * 1000LL + usec / 1000LL;
	return (time_ms);
}

time_t	gettime_in_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (convert_miliseconds(time.tv_sec, time.tv_usec));
}

time_t	gettime_interval(time_t start)
{
	struct timeval	current_time;
	time_t			interval;

	gettimeofday(&current_time, NULL);
	interval = ((current_time.tv_sec * 1000LL) + \
				(current_time.tv_usec / 1000)) - start;
	return (interval);
}
