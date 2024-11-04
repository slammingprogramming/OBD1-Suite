# Installation Guide for Universal OBD-I Debugging Suite

Follow these instructions to install the Universal OBD-I Debugging Suite on Windows, macOS, and Linux.

## 1. Windows Installation

1. Install CMake from https://cmake.org/download/ and MinGW from https://www.mingw-w64.org/.
2. Open a terminal and navigate to the project directory.
3. Run the following commands to configure and build:

   - `mkdir build`
   - `cd build`
   - `cmake .. -G "MinGW Makefiles"`
   - `mingw32-make`

4. The compiled executable will be located in the `build` directory.

## 2. macOS Installation

1. Ensure that Homebrew is installed (https://brew.sh/).
2. Install the required tools by running:

   - `brew install cmake gcc`

3. In the project directory, execute the following commands to build:

   - `mkdir build`
   - `cd build`
   - `cmake ..`
   - `make`

4. The compiled executable will be located in the `build` directory.

## 3. Linux Installation

1. Update your package list and install `build-essential` and `cmake` by running:

   - `sudo apt update`
   - `sudo apt install build-essential cmake`

2. Navigate to the project directory and run the following to build:

   - `mkdir build`
   - `cd build`
   - `cmake ..`
   - `make`

3. The compiled executable will be located in the `build` directory.

---

After completing these steps, you should have a working executable of the Universal OBD-I Debugging Suite in the `build` directory, ready for use. If you encounter any issues, please consult the project’s GitHub repository for troubleshooting tips or create an issue for support.
