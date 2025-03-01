NAME	=	lib_dlst_.a

CC		=	cc
INC		=	-I inc
ERR_FLG	=	-Wall -Wextra -Werror -g3
DEP_FLG	=	-MMD -MP
AR		=	ar -crs

SRC_DIR	:=	src/
OBJ_DIR	:=	obj/

SRC_FLS	:=	\
			_dlst_clear\
			_dlst_del\
			_dlst_foreach\
			_dlst_insert_next\
			_dlst_insert_prev\
			_dlst_new\
			_dlst_new_node\
			_dlst_pop_back\
			_dlst_pop_front\
			_dlst_push_back\
			_dlst_push_front\

SRC		:=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FLS)))
OBJ		:=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FLS)))
DEP		:=	$(patsubst %.o, %.d, $(OBJ))


all		:	$(NAME)

$(NAME)	:	$(OBJ)
			$(AR) $@ $^

$(OBJ_DIR)%.o	:	$(SRC_DIR)%.c | obj_dir
			$(CC) $(ERR_FLG) $(INC) $(DEP_FLG) -c $< -o $@

obj_dir	:
			mkdir -p $(OBJ_DIR)

clean	:
			rm -rf $(OBJ_DIR)

fclean	: 	clean
			rm -f $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re

-include $(DEP)
