#include "open_file.h"

void openFile(FILE **file)
{
    if (*file == NULL)
    {
        printf("\nFile ERROR!\n");
        exit(1);
    }
}