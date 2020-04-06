/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 15:30:29 by mburnett          #+#    #+#             */
/*   Updated: 2019/10/01 18:32:28 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 47
# define MAX_FD 4096
# define CHECKEND(car) if (car == 0) return (0);
# define CHECKMEM(x) if (!x) x = ft_strnew(1);
# define MERROR(item) if(!item) return (-1);

#endif
