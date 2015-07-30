CC       = gcc
OBJ      = doubleList

objs := doubleList.o main.o 

${OBJ}:$(objs)
	${CC} -o ${OBJ} ${objs}

%.o:%.c
	${CC} -c -g $< -o $@

.PHONY : clean
clean:
	rm -f *.o ${OBJ}
