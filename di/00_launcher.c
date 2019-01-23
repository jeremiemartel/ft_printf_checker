/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 10:44:07 by jmartel           #+#    #+#             */
/*   Updated: 2019/01/14 16:08:43 by jmartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "ft_printf_test.h"

int			di_launcher(void)
{
	t_test		*start;

	start = NULL;
	libunit_display_header("%d and %i");
	load_test(&start, "basic 1 (-45)    ", &(di_basic1));
	load_test(&start, "basic 2 (0)      ", &(di_basic2));
	load_test(&start, "basic 3 (-879650)", &(di_basic3));
	load_test(&start, "basic 4 (-9856)  ", &(di_basic4));
	load_test(&start, "basic 5 (56432)  ", &(di_basic5));
	load_test(&start, "cast 1 (l)       ", &(di_cast1));
	load_test(&start, "cast 2 (ll)      ", &(di_cast2));
	load_test(&start, "cast 3 (h)       ", &(di_cast3));
	load_test(&start, "cast 4 (hh)      ", &(di_cast4));
	load_test(&start, "hard 1           ", &(di_hard1));
	return (launch_test(start));	
}
