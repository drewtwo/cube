/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#line 1 "/Users/drewowl/workspace/cube/cube/src/cube.ino"
#include "Particle.h"

void setup();
void loop();
void mainLoop();
int drawWalls(String cmd);
int drawColumn(String cmd);
int drawXRow(String cmd);
int drawYRow(String cmd);
int nextColorCube(String cmd);
int lightIt(String cmd);
void drawLed(int x, int y, int z, int color);
void resetLed(int x, int y, int z, int color);
int drawLineAPI(String cmd);
int nextColor(int color);
int toggleAnimation(String cmd);
void planarSpin();
int planarFlop3D(String cmd);
int chaseTheDotOG(String cmd);
void chaseTheDot();
void drawLine(int color, int startx, int starty, int startz, int endx, int endy, int endz);
int roundClosest(int numerator, int denominator);
void swapint(int &one, int &two);
int countUp2(String cmd);
int countUp(String cmd);
void set_pins(int low_pin, int high_pin);
void reset_pins(int low_pin, int high_pin);
void reset_all_pins();
#line 3 "/Users/drewowl/workspace/cube/cube/src/cube.ino"
int pins[] = {D0, D1, D2, D3, D4, D5, D6, D7, A0, A1, A2, A3, A4, A5, A6, A7};
unsigned long microDelay = 100;
int loopDelay = 50;
bool continuePattern = true;

int color = 0;
int xpos = 0;
int ypos = 0;
int zpos = 0;

int grid[4][4][4] = {
    {{3, 3, 3, 3},
     {3, 3, 3, 3},
     {3, 3, 3, 3},
     {3, 3, 3, 3}},
    {{3, 3, 3, 3},
     {3, 3, 3, 3},
     {3, 3, 3, 3},
     {3, 3, 3, 3}},
    {{3, 3, 3, 3},
     {3, 3, 3, 3},
     {3, 3, 3, 3},
     {3, 3, 3, 3}},
    {{3, 3, 3, 3},
     {3, 3, 3, 3},
     {3, 3, 3, 3},
     {3, 3, 3, 3}}};

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

enum Animation
{
  countUpAnimation,
  planarSpinAnimation,
  planarFlopAnimation,
  nextColorCubeAnimation,
  chaseTheDotAnimation,
  columnAnimation,
  drawYRowAnimation,
  drawXRowAnimation,
  drawWallsAnimation
};

Animation currentAnimation = chaseTheDotAnimation;

void setup()
{
  Particle.function("countUp", countUp);
  Particle.function("countUp2", countUp2);
  Particle.function("lightIt", lightIt);
  Particle.function("drawLineAPI", drawLineAPI);
  // Particle.function("planarSpin", planarSpin);
  Particle.function("toggleAnimation", toggleAnimation);
  Particle.function("planarFlop3D", planarFlop3D);
  Particle.function("drawColumn", drawColumn);
  Particle.function("nextColorCube", nextColorCube);
}

void loop()
{
  switch (currentAnimation)
  {
  case countUpAnimation:
    countUp("");
    break;
  case planarSpinAnimation:
    planarSpin();
    break;
  case planarFlopAnimation:
    planarFlop3D("");
    break;
  case nextColorCubeAnimation:
    nextColorCube("");
    break;
  case chaseTheDotAnimation:
    chaseTheDot();
    break;
  case columnAnimation:
    drawColumn("");
    break;
  case drawXRowAnimation:
    drawXRow("");
    break;
  case drawYRowAnimation:
    drawYRow("");
    break;
  case drawWallsAnimation:
    drawWalls("");
    break;
  }
  for (int i = 0; i < 40; i++)
  {
    mainLoop();
  }
}

void mainLoop()
{
  for (int x = 0; x < 4; x++)
  {
    for (int y = 0; y < 4; y++)
    {
      for (int z = 0; z < 4; z++)
      {
        if (grid[x][y][z] < 3)
        {
          drawLed(x, y, z, grid[x][y][z]);
          delayMicroseconds(microDelay);
          resetLed(x, y, z, grid[x][y][z]);
        }
      }
    }
  }
}

int drawWalls(String cmd)
{
  ypos = ypos == 0 ? ypos = 3 : ypos - 1;
  if (ypos == 3)
  {
    color = random(0, 2);
    if (grid[0][ypos][0] == color)
    {
      color = color >= 2 ? color - 1 : color + 1;
    }
  }
  for (int x = 0; x < 4; x++)
  {
    for (int z = 0; z < 4; z++)
    {
      grid[x][ypos][z] = color;
    }
  }
  return 1;
}

int drawColumn(String cmd)
{
  int x = random(0, 4);
  int y = random(0, 4);
  int color = random(0, 4);
  if (sscanf(cmd, "%d, %d, %d", &x, &y, &color) == 3)
  {
    for (int z = 0; z < 4; z++)
    {
      grid[x][y][z] = color;
    }
  }
  else
  {
    for (int z = 0; z < 4; z++)
    {
      grid[x][y][z] = color;
    }
  }
  return 1;
}

int drawXRow(String cmd)
{
  int y = random(0, 4);
  int z = random(0, 4);
  int color = random(0, 4);
  if (sscanf(cmd, "%d, %d, %d", &y, &z, &color) == 3)
  {
    for (int x = 0; x < 4; x++)
    {
      grid[x][y][z] = color;
    }
  }
  else
  {
    for (int x = 0; x < 4; x++)
    {
      grid[x][y][z] = color;
    }
  }
  return 1;
}

