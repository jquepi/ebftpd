CXX = g++
CXXFLAGS = -Wall -Wextra -g -ggdb -DDEBUG
LIBS = -lcryptopp -lboost_thread -lboost_regex -lgnutls -lboost_serialization -lboost_iostreams -lboost_system -lpthread
INCLUDE = -I.

OBJECTS = \
	main.o \
  ftp/listener.o \
	fs/owner.o \
	fs/status.o \
	fs/file.o \
	fs/directory.o \
	acl/acl.o \
	acl/user.o \
	util/logger.o \
	util/verify.o \
	util/passwd.o \
	util/descriptor.o \
	util/error.o \
	util/endpoint.o \
	util/exception.o \
	util/ip.o \
	util/resolver.o \
	util/ssl.o \
	util/tcpclient.o \
	util/tcpserver.o 

all: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(OBJECTS) $(LIBS) -o ftpd

strip:
	@strip -s ftpd

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $(INCLUDE) $*.cpp -o $*.o

clean:
	@rm -f *.o *.d */*.o */*.d
	@rm -f ftpd
