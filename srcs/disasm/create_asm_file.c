#include "dis_asm.h"
#include "corewar.h"

static char				*get_new_filename(const char *filename)
{
	size_t				len_without_extention;
	char				*filename_without_extention;
	char				*new_filename;

	len_without_extention = ft_strlen(filename);
	while (len_without_extention != 0 && filename[len_without_extention] != '.')
		len_without_extention--;
	if (len_without_extention == 0)
		error_dis(ERR_INVALID_FILE_NAME);
	filename_without_extention = ft_strnew(len_without_extention);
	ft_strncpy(filename_without_extention, filename, len_without_extention);
	new_filename = ft_strjoin(filename_without_extention, FILE_EXTENSION);
	ft_strdel(&filename_without_extention);
	return (new_filename);
}

int						create_asm_file(const char *filename)
{
	char				*new_filename;
	int					fd;

	new_filename = get_new_filename(filename);
	if ((fd = open(new_filename, O_CREAT | O_TRUNC | O_WRONLY, 0644)) == -1)
		error_dis(ERR_CREATE_FILE);
	ft_strdel(&new_filename);
	return (fd);
}
