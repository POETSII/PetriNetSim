#include "dphil.h"

#include <tinsel.h>
#include <POLite.h>

typedef PThread<
		DPhilDevice,
		DPhilState,
		None,
		DPhilMessage
	> DPhilThread;

int main()
{
	DPhilThread* thread = (DPhilThread*) tinselHeapBaseSRAM();
	thread->run();
	return 0;
}
