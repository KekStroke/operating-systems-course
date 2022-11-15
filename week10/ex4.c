#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

int main()
{
    DIR *dir = opendir("tmp");

    struct dirent *dp;

    printf("File - Hard Links\n");
    while ((dp = readdir(dir)) != NULL)
    {
        int n_links = 0;
        struct dirent *link;
        DIR *tmp_dir = opendir("tmp");

        while ((link = readdir(tmp_dir)) != NULL)
        {
            if (dp->d_ino == link->d_ino)
            {
                n_links++;
            }
        }

        if ((strcmp(dp->d_name, ".") != 0) && (strcmp(dp->d_name, "..") != 0) && (n_links >= 2))
        {
            printf("%s - ", dp->d_name);
            DIR *tmp_dir = opendir("tmp");
            int i = 0;
            while ((link = readdir(tmp_dir)) != NULL)
            {
                if (dp->d_ino == link->d_ino)
                {
                    printf("%s", link->d_name);
                    i++;
                    if (i != n_links)
                    {
                        printf(", ");
                    }
                }
            }
            printf("\n");
        }
    }
    return 0;
}