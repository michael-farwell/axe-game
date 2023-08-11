#include "raylib.h"

int main() {
    // Window dimensions
    int width{800};
    int height{450};
    InitWindow(width, height, "Axe Game");

    // Circle params
    int circle_x{200};
    int circle_y{200};
    int circle_radius{25};

    // Circle edges
    int l_circle_x{circle_x - circle_radius};
    int r_circle_x{circle_x + circle_radius};
    int u_circle_y{circle_y - circle_radius};
    int b_circle_y{circle_y + circle_radius};

    // Rectangle params
    int rect_x{400};
    int rect_y{0};
    int direction{10};
    int rect_w{50};
    int rect_h{50};

    // Rectangle edges
    int l_rect_x{rect_x};
    int r_rect_x{rect_x + rect_w};
    int u_rect_y{rect_y};
    int b_rect_y{rect_y + rect_h};

    bool collision_with_axe = (b_rect_y >= u_circle_y) &&
                              (u_rect_y <= b_circle_y) &&
                              (r_rect_x >= l_circle_x) &&
                              (l_rect_x <= r_circle_x);

    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);

        if (collision_with_axe) {
            DrawText("Game Over!", 350, 200, 20, RED);
        } else {
            // Update edges
            l_circle_x = circle_x - circle_radius;
            r_circle_x = circle_x + circle_radius;
            u_circle_y = circle_y - circle_radius;
            b_circle_y = circle_y + circle_radius;

            l_rect_x = rect_x;
            r_rect_x = rect_x + rect_w;
            u_rect_y = rect_y;
            b_rect_y = rect_y + rect_h;

            // Check axe collision
            collision_with_axe = (b_rect_y >= u_circle_y) &&
                                 (u_rect_y <= b_circle_y) &&
                                 (r_rect_x >= l_circle_x) &&
                                 (l_rect_x <= r_circle_x);

            // Game logic begins
            DrawCircle(circle_x, circle_y, static_cast<float>(circle_radius), BLUE);
            DrawRectangle(rect_x, rect_y, rect_w, rect_h, RED);

            rect_y += direction;
            if (rect_y > height || rect_y < 0) {
                direction = -direction;
            }

            if (IsKeyDown(KEY_D) && circle_x < width) {
                circle_x += 10;
            }

            if (IsKeyDown(KEY_A) && circle_x > 0) {
                circle_x -= 10;
            }

            if (IsKeyDown(KEY_W) && circle_y > 0) {
                circle_y -= 10;
            }

            if (IsKeyDown(KEY_S) && circle_y < height) {
                circle_y += 10;
            }

        }


        // Game logic ends
        EndDrawing();
    }
}
