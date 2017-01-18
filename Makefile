CC=g++ -pthread
FLAGS= -std=c++11

INCLUDE = -I /home/clem/Documents/Argone/FlowVR/include/ \
	-I/opt/conduit/include/conduit/

Fl=/home/clem/Documents/Argone/FlowVR/lib/
LIBS=$(Fl)libflowvr-base.so $(Fl)libflowvr-mod.so /opt/conduit/lib/libconduit.so -L/opt/Boost/stage/lib/ -lrt

BIN=bin/
SRC=src/

all: $(BIN)generator $(BIN)oddFilter $(BIN)evenFilter

$(BIN)generator: $(BIN)generator.o $(BIN)generatorOut.o $(BIN)AugmentedOutport.o $(BIN)AugmentedInport.o

$(BIN)oddFilter: $(BIN)oddFilter.o $(BIN)generatorOut.o $(BIN)AugmentedOutport.o $(BIN)AugmentedInport.o

$(BIN)evenFilter: $(BIN)evenFilter.o $(BIN)generatorOut.o $(BIN)AugmentedOutport.o $(BIN)AugmentedInport.o



$(BIN)%.o: $(SRC)%.cpp
	$(CC) $(INCLUDE) $(FLAGS) -c -o $@ $<
 
$(BIN)%:$(BIN)%.o $(BIN)generatorOut.o $(BIN)AugmentedOutport.o $(BIN)AugmentedInport.o
	$(CC) $^ -o $@ $(LIBS)
	rm $<



$(BIN)generatorOut.o: $(SRC)generatorOut.cpp $(SRC)generatorOut.hpp $(SRC)DataContract.h
	$(CC) $(INCLUDE) $(FLAGS) -o $@ -c $<



$(BIN)AugmentedOutport.o: $(SRC)AugmentedOutport.cpp $(SRC)AugmentedOutport.hpp $(SRC)AugmentedPort.h
	$(CC) $(INCLUDE) $(FLAGS) -o $@ -c $<

$(BIN)AugmentedInport.o: $(SRC)AugmentedInport.cpp $(SRC)AugmentedInport.hpp $(SRC)AugmentedPort.h
	$(CC) $(INCLUDE) $(FLAGS) -o $@ -c $<


clean:
	rm $(BIN)*


##### FOR TESTING PURPOSE
test.o:test.cpp
	$(CC) $(INCLUDE) $(FLAGS) -c -o $@ $<

test: test.o #bin/generatorOut.o
	$(CC) $^ -o $@ $(LIBS)
	rm $<
#####