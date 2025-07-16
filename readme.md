# Obstacle Assault

## General

The point of the game is to use C++ logic in UE5 to create a simple platformer with moving obstacles.

Player can move using standard `WASD`, jump with `space bar`, crouch with `Ctrl` (hold) or `C` (toggle).
Player can also interact with some objects using `left mouse button` or `E`.

Player has 3 lives to reach the end goal. If player falls off the platform, they lose a life and returned to the latest checkpoint.
If they lose all lives, they must start from the beginning.

Player character was based on the blueprint from the Learning Kit, with minor adjustments (e.g. flight was removed to not make the game too simple).

## Input

The game uses old input settings using Action and Axis mappings.

The Learning Kit brings the controls setup for gamepad and touch interface, but they were not tested and aren't meant to be used.

## Versioning

Unreal Engine 5.5.4 was used.

The following packages were used in the creation of this game:

- Unreal Learning Kit