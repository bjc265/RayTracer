HEADERS = h/*.h
PCHEADERS = $(HEADERS.h=(.h.gch))

SOURCES = src/*.cpp
OBJECTS = $(SOURCES:.cpp=.o)


CC = g++
CFLAGS = -std=c++11 -I../h -c
LDFLAGS = -std=c++11 -w -o $(EXECUTABLE)
HFLAGS = -std=c++11 -Ih -c

EXECUTABLE = RayTracer



all : $(OBJECTS) $(EXECUTABLE)

$(OBJECTS) : $(SOURCES)
	cd src; $(CC) $(CFLAGS) $(notdir $(SOURCES))

$(EXECUTABLE) : $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -larmadillo;


depend : $(PCHEADERS)

$(PCHEADERS): $(HEADERS)
	$(CC) $(HFLAGS) $(HEADERS)

clean :
	rm RayTracer; rm h/*.gch; rm src/*.o