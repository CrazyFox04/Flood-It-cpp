# Flood-It Project

This project is a Flood-It game implementation in C++ using modern CMake. It consists of various modules such as model,
console view, QT view and utils, each responsible for different aspects of the game.

## Prerequisites

- CMake 3.29 or higher
- C++ compiler with C++20 support
- QT6 

## Build

This project uses modern CMake to manage the build process.
The project is composed of <u>**3 libraries**</u> that can be built separately and a main executable that links all the
libraries together.

### <u style="color: red">First step</u> : Configure build directory

We need to create a build directory and configure the project using CMake.
It's in this directory that the build files will be generated and where the following other build commands need to be
executed.

```bash
mkdir build
cd build
cmake ..
```

### Build all

Now that the project is configured, we can build the project by running the following command in the build directory:

```bash
cmake --build .
```

### Build each library separately

If you want to build each library separately, you can do so by specifying the target name.
Please note that all target will not compile the library and not link it with the main executable.

As the build all command, it needs to be executed in the build directory.
> The libraries format are OS specific !

#### Model package

```bash
cmake --build . --target Flood-It-model 
```

#### Utils package

```bash
cmmake --build . --target Flood-It-utils
```

#### View package

```bash
cmake --build . --target Flood-It-view
```

#### Main executable

```bash
cmake --build . --target Flood-It 
```
The main executable will link all the libraries together. 
If you compile it with Qt, the main executable will automatically launch the QT view.
In this case, you can specify -c to launch the console view instead.

## Run

### Main executable

After building the project, you can run the main executable by running the following command:

```bash
cd src/
./Flood-It
```

## Documentation

Documentation for the project can be generated using Doxygen. Follow these steps to generate the documentation:

1) Ensure Doxygen is installed on your system.
2) Run the following commands from the root directory of the project :

```bash
cd build/
cmake --build . --target doc_doxygen
```

3) Open the generated documentation by opening the following file in a web browser.

> Note : The documentation is generated in __the "documentation/gen_doxygen/html" folder__ <u>in the root directory</u>
> of the project.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE.txt) file for details.
