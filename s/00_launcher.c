/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 10:44:07 by jmartel           #+#    #+#             */
/*   Updated: 2019/01/14 14:02:04 by jmartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "ft_printf_test.h"

int			s_launcher(void)
{
	t_test		*start;

	start = NULL;
	libunit_display_header("%s");
	load_test(&start, "basic 1        ", &(s_basic1));
	load_test(&start, "basic 2        ", &(s_basic2));
	load_test(&start, "basic 3        ", &(s_basic3));
	load_test(&start, "basic 4 (empty)", &(s_basic4));
	load_test(&start, "basic 5 (NULL) ", &(s_basic5));
	return (launch_test(start));	
}
