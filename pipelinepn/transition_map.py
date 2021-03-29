import sys

steps = 1
if(len(sys.argv)>1):
	steps = int(sys.argv[1])

localPlaces = 9*steps
transitions = 8*steps + 2

print('#ifndef _PPN_TMAP_H_')
print('#define _PPN_TMAP_H_\n')

print('#define MAX_PLACES %d' % (1<<(localPlaces+4).bit_length()))
print('#define MAX_TRANSITIONS %d' % (1<<(transitions+1).bit_length()))
print('#define MAX_OUTMAP 4\n')

print('const uint16_t localPlaces = %d;' % localPlaces)
print('const uint8_t outPlaces = 4;')
print('const uint16_t transitions = %d;\n' % transitions)

print('const Transition tmap[MAX_TRANSITIONS] = {')
print('\t{1, 0, %d},' % (localPlaces+2))
print('\t{1, 1, %d},' % (localPlaces+3))
i=2

def pipe(i):
	print('\t{1, %d, %d},' % (i, i-2))
	print('\t{1, %d, %d},' % (i+1, i-1))
	return i+2

def sync(i):
	print('\t{2, %d, %d, %d},' % (i, i-2, i-1))
	print('\t{3, %d, %d, %d},' % (i, i+1, i+2))
	return i+3

for s in range(steps):
	i = pipe(pipe(sync(pipe(i))))

print('\t{0}\n};\n')
print('#endif')
