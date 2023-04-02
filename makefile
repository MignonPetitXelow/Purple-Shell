SRC = $(shell find src/ -type f -name '*.cpp')

OBJ = $(SRC:.cpp=.o)

CC = x86_64-w64-mingw64-g++
CCL = g++

NAME = PurpleShell

PACKAGES_NEEDED = build-essential

all: $(NAME) 

$(NAME): $(OBJ)
	$(CCL) -o $(NAME) $(OBJ)
	
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

commit: clean
	git add .
	git commit -a

packages:
	apt-get install $(PACKAGES_NEEDED)

run: re 
	./$(NAME)

install: packages re
	rm -f /bin/$(NAME)
	mv ./$(NAME) /bin/$(NAME)