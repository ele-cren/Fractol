/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 16:12:03 by ele-cren          #+#    #+#             */
/*   Updated: 2017/02/10 10:30:29 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

static int		ft_getlength(int j, const char *s, char c)
{
	int		i;

	i = j;
	while (s[i] != c && s[i])
		i++;
	return (i - j);
}

char			**ft_strsplit(const char *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	if (s)
	{
		tab = NULL;
		i = -1;
		j = 0;
		if ((tab = (char **)malloc(sizeof(char *) * \
						ft_count_words(s, c) + 1)) == NULL)
			return (NULL);
		while (++i < ft_count_words(s, c))
		{
			k = 0;
			while (s[j] == c && s[j])
				j++;
			tab[i] = ft_strnew(ft_getlength(j, s, c));
			while (s[j] != c && s[j])
				tab[i][k++] = s[j++];
		}
		tab[i] = NULL;
	}
	return ((s) ? tab : NULL);
}
