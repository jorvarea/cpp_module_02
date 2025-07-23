################################################################################
##                               COMPILATION INFO                             ##
################################################################################

NAME = a.out
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

################################################################################
##                              SOURCES AND OBJECTS                           ##
################################################################################

SRC = main.cpp Fixed.cpp

OBJECTS = $(SRC:.cpp=.o)

################################################################################
##                                    COLORS                                 ##
################################################################################

END=\033[0m
BOLD=\033[1m
GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
YELLOW=\033[33m
MAGENTA=\033[35m
TURQUOISE=\033[36m

################################################################################
##                                     RULES                                  ##
################################################################################

all : head $(NAME)

head :
	@echo " $(MAGENTA) 42MLG: $(BLUE) by jorvarea$(END)"
	@echo " $(MAGENTA) Executable: $(BLUE) $(NAME)$(END)"
	@echo " $(MAGENTA) Commands: $(BLUE)all clean fclean re$(END)"
	@echo " $(MAGENTA) 🛠   Compiler: $(BLUE) $(CC) $(CFLAGS) $(END)"

$(NAME) : $(OBJECTS)
	@$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

%.o : %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)  ✓ Compiled: $(notdir $<)$(END)"

clean :
	@echo "$(RED)$(BOLD)  CLEANING...$(END)"
	@$(RM) $(OBJECTS)

fclean : clean
	@$(RM) $(NAME)
	@echo "$(RED)  ✓  Removed $(NAME) $(END)"

re : fclean all

.PHONY: all head clean fclean re
