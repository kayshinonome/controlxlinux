#include "controlxlinux.hpp"

int main(int argc, char **argv)
{
	std::ofstream dest;
	uint32_t dtb_size;
	uint32_t initrd_size;
	uint32_t kernel_size;
	uint32_t buffer[4];
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << "<dtb> <initrd> <kernel>\n";
		return 1;
	}
	dest.open("controlxlinux.img", std::ios::out | std::ios::binary);
	if (dest.is_open())
	{
		std::cerr << "";
	}
	dest << header_data;
	dest << 0xDEDC0FFE;
	dtb_size = std::filesystem::file_size(argv[1]);
	initrd_size = std::filesystem::file_size(argv[2]);
	kernel_size = std::filesystem::file_size(argv[3]);

	dest << dtb_size << initrd_size << kernel_size;

	append_file(dest, argv[1], dtb_size);
	append_file(dest, argv[2], initrd_size);
	append_file(dest, argv[3], kernel_size);
	fclose(dest);
}