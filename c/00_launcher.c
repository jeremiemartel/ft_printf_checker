/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 10:44:07 by jmartel           #+#    #+#             */
/*   Updated: 2019/01/16 21:20:12 by jmartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "ft_printf_test.h"

int			c_launcher(void)
{
	t_test		*start;

	start = NULL;
	libunit_display_header("%c");
	load_test(&start, "basic 1        ", &(c_basic1));
	load_test(&start, "basic 2        ", &(c_basic2));
	load_test(&start, "basic 3 ('\\0') ", &(c_null));
	load_test(&start, "percent : (%%) ", &(c_percent));
	return (launch_test(start));
}
