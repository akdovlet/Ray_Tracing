#ifndef _DLST_H_
# define _DLST_H_

# include <stdlib.h>

typedef struct s_dlst		t_dlst;
typedef struct s_dlst_node	t_dlst_node;

t_dlst_node					*_dlst_new_node(void);
t_dlst						*_dlst_new(void);

t_dlst						*_dlst_push_back(t_dlst *, void *);
t_dlst						*_dlst_push_front(t_dlst *, void *);

t_dlst						*_dlst_insert_next(t_dlst *, t_dlst_node *, void *);
t_dlst						*_dlst_insert_prev(t_dlst *, t_dlst_node *, void *);

t_dlst						*_dlst_pop_front(t_dlst *, void *(*f)(void *));
t_dlst						*_dlst_pop_back(t_dlst *, void *(*f)(void *));
t_dlst						*_dlst_del(t_dlst *, t_dlst_node *,
								void *(*f)(void *));

t_dlst						*_dlst_clear(t_dlst *, void *(*f)(void *));

t_dlst						*_dlst_foreach(t_dlst *, void (*f)(void *));

struct						s_dlst_node
{
	t_dlst_node				*next;
	t_dlst_node				*prev;
	t_dlst					*mgr;
	void					*ptr;
};

struct						s_dlst
{
	t_dlst_node				*top;
	t_dlst_node				*bot;
	unsigned int			len;
};

#endif /* !_DLST_H_ */
