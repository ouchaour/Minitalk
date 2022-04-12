
CL = client

SR = server

PR = ./ft_printf/libftprintf.a

CFLAGS = -Wall -Wextra -Werror



all: $(PR) $(SR) $(CL)
	@echo -------- done ---------

$(SR): server.c $(PR)
	@gcc $(CFLAGS) server.c tools.c $(PR) -o $@

$(CL): client.c $(PR)
	@gcc $(CFLAGS) client.c tools.c $(PR) -o $@

$(PR):
	@make -C ./ft_printf

clean:
	@make clean -C ./ft_printf

fclean: clean
	@make fclean -C ./ft_printf
	rm -rf $(SR) $(CL)

re: fclean all
