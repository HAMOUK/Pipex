/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 12:27:44 by hlongin           #+#    #+#             */
/*   Updated: 2025/09/18 12:46:02 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_px
{
	const char	*infile;
	const char	*outfile;
	const char	*cmd1_line;
	const char	*cmd2_line;
	char		**cmd1_argv;
	char		**cmd2_argv;
}				t_px;

typedef struct s_qstate
{
	int			in_single;
	int			in_double;
}				t_qstate;

typedef struct s_buf
{
	char		*data;
	int			len;
	int			cap;
}				t_buf;

//===parsing===
int				pars_args(int argc, char **argv, t_px *px);
int				build_commands(t_px *px, char **envp);
char			**split_cmd_simple(const char *line);
int				error(char *str);

//===buffer===
int				buf_init(t_buf *b);
int				buf_push(t_buf *b, char c);
char			*buf_to_cstr(t_buf *b);
void			buf_free(t_buf *b);

//===split===
char			**split_cmd_simple(const char *line);
int				is_white_space(char c);
int				skip_blanks(const char *s, int i);
void			free_tab(char **argv);
void			free_partial_tab(char **argv, int count);

//===qstate===
void			qstate_init(t_qstate *q);
void			qstate_toggle(t_qstate *q, char c);

//===token===
int				count_tokens(const char *s);
int				fill_argv(const char *s, char **argv);
int				handle_backslash(const char *s, int *i, t_qstate *q, t_buf *b);
int				handle_token_char(const char *s, int *i, t_qstate *q,
					t_buf *buf);
int				extract_token(const char *s, int *i, char **token);

//===path===
const char		*px_find_path_value(char **envp);
int				px_count_segments(const char *s);
char			**px_get_paths(char **envp);
char			**px_fill_segments(const char *s, int count);
int				has_slash(const char *cmd);
char			*build_candidate(const char *dir, const char *cmd);
char			*join3(const char *a, const char *b, const char *c);
char			*px_find_cmd_path(const char *cmd, char **paths);
int				calculate_total_length(const char *a, const char *b,
					const char *c);
char			*search_command_in_paths(const char *cmd, char **paths);
char			*try_command_with_slash(const char *cmd);
int				fill_single_segment(const char *s, char **tab, int i,
					int *start);
char			*create_segment(const char *s, int start, int len);

//===exec===
void			px_exec_cmd1(t_px *px, int pipefd[2], int infd, char **envp);
void			px_exec_cmd2(t_px *px, int pipefd[2], int outfd, char **envp);
char			*px_resolve_path(const char *cmd, char **envp);
int				x_dup2(int oldfd, int newfd);
int				setup_cmd_io(int infd, int outfd, int unused_pipe);
char			*search_in_paths(const char *cmd, char **paths);
char			*try_direct_path(const char *cmd);

//===run===
int				px_run(t_px *px, char **envp);
int				wait_for_children(pid_t p1, pid_t p2);
int				fork_and_exec_cmd2(t_px *px, int pipefd[2], int outfd,
					char **envp);

#endif
