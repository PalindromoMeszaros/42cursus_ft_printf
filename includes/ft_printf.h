/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 13:22:04 by pablomar          #+#    #+#             */
/*   Updated: 2020/01/16 18:44:52 by pablomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/libft.h"

typedef struct		s_var
{
	int				count;
	char			*format;
	int				printf_len;
	int				number_flag;
	unsigned long	width;
	char			*flags_map;
	char			*conversion_map;
	char			flag[5];
	unsigned long	precision;
	va_list			args;
	int				negative_num;
	char			*str_null;
	int				neg_star;
}					t_var;

t_var				*print(t_var *var);
t_var				*initialize(t_var *var);
t_var				*reinitialize(t_var *var);
int					ft_printf(const char *format, ...);
char				*ft_itoa_special(int n);
t_var				*pct_conversion(t_var *var);
t_var				*c_conversion(int c, t_var *var);
t_var				*s_conversion(char *str, t_var *var);
t_var				*di_conversion(int num, t_var *var);
t_var				*not_zero_for_u(unsigned int num,
					unsigned int aux, int len, t_var *var);
t_var				*u_conversion(unsigned int num, t_var *var);
unsigned long		num_len(unsigned int aux, unsigned long len);
t_var				*p_conversion(void *ptr, t_var *var);
t_var				*x_conversion(unsigned int num, t_var *var);
t_var				*x_capital_conversion(unsigned int num, t_var *var);
t_var				*flags_activate(t_var *var);
t_var				*field_width(t_var *var);
t_var				*precision(t_var *var);
t_var				*conversion(t_var *var);
void				check_negative(t_var *var);
unsigned long		d_precision_null(char *str, t_var *var, unsigned long aux2);
int					flag_saving(t_var *var, int j);
unsigned long		pointer_zero_precision(unsigned long aux,
					t_var *var, unsigned long num_len);
void				p_justified_precision(char *ptr, char *value, t_var *var,
					unsigned long num_len);
void				p_unjustified_precision(char *ptr, char *value, t_var *var,
					unsigned long num_len);
void				p_null_processing(void *ptr, char *value, t_var *var,
					unsigned long num_len);
unsigned long		p_check_precision(void *ptr, t_var *var,
					char *value, unsigned long num_len);
unsigned long		p_num_len_conditions(char *value, t_var *var);
unsigned long		di_num_len(char *value, t_var *var, int num);

#endif
