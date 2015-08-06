CC       = gcc
OBJ      = tree

objs := stack.o tree.o main.o

${OBJ}:$(objs)
	${CC} -o ${OBJ} ${objs}

%.o:%.c
	${CC} -c -g $< -o $@

.PHONY : clean
clean:
	rm -f *.o ${OBJ}
