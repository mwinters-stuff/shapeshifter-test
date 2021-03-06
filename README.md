[![CMake](https://github.com/mwinters-stuff/shapeshifter-test/actions/workflows/cmake.yml/badge.svg)](https://github.com/mwinters-stuff/shapeshifter-test/actions/workflows/cmake.yml)

# shapeshifter-test

## Build Instructions


### Docker

To build and run in docker, the following scripts can be used.
```
./build-in-docker.sh
./run-in-docker.sh
./run-tests-in-docker.sh
```
### Windows - Native in Visual Studio Code (Community)

Should work with Visual Studio Code Community edition, with Git for Windows installed.
1. Clone the project in Visual Studio Comminuty.
2. Allow CMake to confgure.
3. Select run target. Configure run parameter for input file.
4. Run.


### Linux (Or WSL)

```
./build.sh
```

## Running tests
``` 
./build/shapeshifter-test-tests
```
or
```
./run-tests-in-docker.sh
```

## Running
```
./build/shapeshifter-test <file>
```
or 
```
./run-in-docker.sh
```
which will run for all files named ?.txt



## Editing in VSCODE

The project is setup to use a devcontainer with all requirements installed. Upon
opening the folder for the first time, vscode will ask to open in the devcontainer
you should answer "yes" and it will build the container and install the required
plugins.

From there you can use the cmake extension to set build and debug targets
and the test extension will show the tests in the test explorer.

