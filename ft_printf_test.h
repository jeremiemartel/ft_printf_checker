/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_test.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 10:45:11 by jmartel           #+#    #+#             */
/*   Updated: 2019/01/16 21:18:46 by jmartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_TEST_H
# define FT_PRINTF_TEST_H

int			ft_printf(const char * restrict format, ...);

/*
** printf(3)
*/
# include <stdio.h>

/*
** strcmp(3)
*/
# include <string.h>

# include <limits.h>

# define READING_SIZE	3000

/*
** di:
*/
int			di_launcher(void);
int			di_basic1(void);
int			di_basic2(void);
int			di_basic3(void);
int			di_basic4(void);
int			di_basic5(void);
int			di_cast1(void);
int			di_cast2(void);
int			di_cast3(void);
int			di_cast4(void);
int			di_hard1(void);

/*
** xX:
*/
int			xx_launcher(void);
int			xx_basic1(void);
int			xx_basic2(void);
int			xx_basic3(void);
int			xx_basic4(void);
int			xx_cast1(void);
int			xx_cast2(void);
int			xx_cast3(void);

/*
** f:
*/
int			f_launcher(void);
int			f_basic1(void);
int			f_basic2(void);
int			f_basic3(void);
int			f_basic4(void);
int			f_basic5(void);
int			f_special1(void);

/*
** c:
*/
int			c_launcher(void);
int			c_basic1(void);
int			c_basic2(void);
int			c_null(void);
int			c_percent(void);

/*
** u:
*/
int			u_launcher(void);
int			u_basic1(void);
int			u_basic2(void);
int			u_basic3(void);
int			u_basic4(void);
int			u_basic5(void);

/*
** o :
*/
int			o_launcher(void);
int			o_basic1(void);
int			o_basic2(void);
int			o_basic3(void);
int			o_basic4(void);
int			o_basic5(void);

/*
** p :
*/
int			p_launcher(void);
int			p_basic1(void);
int			p_basic2(void);
int			p_basic3(void);
int			p_basic4(void);
int			p_basic5(void);

/*
** s :
*/
int			s_launcher(void);
int			s_basic1(void);
int			s_basic2(void);
int			s_basic3(void);
int			s_basic4(void);
int			s_basic5(void);

/*
** prec :
*/
int			nullprec_launcher(void);
int			nullprec1(void);
int			nullprec2(void);
int			nullprec3(void);
int			nullprec4(void);
int			nullprec5(void);
int			bigprec1(void);
int			bigprec2(void);
int			bigprec3(void);

/*
** segf :
*/
int			segf_launcher(void);
int			segf1(void);
int			segf2(void);
int			segf3(void);
int			segf4(void);
int			segf5(void);

/*
** return :
*/
int			return_launcher(void);
int			return1(void);
int			return2(void);
int			hard1(void);

/*
** multiargs :
*/
int			multiargs_launcher(void);
int			multiargs1(void);
int			multiargs2(void);


#endif