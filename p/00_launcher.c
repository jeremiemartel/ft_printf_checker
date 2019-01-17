/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 10:44:07 by jmartel           #+#    #+#             */
/*   Updated: 2019/01/14 11:19:10 by jmartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "ft_printf_test.h"

int			p_launcher(void)
{
	t_test		*start;

	start = NULL;
	libunit_display_header("%p");
	load_test(&start, "basic 1 ", &(p_basic1));
	load_test(&start, "basic 2 ", &(p_basic2));
	load_test(&start, "basic 3 ", &(p_basic3));
	load_test(&start, "basic 4 ", &(p_basic4));
	load_test(&start, "basic 5 ", &(p_basic5));
	return (launch_test(start));	
}
