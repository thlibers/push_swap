# Nom du programme
NAME = push_swap

# Compilateur et flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
INCLUDES = -I./includes -I./mylibft

# Chemins
SRC_DIR = srcs
OBJ_DIR = objs
LIBFT_DIR = mylibft

# Bibliothèques
LIBFT = $(LIBFT_DIR)/libft.a

# Fichiers sources
SRCS = $(SRC_DIR)/main.c\
	$(SRC_DIR)/parsing/parsing.c\
	$(SRC_DIR)/parsing/checks.c\
	$(SRC_DIR)/operations/push.c\
	$(SRC_DIR)/operations/reverse.c\
	$(SRC_DIR)/operations/rotate.c\
	$(SRC_DIR)/operations/swap.c\
	$(SRC_DIR)/algorithm/init_stack.c\
	$(SRC_DIR)/algorithm/sort_stack.c\
	$(SRC_DIR)/algorithm/mini_sort.c\
	$(SRC_DIR)/algorithm/utils.c


# Fichiers objets
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Couleurs pour l'affichage
GREEN = \033[0;32m
RED = \033[0;31m
BLUE = \033[0;34m
RESET = \033[0m

# Règle par défaut
all: $(NAME)

# Compilation du programme principal
$(NAME): $(LIBFT) $(OBJS)
	@echo "$(BLUE)Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) compiled successfully!$(RESET)"

# Compilation des fichiers objets
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "$(BLUE)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Compilation de la libft
$(LIBFT):
	@echo "$(BLUE)Compiling libft...$(RESET)"
	@make -C $(LIBFT_DIR)
	@echo "$(GREEN)✓ libft compiled!$(RESET)"

# Nettoyage des fichiers objets
clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@echo "$(GREEN)✓ Object files cleaned!$(RESET)"

# Nettoyage complet
fclean: clean
	@echo "$(RED)Cleaning executables...$(RESET)"
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "$(GREEN)✓ Full clean completed!$(RESET)"

# Recompilation complète
re: fclean all

# Vérification des fuites mémoire
valgrind: $(NAME)
	@echo "$(BLUE)Checking for memory leaks with valgrind...$(RESET)"
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) maps/valid_map.ber

# Règles .PHONY
.PHONY: all clean fclean re test leaks valgrind
