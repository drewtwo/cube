#include "Particle.h"

enum Animation
{
    chaseTheDotAnimation,
    countUpAnimation,
    crazyFollowColorsAnimation,
    drawWallsAnimation,
    drawWholeCubeAnimation,
    drawXRowAnimation,
    drawYRowAnimation,
    drawZRowAnimation,
    fountainAnimation,
    planarSpinAnimation,
    tunnelAnimation,
    // planarFlopAnimation
};

int pins[] = {D0, D1, D2, D3, D4, D5, D6, D7, A0, A1, A2, A3, A4, A5, A6, A7};

int allColorsOld[27][3] =
    {
        {0, 0, 1},
        {0, 1, 0},
        {1, 0, 0}, // yellow green

        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}, // green yellow

        {0, 0, 2},
        {0, 2, 0},
        {2, 0, 0}, // purple

        {0, 2, 2},
        {2, 0, 2},
        {2, 2, 0}, // deeper purple

        {1, 1, 2},
        {1, 2, 1},
        {2, 1, 1}, // green blue

        {1, 2, 2},
        {2, 1, 2},
        {2, 2, 1}, // blue green

        {0, 1, 2},
        {1, 2, 0},
        {0, 2, 1},
        {2, 1, 0},
        {1, 0, 2},
        {2, 0, 1}, // white

        {0, 0, 0},
        {1, 1, 1},
        {2, 2, 2}};

int allColors[10][3] =
    {
        {0, 0, 1},  // yellow green
        {0, 1, 1},  // green yellow
        {1, 1, 1},  // green
        {1, 1, 2},  // green blue
        {1, 2, 2},  // blue green
        {2, 2, 2},  // blue
        {0, 2, 2},  // bluish purple
        {0, 0, 2},  // reddish purple
        {0, 0, 0},  // red
        {0, 1, 2}}; // white

int primaryColors[3][3] =
    {
        {0, 0, 0},
        {1, 1, 1},
        {2, 2, 2}};

int red[4][4][4][2] = {
    {{{D3, D7}, {A7, D3}, {A3, A7}, {D7, A3}},
     {{D2, D7}, {A6, D2}, {A2, A6}, {D7, A2}},
     {{D1, D7}, {A5, D1}, {A1, A5}, {D7, A1}},
     {{D0, D7}, {A4, D0}, {A0, A4}, {D7, A0}}},
    {{{D3, D6}, {A4, D3}, {A2, A4}, {D6, A2}},
     {{D2, D6}, {A5, D2}, {A3, A5}, {D6, A3}},
     {{D1, D6}, {A6, D1}, {A0, A6}, {D6, A0}},
     {{D0, D6}, {A7, D0}, {A1, A7}, {D6, A1}}},
    {{{D3, D5}, {A6, D3}, {A1, A6}, {D5, A1}},
     {{D2, D5}, {A7, D2}, {A0, A7}, {D5, A0}},
     {{D1, D5}, {A4, D1}, {A3, A4}, {D5, A3}},
     {{D0, D5}, {A5, D0}, {A2, A5}, {D5, A2}}},
    {{{D3, D4}, {A5, D3}, {A0, A5}, {D4, A0}},
     {{D2, D4}, {A4, D2}, {A1, A4}, {D4, A1}},
     {{D1, D4}, {A7, D1}, {A2, A7}, {D4, A2}},
     {{D0, D4}, {A6, D0}, {A3, A6}, {D4, A3}}}};

int green[4][4][4][2] = {
    {{{D3, A3}, {A7, D7}, {A3, D3}, {D7, A7}},
     {{D2, A2}, {A6, D7}, {A2, D2}, {D7, A6}},
     {{D1, A1}, {A5, D7}, {A1, D1}, {D7, A5}},
     {{D0, A0}, {A4, D7}, {A0, D0}, {D7, A4}}},
    {{{D3, A2}, {A4, D6}, {A2, D3}, {D6, A4}},
     {{D2, A3}, {A5, D6}, {A3, D2}, {D6, A5}},
     {{D1, A0}, {A6, D6}, {A0, D1}, {D6, A6}},
     {{D0, A1}, {A7, D6}, {A1, D0}, {D6, A7}}},
    {{{D3, A1}, {A6, D5}, {A1, D3}, {D5, A6}},
     {{D2, A0}, {A7, D5}, {A0, D2}, {D5, A7}},
     {{D1, A3}, {A4, D5}, {A3, D1}, {D5, A4}},
     {{D0, A2}, {A5, D5}, {A2, D0}, {D5, A5}}},
    {{{D3, A0}, {A5, D4}, {A0, D3}, {D4, A5}},
     {{D2, A1}, {A4, D4}, {A1, D2}, {D4, A4}},
     {{D1, A2}, {A7, D4}, {A2, D1}, {D4, A7}},
     {{D0, A3}, {A6, D4}, {A3, D0}, {D4, A6}}}};

int blue[4][4][4][2] = {
    {{{D3, A7}, {A7, A3}, {A3, D7}, {D7, D3}},
     {{D2, A6}, {A6, A2}, {A2, D7}, {D7, D2}},
     {{D1, A5}, {A5, A1}, {A1, D7}, {D7, D1}},
     {{D0, A4}, {A4, A0}, {A0, D7}, {D7, D0}}},
    {{{D3, A4}, {A4, A2}, {A2, D6}, {D6, D3}},
     {{D2, A5}, {A5, A3}, {A3, D6}, {D6, D2}},
     {{D1, A6}, {A6, A0}, {A0, D6}, {D6, D1}},
     {{D0, A7}, {A7, A1}, {A1, D6}, {D6, D0}}},
    {{{D3, A6}, {A6, A1}, {A1, D5}, {D5, D3}},
     {{D2, A7}, {A7, A0}, {A0, D5}, {D5, D2}},
     {{D1, A4}, {A4, A3}, {A3, D5}, {D5, D1}},
     {{D0, A5}, {A5, A2}, {A2, D5}, {D5, D0}}},
    {{{D3, A5}, {A5, A0}, {A0, D4}, {D4, D3}},
     {{D2, A4}, {A4, A1}, {A1, D4}, {D4, D2}},
     {{D1, A7}, {A7, A2}, {A2, D4}, {D4, D1}},
     {{D0, A6}, {A6, A3}, {A3, D4}, {D4, D0}}}};