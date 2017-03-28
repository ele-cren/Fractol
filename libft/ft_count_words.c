/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 13:31:10 by ele-cren          #+#    #+#             */
/*   Updated: 2017/02/01 15:21:45 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_words(const char *s, int c)
{
	int		i;
	int		count;

	if (s && c)
	{
		i = 0;
		count = 0;
		while (s[i])
		{
			while (s[i] == c && s[i])
				i++;
			if (s[i] != '\0')
				count++;
			while (s[i] != c && s[i])
				i++;
		}
		return (count);
	}
	return (0);
}