int drawYRow(String cmd)
{
  int x = random(0, 4);
  int z = random(0, 4);
  int color = random(0, 4);
  if (sscanf(cmd, "%d, %d, %d", &x, &z, &color) == 3)
  {
    for (int y = 0; y < 4; y++)
    {
      grid[x][y][z] = color;
    }
  }
  else
  {
    for (int y = 0; y < 4; y++)
    {
      grid[x][y][z] = color;
    }
  }
  return 1;
}

int nextColorCube(String cmd)
{
  for (int x = 0; x < 4; x++)
  {
    for (int y = 0; y < 4; y++)
    {
      for (int z = 0; z < 4; z++)
      {
        grid[x][y][z] = nextColor(grid[x][y][z]);
      }
    }
  }
  return 1;
}

int lightIt(String cmd)
{
  int x = 0;
  int y = 0;
  int z = 0;
  int color = 0;
  if (sscanf(cmd, "%d, %d, %d, %d", &x, &y, &z, &color) == 4)
  {
    if (grid[x][y][z] < 3)
    {
      resetLed(x, y, z, grid[x][y][z]);
    }
    // drawLed(x, y, z, color);
    grid[x][y][z] = color;
  }
  return 1;
}

void drawLed(int x, int y, int z, int color)
{
  int pin1 = 0;
  int pin2 = 0;
  switch (color)
  {
  case 0:
    pin1 = red[x][y][z][0];
    pin2 = red[x][y][z][1];
    set_pins(pin1, pin2);
    break;
  case 1:
    pin1 = green[x][y][z][0];
    pin2 = green[x][y][z][1];
    set_pins(pin1, pin2);
    break;
  case 2:
    pin1 = blue[x][y][z][0];
    pin2 = blue[x][y][z][1];
    set_pins(pin1, pin2);
    break;
  }
}

void resetLed(int x, int y, int z, int color)
{
  int pin1 = 0;
  int pin2 = 0;
  switch (color)
  {
  case 0:
    pin1 = red[x][y][z][0];
    pin2 = red[x][y][z][1];
    reset_pins(pin1, pin2);
    break;
  case 1:
    pin1 = green[x][y][z][0];
    pin2 = green[x][y][z][1];
    reset_pins(pin1, pin2);
    break;
  default:
    pin1 = blue[x][y][z][0];
    pin2 = blue[x][y][z][1];
    reset_pins(pin1, pin2);
    break;
  }
}

int drawLineAPI(String cmd)
{
  int startx = 0;
  int starty = 0;
  int startz = 0;
  int endx = 0;
  int endy = 0;
  int endz = 0;
  int color = 0;
  if (sscanf(cmd, "%d, %d, %d, %d, %d, %d, %d", &startx, &starty, &startz, &endx, &endy, &endz, &color) == 7)
  {
    drawLine(color, startx, starty, startz, endx, endy, endz);
  }
  return 1;
}

int nextColor(int color) { return (color + 1) % 3; }

int toggleAnimation(String cmd)
{
  continuePattern = !continuePattern;
  return 1;
}

void planarSpin()
{
  for (int i = 0; i < 100; i++)
  {
    int spinsPerColor = 20; // a spin is actually half a revolution
    for (int i = 0; i < spinsPerColor; i++)
    {
      for (int x = 0; x < 3; x++)
      {
        drawLine(color, x, 0, 0, 3 - x, 3, 0);
        drawLine(color, x, 0, 1, 3 - x, 3, 1);
        drawLine(color, x, 0, 2, 3 - x, 3, 2);
        drawLine(color, x, 0, 3, 3 - x, 3, 3);
      }
      for (int y = 0; y < 3; y++)
      {
        drawLine(color, 3, y, 0, 0, 3 - y, 0);
        drawLine(color, 3, y, 1, 0, 3 - y, 1);
        drawLine(color, 3, y, 2, 0, 3 - y, 2);
        drawLine(color, 3, y, 3, 0, 3 - y, 3);
      }
      for (int i = 0; i < 100; i++)
      {
        mainLoop();
      }
    }
    color = nextColor(color);
  }
}

