# EE5203 L03 Starter Files

Copy these files into a working copy of the completed L02 Nucleo-F401RE project:

- `Core/Inc/sensor_math.h` -> project `Core/Inc`
- `Core/Inc/status_text.h` -> project `Core/Inc`
- `Core/Src/sensor_math.c` -> project `Core/Src`
- `Core/Src/status_text.c` -> project `Core/Src`

The starter implementations compile but intentionally return placeholder
results. Complete every `TODO` using the L03 lab guide. Add the fixed arrays,
debugger-visible result variables, and pipeline calls to generated `main.c` only
inside its `USER CODE` regions.

Before copying the `main.c` declarations, be able to explain them:

- `uint16_t` is an unsigned 16-bit whole-number type; it can hold 0 through
  65,535 and comes from `<stdint.h>`.
- ordinary `int` is used for the lab's small counts, indices, and capacities.
- `bool` stores `true` or `false` and comes from `<stdbool.h>`.
- `#define SAMPLE_COUNT 8` gives the preprocessor a readable name to replace
  before C compilation; it is not a variable.

Do not add these files to a different project without checking its include paths
and source folders.
