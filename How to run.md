# How to run the code?

# If you have CLion...

Just create a new project from existing source code and add the source code from /ParticleToy, copy the content of the CMakeLists.txt and build and run the application. Everything should work.

# If you do not have CLion ...

- Either install it and proceed from previous steps...

- Manually install CMake
-- Download the source from [their download page](https://cmake.org/download/), by the time of writing 3.8.2 is the latest version. You can get it from [here](https://cmake.org/files/v3.8/cmake-3.8.2.tar.gz)
--Extract the tar, run ```./bootstrap``` this will test the environment and create the make file for CMake
--Make the application by running ```make -j4``` and next install it by running ```sudo make install```
--You can test whether the installation has succeeded by running the command ```cmake --version```. This should show the value 3.8.2
--Now go back to the source code directory and run ```cmake CMakeLists.txt```




