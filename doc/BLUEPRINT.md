# CUB3D PROJECT BLUEPRINT

## Project Overview
Create a Wolfenstein 3D-inspired raycasting game using miniLibX, implementing a first-person 3D perspective from a 2D map.

---

## Core Requirements

### Mandatory Features
- Parse `.cub` scene description files
- Render 3D view using raycasting technique
- Display different wall textures based on direction (N/S/E/W)
- Set floor and ceiling colors
- Player movement (W/A/S/D)
- Camera rotation (Left/Right arrows)
- Window management (ESC, red cross)
- Map validation (closed by walls, valid characters: 0, 1, N, S, E, W)

### Bonus Features
- Wall collisions
- Minimap system
- Doors (open/close)
- Animated sprites
- Mouse rotation

---

## Architecture Design

```
┌─────────────────────────────────────────────────────────────┐
│                        MAIN PROGRAM                         │
└─────────────────────────────────────────────────────────────┘
                              │
        ┌─────────────────────┼─────────────────────┐
        │                     │                     │
        ▼                     ▼                     ▼
┌──────────────┐     ┌──────────────┐     ┌──────────────┐
│   PARSING    │     │   GRAPHICS   │     │     GAME     │
│   MODULE     │────▶│   ENGINE     │◀────│    LOGIC     │
└──────────────┘     └──────────────┘     └──────────────┘
        │                     │                     │
        │                     │                     │
        ▼                     ▼                     ▼
  ┌──────────┐        ┌──────────┐        ┌──────────┐
  │Map Data  │        │Raycaster │        │Movement  │
  │Textures  │        │Renderer  │        │Input     │
  │Colors    │        │MLX       │        │Collision │
  └──────────┘        └──────────┘        └──────────┘
```

---

## Data Structures

### Main Game Structure
```c
typedef struct s_game
{
    void        *mlx;               // MLX instance
    void        *win;               // MLX window
    t_img       img;                // Image buffer
    t_map       map;                // Map data
    t_player    player;             // Player state
    t_textures  textures;           // All textures
    t_ray       ray;                // Raycasting data
}   t_game;
```

### Map Configuration
```c
typedef struct s_map
{
    char        **grid;             // 2D map array
    int         width;              // Map width
    int         height;             // Map height
    char        *texture_no;        // North texture path
    char        *texture_so;        // South texture path
    char        *texture_we;        // West texture path
    char        *texture_ea;        // East texture path
    int         floor_color;        // Floor RGB as int
    int         ceiling_color;      // Ceiling RGB as int
}   t_map;
```

### Player State
```c
typedef struct s_player
{
    double      pos_x;              // X position on map
    double      pos_y;              // Y position on map
    double      dir_x;              // Direction vector X
    double      dir_y;              // Direction vector Y
    double      plane_x;            // Camera plane X
    double      plane_y;            // Camera plane Y
    double      move_speed;         // Movement speed
    double      rot_speed;          // Rotation speed
}   t_player;
```

### Raycasting
```c
typedef struct s_ray
{
    double      camera_x;           // X-coordinate in camera space
    double      ray_dir_x;          // Ray direction X
    double      ray_dir_y;          // Ray direction Y
    int         map_x;              // Current map square X
    int         map_y;              // Current map square Y
    double      side_dist_x;        // Distance to next X side
    double      side_dist_y;        // Distance to next Y side
    double      delta_dist_x;       // Distance between X sides
    double      delta_dist_y;       // Distance between Y sides
    double      perp_wall_dist;     // Perpendicular wall distance
    int         step_x;             // Step direction X (-1 or 1)
    int         step_y;             // Step direction Y (-1 or 1)
    int         hit;                // Wall hit flag
    int         side;               // NS or EW wall hit
    int         line_height;        // Height of line to draw
    int         draw_start;         // Start draw position
    int         draw_end;           // End draw position
}   t_ray;
```

### Image/Texture
```c
typedef struct s_img
{
    void        *img;               // MLX image pointer
    char        *addr;              // Image data address
    int         bpp;                // Bits per pixel
    int         line_len;           // Line length
    int         endian;             // Endian
    int         width;              // Image width
    int         height;             // Image height
}   t_img;

typedef struct s_textures
{
    t_img       north;
    t_img       south;
    t_img       east;
    t_img       west;
}   t_textures;
```

