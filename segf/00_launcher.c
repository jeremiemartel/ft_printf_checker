/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 10:44:07 by jmartel           #+#    #+#             */
/*   Updated: 2019/01/14 18:27:30 by jmartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "ft_printf_test.h"

int			segf_launcher(void)
{
	t_test		*start;

	start = NULL;
	libunit_display_header("trying to segf");
	load_test(&start, "segf1 : maj conv                      ", &(segf1));
	load_test(&start, "segf2 : NULL param (optionnal)        ", &(segf2));
	load_test(&start, "segf3 : too much params               ", &(segf3));
	load_test(&start, "segf4 : not enough params (optionnal)", &(segf4));
	load_test(&start, "segf5 : NULL param (optionnal)        ", &(segf5));
	return (launch_test(start));	
}
