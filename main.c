/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 10:43:15 by jmartel           #+#    #+#             */
/*   Updated: 2019/01/16 16:46:41 by jmartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "ft_printf_test.h"

int			main(void)
{
	di_launcher();
	c_launcher();
	xx_launcher();
	f_launcher();
	u_launcher();
	o_launcher();
	s_launcher();
	p_launcher();
	nullprec_launcher();
	segf_launcher();
	return_launcher();
	multiargs_launcher();
	return (0);
}
