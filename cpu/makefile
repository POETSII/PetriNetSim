.PHONY: default all clean

default:
	@echo "Cannot make default"

dphil: pnsim.cpp pnsim.h
	g++ -D DPHIL pnsim.cpp -o pnsim

pipe: pnsim.cpp pnsim.h
	g++ -D PIPE pnsim.cpp -o pnsim

hype: pnsim.cpp pnsim.h
	g++ -D HYPE pnsim.cpp -o pnsim

hhype: pnsim.cpp pnsim.h
	g++ -D HHYPE pnsim.cpp -o pnsim

clean:
	rm pnsim
