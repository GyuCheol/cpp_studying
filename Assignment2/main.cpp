#include <cassert>

#include "Vehicle.h"
#include "Airplane.h"
#include "Boat.h"
#include "Boatplane.h"
#include "Motorcycle.h"
#include "Sedan.h"
#include "Trailer.h"
#include "UBoat.h"
#include "DeusExMachina.h"
#include "Person.h"

using namespace assignment2;

int main()
{
	DeusExMachina* deusExMachina1 = DeusExMachina::GetInstance();

	Sedan* sedan1 = new Sedan();
	sedan1->AddTrailer(new Trailer(50));

	deusExMachina1->AddVehicle(sedan1);

	
	
	deusExMachina1->Travel();
	deusExMachina1->Travel();
	deusExMachina1->Travel();
	deusExMachina1->Travel();
	deusExMachina1->Travel();
	
	deusExMachina1->RemoveVehicle(0);

	return 0;
}