ROOTS = raytracer ray scene shader surface intersection dummylight dummyshader dummysurface dummycamera camera
HEAD_ONLY = light color
SOURCE_ONLY = main


CC = g++
CFLAGS = -c
LDFLAGS =
HEADERS = $(addsuffix .h, $(ROOTS) $(HEAD_ONLY))
PCHEADERS = $(addsuffix .gch, $(HEADERS))
SOURCES = $(addsuffix .cpp, $(ROOTS) $(SOURCE_ONLY))
OBJECTS = $(addsuffix .o, $(ROOTS) $(SOURCE_ONLY))
EXECUTABLE = RayTracer

all : $(SOURCES) $(EXECUTABLE)

$(OBJECTS) : $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -c -w

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ -larmadillo -w

depend :
	$(CC) $(HEADERS)

clean :
	rm $(EXECUTABLE) $(OBJECTS) $(PCHEADERS)