int planarFlop3D(String cmd)
{
  int color = 0;
  int animationSpeed = 50;
  if (sscanf(cmd, "%d", &animationSpeed) == 1)
  {
    Log.info("delayTime=%d", animationSpeed);
  }
  while (continuePattern)
  {

    for (int y = 3; y > 0; y--)
    {
      for (int z = 0; z < 4; z++)
        drawLine(color, 0, 3, z, 3, y, z);
      delay(animationSpeed);
    }
    for (int x = 3; x > 0; x--)
    {
      for (int z = 0; z < 4; z++)
        drawLine(color, 0, 3, z, x, 0, z);
      delay(animationSpeed);
    }

    for (int x = 0; x < 3; x++)
    {
      for (int y = 0; y < 4; y++)
        drawLine(color, 0, y, 0, x, y, 3);
      delay(animationSpeed);
    }
    for (int z = 3; z > 0; z--)
    {
      for (int y = 0; y < 4; y++)
        drawLine(color, 0, y, 0, 3, y, z);
      delay(animationSpeed);
    }

    for (int z = 0; z < 3; z++)
    {
      for (int x = 0; x < 4; x++)
        drawLine(color, x, 0, 0, x, 3, z);
      delay(animationSpeed);
    }
    for (int y = 3; y > 0; y--)
    {
      for (int x = 0; x < 4; x++)
        drawLine(color, x, 0, 0, x, y, 3);
      delay(animationSpeed);
    }

    for (int y = 0; y < 3; y++)
    {
      for (int z = 0; z < 4; z++)
        drawLine(color, 3, 0, z, 0, y, z);
      delay(animationSpeed);
    }
    for (int x = 0; x < 3; x++)
    {
      for (int z = 0; z < 4; z++)
        drawLine(color, 3, 0, z, x, 3, z);
      delay(animationSpeed);
    }

    for (int x = 3; x > 0; x--)
    {
      for (int y = 0; y < 4; y++)
        drawLine(color, 3, y, 3, x, y, 0);
      delay(animationSpeed);
    }
    for (int z = 0; z < 3; z++)
    {
      for (int y = 0; y < 4; y++)
        drawLine(color, 3, y, 3, 0, y, z);
      delay(animationSpeed);
    }

    for (int z = 3; z > 0; z--)
    {
      for (int x = 0; x < 4; x++)
        drawLine(color, x, 3, 3, x, 0, z);
      delay(animationSpeed);
    }
    for (int y = 0; y < 3; y++)
    {
      for (int x = 0; x < 4; x++)
        drawLine(color, x, 3, 3, x, y, 0);
      delay(animationSpeed);
    }
    color = nextColor(color);
  }
  return 1;
}

int chaseTheDotOG(String cmd)
{
  int color = 0;
  int animationSpeed = 200;
  if (sscanf(cmd, "%d", &animationSpeed) == 1)
  {
    Log.info("delayTime=%d", animationSpeed);
  }

  int xpos = 0;
  int ypos = 0;
  int zpos = 0;

  while (continuePattern)
  {
    switch (random(0, 6))
    {
    case 0:
      if (xpos > 0)
      {
        xpos--;
        break;
      }
      else
        color = nextColor(color);
    case 1:
      if (xpos < 3)
      {
        xpos++;
        break;
      }
      else
      {
        color = nextColor(color);
      }
      xpos--;
      break;

    case 2:
      if (ypos > 0)
      {
        ypos--;
        break;
      }
      else
      {
        color = nextColor(color);
      }

    case 3:
      if (ypos < 3)
      {
        ypos++;
        break;
      }
      else
      {
        color = nextColor(color);
      }
      ypos--;
      break;

    case 4:
      if (zpos > 0)
      {
        zpos--;
        break;
      }
      else
      {
        color = nextColor(color);
      }
    case 5:
      if (zpos < 3)
      {
        zpos++;
        break;
      }
      else
      {
        color = nextColor(color);
      }
      zpos--;
      break;
    }
    drawLed(color, xpos, ypos, zpos);
    delay(animationSpeed);
    reset_all_pins();
  }
  return 1;
}

void chaseTheDot()
{
  switch (random(0, 6))
  {
  case 0:
    if (xpos > 0)
    {
      xpos--;
      break;
    }
    else
      color = random(0, 4);
  case 1:
    if (xpos < 3)
    {
      xpos++;
      break;
    }
    else
    {
      color = random(0, 4);
    }
    xpos--;
    break;

  case 2:
    if (ypos > 0)
    {
      ypos--;
      break;
    }
    else
    {
      color = random(0, 4);
    }

  case 3:
    if (ypos < 3)
    {
      ypos++;
      break;
    }
    else
    {
      color = random(0, 4);
    }
    ypos--;
    break;

  case 4:
    if (zpos > 0)
    {
      zpos--;
      break;
    }
    else
    {
      color = random(0, 4);
    }
  case 5:
    if (zpos < 3)
    {
      zpos++;
      break;
    }
    else
    {
      color = random(0, 4);
    }
    zpos--;
    break;
  }
  grid[xpos][ypos][zpos] = color;
}

void drawLine(int color, int startx, int starty, int startz, int endx, int endy, int endz)
{
  bool reverseX = false;
  bool reverseY = false;
  bool reverseZ = false;
  if (startx > endx)
  {
    swapint(startx, endx);
    reverseX = true;
  }
  if (starty > endy)
  {
    swapint(starty, endy);
    reverseY = true;
  }
  if (startz > endz)
  {
    swapint(startz, endz);
    reverseZ = true;
  }

  int delx = endx - startx;
  int dely = endy - starty;
  int delz = endz - startz;

  int longest = (delx > dely   ? delx > delz ? delx : delz > dely ? delz
                                                                  : dely
                 : dely > delz ? dely
                 : delz > delx ? delz
                               : delx);
  for (int i = 0; i < longest; i++)
  {
    int xpos;
    if (reverseX)
      xpos = roundClosest(((longest - i) * delx), longest) + startx;
    else
      xpos = roundClosest((i * delx), longest) + startx;

    int ypos;
    if (reverseY)
      ypos = roundClosest(((longest - i) * dely), longest) + starty;
    else
      ypos = roundClosest((i * dely), longest) + starty;

    int zpos;
    if (reverseZ)
      zpos = roundClosest(((longest - i) * delz), longest) + startz;
    else
      zpos = roundClosest((i * delz), longest) + startz;
    grid[xpos][ypos][zpos] = color;
  }

  if (reverseX)
    swapint(startx, endx);
  if (reverseY)
    swapint(starty, endy);
  if (reverseZ)
    swapint(startz, endz);
  grid[endx][endy][endz] = color;
}