---

## Module Breakdown

### 1. PARSING MODULE (`srcs/parse/`)

#### Files:
- `parse.c` - Main parsing orchestrator
- `parse_file.c` - File reading and validation
- `parse_texture.c` - Texture path parsing
- `parse_color.c` - Floor/ceiling color parsing
- `parse_map.c` - Map grid parsing
- `validate_map.c` - Map validation (walls, characters)

#### Functions:
```c
// Main parser
int     parse_scene(char *filename, t_game *game);

// File operations
int     read_config_file(char *filename, t_map *map);
int     validate_extension(char *filename);

// Element parsing
int     parse_texture_line(char *line, t_map *map);
int     parse_color_line(char *line, t_map *map);
int     parse_map_grid(int fd, t_map *map);

// Validation
int     validate_map(t_map *map);
int     check_walls_closed(t_map *map);
int     check_valid_characters(t_map *map);
int     find_player_start(t_map *map, t_player *player);
```

### 2. INITIALIZATION MODULE (`srcs/init/`)

#### Files:
- `init_game.c` - Game structure initialization
- `init_mlx.c` - MLX setup
- `init_textures.c` - Texture loading
- `init_player.c` - Player setup

#### Functions:
```c
int     init_game(t_game *game);
int     init_mlx(t_game *game);
int     load_textures(t_game *game);
void    init_player(t_player *player, char orientation);
```

### 3. RAYCASTING MODULE (`srcs/raycast/`)

#### Files:
- `raycast.c` - Main raycasting loop
- `dda.c` - DDA algorithm implementation
- `wall_calc.c` - Wall height/position calculations
- `texture_calc.c` - Texture coordinate calculations

#### Functions:
```c
void    raycast(t_game *game);
void    init_ray(t_game *game, int x);
void    perform_dda(t_game *game);
void    calculate_wall_height(t_game *game);
int     get_texture_x(t_game *game);
```

### 4. RENDERING MODULE (`srcs/render/`)

#### Files:
- `render.c` - Main rendering loop
- `draw_wall.c` - Wall drawing with textures
- `draw_floor_ceiling.c` - Floor and ceiling rendering

#### Functions:
```c
void    render_frame(t_game *game);
void    draw_vertical_line(t_game *game, int x);
void    draw_floor_ceiling(t_game *game);
void    my_mlx_pixel_put(t_img *img, int x, int y, int color);
int     get_pixel_color(t_img *img, int x, int y);
```

### 5. INPUT/GAME LOGIC MODULE (`srcs/game/`)

#### Files:
- `input.c` - Keyboard input handling
- `movement.c` - Player movement
- `rotation.c` - Camera rotation
- `collision.c` - Collision detection (bonus)

#### Functions:
```c
int     key_press(int keycode, t_game *game);
int     key_release(int keycode, t_game *game);
void    move_forward(t_game *game);
void    move_backward(t_game *game);
void    strafe_left(t_game *game);
void    strafe_right(t_game *game);
void    rotate_left(t_game *game);
void    rotate_right(t_game *game);
int     check_collision(t_game *game, double new_x, double new_y);
```

### 6. UTILITY MODULE (`srcs/utils/`)

#### Files:
- `error.c` - Error handling and messages
- `cleanup.c` - Memory cleanup
- `utils.c` - Helper functions
- `math_utils.c` - Math utilities

#### Functions:
```c
void    error_exit(char *message, t_game *game);
void    cleanup_game(t_game *game);
void    free_map(t_map *map);
int     rgb_to_int(int r, int g, int b);
int     close_game(t_game *game);
```

---

## File Structure

