output: main.o
	g++ main.o -o output

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm main.o output