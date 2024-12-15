NAME := a.out
DNAME := $(NAME)_debug

HEADER :=
SOURCES :=

# Header
HEADER += fractol.h 
HEADER += libft.h
HEADER += 

# Sources
SOURCES += main.c  
SOURCES += calc.c
SOURCES += color.c
SOURCES += event.c
SOURCES += init.c
SOURCES += msg.c
SOURCES += render.c
SOURCES += utils.c

SOURCES += libft/ft_bzero.c
SOURCES += libft/ft_atoi.c
SOURCES += libft/ft_calloc.c
SOURCES += libft/ft_isalnum.c
SOURCES += libft/ft_isalpha.c
SOURCES += libft/ft_isascii.c
SOURCES += libft/ft_isdigit.c
SOURCES += libft/ft_isprint.c
SOURCES += libft/ft_itoa.c
SOURCES += libft/ft_lstadd_back.c
SOURCES += libft/ft_lstadd_front.c
SOURCES += libft/ft_lstclear.c
SOURCES += libft/ft_lstdelone.c
SOURCES += libft/ft_lstiter.c
SOURCES += libft/ft_lstlast.c
SOURCES += libft/ft_lstmap.c
SOURCES += libft/ft_lstnew.c
SOURCES += libft/ft_lstsize.c
SOURCES += libft/ft_memchr.c
SOURCES += libft/ft_memcmp.c
SOURCES += libft/ft_memcpy.c
SOURCES += libft/ft_memmove.c
SOURCES += libft/ft_memset.c
SOURCES += libft/ft_putchar_fd.c
SOURCES += libft/ft_putendl_fd.c
SOURCES += libft/ft_putnbr_fd.c
SOURCES += libft/ft_putstr_fd.c
SOURCES += libft/ft_split.c
SOURCES += libft/ft_strchr.c
SOURCES += libft/ft_strdup.c
SOURCES += libft/ft_striteri.c
SOURCES += libft/ft_strjoin.c
SOURCES += libft/ft_strlcat.c
SOURCES += libft/ft_strlcpy.c
SOURCES += libft/ft_strlen.c
SOURCES += libft/ft_strmapi.c
SOURCES += libft/ft_strncmp.c
SOURCES += libft/ft_strnstr.c
SOURCES += libft/ft_strrchr.c
SOURCES += libft/ft_strtrim.c
SOURCES += libft/ft_substr.c
SOURCES += libft/ft_tolower.c
SOURCES += libft/ft_toupper.c

SOURCES_PREFIX = src/

LIBRARY_DIR = lib
HEADER_DIR = include
BUILD_DIR = build

CC := cc
CFLAGS := -Wall -Wextra -Werror -O2
IFLAGS := -I$(HEADER_DIR)
LFLAGS := -L$(LIBRARY_DIR) -lmlx_Linux -lXext -lX11 -lm
DFLAGS := -fdiagnostics-color=always -g3 -fsanitize=address

SOURCES := $(addprefix $(SOURCES_PREFIX),$(SOURCES))
OBJS := $(SOURCES:.c=.o)
DOBJS := $(SOURCES:.c=_d.o)

MLX_HEADER := $(addprefix $(HEADER_DIR)/,mlx.h)
MLX_LIB := $(addprefix $(LIBRARY_DIR)/,libmlx.a)

HEADER_FILES := $(addprefix $(HEADER_DIR)/,$(HEADER))

define install_minilibx
	current_dir=$(shell pwd); \
	lib_dir="$${current_dir}/lib"; \
	include_dir="$${current_dir}/include"; \
	mlx_repo_dir="$${current_dir}/temp_____/minilibx-linux"; \
	build_flag_file="$${lib_dir}/libmlx_Linux.a"; \
	build_header_file="$${include_dir}/mlx.h"; \
	\
	if [ -f "$$build_flag_file" ] && [ -f "$$build_header_file" ]; then \
		echo "libmlx_Linux.a and mlx.h already exist. ";  \
		exit 0;  \
	fi; \
	\
	mkdir -p "$$lib_dir" "$$include_dir" temp_____; \
	cd temp_____ || exit;\
	\
	if [ ! -d "minilibx-linux" ]; then \
		git clone https://github.com/42Paris/minilibx-linux.git; \
	fi; \
	\
	cd minilibx-linux || exit; \
	make; \
	\
	mv *.a "$$lib_dir/"; \
	mv mlx.h "$$include_dir/"; \
	\
	cd "$$current_dir" || exit; \
	rm -rf temp_____; \
	\
	echo "libmlx_Linux.a and mlx.h build complete.;"
endef

.PHONY: all
all: init $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $@

%.o: %.c $(HEADER_FILES)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

%_d.o: %.c $(HEADER_FILES)
	$(CC) $(CFLAGS) $(DFLAGS) $(IFLAGS) -c $< -o $@

.PHONY: init
init: $(MLX_HEADER) $(MLX_LIB)

$(MLX_HEADER) $(MLX_LIB): 
	$(install_minilibx)

.PHONY: clean
clean: 
	rm -f $(OBJS) $(DOBJS) $(DNAME) $(MLX_HEADER)
	rm -rf $(LIBRARY_DIR) $(BUILD_DIR)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all

.PHONY: debug
debug: $(DNAME)

$(DNAME): $(DOBJS)
	$(CC) $(CFLAGS) $(DFLAGS) $(DOBJS) $(LFLAGS) -o $@