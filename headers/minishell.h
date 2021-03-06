/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 17:15:14 by bndao             #+#    #+#             */
/*   Updated: 2016/04/22 18:40:30 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <signal.h>
# define TAB_SIZE 2
# define CLEAR ft_putstr("\033c");
# define RESET ft_putstr("\x1B[0m");

typedef struct          s_val
{
    char                *entry;
    struct s_val        *next;
    struct s_val        *prev;
}                       t_val;

typedef struct          s_env
{
    char                *key;
    struct s_val        *value;
    struct s_env        *next;
    struct s_env        *prev;
}                       t_env;

typedef struct          s_data
{
    int                 ac;
    char                **av;
    char                **env;
    struct s_env        *e;
}                       t_data;

typedef struct          s_builtins
{
    char		        *cmd;
	void		        (*f)(struct s_data *d, char **av);
}				        t_builtins;

struct s_builtins		tab[TAB_SIZE];

char					*bin_to_path(char *path, char *bin);
char					*find_path_to_bin(char *cmd, t_env *e);
int	            		handle(t_builtins tab[TAB_SIZE], t_data *d, char **av);
void	       			launch_it(char *asked, t_data *d);
void					forked(t_data *d);

void			        print_env(t_data *d, char **av);
void                    set_env(t_data *d, char **av);

t_val					*val_new(char *value);
t_env					*key_new(char *key, t_val *v);
t_val					*path_to_list(char *str);
t_env					*env_to_list(char **env);
t_data		    		*new_data(int ac, char **av, char **environ);

char 					**list_to_tab(t_env *list);
void					error_handler(char *str, int num);
void					push_back_list_val(t_val **b_list, t_val *new);
void					push_back_list_en(t_env **b_list, t_env *new);

char					*check_absolute(char *cmd);
int     				ft_list_size(t_env *b);
int						fields(char **env);
int						is_dir(char *str);
int		           		close_dir(DIR *dir);
void					print_that_tab(char **tab);
char					*ft_strcut(char *str, char c);
char					is_in(char *fmt, char c);

#endif
