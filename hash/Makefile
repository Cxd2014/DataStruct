CC       = gcc

objs := fanction.o hash.o action.o 

hash:$(objs)
	${CC} -o hash ${objs}

%.o:%.c
	${CC} -c -g $< -o $@

.PHONY : clean
clean:
	rm -f *.o hash