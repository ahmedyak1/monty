#include "monty.h"


globals_var global_var = {NULL, NULL, NULL, 0};


int main(int argc, char *argv[])
{
    stack_t *sf = NULL;
    char *conte;
    FILE *file;
    size_t s = 0;
    ssize_t rl = 1;
    unsigned int cont = 0;


    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    file = fopen(argv[1], "r");
    global_var.file = file;
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    while (rl > 0)
    {
        conte = NULL;
        rl = getline(&conte, &s, file);
        global_var.conte = conte;
        cont++;
        if (rl > 0)
        {
            funcc_instru(&sf,conte , cont, file);
        }
        free(conte);
    }
    funcc_free_stack(sf);
    fclose(file);
return (0);
}

