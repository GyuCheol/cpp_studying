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

	deusExMachina1->AddVehicle(new Airplane(5));
	deusExMachina1->AddVehicle(new Boat(5));
	deusExMachina1->AddVehicle(new Boatplane(5));
	deusExMachina1->AddVehicle(new Motorcycle());
	deusExMachina1->AddVehicle(new Sedan());

	Sedan* sedan1 = new Sedan();
	sedan1->AddTrailer(new Trailer(50));

	deusExMachina1->AddVehicle(sedan1);
	deusExMachina1->AddVehicle(new UBoat());

	deusExMachina1->Travel(); // 모든 운송 수단이 이동
	deusExMachina1->Travel(); // Boat, Motorcycle, 두 Sedan, UBoat가 이동
	deusExMachina1->Travel(); // Motorcycle, 두 Sedan이 이동
	deusExMachina1->Travel(); // Boat, Motorcycle, 두 Sedan이 이동
	deusExMachina1->Travel(); // UBoat만 빼고 모두 이동
	deusExMachina1->Travel(); // 어떤 운송 수단도 움직이지 않음
	deusExMachina1->Travel(); // Boat, Motorcycle, 트레일러 안 달린 Sedan, UBoat가 이동
	deusExMachina1->Travel(); // Boat Motorcycle, 두 Sedan, UBoat가 이동
	deusExMachina1->Travel(); // Airplane, Boatplane, Motorcycle, 두 Sedan 이 이동
	deusExMachina1->Travel(); // Boat, Motorcycle, 두 Sedan이 이동
	deusExMachina1->Travel(); // Boat, Motorcycle, 두 Sedan이 이동
	deusExMachina1->Travel(); // 트레일러 달린 Sedan만 이동

	while (deusExMachina1->RemoveVehicle(0))
	{

	}

	assert(deusExMachina1->GetFurthestTravelled() == NULL);

	return 0;
}