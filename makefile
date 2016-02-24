HEADERS = h/*.h
PCHEADERS = $(addprefix bin/,$(notdir $(HEADERS.h=.h.gch)))

SOURCES = src/*.cpp
OBJECTS = $(addprefix bin/,$(notdir $(SOURCES:.cpp=.o)))


CC = g++
CFLAGS = -Ibin -Ih -c
LDFLAGS = -Ibin -w -o $(EXECUTABLE)
HFLAGS = -Ih -c

EXECUTABLE = RayTracer



all : $(OBJECTS) $(EXECUTABLE)

$(OBJECTS) : $(SOURCES) $(PCHEADERS)
	$(CC) $(CFLAGS) $(SOURCES); mv *.o bin

$(EXECUTABLE) : $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -larmadillo;


depend : $(PCHEADERS)

$(PCHEADERS): $(HEADERS)
	$(CC) $(HFLAGS) $(HEADERS); ls; mv h/*.h.gch bin

clean :
	rm bin/*