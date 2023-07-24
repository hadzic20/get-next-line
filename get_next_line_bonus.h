/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadzic <ahadzic@42.tr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:11:02 by ahadzic           #+#    #+#             */
/*   Updated: 2022/09/21 13:23:24 by ahadzic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 999
# endif

int		ft_strlen(const char *str);
char	*ft_newline(const char *str);
char	*ft_substr(char const *str);
char	*ft_strjoin(char *str1, char *str2);
char	*ft_get_left_line(char *str);
char	*get_next_line(int fd);

#endif
