CC=g++

CFLAGS=-c -Wall

all: hello

hello: main.o essence.o map.o
	$(CC)  main.o essence.o map.o -o game -L/home/dartheil/Desktop/2kurs/Миряха/SFML-2.3.2/lib -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp -I/home/dartheil/Desktop/2kurs/Миряха/SFML-2.3.2/include/SFML -I/home/dartheil/Desktop/2kurs/Миряха/HW/3prog/src

essence.o: essence.cpp
	$(CC) $(CFLAGS) essence.cpp -I/home/dartheil/Desktop/2kurs/Миряха/SFML-2.3.2/include/SFML -I/home/dartheil/Desktop/2kurs/Миряха/HW/3prog/src

map.o: map.cpp
	$(CC) $(CFLAGS) map.cpp -I/home/dartheil/Desktop/2kurs/Миряха/SFML-2.3.2/include/SFML -I/home/dartheil/Desktop/2kurs/Миряха/HW/3prog/src
	

clean:
	rm -rf *.o hello
