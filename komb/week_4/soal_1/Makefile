# Target to compile the C++ program
soal_1 : soal_1.o
	g++ soal_1.o -o soal_1

# Target to compile the object file
soal_1 . o : soal_1.cpp
	g++ -c soal_1.cpp -o soal_1.o

# Target to run the program
run : soal_1
	./soal_1

# Target to clean up compiled files
clean :
	rm -f soal_1.o soal_1