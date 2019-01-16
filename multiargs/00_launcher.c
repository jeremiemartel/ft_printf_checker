/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 10:44:07 by jmartel           #+#    #+#             */
/*   Updated: 2019/01/16 16:32:34 by jmartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "ft_printf_test.h"

int			multiargs_launcher(void)
{
	t_test		*start;

	start = NULL;
	libunit_display_header("Testing with multiple arguments");
	load_test(&start, "multiargs1 :    ", &(multiargs1));
	load_test(&start, "multiargs2 :    ", &(multiargs2));
	return (launch_test(start));	
}
