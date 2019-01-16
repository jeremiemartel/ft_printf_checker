/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 10:44:07 by jmartel           #+#    #+#             */
/*   Updated: 2019/01/16 15:50:37 by jmartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "ft_printf_test.h"

int			return_launcher(void)
{
	t_test		*start;

	start = NULL;
	libunit_display_header("Testing return value");
	load_test(&start, "return1 :    ", &(return1));
	load_test(&start, "return2 :    ", &(return2));
	load_test(&start, "hard1 :      ", &(hard1));
	return (launch_test(start));	
}
