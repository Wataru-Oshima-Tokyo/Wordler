.PHONY: clean

all:
	g++ --std=c++17 -Wfatal-errors main.cpp dictionary.cpp -o wordler

clean:
	rm -rf *.o wordler