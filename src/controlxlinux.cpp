#include "controlxlinux.hpp"

using namespace std;

int main(int argc, char **argv)
{
  // Output file
  ofstream dest;

  // The dtb file being used
  ifstream dtb_file;

  // The initrd file being used
  ifstream initrd_file;

  // The kernel file being used
  ifstream kernel_file;

  // The size of the dtb
  uint32_t dtb_size;

  // The size of the initrd
  uint32_t initrd_size;

  // The size of the kernel
  uint32_t kernel_size;

  // Make sure the correct number of arguments are here
  if (argc != 5)
  {
    cerr << "Usage: " << argv[0] << " <dtb> <initrd> <kernel> <output_file>\n";
    return EXIT_FAILURE;
  }
  
  if (strcmp("about", argv[1]) == 0)
  {
    cout << "controlxlinux Copyright (C) 2021 Tsuki Superior\n";
    cout << "This program comes with ABSOLUTELY NO WARRANTY\n";
    cout << "This is free software, and you are welcome to redistribute it\n";
    cout << "under certain conditions.\n";
    return EXIT_FAILURE;
  }
      
  // Open all of the file
  dest.open(argv[4], ios::binary);
  dtb_file.open(argv[1], ios::binary);
  initrd_file.open(argv[2], ios::binary);
  kernel_file.open(argv[3], ios::binary);

  // Make sure all those files actually compiled
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

  // Write the initial header data
  dest.write((char *)&header_data, sizeof(header_data));

  // Get the sizes of the files
  dtb_size = filesystem::file_size(argv[1]);
  initrd_size = filesystem::file_size(argv[2]);
  kernel_size = filesystem::file_size(argv[3]);

  // Write the sizes
  dest.write(reinterpret_cast<char *>(&dtb_size), sizeof(dtb_size));
  dest.write(reinterpret_cast<char *>(&kernel_size), sizeof(kernel_size));
  dest.write(reinterpret_cast<char *>(&initrd_size), sizeof(initrd_size));

  // Write the files
  dest << dtb_file.rdbuf();
  dest << kernel_file.rdbuf();
  dest << initrd_file.rdbuf();

  // Close the files
  dest.close();
  dtb_file.close();
  initrd_file.close();
  kernel_file.close();
  return EXIT_SUCCESS;
}
