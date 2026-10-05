# EE5203 Lab 3 Starter Files

Download [`EE5203_L03_starter.zip`](EE5203_L03_starter.zip). It holds four files:

- `Core/Inc/sensor_math.h`, `Core/Src/sensor_math.c` — sensor functions
- `Core/Inc/led_reg.h`, `Core/Src/led_reg.c` — LED driver for LD2 through registers

## Add them to your project

1. Create a new CubeMX project `EE5203_L03_<studentnumber>` (NUCLEO-F401RE,
   Toolchain/IDE = CMake) and copy the lab `.vscode` template into it.
2. Open the zip. Copy the `Core` folder inside and paste it into your project
   folder. The files go to your `Core\Inc` and `Core\Src`.
3. In `CMakeLists.txt`, add the two `.c` files to `target_sources`, below
   `# Add user sources here`.

Without step 3 the build stops with an `undefined reference` error as soon as
`main.c` calls one of the new functions.

## What the starter contains

The files build, but they are not finished. Each `TODO` comment says what you
write: the missing declarations in the `.h` files and the function bodies in
the `.c` files. The Lab 3 guide has every step.
