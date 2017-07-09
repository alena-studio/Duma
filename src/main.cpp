/*
*
*   Copyright (C) Alena Studio - 2017
*   Author : Akadream
*   Project : Duma
*
*
*/

#include <iostream>
#include <SDL.h>
#include <SDL_mixer.h>

#include "Font.h"
#include "Sprite.h"
#include "Mixer.h"
#include "Sound.h"
#include "Windows.h"
#include "Donjon.h"
#include "Titlescreen.h"

using namespace std;

int main(int argc, char** argv)
{
    if(argc && argv); // Permet d'éviter une erreur/warning;

    freopen("CON", "w", stdout);
    freopen("CON", "r", stdin);
    freopen("CON", "w", stderr);

    cout << "Demarrage\n";
    // Settings of the main window
    int currentWindow = 0;
    int title_index = 0;
    string title = "Duma - Create your own dungeon";
    string logo = "Logo.png";

    SDL_Rect cursorPosition;

    Donjon dungeon;

    Sprite background(Titlescreen::getInstance()->getBackgroundFileName());
    Sprite cursor("database/pictures/selection.png");

    // To control the loop
    SDL_Event event;

    if(Mixer::getInstance()->loadAudio() < 0) {
        printf("Erreur !");
        exit(-1);
    }

    if(Font::getInstance()->loadFont() < 0) {
        printf("Erreur !");
        exit(-1);
    }

    Sound titleMusic("TitleScreen.wav");
    Sound titleSound("Cursor.wav");
    titleMusic.play();

    if(Windows::getInstance()->createWindow(title, logo, 800, 640, 32) < 0) {
        printf("Erreur !");
        exit(-1);
    }

    while(Windows::getInstance()->getCreated())
    {
        // Wait an event
        SDL_WaitEvent(&event);

        // Check events type
        switch (event.type)
        {
            case SDL_QUIT:
                Windows::getInstance()->close();
                break;
            case SDL_MOUSEBUTTONDOWN:
                if(currentWindow == 2) {
                    switch(event.button.button) {
                        case SDL_BUTTON_LEFT:
                            dungeon.setRoom((event.button.x / 32), (event.button.y / 32), 1);
                            cout << "X : " << event.button.x / 32 << "\nY : " << event.button.y / 32 << "\n";
                            break;
                        case SDL_BUTTON_RIGHT:
                            dungeon.setRoom((event.button.x / 32), (event.button.y / 32), 0);
                            cout << "X : " << event.button.x / 32 << "\nY : " << event.button.y / 32 << "\n";
                            break;
                    }
                }
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        switch(currentWindow) {
                            case 0:
                                Windows::getInstance()->close();
                                break;
                            case 1:
                                Windows::getInstance()->setWindow(title, 800, 640);
                                currentWindow = 0;
                                break;
                            case 2:
                                Windows::getInstance()->setWindow(title, 800, 640);
                                currentWindow = 0;
                                break;
                            case 3:
                                Windows::getInstance()->setWindow(title, 800, 640);
                                currentWindow = 0;
                                break;
                        }
                        break;
                    case SDLK_e:
                        if(currentWindow == 0) {
                            Windows::getInstance()->setWindow("Alena Studio - Editor", 1500, 800);
                            currentWindow = 2;
                            //Map newMap("Donjon 1", "Dungeon_A5.png");
                        }
                        break;
                    case SDLK_d:
                        if(currentWindow == 2) {
                            dungeon.console();
                        }
                        break;
                    case SDLK_UP:
                        if(currentWindow == 0) {
                          title_index--;
                            if(title_index < 0) {
                                title_index = 3;
                            }
                        }
                        break;
                    case SDLK_DOWN:
                        if(currentWindow == 0) {
                            title_index++;
                            if(title_index > 3) {
                                title_index = 0;
                            }
                        }
                        break;
                    case SDLK_RETURN:
                        if(currentWindow == 0) {
                            switch(title_index) {
                                case 0:
                                    Windows::getInstance()->setWindow("Alena Studio - Play", 1500, 800);
                                    currentWindow = 1;
                                    break;
                                case 1:
                                    Windows::getInstance()->setWindow("Duma - Editeur de donjon", 320, 320);
                                    currentWindow = 2;
                                    titleMusic.pause();
                                    //Map newMap("Donjon 1", "Dungeon_A5.png");
                                    break;
                                case 2:
                                    Windows::getInstance()->setWindow("Alena Studio - Options ", 1500, 800);
                                    currentWindow = 3;
                                    // Options
                                    break;
                                case 3:
                                    Windows::getInstance()->close();
                                    break;
                            }
                        }
                        break;
                }
                break;
        }
        // Position du curseur
        switch(title_index) {
            case 0:
                cursorPosition.x = 300;
                cursorPosition.y = 378;
                break;
            case 1:
                cursorPosition.x = 300;
                cursorPosition.y = 431;
                break;
            case 2:
                cursorPosition.x = 300;
                cursorPosition.y = 486;
                break;
            case 3:
                cursorPosition.x = 300;
                cursorPosition.y = 541;
                break;
        }

        // Images a afficher
        Windows::getInstance()->fillRect();
        switch(currentWindow) {
            case 0:
                background.display(0, 0, Windows::getInstance()->getWindow());
                cursor.display(cursorPosition.x, cursorPosition.y, Windows::getInstance()->getWindow());
                break;
            case 2:
                dungeon.display();
                break;
        }
        Windows::getInstance()->refreshWindow();
    } // End of the main loop

    // End of SDL
    background.free();
    cursor.free();
    dungeon.free();
    titleMusic.free();
    Mixer::getInstance()->exit();
    Windows::getInstance()->exit();

    return EXIT_SUCCESS;
}
