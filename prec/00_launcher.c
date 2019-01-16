/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 10:44:07 by jmartel           #+#    #+#             */
/*   Updated: 2019/01/15 14:22:36 by jmartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "ft_printf_test.h"

int			nullprec_launcher(void)
{
	t_test		*start;

	start = NULL;
	libunit_display_header("prec tests");
	load_test(&start, "nullprec1 : (di)", &(nullprec1));
	load_test(&start, "nullprec2 : (u) ", &(nullprec2));
	load_test(&start, "nullprec3 : (f) ", &(nullprec3));
	load_test(&start, "nullprec4 :(xXo)", &(nullprec4));
	load_test(&start, "nullprec5 : (s) ", &(nullprec5));
	load_test(&start, "bigprec1  : (di)", &(bigprec1));
	load_test(&start, "bigprec2  : (f) ", &(bigprec2));
	load_test(&start, "bigprec3  :(xXo)", &(bigprec3));
	return (launch_test(start));	
}