```
cub3d/
├── Makefile
├── BLUEPRINT.md
├── README.md
│
├── includes/
│   ├── cub3d.h          # Main header
│   ├── parse.h          # Parsing structures/functions
│   ├── render.h         # Rendering structures/functions
│   └── game.h           # Game logic structures/functions
│
├── srcs/
│   ├── main.c
│   │
│   ├── parse/
│   │   ├── parse.c
│   │   ├── parse_file.c
│   │   ├── parse_texture.c
│   │   ├── parse_color.c
│   │   ├── parse_map.c
│   │   └── validate_map.c
│   │
│   ├── init/
│   │   ├── init_game.c
│   │   ├── init_mlx.c
│   │   ├── init_textures.c
│   │   └── init_player.c
│   │
│   ├── raycast/
│   │   ├── raycast.c
│   │   ├── dda.c
│   │   ├── wall_calc.c
│   │   └── texture_calc.c
│   │
│   ├── render/
│   │   ├── render.c
│   │   ├── draw_wall.c
│   │   └── draw_floor_ceiling.c
│   │
│   ├── game/
│   │   ├── input.c
│   │   ├── movement.c
│   │   ├── rotation.c
│   │   └── collision.c (bonus)
│   │
│   └── utils/
│       ├── error.c
│       ├── cleanup.c
│       ├── utils.c
│       └── math_utils.c
│
├── maps/
│   ├── valid/
│   │   ├── simple.cub
│   │   ├── complex.cub
│   │   └── test.cub
│   └── invalid/
│       ├── no_walls.cub
│       ├── invalid_char.cub
│       └── multiple_players.cub
│
├── textures/
│   ├── north_wall.xpm
│   ├── south_wall.xpm
│   ├── east_wall.xpm
│   └── west_wall.xpm
│
└── libft/
```

---

## Implementation Phases

### Phase 1: Setup & Parsing (Week 1)
**Goal:** Read and validate .cub files

**Tasks:**
1. Set up project structure (Makefile, headers)
2. Implement file reading with GNL
3. Parse texture paths (NO, SO, EA, WE)
4. Parse colors (F, C) - convert RGB to int
5. Parse map grid into 2D array
6. Validate map:
   - Check for walls enclosing the map
   - Validate characters (0, 1, N, S, E, W)
   - Find player starting position
   - Handle spaces in map
7. Error handling for all parsing errors

**Test:** Parser should accept/reject maps correctly

---

### Phase 2: MLX Initialization & Basic Window (Week 1-2)
**Goal:** Create window and image buffer

**Tasks:**
1. Initialize MLX
2. Create window (recommended: 1280x720 or 1920x1080)
3. Create image buffer for rendering
4. Set up basic pixel manipulation
5. Load textures into t_img structures
6. Test texture loading
7. Implement clean exit (ESC, red cross)

**Test:** Window opens, displays solid colors, closes properly

---

### Phase 3: Player & Camera Setup (Week 2)
**Goal:** Initialize player position and direction

**Tasks:**
1. Extract player start position from map
2. Set direction vector based on N/S/E/W
3. Calculate camera plane (perpendicular to direction)
4. Define movement and rotation speeds

**Initial values:**
- If player faces North (N): dir_x = 0, dir_y = -1
- Camera plane should be perpendicular to direction
- Typical FOV: 66 degrees (plane length ~0.66)

**Test:** Player initializes at correct position with correct orientation

---

### Phase 4: Raycasting Algorithm (Week 2-3)
**Goal:** Implement core raycasting

**Tasks:**
1. Understand DDA (Digital Differential Analysis) algorithm
2. For each screen column (x):
   - Calculate ray direction
   - Initialize DDA variables
   - Perform DDA (step through map until wall hit)
   - Calculate perpendicular wall distance
   - Calculate wall height
   - Determine which texture to use (N/S/E/W)
3. Handle fisheye correction (use perpendicular distance)

**Key Algorithm:**
```
For each x from 0 to screen_width:
    1. Calculate ray position and direction
    2. Calculate which box of map we're in
    3. Calculate length of ray from current position to next x or y-side
    4. Perform DDA:
       - Jump to next map square in x or y direction
       - Check if ray has hit a wall
    5. Calculate distance to wall
    6. Calculate wall height on screen
    7. Draw textured vertical line
```

