CC       = gcc

objs := stack.o main.o 

stack:$(objs)
	${CC} -o stack ${objs}

%.o:%.c
	${CC} -c -g $< -o $@

.PHONY : clean
clean:
	rm -f *.o stack
