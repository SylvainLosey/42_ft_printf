# Debugging

For debugging, the programm has to be compiled with the -g flag. 
_In this case use make CFLAGS=-g to build_

```make CFLAGS=-g && gcc -Wall -Wextra -Werror -g test.c libftprintf.a ```

For M1 debugging, use CodeLLDB extension. 
_In this case launch debugger with launch.json and type: "lldb"_

## Tips

- When for some reason debugger can't go into some files do a fclean

# TODO

- [ ] Check that folder structure with /src/libft is ok