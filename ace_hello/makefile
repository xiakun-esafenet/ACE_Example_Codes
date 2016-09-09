#make file
##
##
C++:=g++
GCC:=gcc
CCFLAG:=-g 
CCINCLUDE:=-I$(ACE_ROOT)
LIBPATH=$(ACE_ROOT)/ace
SOFLAG:=-g -shared -fPIC
LDFLAG := -Wl,-rpath,. $(CCINCLUDE) -L. -L$(LIBPATH) -lACE -lpthread  -lstdc++ 
LDCLIENTFLAG := -lace_hello_client
LDSERVERFLAG := -lace_hello_server

vpath %.cpp .
vpath %.h .
vpath %.so .

LIBS:=libace_hello_client.so libace_hello_server.so


BINS:=ace_hello_client ace_hello_server



all:$(LIBS) $(BINS)


libace_hello_client.so: ace_hello_client.cpp
	$(C++) $(SOFLAG) -o $@ $^ $(CCINCLUDE)

libace_hello_server.so: ace_hello_server.cpp 
	$(C++) $(SOFLAG) -o $@ $^ $(CCINCLUDE) 

ace_hello_client:ace_hello_reactor_client.cpp
	$(C++) $(CCFLAG) $(LDFLAG) $(LDCLIENTFLAG) -o $@ $^

ace_hello_server:ace_hello_reactor_server.cpp
	$(C++) $(CCFLAG) $(LDFLAG) $(LDSERVERFLAG) -o $@ $^


.PHONY : clean
clean:
	rm -f *.so 
	rm ace_hello_client ace_hello_server

