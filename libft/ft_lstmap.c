/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_lstmap.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: bolmos-o <bolmos-o@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/11/20 21:38:42 by bolmos-o		  #+#	#+#			 */
/*   Updated: 2020/11/20 22:12:59 by bolmos-o		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*add;

	if (!lst || !(new = (ft_lstnew(f(lst->content)))))
		return (NULL);
	add = new;
	while ((lst = lst->next))
	{
		if(!(new->next = ft_lstnew(f(lst->content))))
			ft_lstclear(&add, del);
		new = new->next;
	}
	return(add);
}
