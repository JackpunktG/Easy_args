# Easy Args

Simple and lightweight header lib for easy creating and parsing of C commandline arguments.

## Installation and use

Download the `easy_args.h` and `and easy_args.inc` replace with example args in the .inc file with your args for your application.

#### ARG macro synatx:
```c
#define ARG(flag, arg_string, abbr, ...)
```
- flag: the flag name to be referenced throughout the program
- arg_string: the valid user input to to set the flag. must being with "--"
- abbr: whether or not (turn off with 0) you would like to have a shortarg, single char abbreviation, to set the flag. This can be combined, e.g: -xyz
- *optional* ARG_INFO("flag info"): adding information about the flag to be used to auto generate the --help page

```c
//e.g:
ARG(FLAG_ONE, "--one", 'o')
ARG(FLAG_THREE, "--three", ARG_ABBR_NO, ARG_INFO("It's the third arg. thats kinda cool :)"))
```

#### Program code use:

in the main entry point in your program
```c
#include "easy_args.h"
```
then to set the flags with the set_flags(const int argc, char* argv[], const uint8_t expecting_unknown)
- expecting_unknown unknown mean that you are expection user inputs that are not defined by the table, like filepaths or names.
the funtion fills out the Program_Flags struct, with the set flags.
- if expecting_unknown is set, it will also keep track of unknown args and keep them in a char* [] ready to be referenced
- max is 5, but this can easily be changed by editing the MAX_UNKNOWN_ARGS amount
```c
Program_Flags flags;
if (!set_flags(&flags, argc, argv, ARG_TRUE))
    return 1;
```

To see if a flag is set:
```c
static inline uint8_t is_flag_set(Program_Flags* flags, Flag_Options flag);

if (is_flag_set(&flags, FLAG_TEST))
    printf("test is set\n");
```


The lib contains some helper functions to see what flag are set and the flag table is built
```c
// prints the complete argument table
print_args_table(); 
```
![print table](/images/print_args_table.png)

```c
// prints off currently set flags, the bit representaiton
// and the unknown args being tracked
print_program_flags(Program_Flags* flags);
```
![print program flags](/images/print_program_flags.png)

## Auto generation of --help page

when writing the ARGs macro, the information for ARG_INFO will be used to auto generation for the --help page. If --help if already defined that it won't print out, allow the intergation of existing / self-made --help pages.
- if no ARG_INFO is set then the program will print out the flag it triggers.

 ![--help page](/images/help_page.png)


 