int roundClosest(int numerator, int denominator)
{
  numerator = (numerator << 1) / denominator;
  int output = (numerator >> 1) + (numerator % 2);
  return output;
}

void swapint(int &one, int &two)
{
  one = one ^ two;
  two = one ^ two;
  one = one ^ two;
}

int countUp2(String cmd)
{
  int delayTime = 50;
  if (sscanf(cmd, "%d", &delayTime) == 1)
  {
    Log.info("delayTime=%d", delayTime);
  }
  for (int x = 0; x < 4; x++)
  {
    for (int y = 0; y < 4; y++)
    {
      for (int z = 0; z < 4; z++)
      {
        set_pins(red[x][y][z][0], red[x][y][z][1]);
        delay(delayTime);
        reset_pins(red[x][y][z][0], red[x][y][z][1]);
        set_pins(green[x][y][z][0], green[x][y][z][1]);
        delay(delayTime);
        reset_pins(green[x][y][z][0], green[x][y][z][1]);
        set_pins(blue[x][y][z][0], blue[x][y][z][1]);
        delay(delayTime);
        reset_pins(blue[x][y][z][0], blue[x][y][z][1]);
      }
    }
  }
  return 1;
}

int countUp(String cmd)
{

  int delayTime = 500;
  if (sscanf(cmd, "%d", &delayTime) == 1)
  {
    Log.info("delayTime=%d", delayTime);
  }
  set_pins(D3, D7); // (0,0,0, Red)
  delay(delayTime);
  reset_all_pins();
  set_pins(A7, D3); // (0,0,1, Red)
  delay(delayTime);
  reset_all_pins();
  set_pins(A3, A7); // (0,0,2, Red)
  delay(delayTime);
  reset_all_pins();
  set_pins(D7, A3); // (0,0,3, Red)
  delay(delayTime);
  reset_all_pins();
  set_pins(D2, D7); // (0,1,0, Red)
  delay(delayTime);
  reset_all_pins();
  set_pins(A6, D2); // (0,1,1, Red)
  delay(delayTime);
  reset_all_pins();
  set_pins(A2, A6); // (0,1,2, Red)
  delay(delayTime);
  reset_all_pins();
  set_pins(D7, A2); // (0,1,3, Red)
  delay(delayTime);
  reset_all_pins();
  set_pins(D1, D7); // (0,2,0, Red)
  delay(delayTime);
  reset_all_pins();
  set_pins(A5, D1); // (0,2,1, Red)
  delay(delayTime);
  reset_all_pins();
  set_pins(A1, A5); // (0,2,2, Red)
  delay(delayTime);
  reset_all_pins();
  set_pins(D7, A1); // (0,2,3, Red)
  delay(delayTime);
  reset_all_pins();
  set_pins(D0, D7); // (0,3,0, Red)
  delay(delayTime);
  reset_all_pins();
  set_pins(A4, D0); // (0,3,1, Red)
  delay(delayTime);
  reset_all_pins();
  set_pins(A0, A4); // (0,3,2, Red)
  delay(delayTime);
  reset_all_pins();
  set_pins(D7, A0); // (0,3,3, Red)
  delay(delayTime);
  reset_all_pins();
  set_pins(D3, D6); // (1,0,0, Red)
  delay(delayTime);
  reset_all_pins();
  set_pins(A4, D3); // (1,0,1, Red)
  delay(delayTime);
  reset_all_pins();
  set_pins(A2, A4); // (1,0,2, Red)
  delay(delayTime);
  reset_all_pins();
  set_pins(D6, A2); // (1,0,3, Red)
  delay(delayTime);
  reset_all_pins();
  set_pins(D2, D6); // (1,1,0, Red)
  delay(delayTime);
  reset_all_pins();
  set_pins(A5, D2); // (1,1,1, Red)
  delay(delayTime);
  reset_all_pins();
  set_pins(A3, A5); // (1,1,2, Red)
  delay(delayTime);
  reset_all_pins();
  set_pins(D6, A3); // (1,1,3, Red)
  delay(delayTime);
  reset_all_pins();
  set_pins(D1, D6); // (1,2,0, Red)
  delay(delayTime);
  reset_all_pins();
  set_pins(A6, D1); // (1,2,1, Red)
  delay(delayTime);
  reset_all_pins();
  set_pins(A0, A6); // (1,2,2, Red)
  delay(delayTime);
  reset_all_pins();
  set_pins(D6, A0); // (1,2,3, Red)
  delay(delayTime);
  reset_all_pins();
  set_pins(D0, D6); // (1,3,0, Red)
  delay(delayTime);
  reset_all_pins();
  set_pins(A7, D0); // (1,3,1, Red)
  delay(delayTime);
  reset_all_pins();
  set_pins(A1, A7); // (1,3,2, Red)
  delay(delayTime);
  reset_all_pins();
  set_pins(D6, A1); // (1,3,3, Red)
  delay(delayTime);
  reset_all_pins();
  set_pins(D3, D5); // (2,0,0, Red)
  delay(delayTime);
  reset_all_pins();
  set_pins(A6, D3); // (2,0,1, Red)
  delay(delayTime);
  reset_all_pins();
  set_pins(A1, A6); // (2,0,2, Red)
  delay(delayTime);
  reset_all_pins();
  set_pins(D5, A1); // (2,0,3, Red)
  delay(delayTime);
  reset_all_pins();
  set_pins(D2, D5); // (2,1,0, Red)
  delay(delayTime);
  reset_all_pins();
  set_pins(A7, D2); // (2,1,1, Red)
  delay(delayTime);
  reset_all_pins();
  set_pins(A0, A7); // (2,1,2, Red)
  delay(delayTime);
  reset_all_pins();
  set_pins(D5, A0); // (2,1,3, Red)
  delay(delayTime);
  reset_all_pins();
  set_pins(D1, D5); // (2,2,0, Red)
  delay(delayTime);
  reset_all_pins();
  set_pins(A4, D1); // (2,2,1, Red)
  delay(delayTime);
  reset_all_pins();
  set_pins(A3, A4); // (2,2,2, Red)
  delay(delayTime);
  reset_all_pins();
  set_pins(D5, A3); // (2,2,3, Red)
  delay(delayTime);
  reset_all_pins();
  set_pins(D0, D5); // (2,3,0, Red)
  delay(delayTime);
  reset_all_pins();
  set_pins(A5, D0); // (2,3,1, Red)
  delay(delayTime);
  reset_all_pins();
  set_pins(A2, A5); // (2,3,2, Red)
  delay(delayTime);
  reset_all_pins();
  set_pins(D5, A2); // (2,3,3, Red)
  delay(delayTime);
  reset_all_pins();
  set_pins(D3, D4); // (3,0,0, Red)
  delay(delayTime);
  reset_all_pins();
  set_pins(A5, D3); // (3,0,1, Red)
  delay(delayTime);
  reset_all_pins();
  set_pins(A0, A5); // (3,0,2, Red)
  delay(delayTime);
  reset_all_pins();
  set_pins(D4, A0); // (3,0,3, Red)
  delay(delayTime);
  reset_all_pins();
  set_pins(D2, D4); // (3,1,0, Red)
  delay(delayTime);
  reset_all_pins();
  set_pins(A4, D2); // (3,1,1, Red)
  delay(delayTime);
  reset_all_pins();
  set_pins(A1, A4); // (3,1,2, Red)
  delay(delayTime);
  reset_all_pins();
  set_pins(D4, A1); // (3,1,3, Red)
  delay(delayTime);
  reset_all_pins();
  set_pins(D1, D4); // (3,2,0, Red)
  delay(delayTime);
  reset_all_pins();
  set_pins(A7, D1); // (3,2,1, Red)
  delay(delayTime);
  reset_all_pins();
  set_pins(A2, A7); // (3,2,2, Red)
  delay(delayTime);
  reset_all_pins();
  set_pins(D4, A2); // (3,2,3, Red)
  delay(delayTime);
  reset_all_pins();
  set_pins(D0, D4); // (3,3,0, Red)
  delay(delayTime);
  reset_all_pins();
  set_pins(A6, D0); // (3,3,1, Red)
  delay(delayTime);
  reset_all_pins();
  set_pins(A3, A6); // (3,3,2, Red)
  delay(delayTime);
  reset_all_pins();
  set_pins(D4, A3); // (3,3,3, Red)
  delay(delayTime);
  reset_all_pins();

  set_pins(D3, A3); // (0,0,0, Green)
  delay(delayTime);
  reset_all_pins();
  set_pins(A7, D7); // (0,0,1, Green)
  delay(delayTime);
  reset_all_pins();
  set_pins(A3, D3); // (0,0,2, Green)
  delay(delayTime);
  reset_all_pins();
  set_pins(D7, A7); // (0,0,3, Green)
  delay(delayTime);
  reset_all_pins();
  set_pins(D2, A2); // (0,1,0, Green)
  delay(delayTime);
  reset_all_pins();
  set_pins(A6, D7); // (0,1,1, Green)
  delay(delayTime);
  reset_all_pins();
  set_pins(A2, D2); // (0,1,2, Green)
  delay(delayTime);
  reset_all_pins();
  set_pins(D7, A6); // (0,1,3, Green)
  delay(delayTime);
  reset_all_pins();
  set_pins(D1, A1); // (0,2,0, Green)
  delay(delayTime);
  reset_all_pins();
  set_pins(A5, D7); // (0,2,1, Green)
  delay(delayTime);
  reset_all_pins();
  set_pins(A1, D1); // (0,2,2, Green)
  delay(delayTime);
  reset_all_pins();
  set_pins(D7, A5); // (0,2,3, Green)
  delay(delayTime);
  reset_all_pins();
  set_pins(D0, A0); // (0,3,0, Green)
  delay(delayTime);
  reset_all_pins();
  set_pins(A4, D7); // (0,3,1, Green)
  delay(delayTime);
  reset_all_pins();
  set_pins(A0, D0); // (0,3,2, Green)
  delay(delayTime);
  reset_all_pins();
  set_pins(D7, A4); // (0,3,3, Green)
  delay(delayTime);
  reset_all_pins();
  set_pins(D3, A2); // (1,0,0, Green)
  delay(delayTime);
  reset_all_pins();
  set_pins(A4, D6); // (1,0,1, Green)
  delay(delayTime);
  reset_all_pins();
  set_pins(A2, D3); // (1,0,2, Green)
  delay(delayTime);
  reset_all_pins();
  set_pins(D6, A4); // (1,0,3, Green)
  delay(delayTime);
  reset_all_pins();
  set_pins(D2, A3); // (1,1,0, Green)
  delay(delayTime);
  reset_all_pins();
  set_pins(A5, D6); // (1,1,1, Green)
  delay(delayTime);
  reset_all_pins();
  set_pins(A3, D2); // (1,1,2, Green)
  delay(delayTime);
  reset_all_pins();
  set_pins(D6, A5); // (1,1,3, Green)
  delay(delayTime);
  reset_all_pins();
  set_pins(D1, A0); // (1,2,0, Green)
  delay(delayTime);
  reset_all_pins();
  set_pins(A6, D6); // (1,2,1, Green)
  delay(delayTime);
  reset_all_pins();
  set_pins(A0, D1); // (1,2,2, Green)
  delay(delayTime);
  reset_all_pins();
  set_pins(D6, A6); // (1,2,3, Green)
  delay(delayTime);
  reset_all_pins();
  set_pins(D0, A1); // (1,3,0, Green)
  delay(delayTime);
  reset_all_pins();
  set_pins(A7, D6); // (1,3,1, Green)
  delay(delayTime);
  reset_all_pins();
  set_pins(A1, D0); // (1,3,2, Green)
  delay(delayTime);
  reset_all_pins();
  set_pins(D6, A7); // (1,3,3, Green)
  delay(delayTime);
  reset_all_pins();
  set_pins(D3, A1); // (2,0,0, Green)
  delay(delayTime);
  reset_all_pins();
  set_pins(A6, D5); // (2,0,1, Green)
  delay(delayTime);
  reset_all_pins();
  set_pins(A1, D3); // (2,0,2, Green)
  delay(delayTime);
  reset_all_pins();
  set_pins(D5, A6); // (2,0,3, Green)
  delay(delayTime);
  reset_all_pins();
  set_pins(D2, A0); // (2,1,0, Green)
  delay(delayTime);
  reset_all_pins();
  set_pins(A7, D5); // (2,1,1, Green)
  delay(delayTime);
  reset_all_pins();
  set_pins(A0, D2); // (2,1,2, Green)
  delay(delayTime);
  reset_all_pins();
  set_pins(D5, A7); // (2,1,3, Green)
  delay(delayTime);
  reset_all_pins();
  set_pins(D1, A3); // (2,2,0, Green)
  delay(delayTime);
  reset_all_pins();
  set_pins(A4, D5); // (2,2,1, Green)
  delay(delayTime);
  reset_all_pins();
  set_pins(A3, D1); // (2,2,2, Green)
  delay(delayTime);
  reset_all_pins();
  set_pins(D5, A4); // (2,2,3, Green)
  delay(delayTime);
  reset_all_pins();
  set_pins(D0, A2); // (2,3,0, Green)
  delay(delayTime);
  reset_all_pins();
  set_pins(A5, D5); // (2,3,1, Green)
  delay(delayTime);
  reset_all_pins();
  set_pins(A2, D0); // (2,3,2, Green)
  delay(delayTime);
  reset_all_pins();
  set_pins(D5, A5); // (2,3,3, Green)
  delay(delayTime);
  reset_all_pins();
  set_pins(D3, A0); // (3,0,0, Green)
  delay(delayTime);
  reset_all_pins();
  set_pins(A5, D4); // (3,0,1, Green)
  delay(delayTime);
  reset_all_pins();
  set_pins(A0, D3); // (3,0,2, Green)
  delay(delayTime);
  reset_all_pins();
  set_pins(D4, A5); // (3,0,3, Green)
  delay(delayTime);
  reset_all_pins();
  set_pins(D2, A1); // (3,1,0, Green)
  delay(delayTime);
  reset_all_pins();
  set_pins(A4, D4); // (3,1,1, Green)
  delay(delayTime);
  reset_all_pins();
  set_pins(A1, D2); // (3,1,2, Green)
  delay(delayTime);
  reset_all_pins();
  set_pins(D4, A4); // (3,1,3, Green)
  delay(delayTime);
  reset_all_pins();
  set_pins(D1, A2); // (3,2,0, Green)
  delay(delayTime);
  reset_all_pins();
  set_pins(A7, D4); // (3,2,1, Green)
  delay(delayTime);
  reset_all_pins();
  set_pins(A2, D1); // (3,2,2, Green)
  delay(delayTime);
  reset_all_pins();
  set_pins(D4, A7); // (3,2,3, Green)
  delay(delayTime);
  reset_all_pins();
  set_pins(D0, A3); // (3,3,0, Green)
  delay(delayTime);
  reset_all_pins();
  set_pins(A6, D4); // (3,3,1, Green)
  delay(delayTime);
  reset_all_pins();
  set_pins(A3, D0); // (3,3,2, Green)
  delay(delayTime);
  reset_all_pins();
  set_pins(D4, A6); // (3,3,3, Green)
  delay(delayTime);
  reset_all_pins();

  set_pins(D3, A7); // (0,0,0, Blue)
  delay(delayTime);
  reset_all_pins();
  set_pins(A7, A3); // (0,0,1, Blue)
  delay(delayTime);
  reset_all_pins();
  set_pins(A3, D7); // (0,0,2, Blue)
  delay(delayTime);
  reset_all_pins();
  set_pins(D7, D3); // (0,0,3, Blue)
  delay(delayTime);
  reset_all_pins();
  set_pins(D2, A6); // (0,1,0, Blue)
  delay(delayTime);
  reset_all_pins();
  set_pins(A6, A2); // (0,1,1, Blue)
  delay(delayTime);
  reset_all_pins();
  set_pins(A2, D7); // (0,1,2, Blue)
  delay(delayTime);
  reset_all_pins();
  set_pins(D7, D2); // (0,1,3, Blue)
  delay(delayTime);
  reset_all_pins();
  set_pins(D1, A5); // (0,2,0, Blue)
  delay(delayTime);
  reset_all_pins();
  set_pins(A5, A1); // (0,2,1, Blue)
  delay(delayTime);
  reset_all_pins();
  set_pins(A1, D7); // (0,2,2, Blue)
  delay(delayTime);
  reset_all_pins();
  set_pins(D7, D1); // (0,2,3, Blue)
  delay(delayTime);
  reset_all_pins();
  set_pins(D0, A4); // (0,3,0, Blue)
  delay(delayTime);
  reset_all_pins();
  set_pins(A4, A0); // (0,3,1, Blue)
  delay(delayTime);
  reset_all_pins();
  set_pins(A0, D7); // (0,3,2, Blue)
  delay(delayTime);
  reset_all_pins();
  set_pins(D7, D0); // (0,3,3, Blue)
  delay(delayTime);
  reset_all_pins();
  set_pins(D3, A4); // (1,0,0, Blue)
  delay(delayTime);
  reset_all_pins();
  set_pins(A4, A2); // (1,0,1, Blue)
  delay(delayTime);
  reset_all_pins();
  set_pins(A2, D6); // (1,0,2, Blue)
  delay(delayTime);
  reset_all_pins();
  set_pins(D6, D3); // (1,0,3, Blue)
  delay(delayTime);
  reset_all_pins();
  set_pins(D2, A5); // (1,1,0, Blue)
  delay(delayTime);
  reset_all_pins();
  set_pins(A5, A3); // (1,1,1, Blue)
  delay(delayTime);
  reset_all_pins();
  set_pins(A3, D6); // (1,1,2, Blue)
  delay(delayTime);
  reset_all_pins();
  set_pins(D6, D2); // (1,1,3, Blue)
  delay(delayTime);
  reset_all_pins();
  set_pins(D1, A6); // (1,2,0, Blue)
  delay(delayTime);
  reset_all_pins();
  set_pins(A6, A0); // (1,2,1, Blue)
  delay(delayTime);
  reset_all_pins();
  set_pins(A0, D6); // (1,2,2, Blue)
  delay(delayTime);
  reset_all_pins();
  set_pins(D6, D1); // (1,2,3, Blue)
  delay(delayTime);
  reset_all_pins();
  set_pins(D0, A7); // (1,3,0, Blue)
  delay(delayTime);
  reset_all_pins();
  set_pins(A7, A1); // (1,3,1, Blue)
  delay(delayTime);
  reset_all_pins();
  set_pins(A1, D6); // (1,3,2, Blue)
  delay(delayTime);
  reset_all_pins();
  set_pins(D6, D0); // (1,3,3, Blue)
  delay(delayTime);
  reset_all_pins();
  set_pins(D3, A6); // (2,0,0, Blue)
  delay(delayTime);
  reset_all_pins();
  set_pins(A6, A1); // (2,0,1, Blue)
  delay(delayTime);
  reset_all_pins();
  set_pins(A1, D5); // (2,0,2, Blue)
  delay(delayTime);
  reset_all_pins();
  set_pins(D5, D3); // (2,0,3, Blue)
  delay(delayTime);
  reset_all_pins();
  set_pins(D2, A7); // (2,1,0, Blue)
  delay(delayTime);
  reset_all_pins();
  set_pins(A7, A0); // (2,1,1, Blue)
  delay(delayTime);
  reset_all_pins();
  set_pins(A0, D5); // (2,1,2, Blue)
  delay(delayTime);
  reset_all_pins();
  set_pins(D5, D2); // (2,1,3, Blue)
  delay(delayTime);
  reset_all_pins();
  set_pins(D1, A4); // (2,2,0, Blue)
  delay(delayTime);
  reset_all_pins();
  set_pins(A4, A3); // (2,2,1, Blue)
  delay(delayTime);
  reset_all_pins();
  set_pins(A3, D5); // (2,2,2, Blue)
  delay(delayTime);
  reset_all_pins();
  set_pins(D5, D1); // (2,2,3, Blue)
  delay(delayTime);
  reset_all_pins();
  set_pins(D0, A5); // (2,3,0, Blue)
  delay(delayTime);
  reset_all_pins();
  set_pins(A5, A2); // (2,3,1, Blue)
  delay(delayTime);
  reset_all_pins();
  set_pins(A2, D5); // (2,3,2, Blue)
  delay(delayTime);
  reset_all_pins();
  set_pins(D5, D0); // (2,3,3, Blue)
  delay(delayTime);
  reset_all_pins();
  set_pins(D3, A5); // (3,0,0, Blue)
  delay(delayTime);
  reset_all_pins();
  set_pins(A5, A0); // (3,0,1, Blue)
  delay(delayTime);
  reset_all_pins();
  set_pins(A0, D4); // (3,0,2, Blue)
  delay(delayTime);
  reset_all_pins();
  set_pins(D4, D3); // (3,0,3, Blue)
  delay(delayTime);
  reset_all_pins();
  set_pins(D2, A4); // (3,1,0, Blue)
  delay(delayTime);
  reset_all_pins();
  set_pins(A4, A1); // (3,1,1, Blue)
  delay(delayTime);
  reset_all_pins();
  set_pins(A1, D4); // (3,1,2, Blue)
  delay(delayTime);
  reset_all_pins();
  set_pins(D4, D2); // (3,1,3, Blue)
  delay(delayTime);
  reset_all_pins();
  set_pins(D1, A7); // (3,2,0, Blue)
  delay(delayTime);
  reset_all_pins();
  set_pins(A7, A2); // (3,2,1, Blue)
  delay(delayTime);
  reset_all_pins();
  set_pins(A2, D4); // (3,2,2, Blue)
  delay(delayTime);
  reset_all_pins();
  set_pins(D4, D1); // (3,2,3, Blue)
  delay(delayTime);
  reset_all_pins();
  set_pins(D0, A6); // (3,3,0, Blue)
  delay(delayTime);
  reset_all_pins();
  set_pins(A6, A3); // (3,3,1, Blue)
  delay(delayTime);
  reset_all_pins();
  set_pins(A3, D4); // (3,3,2, Blue)
  delay(delayTime);
  reset_all_pins();
  set_pins(D4, D0); // (3,3,3, Blue)
  delay(delayTime);
  reset_all_pins();

  return 1;
}

