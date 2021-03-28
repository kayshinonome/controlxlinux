#include "controlxlinux.hpp"

using namespace std;

int main(int argc, char **argv)
{
  ofstream dest;
  ifstream dtb_file;
  ifstream initrd_file;
  ifstream kernel_file;

  uint32_t dtb_size;
  uint32_t initrd_size;
  uint32_t kernel_size;

  if (argc != 5)
  {
    cerr << "Usage: " << argv[0] << " <dtb> <initrd> <kernel> <output_file>\n";
    return EXIT_FAILURE;
  }

  dest.open(argv[4], ios::binary);
  dtb_file.open(argv[1], ios::binary);
  initrd_file.open(argv[2], ios::binary);
  kernel_file.open(argv[3], ios::binary);

  if (!dest.is_open())
  {
    cerr << "Could not open output file\n";
    return EXIT_FAILURE;
  }

  if (!dtb_file.is_open())
  {
    cerr << argv[1] << " could not be opened\n";
    return EXIT_FAILURE;
  }

  if (!initrd_file.is_open())
  {
    cerr << argv[2] << " could not be opened\n";
    return EXIT_FAILURE;
  }

  if (!kernel_file.is_open())
  {
    cerr << argv[3] << " could not be opened\n";
    return EXIT_FAILURE;
  }

  dest.write((char *)&header_data, sizeof(header_data));

  dtb_size = filesystem::file_size(argv[1]);
  initrd_size = filesystem::file_size(argv[2]);
  kernel_size = filesystem::file_size(argv[3]);

  dest.write((char *)&dtb_size, sizeof(dtb_size));
  dest.write((char *)&kernel_size, sizeof(kernel_size));
  dest.write((char *)&initrd_size, sizeof(initrd_size));

  dest << dtb_file.rdbuf();
  dest << kernel_file.rdbuf();
  dest << initrd_file.rdbuf();

  dest.close();
  dtb_file.close();
  initrd_file.close();
  kernel_file.close();
  return EXIT_SUCCESS;
}