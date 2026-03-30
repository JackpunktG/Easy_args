#include "easy_args.h"

int main(int argc, char* argv[])
{
    Program_Flags flags;
    if (!set_flags(& flags, argc, argv, ARG_TRUE))
        return 1;

    print_program_flags(&flags);

    print_args_table();

    if (is_flag_set(&flags, FLAG_TEST))
        printf("test is set\n");
    if (is_flag_set(&flags, FLAG_ONE))
        printf("one is set\n");
    if (is_flag_set(&flags, FLAG_TWO))
        printf("two is set\n");
    if (is_flag_set(&flags, FLAG_THREE))
        printf("three is set\n");

    return 0;
}
