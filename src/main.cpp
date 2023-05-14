/* ***********************************************************
	main.cpp
	
	The main entry point of the code.
	
	This file forms part of the qbRayTrace project as described
	in the series of videos on the QuantitativeBytes YouTube
	channel.
	
	This code corresponds specifically to Episode 2 of the series,
	which may be found here:
	https://youtu.be/KBK6g6RFgdA
	
	The whole series may be found on the QuantitativeBytes 
	YouTube channel at:
	www.youtube.com/c/QuantitativeBytes
	
	GPLv3 LICENSE
	Copyright (c) 2021 Michael Bennett
	
***********************************************************/

#include "RayTracer.h"

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[]) {
	// Imposta lo standard C++17
#if __cplusplus < 20170
	static_assert(false, "È richiesto almeno lo standard C++17 per compilare questo codice.");

#endif

	RayTrace theApp;
	return theApp.OnExecute();
}
