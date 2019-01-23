/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit_display.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 15:48:40 by thberrid          #+#    #+#             */
/*   Updated: 2018/12/02 19:34:27 by jmartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libunit.h"

void		libunit_display_header(char *fct_name)
{
	putstr_safe("\nTESTS > ");
	putstr_safe(fct_name);
	putstr_safe("\n\n");
}

void		libunit_display_initial(char *test_name)
{
	putstr_safe("\t");
	putstr_safe(test_name);
	putstr_safe("\n");
}

void		libunit_display_final(int success, int len)
{
	putstr_safe("\n\t ");
	putnbr_safe(success);
	putstr_safe(" / ");
	putnbr_safe(len);
	putstr_safe(" achieved tests.\n\n\n");
}

void		libunit_display_result(int res, t_test *test)
{
	putstr_safe("\t ");
	putstr_safe(test->name);
	putstr_safe(" : ");
	if (res == SIGSEGV)
		putstr_safe(RES_SEGF);
	else if (res == SIGUSR1 << 8)
		putstr_safe(RES_TIMEOUT);
	else if (res == SIGFPE)
		putstr_safe(RES_FPE);
	else if (res == SIGIO)
		putstr_safe(RES_IO);
	else if (res == SIGBUS)
		putstr_safe(RES_BUS);
	else if (res == SUCCESS)
		putstr_safe(RES_OK);
	else
		putstr_safe(RES_KO);
	putstr_safe("\n");
}
