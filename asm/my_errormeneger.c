/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_errormeneger.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 18:25:51 by amovchan          #+#    #+#             */
/*   Updated: 2017/09/14 18:25:55 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			*ft_tab(int i, int j, int k)
{
	int		*tab;

	tab = (int*)malloc(sizeof(int) * 3);
	tab[0] = i;
	tab[1] = j;
	tab[2] = k;
	return (tab);
}

static int	errorsintaks(char *str, int *tab)
{
	char	*src;

	if (str[0] == '\0')
	{
		ft_printf(
		"{fd}Syntax error at token[TOKEN][%{fd}03d{fd}:%{fd}03d{fd}] ENDLINE\n",
			2, 2, tab[0], 2, 2, tab[1], 2);
		free(tab);
		return (-1);
	}
	if (str[0] == ',')
		src = "SEPARATOR";
	else if (tab[2] == 4)
		src = "DIRECT";
	else if (tab[2] == 3)
		src = "INDIRECT";
	else if (tab[2] == 2)
		src = "REGISTER";
	else if (tab[2] == 1)
		src = "INSTRUCTION";
	ft_printf("{fd}Syntax error at token [TOKEN][%{fd}03d"
			"{fd}:%{fd}03d{fd}] %{fd}s \"%{fd}s{fd}\"\n",
			2, 2, tab[0], 2, 2, tab[1], 2, 2, src, 2, str, 2);
	free(tab);
	return (-1);
}

static void	my_erormanager_2(char *str, int *tab, int error)
{
	if (error == 7)
		ft_printf("{fd}No such label %{fd}d while attempting to dereference "
			"token [TOKEN][%{fd}03d{fd}:%{fd}03d{fd}] DIRECT_LABEL \""
		"%{fd}s{fd}\"\n", 2, 2, tab[2], 2, tab[0], 2, 2, tab[1], 2, 2, str, 2);
	else if (error == 8)
		ft_printf("{fd}Champion name too long (Max length 128)\n", 2);
	else if (error == 9)
		ft_printf("{fd}No such name or coment at token [TOKEN][%{fd}03d{fd}:"
				"%{fd}03d{fd}]\n", 2, 2, tab[0], 2, 2, tab[1], 2);
	else if (error == 10)
		ft_printf("{fd}Syntax error - unexpected end of input "
				"(Perhaps you forgot to end with a newline ?)\n", 2);
}

int			my_erormanager(char *str, int *tab, int error)
{
	tab[1]++;
	if (error == 1)
		ft_printf("{fd}Lexical error at [%{fd}d{fd}:%{fd}d{fd}]\n",
				2, 2, tab[0], 2, 2, tab[1], 2);
	else if (error == 2)
		return (errorsintaks(str, tab));
	else if (error == 3)
		ft_printf("{fd}Invalid parameter count for "
					"instruction %{fd}s{fd}\n", 2, 2, str, 2);
	else if (error == 4)
		ft_printf("{fd}Invalid parameter %{fd}d {fd}type indirect "
					"for instruction %{fd}s{fd}\n", 2, 2, tab[2], 2, 2, str, 2);
	else if (error == 5)
		ft_printf("{fd}Invalid instruction at token [TOKEN]"
					"[%{fd}03d{fd}:%{fd}03d{fd}] INSTRUCTION \"%{fd}s{fd}\"\n",
				2, 2, tab[0], 2, 2, tab[1], 2, 2, str, 2);
	else if (error == 6)
		ft_printf("{fd}No such label %{fd}s {fd}while attempting to "
		"dereference token [TOKEN][%{fd}03d{fd}:%{fd}03d{fd}] DIRECT_LABEL \":"
		"%{fd}s{fd}\"\n", 2, 2, str, 2, 2, tab[0], 2, 2, tab[1], 2, 2, str, 2);
	else
		my_erormanager_2(str, tab, error);
	free(tab);
	return (-1);
}