**Resources:**
- [Lode's Raycasting Tutorial](https://lodev.org/cgtutor/raycasting.html)
- Classic DDA algorithm

**Test:** Display untextured walls with correct perspective

---

### Phase 5: Texture Mapping (Week 3)
**Goal:** Apply textures to walls

**Tasks:**
1. Determine which wall side was hit (N/S/E/W)
2. Calculate exact hit point on wall
3. Calculate texture X coordinate
4. For each pixel in vertical line:
   - Calculate texture Y coordinate
   - Get pixel color from texture
   - Draw to screen
5. Ensure textures display correctly for all sides

**Test:** Textured walls display correctly from all angles

---

### Phase 6: Floor & Ceiling (Week 3)
**Goal:** Fill floor and ceiling with colors

**Tasks:**
1. For each pixel above wall: draw ceiling color
2. For each pixel below wall: draw floor color
3. Optimize by using larger draw operations

**Test:** Floor and ceiling display in correct colors

---

### Phase 7: Movement & Rotation (Week 3-4)
**Goal:** Implement player controls

**Tasks:**
1. Implement key hooks (key_press, key_release)
2. Forward movement (W):
   - New position = current + (direction × speed)
3. Backward movement (S):
   - New position = current - (direction × speed)
4. Strafe left (A):
   - Use perpendicular to direction
5. Strafe right (D):
   - Use perpendicular to direction (opposite)
6. Rotate left (←):
   - Rotate direction and plane vectors
7. Rotate right (→):
   - Rotate direction and plane vectors

**Rotation matrix:**
```c
old_dir_x = dir_x;
dir_x = dir_x * cos(angle) - dir_y * sin(angle);
dir_y = old_dir_x * sin(angle) + dir_y * cos(angle);
// Same for plane vector
```

**Test:** Player can move and rotate smoothly

---

### Phase 8: Final Touches & Polish (Week 4)
**Goal:** Optimize and fix bugs

**Tasks:**
1. Fix any rendering glitches
2. Optimize rendering (if needed)
3. Ensure proper memory cleanup
4. Test with various maps
5. Check norm compliance
6. Handle edge cases

**Test:** Program runs smoothly without leaks or crashes

---

### Phase 9: Bonus Features (Optional)
**Goal:** Implement bonus features

**Priority order:**
1. **Wall collision** (easiest) - Don't let player walk through walls
2. **Minimap** - Display 2D map overlay
3. **Mouse rotation** - Rotate camera with mouse movement
4. **Doors** - Add door tiles that can open/close
5. **Animated sprites** - Add sprite rendering

**Test:** Each bonus feature works independently

---

## Key Algorithms

### 1. DDA (Digital Differential Analysis)
```c
void    perform_dda(t_game *game)
{
    int hit = 0;

    while (hit == 0)
    {
        // Jump to next map square in x or y direction
        if (game->ray.side_dist_x < game->ray.side_dist_y)
        {
            game->ray.side_dist_x += game->ray.delta_dist_x;
            game->ray.map_x += game->ray.step_x;
            game->ray.side = 0; // X-side (East or West)
        }
        else
        {
            game->ray.side_dist_y += game->ray.delta_dist_y;
            game->ray.map_y += game->ray.step_y;
            game->ray.side = 1; // Y-side (North or South)
        }

        // Check if ray has hit a wall
        if (game->map.grid[game->ray.map_y][game->ray.map_x] == '1')
            hit = 1;
    }
}
```

### 2. Perpendicular Wall Distance
```c
// Avoid fisheye effect by using perpendicular distance
if (game->ray.side == 0)
    game->ray.perp_wall_dist = (game->ray.map_x - game->player.pos_x
        + (1 - game->ray.step_x) / 2) / game->ray.ray_dir_x;
else
    game->ray.perp_wall_dist = (game->ray.map_y - game->player.pos_y
        + (1 - game->ray.step_y) / 2) / game->ray.ray_dir_y;
```

### 3. Wall Height Calculation
```c
int line_height = (int)(SCREEN_HEIGHT / game->ray.perp_wall_dist);

int draw_start = -line_height / 2 + SCREEN_HEIGHT / 2;
if (draw_start < 0)
    draw_start = 0;

int draw_end = line_height / 2 + SCREEN_HEIGHT / 2;
if (draw_end >= SCREEN_HEIGHT)
    draw_end = SCREEN_HEIGHT - 1;
```

### 4. Texture Coordinate Calculation
```c
// Calculate value of wall_x (where exactly wall was hit)
double wall_x;
if (side == 0)
    wall_x = pos_y + perp_wall_dist * ray_dir_y;
else
    wall_x = pos_x + perp_wall_dist * ray_dir_x;
wall_x -= floor(wall_x);

// X coordinate on texture
int tex_x = (int)(wall_x * (double)TEX_WIDTH);
if ((side == 0 && ray_dir_x > 0) || (side == 1 && ray_dir_y < 0))
    tex_x = TEX_WIDTH - tex_x - 1;

// Y coordinate on texture (per pixel)
double step = 1.0 * TEX_HEIGHT / line_height;
double tex_pos = (draw_start - SCREEN_HEIGHT / 2 + line_height / 2) * step;

for (int y = draw_start; y < draw_end; y++)
{
    int tex_y = (int)tex_pos & (TEX_HEIGHT - 1);
    tex_pos += step;
    int color = texture[TEX_HEIGHT * tex_y + tex_x];
    // Draw color at (x, y)
}
```

---

## Map File Format (.cub)

### Example:
```
NO ./textures/north_wall.xpm
SO ./textures/south_wall.xpm
WE ./textures/west_wall.xpm
EA ./textures/east_wall.xpm

F 220,100,0
C 225,30,0

        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```

### Parsing Rules:
1. Texture lines: identifier + path (NO, SO, WE, EA)
2. Color lines: identifier + R,G,B (F, C)
3. Map must be last
4. Map can have empty lines before it
5. Spaces are valid in map
6. Map must be closed by walls (1)
7. Only one player start position (N, S, E, W)

---

## Testing Strategy

### Unit Tests:
1. **Parser tests:**
   - Valid maps
   - Invalid maps (unclosed, invalid chars, multiple players)
   - Color parsing (valid RGB, out of range)
   - Texture paths (valid, invalid, missing files)

2. **Raycasting tests:**
   - Different player positions
   - Different orientations
   - Edge cases (corners, diagonal walls)

3. **Movement tests:**
   - All directions
   - Wall collision
   - Rotation accuracy

### Integration Tests:
1. Load map → render → move → exit
2. Test with subject example maps
3. Test with complex maps
4. Memory leak tests (valgrind)

### Performance:
- Aim for 60 FPS (frame time < 16ms)
- Profile if slow (optimize DDA, texture access)

---

## Common Pitfalls & Tips

### Pitfalls:
1. **Fisheye effect:** Always use perpendicular distance, not Euclidean
2. **Texture orientation:** Check if texture needs to be flipped
3. **Map validation:** Spaces in maps are valid - handle them
4. **Memory leaks:** Free all allocated memory (map, textures, MLX)
5. **Norm:** Keep functions under 25 lines

### Tips:
1. Start simple: get basic raycasting working before textures
2. Use Lode's tutorial as reference
3. Test frequently with simple maps
4. Use debug visualizations (print ray data, map state)
5. Handle MLX events in a loop hook for smooth rendering

---

## Resources

### Must-Read:
- [Lodev Raycasting Tutorial](https://lodev.org/cgtutor/raycasting.html)
- [Ray-Casting Tutorial For Game Development](https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/)

### MLX Documentation:
- [MLX Documentation (42Docs)](https://harm-smits.github.io/42docs/libs/minilibx)
- Your school's MLX man pages

### Math:
- Vector rotation formulas
- Trigonometry basics (sin, cos for rotation)
- Linear algebra (vectors, dot product)

---

## Compilation & Execution

### Compile:
```bash
make
```

### Run:
```bash
./cub3D maps/valid/simple.cub
```

### Clean:
```bash
make fclean
```

---

## Norminette Compliance

- All functions ≤ 25 lines
- All files ≤ 5 functions
- Maximum function parameters: 4
- No forbidden functions
- Proper header guards
- No global variables (except those allowed)

---

## Deliverables Checklist

### Mandatory:
- [ ] Makefile (all, clean, fclean, re, bonus)
- [ ] Parse .cub files correctly
- [ ] Validate maps (walls, characters)
- [ ] Render 3D view with raycasting
- [ ] Wall textures (N/S/E/W)
- [ ] Floor and ceiling colors
- [ ] Movement (W/A/S/D)
- [ ] Rotation (←/→)
- [ ] Clean exit (ESC, red cross)
- [ ] No memory leaks
- [ ] No crashes
- [ ] Norm compliant

### Bonus:
- [ ] Wall collision
- [ ] Minimap
- [ ] Doors
- [ ] Animated sprites
- [ ] Mouse rotation

---

## Getting Started

### Immediate Next Steps:
1. Read this entire blueprint
2. Study Lode's raycasting tutorial (Parts 1-4)
3. Fix existing parsing code bugs
4. Set up proper header files
5. Create test maps (simple → complex)
6. Implement complete parser with validation
7. Test parser thoroughly before moving to graphics

Good luck! 🎮
