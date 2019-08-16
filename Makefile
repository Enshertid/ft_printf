SRCS = main.c printf.c alphas.c digitals.c buf.c pointers.c format.c float.c

NAME = libftprintf.a




all: $(NAME)


$(NAME):
	@make -C libft
	@gcc -c -Wall -Werror -Wextra $(SRCS) -Ilibft/includes
	@ar rcs $(NAME) *.o libft/*.o
	@ranlib $(NAME)


clean:
	@make c -C libft
	@rm -f *.o


fclean: clean
	@make f -C libft
	@rm -f $(NAME)


re: fclean all



c: clean


f: fclean


g:
	@make g -C libft
	@gcc -g -Wall -Werror -Wextra $(SRCS) libft/libft.a -Ilibft/includes
	@clear


wg:
	@make g -C libft
	@gcc -g $(SRCS) libft/libft.a -Ilibft/includes
	@clear


c:
	@clear
	@make -C libft
	@gcc -Wall -Werror -Wextra $(SRCS) libft/libft.a -Ilibft/includes
	@clear
	@./a.out


wc:
	@clear
	@make -C libft
	@gcc $(SRCS) libft/libft.a -Ilibft/includes
	@clear
	@./a.out


t:
		@clear
	@make -C libft
	@gcc main_test.c digitals.c buf.c alphas.c printf.c pointers.c format.c libft/libft.a -Ilibft/includes
	@clear
	@./a.out