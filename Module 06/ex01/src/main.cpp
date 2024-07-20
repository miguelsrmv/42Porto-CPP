#include "Serializer.hpp"

int
main (void)
{
	Data data_structure;

	std::cout << "Data address: " << &data_structure << std::endl;
	std::cout << data_structure << std::endl;

	uintptr_t serialized_data = Serializer::serialize (&data_structure);
	std::cout << std::endl;
	Serializer::deserialize (serialized_data);

	std::cout << "Data address: " << &data_structure << std::endl;
	std::cout << data_structure << std::endl;
}
