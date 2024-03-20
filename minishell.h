/*	AND_OR.C			*/
t_node		*add_nodes(t_node *root, char *str, int i);
t_node		*read_node(char *str, int *i);
void		add_child(t_node *root, t_node *child);
char		*get_line_inside(char *str, int *i);
void		skip_spaces(char *str, int *i);

/*	AND_OR2.C			*/
t_node		*createnode();
void		freetree(t_node *root);
t_node		*create_parent(t_node *child, char *line);
void		or(char *cmd2, t_node *root, char *str, int *i);
t_node		*create_node(char *cmd);

/*	AND_OR3.C			*/
char		*parse_command(char *str, int *i);
t_node		*manage_parent(char	*cmd1, t_node *root, char *str, int *i);
