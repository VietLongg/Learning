OBJS	= Food_Ordering.o Implementation.o
SOURCE	= Food_Ordering.cpp Implementation.cpp
HEADER	= class.h library.h
OUT	= main
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

Food_Ordering.o: Food_Ordering.cpp
	$(CC) $(FLAGS) Food_Ordering.cpp 

Implementation.o: Implementation.cpp
	$(CC) $(FLAGS) Implementation.cpp 


clean:
	rm -f $(OBJS) $(OUT)

run: $(OUT)
	./$(OUT)
