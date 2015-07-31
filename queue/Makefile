CC       = gcc
OBJ      = queue

objs := queue.o main.o 

${OBJ}:$(objs)
	${CC} -o ${OBJ} ${objs}

%.o:%.c
	${CC} -c -g $< -o $@

.PHONY : clean
clean:
	rm -f *.o ${OBJ}
