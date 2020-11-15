SRCS = struct_client.cpp ft_strcmp.cpp
OBJS = ${SRCS:.cpp=.o}
NAME = test
FLAGS = -Wall -Wextra -Werror

all : 	
	@g++ ${FLAGS} ${SRCS} -o ${NAME}
	@${NAME}
clean : 
	@Remove-Item ${NAME}
re : clean all
     