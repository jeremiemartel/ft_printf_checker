/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 17:08:54 by jmartel           #+#    #+#             */
/*   Updated: 2019/01/13 12:36:04 by jmartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H

/*
** fork, write(2)
*/
# include <unistd.h>

/*
** malloc, free, exit(3)
*/
# include <stdlib.h>

/*
** wait(2)
*/
# include <sys/wait.h>
# include <signal.h>

# define SUCCESS			0
# define FAILURE			-1
# define INTERNAL_FAILURE	SIGUSR2

# define RES_OK			"\033[32m[OK]\033[0m"
# define RES_KO			"\033[31m[KO]\033[0m"
# define RES_INTERNAL	"\033[31m[INTERNAL]\033[0m"
# define RES_FPE		"\033[31m[FPE]\033[0m"
# define RES_IO			"\033[31m[IO]\033[0m"
# define RES_SEGF		"\033[31m[SEGV]\033[0m"
# define RES_BUS		"\033[31m[BUS]\033[0m"
# define RES_TIMEOUT	"\033[31m[TIMEOUT]\033[0m"

typedef struct	s_test
{
	char	*name;
	int		(*test)(void);
	void	*next;
}				t_test;

/*
** ./libunit.c
*/
void			free_test_list(t_test **start);
void			load_test(t_test **start, char *name, int (*test)(void));
int				test_len(t_test	*start);
int				launch_test(t_test *start);
int				launch_test2(t_test *start, int success);

/*
** ./libunit_library.c
*/
void			putstr_safe(char *s);
char			*strdup_safe(const char *s1);
void			putnbr_safe(int n);

/*
** ./libunit_display.c
*/
void			libunit_display_result(int res, t_test *test);
void			libunit_display_initial(char *fct_name);
void			libunit_display_final(int success, int len);
void			libunit_display_header(char *fct_name);

#endif
