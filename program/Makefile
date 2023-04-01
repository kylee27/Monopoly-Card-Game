FLAGS = -pedantic-errors -std=c++11 

game.o: game.cpp header.h
	g++ $(FLAGS) -c $< 
	
file.o: file.cpp header.h
	g++ $(FLAGS) -c $<
	
main.o: main.cpp header.h
	g++ $(FLAGS) -c $<

main: game.o file.o main.o
	g++ $(FLAGS) $^ -o $@

clean:
	rm -f main game.o file.o main.o main.tgz

tar:
	tar -czvf main.tgz *.cpp *.h

.PHONY: clean tar