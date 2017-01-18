CC=g++
FLAGS= -std=c++11

INCLUDE = -I /home/clem/Documents/Argone/FlowVR/include/ \
	-I/opt/conduit/include/conduit/

Fl=/home/clem/Documents/Argone/FlowVR/lib/
LIBS=$(Fl)libflowvr-base.so $(Fl)libflowvr-mod.so /opt/conduit/lib/libconduit.so



#FOR TESTING

%.o: %.cpp
	$(CC) $(INCLUDE) $(FLAGS) -c -o $@ $<

%:%.o myUtils.o
	$(CC) $^ -o $@ $(LIBS)


myUtils.o: myUtils.cpp myUtils.hpp
	$(CC) $(INCLUDE) $(FLAGS) -o $@ -c $<
