HEADERS = h/*.h
PCHEADERS = $(HEADERS.h=(.h.gch))

SOURCES = src/*.cpp
OBJECTS = $(SOURCES:.cpp=.o)


CC = g++
CFLAGS = -Ih -c -o src/$(notdir $@)
LDFLAGS = -w -o $(EXECUTABLE)
HFLAGS = -Ih -c

EXECUTABLE = RayTracer



all : $(OBJECTS) $(EXECUTABLE)

$(OBJECTS) : $(SOURCES)
	$(CC) $(CFLAGS) $(addprefix src/, $(addsuffix .cpp, $(notdir $(basename $@))))

$(EXECUTABLE) : $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -larmadillo;


depend : $(PCHEADERS)

$(PCHEADERS): $(HEADERS)
	$(CC) $(HFLAGS) $(HEADERS)

clean :
	rm RayTracer; rm h/*.gch; rm src/*.o