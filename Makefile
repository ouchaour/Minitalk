# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yait-ouc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/20 00:37:14 by yait-ouc          #+#    #+#              #
#    Updated: 2022/04/20 00:37:20 by yait-ouc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CL = client

CLB = client_bonus

SR = server

SRB = server_bonus

PR = ./ft_printf/libftprintf.a

CFLAGS = -Wall -Wextra -Werror



all: $(PR) $(SR) $(CL)
	@echo -------- done ---------

bonus: $(PR) $(SRB) $(CLB)
	@echo -------- bonus_done ---------

$(SR): server.c $(PR)
	@gcc $(CFLAGS) server.c tools.c $(PR) -o $@

$(CL): client.c $(PR)
	@gcc $(CFLAGS) client.c tools.c $(PR) -o $@

$(SRB): server_bonus.c $(PR)
	@gcc $(CFLAGS) server_bonus.c tools.c $(PR) -o $@

$(CLB): client_bonus.c $(PR)
	@gcc $(CFLAGS) client_bonus.c tools.c $(PR) -o $@



$(PR):
	@make -C ./ft_printf

clean:
	@make clean -C ./ft_printf

fclean: clean
	@make fclean -C ./ft_printf
	rm -rf $(SR) $(CL) $(SRB) $(CLB)

re: fclean all
