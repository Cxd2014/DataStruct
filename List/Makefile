CC       = gcc

objs := fanction.o main.o 

List:$(objs)
	${CC} -o List ${objs}

%.o:%.c
	${CC} -c -g $< -o $@

.PHONY : clean
clean:
	rm -f *.o List
