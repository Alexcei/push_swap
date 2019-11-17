cmake_minimum_required(VERSION 3.14)
project(push_swap C)

file(GLOB FILES
        "push_swap.h"
        "push_swap.c"
        "commands.c"
        "solver_algo.c"
        "ft_printf/libft/*.h"
        "ft_printf/libft/*.c"
        "ft_printf/*.h"
        "ft_printf/*.c")

set(CMAKE_C_STANDARD 99)
add_definitions(-Wall -Wextra -Werror)
add_executable(push_swap ${FILES})