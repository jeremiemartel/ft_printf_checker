/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 10:44:07 by jmartel           #+#    #+#             */
/*   Updated: 2019/01/14 16:21:20 by jmartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "ft_printf_test.h"

int			xx_launcher(void)
{
	t_test		*start;

	start = NULL;
	libunit_display_header("%x and %X");
	load_test(&start, "basic 1           ", &(xx_basic1));
	load_test(&start, "basic 2 (zero)    ", &(xx_basic2));
	load_test(&start, "basic 3 (negatifs)", &(xx_basic3));
	load_test(&start, "basic 4           ", &(xx_basic4));
	load_test(&start, "cast 1            ", &(xx_cast1));
	load_test(&start, "cast 1            ", &(xx_cast2));
	load_test(&start, "cast 1            ", &(xx_cast3));
	return (launch_test(start));	
}
