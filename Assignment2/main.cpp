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

	deusExMachina1->Travel(); // ��� ��� ������ �̵�
	deusExMachina1->Travel(); // Boat, Motorcycle, �� Sedan, UBoat�� �̵�
	deusExMachina1->Travel(); // Motorcycle, �� Sedan�� �̵�
	deusExMachina1->Travel(); // Boat, Motorcycle, �� Sedan�� �̵�
	deusExMachina1->Travel(); // UBoat�� ���� ��� �̵�
	deusExMachina1->Travel(); // � ��� ���ܵ� �������� ����
	deusExMachina1->Travel(); // Boat, Motorcycle, Ʈ���Ϸ� �� �޸� Sedan, UBoat�� �̵�
	deusExMachina1->Travel(); // Boat Motorcycle, �� Sedan, UBoat�� �̵�
	deusExMachina1->Travel(); // Airplane, Boatplane, Motorcycle, �� Sedan �� �̵�
	deusExMachina1->Travel(); // Boat, Motorcycle, �� Sedan�� �̵�
	deusExMachina1->Travel(); // Boat, Motorcycle, �� Sedan�� �̵�
	deusExMachina1->Travel(); // Ʈ���Ϸ� �޸� Sedan�� �̵�

	while (deusExMachina1->RemoveVehicle(0))
	{

	}

	assert(deusExMachina1->GetFurthestTravelled() == NULL);

	return 0;
}