/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_printf.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: bolmos-o <bolmos-o@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/11/21 17:31:26 by bolmos-o		  #+#	#+#			 */
/*   Updated: 2020/12/15 10:45:01 by bolmos-o		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

void	get_spec(t_print *spec, char *str, va_list ap)
{
	if (*str == '-')
	{
		spec->neg = 1;
		str++;
	}
	else if (*str == '0')
	{
		spec->zer = 1;
		str++;
	}
	while (ft_isdigit(*str))
		spec->wid = (spec->wid * 10) + (*str++ - '0');
	if (*str == '*')
	{
		spec->wid = va_arg(ap, int);
		str++;
	}
	if (*str == '.' )
	{
		spec->pre = 1;
		str++;
		while (ft_isdigit(*str))
			spec->prv = (spec->prv * 10) + (*str++ - '0');
		if (*str == '*')
		{
			spec->prv = va_arg(ap, int);
			str++;
		}
	}
	if (spec->neg == 1)
		spec->wid = -spec->wid;
	spec->type = *str;
	if (ft_isalpha(spec->type))
		spec->arg = va_arg(ap, long);
}

int	get_len(long arg, int base)
{
	int	len;

	if (arg == 0)
		return (1);
	len = (arg < 0) ? 1 : 0;
	while (arg)
	{
		arg = arg / base;
		len++;
	}
	return (len);
}

void	print_arg(t_print conv)
{
	int	len;

	len = get_len(conv.arg, 10);
	while (conv.wid > len && conv.wid-- > conv.prv)
		ft_putchar_fd(' ', 1);
	while (conv.prv-- > len)
		ft_putchar_fd('0', 1);
	ft_putnbr_fd(conv.arg, 1);
	while (conv.wid++ < -len)
		ft_putchar_fd(' ', 1);
}

void	chk_spec(t_print *spec, long arg)
{
	if (spec->neg == 1)
		spec->zer = 0;
	if (get_len(arg, 10))
		spec->zer = 0;
	if (spec->prv > spec->wid)
		spec->wid = spec->prv;
}

int	convert(va_list ap, char *str)
{
	t_print conv;

	conv.neg = 0;
	conv.zer = 0;
	conv.wid = 0;
	conv.pre = 0;
	conv.prv = 0;
	get_spec(&conv, ++str, ap);
//	chk_spec(&spec, arg);
	print_arg(conv);
	/*	ft_putchar_fd('N', 1);
		ft_putnbr_fd(spec.neg, 1);
		ft_putchar_fd('\n', 1);
		ft_putchar_fd('Z', 1);
		ft_putnbr_fd(spec.zer, 1);
		ft_putchar_fd('\n', 1);
		ft_putchar_fd('W', 1);
		ft_putnbr_fd(spec.wid, 1);
		ft_putchar_fd('\n', 1);
		ft_putchar_fd('P', 1);
		ft_putnbr_fd(spec.pre, 1);
		ft_putchar_fd('\n', 1);
		ft_putchar_fd('T', 1);
		ft_putchar_fd(spec.type, 1);
		ft_putchar_fd('\n', 1);
		*/	//get_arg(ap, str, &arg);
	return (0);	
}

int	ft_printf(const char *str, ...)
{
	va_list ap;
	int		count;

	va_start(ap, str);
	count = 0;
	while (*str)
	{
		while (*str && *str != '%')
		{
			ft_putchar(*str++);
			count++;
		}
		if (*str == '%')
		{
			convert(ap, (char *)str++);
			while (!(ft_isalpha(*(str - 1)) && *(str - 1) != '%'))
				str++;
		}
	}
	va_end(ap);
	return (count);
}
