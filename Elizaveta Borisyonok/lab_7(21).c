#include "mylib.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	file_name = "info.txt";
	get_data_from_file();
	main_menu();
	write_data_to_file();
	int i;
	for (i = 0; i < num_of_groups; i++)
	{
		delete_group(groups[i]);
	}
	free(groups);
	for (i = 0; i < num_of_releases; i++)
	{
		delete_release(releases[i]);
	}
	free(releases);
	for (i = 0; i < num_of_users; i++)
	{
		delete_user(users[i]);
	}
	free(users);
}
