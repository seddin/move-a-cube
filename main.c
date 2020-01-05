/*******************************************************************************************
*
*   A simple game
*
********************************************************************************************/

#include "raylib.h"
#include "stdio.h"

int main (void) {
    const int sw = 512;
    const int sh = 512;

    InitWindow (sw, sh, "test v0.0001");

    // 3D Camera
    Camera3D camera = { 0 };
    camera.position = (Vector3){ 0.0f, 10.0f, 10.0f };
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 60.0f;
    camera.type = CAMERA_PERSPECTIVE;

    Vector3 cubePosition = { 2.0f, 1.0f, 0.0f };

    SetTargetFPS (60);

    while (!WindowShouldClose()) {
        
        if (cubePosition.x < 10.0 || cubePosition.z < 10) {
            if (IsKeyDown(KEY_RIGHT) && cubePosition.x < 4.0f) {
                cubePosition.x += 0.1f;
            }
            if (IsKeyDown(KEY_LEFT) && cubePosition.x > -4.0f) {
                cubePosition.x -= 0.1f;
            }
            if (IsKeyDown(KEY_UP) && cubePosition.z > -4.0f) {
                cubePosition.z -= 0.1f;
            }
            if (IsKeyDown(KEY_DOWN) && cubePosition.z < 4.5f) {
                cubePosition.z += 0.1f;
            }
        }

        BeginDrawing ();
            ClearBackground(GetColor(0x40abf2ff));

            BeginMode3D(camera);
                DrawCube(cubePosition, 1.0f, 1.2f, 1.0f, RED);
                DrawCubeWires(cubePosition, 1.0f, 1.2f, 1.0f, MAROON);
                DrawPlane((Vector3){ 0.0f, 0.0f, 0.0f }, (Vector2){ 10.0f, 10.0f}, GetColor(0x359c21ff));
            EndMode3D ();

            DrawText ("3d!", 10, 40, 20, DARKGREEN);
            DrawFPS (10, 10);
        EndDrawing ();
    }

    CloseWindow ();

    return 0;
}