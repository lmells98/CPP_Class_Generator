NAME		= GenClass
SRCS		= srcs
INCS		= includes
OBJS		= objs

SRC_FILES	= $(wildcard $(SRCS)/*.cpp)
OBJ_FILES	= $(addprefix $(OBJS)/, $(notdir $(SRC_FILES:.cpp=.o)))

CC			= g++ -std=c++98 -Wall -Werror -Wextra -g
HDR			= -I$(INCS)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(HDR) $^ -o $@

$(OBJS)/%.o: $(SRCS)/%.cpp | $(OBJS)
	$(CC) $(HDR) -c $< -o $@

$(OBJS):
	@mkdir $@

fclean:
	@rm -rf $(OBJS)
	@rm -rf $(NAME)

re: fclean all