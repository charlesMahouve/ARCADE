##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## to make project
##

all:
	@mkdir lib
	@make --no-print-directory -C core
	@make --no-print-directory -C games
	@make --no-print-directory -C graphicals

core:
	@make --no-print-directory -C core

games:
	@make --no-print-directory -C games

graphicals:
	@make --no-print-directory -C graphicals

clean:
	@make clean  --no-print-directory -C core
	@make clean  --no-print-directory -C games
	@make clean  --no-print-directory -C graphicals
	@rm -rf lib

fclean:
	@make fclean  --no-print-directory -C core
	@make fclean  --no-print-directory -C games
	@make fclean  --no-print-directory -C graphicals
	@rm -rf lib

re:
	@rm -rf lib
	@mkdir lib
	@make re  --no-print-directory -C core
	@make re  --no-print-directory -C games
	@make re  --no-print-directory -C graphicals