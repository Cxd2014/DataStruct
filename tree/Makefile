CC       = gcc
OBJ      = tree
FLAGS    = -c -g

objs := main.o stack.o tree.o 

${OBJ}:$(objs)
	${CC} -o ${OBJ} ${objs}

%.o:%.c
	${CC} ${FLAGS} $< -o $@

.PHONY : clean
clean:
	rm -f *.o ${OBJ}