// (x,y,z, color)
// set_pins(D0, D0); // Nothing
// set_pins(D0, D1); // Nothing
// set_pins(D0, D2); // Nothing
// set_pins(D0, D3); // Nothing
// set_pins(D1, D0); // Nothing
// set_pins(D1, D1); // Nothing
// set_pins(D1, D2); // Nothing
// set_pins(D1, D3); // Nothing
// set_pins(D2, D0); // Nothing
// set_pins(D2, D1); // Nothing
// set_pins(D2, D2); // Nothing
// set_pins(D2, D3); // Nothing
// set_pins(D3, D0); // Nothing
// set_pins(D3, D1); // Nothing
// set_pins(D3, D2); // Nothing
// set_pins(D3, D3); // Nothing
// set_pins(D4, D4); // Nothing
// set_pins(D4, D5); // Nothing
// set_pins(D4, D6); // Nothing
// set_pins(D4, D7); // Nothing
// set_pins(D5, D4); // Nothing
// set_pins(D5, D5); // Nothing
// set_pins(D5, D6); // Nothing
// set_pins(D5, D7); // Nothing
// set_pins(D6, D4); // Nothing
// set_pins(D6, D5); // Nothing
// set_pins(D6, D6); // Nothing
// set_pins(D6, D7); // Nothing
// set_pins(A1, A0); // Nothing
// set_pins(A1, A1); // Nothing
// set_pins(A1, A2); // Nothing
// set_pins(A1, A3); // Nothing
// set_pins(D7, D4); // Nothing
// set_pins(D7, D5); // Nothing
// set_pins(D7, D6); // Nothing
// set_pins(D7, D7); // Nothing
// set_pins(A2, A0); // Nothing
// set_pins(A2, A1); // Nothing
// set_pins(A2, A2); // Nothing
// set_pins(A2, A3); // Nothing
// set_pins(A3, A0); // Nothing
// set_pins(A3, A1); // Nothing
// set_pins(A3, A2); // Nothing
// set_pins(A3, A3); // Nothing
// set_pins(A4, A4); // Nothing
// set_pins(A4, A5); // Nothing
// set_pins(A4, A6); // Nothing
// set_pins(A4, A7); // Nothing
// set_pins(A5, A4); // Nothing
// set_pins(A5, A5); // Nothing
// set_pins(A5, A6); // Nothing
// set_pins(A5, A7); // Nothing
// set_pins(A6, A4); // Nothing
// set_pins(A6, A5); // Nothing
// set_pins(A6, A6); // Nothing
// set_pins(A6, A7); // Nothing
// set_pins(A7, A4); // Nothing
// set_pins(A7, A5); // Nothing
// set_pins(A7, A6); // Nothing
// set_pins(A7, A7); // Nothing

void set_pins(int low_pin, int high_pin)
{
  // reset all the pins
  reset_pins(low_pin, high_pin);

  // set the high and low pins to output
  pinMode(high_pin, OUTPUT);
  pinMode(low_pin, OUTPUT);

  // set high pin to logic high, low to logic low
  digitalWrite(high_pin, HIGH);
  digitalWrite(low_pin, LOW);
}

void reset_pins(int low_pin, int high_pin)
{
  pinMode(low_pin, INPUT);
  pinMode(high_pin, INPUT);

  digitalWrite(low_pin, LOW);
  digitalWrite(high_pin, LOW);
}

void reset_all_pins()
{
  for (int x = 0; x < 16; x++)
  {
    pinMode(pins[x], INPUT);
    digitalWrite(pins[x], LOW);
  }
}