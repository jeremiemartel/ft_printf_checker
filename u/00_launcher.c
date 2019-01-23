/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 10:44:07 by jmartel           #+#    #+#             */
/*   Updated: 2019/01/14 11:35:00 by jmartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "ft_printf_test.h"

int			u_launcher(void)
{
	t_test		*start;

	start = NULL;
	libunit_display_header("%u");
	load_test(&start, "basic 1 (0)                  ", &(u_basic1));
	load_test(&start, "basic 2 (45)                 ", &(u_basic2));
	load_test(&start, "basic 3 (123564789)          ", &(u_basic2));
	load_test(&start, "basic 4 (-1235)              ", &(u_basic2));
	load_test(&start, "basic 5 (56489612321568652)  ", &(u_basic2));
	return (launch_test(start));	
}
