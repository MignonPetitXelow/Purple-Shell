SRC = $(shell find src/ -type f -name '*.cpp')

OBJ = $(SRC:.cpp=.o)

CC = x86_64-w64-mingw64-g++
CCL = g++

NAME = PurpleShell

all: $(NAME)

$(NAME): $(OBJ)
	$(CCL) -o $(NAME) $(OBJ)
	
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

commit:
	git add .
	git commit -a

run: re 
	./$(NAME)