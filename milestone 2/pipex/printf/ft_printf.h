/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 21:37:50 by lkoh              #+#    #+#             */
/*   Updated: 2024/07/26 21:37:51 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *text, ...);
int	ft_strlen(const char *str);
int	ft_putstr(char *str);
int	ft_putnbr(int n);
int	ft_putchar(char c);
int	ft_putpercent(char c);
int	ft_unsigned(unsigned int n);
int	ft_printptr(void *ptr);
int	ft_printhex(unsigned long n, char c);
int	ft_printhex_ptr(unsigned long n, char c);

#endif
