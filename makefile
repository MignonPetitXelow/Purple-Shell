SRC = $(shell find src/ -type f -name '*.cpp')

OBJ = $(SRC:.cpp=.o)

CC = x86_64-w64-mingw64-g++
CCL = g++

NAME = PurpleShell

PACKAGES_NEEDED = build_essential

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

install:
	rm -f ~/$(NAME)
	cp $(NAME) ~/$(NAME)

packages:
	apt-get install $(PACKAGES_NEEDED)

run: re 
	./$(NAME)