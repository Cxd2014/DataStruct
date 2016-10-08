CC       = gcc
OBJ      = calculate
FLAGS    = -c -g

objs := main.o tree.o 

${OBJ}:$(objs)
	${CC} -o ${OBJ} ${objs}

%.o:%.c
	${CC} ${FLAGS} $< -o $@

.PHONY : clean
clean:
	rm -f *.o ${OBJ}
