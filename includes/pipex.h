/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshazaib <mshazaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:39:49 by mshazaib          #+#    #+#             */
/*   Updated: 2023/12/23 13:32:20 by mshazaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdbool.h>

# define EXITWITHFAILURECODE 127
# define ERR_INFILE "Error in the Infile"
# define ERR_OUTFILE "Error in the Outfile"
# define ERR_INPUT "Invalid number of arguments.\n"
# define ERR_PIPE "Error in the Pipe"
# define ERR_CMD "Command not found"

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		tube[2];
	int		infile;
	int		outfile;
	char	*paths;
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd;
	int		statuscode;
}			t_pipex;

void		first_child(t_pipex pipex, char *argv[], char *envp[]);
void		second_child(t_pipex pipex, char *argv[], char *envp[]);
/* free.c */
void		parent_free(t_pipex *pipex);
void		child_free(t_pipex *pipex);

/* error.c */
int			msg(char *err);

/* funcions */
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(const char *src);
char		**ft_split(char const *s, char c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlen(const char *s);

#endif
