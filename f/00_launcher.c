/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 10:44:07 by jmartel           #+#    #+#             */
/*   Updated: 2019/01/24 12:24:43 by jmartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "ft_printf_test.h"

int			f_launcher(void)
{
	t_test		*start;

	start = NULL;
	libunit_display_header("%f");
	load_test(&start, "basic 1 (-12547.58)           ", &(f_basic1));
	load_test(&start, "basic 2 (0)                   ", &(f_basic2));
	load_test(&start, "basic 3 (45.123456789)        ", &(f_basic3));
	load_test(&start, "basic 4 (12389123798)         ", &(f_basic4));
	load_test(&start, "basic 5 (-8965421.12356432156)", &(f_basic5));
	load_test(&start, "special 1 (inf/-inf/nan)      ", &(f_special1));
	load_test(&start, "special 2 (-0.0)              ", &(f_special2));
	return (launch_test(start));	
}
