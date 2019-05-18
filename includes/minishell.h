/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghazrak- <ghazrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 19:48:09 by ghazrak-          #+#    #+#             */
/*   Updated: 2019/02/23 04:50:32 by ghazrak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <sys/ioctl.h>
# include <sys/dir.h>
# include <termios.h>
# include <string.h>
# include "../getnextline/get_next_line.h"
# include "../ft_printf/ft_printf.h"
# include "../libft/includes/libft.h"

# include <readline/readline.h>
# include <readline/history.h>
# include <crt_externs.h>

# define NOTEXIST "cd: no such file or directory: %s\n"
# define NOTDIR "cd: not a directory: %s\n"
# define NOPERM "cd: permission denied: %s\n"
# define CD_ERNOTEXIST(p, e) ({ft_printf(NOTEXIST, p); return (e);})
# define CD_ERNOTDIR(p, e) ({ft_printf(NOTDIR, p); return (e);})
# define CD_ERPERM(p, e) ({ft_printf(NOPERM, p); return (e);})
# define PRINT(str, e) ({ft_printf(str); return (e);})

# define NRM "\x1B[0m"
# define RED "\x1B[31m"
# define GRN "\x1B[32m"
# define YEL "\x1B[33m"
# define BLU "\x1B[34m"
# define MAG "\x1B[35m"
# define CYN "\x1B[36m"

char **g_eenv;

typedef struct dirent		t_dirent;
typedef struct winsize		t_win;

/*
** in main.c
*/
int			msh_execute(char **args);

/*
** in ft_cd.c
*/
int			msh_cd(char **args);

/*
** in ft_echo.c
*/
int			msh_echo(char **args);

/*
** in ft_signal.c
*/
void		ft_signal(int signo);
void		ft_signal2(int signo);

/*
** in ft_eenv.c
*/
void		init_eenv(char **eenv);
int			print_eenv();
int			check_eenv(char *name);

/*
** in ft_setenv.c
*/
int			set_env(char **args);
void		add_eenv(char *name, char *value);
char		**realloc_eenv(int new_size);
void		change_eenv(int i, char *name, char *value);

/*
** in ft_unsetenv.c
*/
int			unset_envv(char **args);

/*
** in ft_path.c
*/
char		*parse_path(char *args, int i);

/*
** in utils.c
*/
int			strlen_geenv(void);
int			check_errors(char **args);
void		free_all(char **mas);
void		change_pwd(char *oldpwd);
void		print_type(t_dirent	*ret);

/*
** in ft_comands.c
*/
int			msh_exit();
int			msh_pwd(char **args);
int			check_commands(char **s);
int			msh_comands(char **commands);

/*
** in ft_dir.c
*/
int			make_dir(char *name);
int			remove_dir(char *name);
int			help(void);

/*
**  in ft_tab.c
*/
void		ft_tab1(void);
void		ft_tab2(void);
int			check_commands2(char *line);
void		ft_tab(char *line);
int			check_path(char *args, int i);

/*
** in ft_tab2.c
*/
int			check_path2(char *args, int i);
int			check_commands3(char *line);
void		print_in_tty(int max, size_t tmp, int count);

#endif
