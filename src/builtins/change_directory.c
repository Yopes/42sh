/*
** cd.c for 42sh in /home/lopes_n/rendu
**
** Made by lopes_n
** Login   <lopes_n@epitech.net>
**
** Started on  Tue May 13 09:44:54 2014 lopes_n
** Last update Sat May 24 12:09:50 2014 menigo_m
*/

#include <sys/stat.h>
#include <stdlib.h>
#include "nautilush.h"
#include "my.h"

static int	access_failed(char *path)
{
  struct stat	buf;

  my_put_error("cd : Cannot access ");
  my_put_error(path);
  if (lstat(path, &buf) == -1)
    my_put_error(": No such file or directory\n");
  else
    if ((buf.st_mode & S_IFDIR) == 0)
      my_put_error(": Not a directory\n");
    else
      my_put_error(": Permission denied\n");
  return (-1);
}

static int	folder_error(int error, t_cmd *cmd, char *pwd, char *oldpwd)
{
  if (error == -1 || cmd->cmdtab[1] == NULL)
    return (access_failed(cmd->cmdtab[1]));
  if (oldpwd != NULL)
    my_setenv_key_value(cmd->env, "OLDPWD", oldpwd);
  if (pwd != NULL)
    my_setenv_key_value(cmd->env, "PWD", pwd);
  if (oldpwd == NULL || pwd == NULL)
    {
      my_put_error("Can not change environment variable\n");
      return (-1);
    }
  return (0);
}

static int	cd_home(t_cmd *cmd)
{
  char		*home;
  char		*pwd;
  char		*oldpwd;

  home = my_getenv("HOME", cmd->env);
  if (home == NULL)
    return (my_put_error("my_getenv failed\n"));
  oldpwd = getcwd(NULL, 512);
  if (chdir(home) == -1)
    return (my_put_error("chdir failed\n"));
  pwd = getcwd(NULL, 512);
  if (oldpwd != NULL)
    my_setenv_key_value(cmd->env, "OLDPWD", oldpwd);
  if (pwd != NULL)
    my_setenv_key_value(cmd->env, "PWD", pwd);
  if (oldpwd == NULL || pwd == NULL)
    {
      my_put_error("Can not change environment variable\n");
      return (-1);
    }
  return (0);
}

int	change_folder(t_cmd *cmd)
{
  int	error;
  char	*pwd;
  char	*oldpwd;

  error = 0;
  if (cmd->cmdtab[1] == NULL)
    return (cd_home(cmd));
  else if (my_strcmp(cmd->cmdtab[1], "-") == 0)
    {
      free(cmd->cmdtab[1]);
      if ((cmd->cmdtab[1] = my_strdup(my_getenv("OLDPWD", cmd->env))) == NULL)
	return (-1);
      my_putstr_fd(my_getenv("OLDPWD", cmd->env), cmd->fd[1]);
      my_putstr_fd("\n", cmd->fd[1]);
    }
  if (cmd->cmdtab[1] != NULL)
    {
      oldpwd = getcwd(NULL, 512);
      error = chdir(cmd->cmdtab[1]);
      pwd = getcwd(NULL, 512);
    }
  if (folder_error(error, cmd, pwd, oldpwd) == -1)
    return (-1);
  return (0);
}
