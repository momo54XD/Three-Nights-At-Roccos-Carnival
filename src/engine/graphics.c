// (c) 2020 MotoLegacy
// This code is licensed under MIT license (see LICENSE for details)

#include "graphics.h"
#include "window.h"
#include "game.h"

sfTexture* RoomTexture;
sfSprite* RoomSprite;

float RoomPanX = 0;
float CameraPanX = 0;

// Free and then re-init
void Graphics_UpdateRoom(gameroom_t Room) {
    free(RoomTexture);
    free(RoomSprite);

    Graphics_InitRoom(Room);
}

void Graphics_InitRoom(gameroom_t Room) {

    RoomTexture = sfTexture_createFromFile(Room.Graphic, NULL);

    // If Texture doesn't exist (TODO)
    /*if (!RoomTexture)
        Sys_Error("Failed to initialize texture %s\n", Room.Graphic);*/

    // Init Sprite, bind Texture to it
    RoomSprite = sfSprite_create();
    sfSprite_setTexture(RoomSprite, RoomTexture, sfTrue);
}

void Graphics_DrawRoom(gameroom_t Room) {
    // Initialize the Room if not already
    if (!RoomTexture || !RoomSprite)
        Graphics_InitRoom(Room);

    if (Scroll_Method == SCROLL_MANUAL)
        sfSprite_setPosition(RoomSprite, (sfVector2f) {RoomPanX, 0});
    else if (Scroll_Method == SCROLL_AUTOMATIC)
        sfSprite_setPosition(RoomSprite, (sfVector2f) {CameraPanX, 0});
    else
        sfSprite_setPosition(RoomSprite, (sfVector2f) {0, 0});

    sfRenderWindow_drawSprite(GameWindow, RoomSprite, NULL);
}