program: Assignment25.o stack.o node.o
	g++ Assignment25.o stack.o node.o -o program

Assignment25.o: Assignment25.cpp stack.h
	g++ -c Assignment25.cpp

stack.o: stack.cpp node.cpp stack.h node.h
	g++ -c stack.cpp node.cpp

node.o: node.cpp node.h
	g++ -c node.cpp
