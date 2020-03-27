OBJ = devSource1.o

runfile : $(OBJ)
	 g++ -o runfile $(OBJ)

devSource1.o : devSource1.cpp
	g++ -c devSource1.cpp

clean :
	rm runfile $(OBJ)

