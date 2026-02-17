# Cub3D

Cub3D is a small raycasting engine written in C, inspired by early 90's games like Wolfenstein 3D.
Given a `.cub` scene file (textures, colors, and a 2D map), the program renders a real-time pseudo-3D view using the classic DDA raycasting technique.

## What is this project?

- A minimal 3D-like renderer built from a 2D grid map.
- A parsing project: read a custom configuration format (`.cub`), validate it, and convert it to internal data structures.
- A graphics/event-loop project using MiniLibX (Linux) to display an interactive window.

## Features

- Textured walls (N/S/E/W textures)
- Floor and ceiling colors
- Real-time movement and rotation
- Collision with walls
- Minimap overlay

## How it works (high level)

1. **Parsing**
	- Reads the `.cub` file.
	- Extracts texture paths (`NO`, `SO`, `WE`, `EA`).
	- Parses floor/ceiling RGB colors (`F`, `C`).
	- Builds a 2D `map_array` and checks validity (characters, single player start, closed by walls, etc.).

2. **Initialization**
	- Initializes MiniLibX, creates a window and an off-screen image buffer.
	- Loads XPM textures.
	- Initializes the player position/direction and the camera plane.

3. **Rendering loop (each frame)**
	- Clears the image buffer.
	- For each screen column, casts a ray into the map:
	  - Computes ray direction from the camera plane.
	  - Runs **DDA** to step from grid cell to grid cell until a wall is hit.
	  - Computes perpendicular wall distance to avoid the “fish-eye” effect.
	  - Projects wall slice height on screen and samples the correct texture.
	- Draws the minimap.
	- Applies movement/rotation based on pressed keys (with collision checks).
	- Displays the final image with `mlx_put_image_to_window`.

## Controls

- `W` / `S`: move forward / backward
- `A` / `D`: strafe left / right
- `Left Arrow` / `Right Arrow`: rotate
- `Esc` or window close button: quit

## Build & Run

### Requirements (Linux)

- `gcc`
- X11 development libraries (commonly: `libx11-dev`, `libxext-dev`)
- MiniLibX (already included in this repository under `mlx/`)

### Compile

```bash
make
```

This produces the `cub3D` binary.

### Run

```bash
./cub3D map.cub
```

You can also try:

```bash
./cub3D little.cub
```

## The .cub file format

A `.cub` file contains:

1. **Texture paths** for each wall direction:
	- `NO path/to/north_texture.xpm`
	- `SO path/to/south_texture.xpm`
	- `WE path/to/west_texture.xpm`
	- `EA path/to/east_texture.xpm`

2. **Colors** for ceiling and floor (RGB):
	- `C R,G,B`
	- `F R,G,B`

3. **The map**, using these characters:
	- `1` wall
	- `0` empty space
	- `N`, `S`, `E`, `W` player start + initial direction (must appear exactly once)
	- spaces are treated as “outside” and must not create openings

Example:

```text
NO textures/NO_texture.xpm
SO textures/SO_texture.xpm
WE textures/WE_texture.xpm
EA textures/EA_texture.xpm

C 40, 24, 120
F 1, 50, 32

11111
10N01
10001
11111
```

## Notions & concepts covered

- **Raycasting** (one ray per screen column)
- **DDA grid traversal** (efficient wall hit detection)
- **Vector math & trigonometry** (direction vectors, camera plane, rotation)
- **Perspective projection** (wall slice height from perpendicular distance)
- **Texture mapping** (choosing texture by hit side and sampling pixels)
- **Event-driven programming** (key press/release hooks + render loop)
- **Low-level graphics** (manual pixel writes to an image buffer)
- **Robust parsing & validation** (custom file format, error handling)
- **Memory management in C** (allocation, cleanup on error/exit)

## Project layout (quick map)

- `src/parsing/`: `.cub` parsing and validations
- `src/raycasting/`: raycasting + textured wall rendering
- `src/map_2d/`: window creation, main loop, inputs
- `src/bonus/`: minimap overlay
- `libft/`: custom C utility library
- `mlx/`: MiniLibX (Linux)

## Notes

- The window size is currently set to 1920x1080 in the code.
- Textures are expected to be XPM files.