/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#line 1 "/Users/drewowl/workspace/cube/src/cube.ino"
#include "Particle.h"
#include "constants.h"
#include "helpers.h"

void setup();
void loop();
void setCurrentAnimation();
void checkAnimationChange();
void setupAndRunTimedLoop();
void rgbMainLoop();
int drawWalls(String cmd);
int drawXRow(String cmd);
int drawYRow(String cmd);
int drawZRow(String cmd);
int lightIt(String cmd);
int drawWholeCube(String cmd);
int crazyFollowColors(String cmd);
void drawLed(int x, int y, int z, int color);
void resetLed(int x, int y, int z, int color);
int drawLineAPI(String cmd);
void planarSpin();
int planarFlop3D(String cmd);
void chaseTheDot();
void checkResetGrid();
void resetGrid();
void drawLine(int color, int startx, int starty, int startz, int endx, int endy, int endz);
int countUp(String cmd);
void set_pins(int low_pin, int high_pin);
void reset_pins(int low_pin, int high_pin);
void reset_all_pins();
#line 5 "/Users/drewowl/workspace/cube/src/cube.ino"
unsigned long microDelay = 10;
unsigned long lastLoopTime = 0;
unsigned long loopTime = 140;
unsigned long lastAnimationChange = 0;
unsigned long animationChange = 60000;

bool continuePattern = true;

int color = 0;
int xpos = 0;
int ypos = 0;
int zpos = 0;
int planarSpinLoops = 0;

int grid[4][4][4][3] = {
    {{{4, 4, 4}, {4, 4, 4}, {4, 4, 4}, {4, 4, 4}},
     {{4, 4, 4}, {4, 4, 4}, {4, 4, 4}, {4, 4, 4}},
     {{4, 4, 4}, {4, 4, 4}, {4, 4, 4}, {4, 4, 4}},
     {{4, 4, 4}, {4, 4, 4}, {4, 4, 4}, {4, 4, 4}}},
    {{{4, 4, 4}, {4, 4, 4}, {4, 4, 4}, {4, 4, 4}},
     {{4, 4, 4}, {4, 4, 4}, {4, 4, 4}, {4, 4, 4}},
     {{4, 4, 4}, {4, 4, 4}, {4, 4, 4}, {4, 4, 4}},
     {{4, 4, 4}, {4, 4, 4}, {4, 4, 4}, {4, 4, 4}}},
    {{{4, 4, 4}, {4, 4, 4}, {4, 4, 4}, {4, 4, 4}},
     {{4, 4, 4}, {4, 4, 4}, {4, 4, 4}, {4, 4, 4}},
     {{4, 4, 4}, {4, 4, 4}, {4, 4, 4}, {4, 4, 4}},
     {{4, 4, 4}, {4, 4, 4}, {4, 4, 4}, {4, 4, 4}}},
    {{{4, 4, 4}, {4, 4, 4}, {4, 4, 4}, {4, 4, 4}},
     {{4, 4, 4}, {4, 4, 4}, {4, 4, 4}, {4, 4, 4}},
     {{4, 4, 4}, {4, 4, 4}, {4, 4, 4}, {4, 4, 4}},
     {{4, 4, 4}, {4, 4, 4}, {4, 4, 4}, {4, 4, 4}}}};

Animation currentAnimation = planarSpinAnimation;

void setup()
{
  // Particle.function("countUp", countUp);
  // Particle.function("countUpOld", countUpOld);
  // Particle.function("lightIt", lightIt);
  // Particle.function("drawLineAPI", drawLineAPI);
  // Particle.function("planarSpin", planarSpin);
  // Particle.function("planarFlop3D", planarFlop3D);
  // Particle.function("drawZRow", drawZRow);
  // Particle.function("drawWholeCube", drawWholeCube);
}

void loop()
{
  setCurrentAnimation();
  checkAnimationChange();
  setupAndRunTimedLoop();
}

void setCurrentAnimation()
{
  switch (currentAnimation)
  {
  case countUpAnimation:
    countUp("");
    break;
  case planarSpinAnimation:
    planarSpin();
    break;
  // case planarFlopAnimation:
  //   planarFlop3D("");
  //   break;
  case drawWholeCubeAnimation:
    drawWholeCube("");
    break;
  case chaseTheDotAnimation:
    chaseTheDot();
    break;
  case drawZRowAnimation:
    drawZRow("");
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
  case crazyFollowColorsAnimation:
    crazyFollowColors("");
    break;
  }
}

void checkAnimationChange()
{
  unsigned long now = millis();
  if ((now - lastAnimationChange) >= animationChange)
  {
    resetGrid();
    lastAnimationChange = now;
    if (currentAnimation == drawZRowAnimation)
    {
      currentAnimation = chaseTheDotAnimation;
    }
    else
    {
      currentAnimation = static_cast<Animation>((currentAnimation + 1) % 9);
    }
  }
}

void setupAndRunTimedLoop()
{
  unsigned long now = millis();
  while ((now - lastLoopTime) <= loopTime)
  {
    rgbMainLoop();
    now = millis();
  }
  lastLoopTime = now;
}

void rgbMainLoop()
{
  for (int x = 0; x < 4; x++)
  {
    for (int y = 0; y < 4; y++)
    {
      for (int z = 0; z < 4; z++)
      {
        for (int currentColor = 0; currentColor < 3; currentColor++)
        {
          drawLed(x, y, z, grid[x][y][z][currentColor]);
          delayMicroseconds(microDelay);
          resetLed(x, y, z, grid[x][y][z][currentColor]);
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
    color = color > 8 ? 0 : color + 1;
  }
  for (int x = 0; x < 4; x++)
  {
    for (int z = 0; z < 4; z++)
    {
      grid[x][ypos][z][0] = allVariants[color][0];
      grid[x][ypos][z][1] = allVariants[color][1];
      grid[x][ypos][z][2] = allVariants[color][2];
    }
  }
  return 1;
}

int drawXRow(String cmd)
{
  int y = random(0, 4);
  int z = random(0, 4);
  color = color > 8 ? 0 : color + 1;
  if (sscanf(cmd, "%d, %d, %d", &y, &z, &color) == 3)
  {
    for (int x = 0; x < 4; x++)
    {
      grid[x][y][z][0] = allVariants[color][0];
      grid[x][y][z][1] = allVariants[color][1];
      grid[x][y][z][2] = allVariants[color][2];
    }
  }
  else
  {
    for (int x = 0; x < 4; x++)
    {
      grid[x][y][z][0] = allVariants[color][0];
      grid[x][y][z][1] = allVariants[color][1];
      grid[x][y][z][2] = allVariants[color][2];
    }
  }
  return 1;
}

int drawYRow(String cmd)
{
  int x = random(0, 4);
  int z = random(0, 4);
  color = color > 8 ? 0 : color + 1;
  if (sscanf(cmd, "%d, %d, %d", &x, &z, &color) == 3)
  {
    for (int y = 0; y < 4; y++)
    {
      grid[x][y][z][0] = allVariants[color][0];
      grid[x][y][z][1] = allVariants[color][1];
      grid[x][y][z][2] = allVariants[color][2];
    }
  }
  else
  {
    for (int y = 0; y < 4; y++)
    {
      grid[x][y][z][0] = allVariants[color][0];
      grid[x][y][z][1] = allVariants[color][1];
      grid[x][y][z][2] = allVariants[color][2];
    }
  }
  return 1;
}

int drawZRow(String cmd)
{
  int x = random(0, 4);
  int y = random(0, 4);
  color = color > 8 ? 0 : color + 1;
  if (sscanf(cmd, "%d, %d, %d", &x, &y, &color) == 3)
  {
    for (int z = 0; z < 4; z++)
    {
      grid[x][y][z][0] = allVariants[color][0];
      grid[x][y][z][1] = allVariants[color][1];
      grid[x][y][z][2] = allVariants[color][2];
      ;
    }
  }
  else
  {
    for (int z = 0; z < 4; z++)
    {
      grid[x][y][z][0] = allVariants[color][0];
      grid[x][y][z][1] = allVariants[color][1];
      grid[x][y][z][2] = allVariants[color][2];
      ;
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
    resetLed(x, y, z, grid[x][y][z][0]);
    resetLed(x, y, z, grid[x][y][z][1]);
    resetLed(x, y, z, grid[x][y][z][2]);
    // drawLed(x, y, z, color);
    grid[x][y][z][0] = color;
    grid[x][y][z][1] = color;
    grid[x][y][z][2] = color;
  }
  return 1;
}

int drawWholeCube(String cmd)
{
  color = color > 8 ? 0 : color + 1;
  for (int x = 0; x < 4; x++)
  {
    for (int y = 0; y < 4; y++)
    {
      for (int z = 0; z < 4; z++)
      {
        grid[x][y][z][0] = allVariants[color][0];
        grid[x][y][z][1] = allVariants[color][1];
        grid[x][y][z][2] = allVariants[color][2];
      }
    }
  }
  return 1;
}

int crazyFollowColors(String cmd)
{
  for (int x = 0; x < 4; x++)
  {
    for (int y = 0; y < 4; y++)
    {
      for (int z = 0; z < 4; z++)
      {
        color = color > 8 ? 0 : color + 1;
        grid[x][y][z][0] = allVariants[color][0];
        grid[x][y][z][1] = allVariants[color][1];
        grid[x][y][z][2] = allVariants[color][2];
      }
    }
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
  default:
    pin1 = red[x][y][z][0];
    pin2 = red[x][y][z][1];
    reset_pins(pin1, pin2);
    pin1 = green[x][y][z][0];
    pin2 = green[x][y][z][1];
    reset_pins(pin1, pin2);
    pin1 = blue[x][y][z][0];
    pin2 = blue[x][y][z][1];
    reset_pins(pin1, pin2);
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

void planarSpin()
{
  resetGrid();
  xpos = xpos > 2 ? 0 : xpos + 1;
  ypos = ypos > 2 ? 0 : ypos + 1;
  drawLine(color, xpos, 0, 0, 3 - xpos, 3, 0);
  drawLine(color, xpos, 0, 1, 3 - xpos, 3, 1);
  drawLine(color, xpos, 0, 2, 3 - xpos, 3, 2);
  drawLine(color, xpos, 0, 3, 3 - xpos, 3, 3);

  drawLine(color, 3, ypos, 0, 0, 3 - ypos, 0);
  drawLine(color, 3, ypos, 1, 0, 3 - ypos, 1);
  drawLine(color, 3, ypos, 2, 0, 3 - ypos, 2);
  drawLine(color, 3, ypos, 3, 0, 3 - ypos, 3);
  if (planarSpinLoops > 10)
  {
    planarSpinLoops = 0;
    color = nextColor(color);
  }
  planarSpinLoops++;
}

int planarFlop3D(String cmd)
{
  int color = 0;
  int animationSpeed = 50;
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

void chaseTheDot()
{
  checkResetGrid();
  switch (random(0, 6))
  {
  case 0:
    if (xpos > 0)
    {
      xpos--;
      break;
    }
  case 1:
    if (xpos < 3)
    {
      xpos++;
      break;
    }
    xpos--;
    break;
  case 2:
    if (ypos > 0)
    {
      ypos--;
      break;
    }
  case 3:
    if (ypos < 3)
    {
      ypos++;
      break;
    }
    ypos--;
    break;
  case 4:
    if (zpos > 0)
    {
      zpos--;
      break;
    }
  case 5:
    if (zpos < 3)
    {
      zpos++;
      break;
    }
    zpos--;
    break;
  }
  if (std::equal(std::begin(grid[xpos][ypos][zpos]), std::end(grid[xpos][ypos][zpos]), std::begin(allVariants[color])))
  {
    color = color > 8 ? 0 : color + 1;
  }
  grid[xpos][ypos][zpos][0] = allVariants[color][0];
  grid[xpos][ypos][zpos][1] = allVariants[color][1];
  grid[xpos][ypos][zpos][2] = allVariants[color][2];
}

void checkResetGrid()
{
  bool reset = true;
  int off[3] = {4,
                4,
                4};
  for (int x = 0; x < 4; x++)
  {
    for (int y = 0; y < 4; y++)
    {
      for (int z = 0; z < 4; z++)
      {

        if ((std::equal(std::begin(grid[x][y][z]), std::end(grid[x][y][z]), std::begin(off))))
          reset = false;
        break;
      }
    }
  }
  if (reset)
  {
    resetGrid();
  }
}

void resetGrid()
{
  for (int x = 0; x < 4; x++)
  {
    for (int y = 0; y < 4; y++)
    {
      for (int z = 0; z < 4; z++)
      {
        grid[x][y][z][0] = 4;
        grid[x][y][z][1] = 4;
        grid[x][y][z][2] = 4;
      }
    }
  }
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
    grid[xpos][ypos][zpos][0] = allVariants[color][0];
    grid[xpos][ypos][zpos][1] = allVariants[color][1];
    grid[xpos][ypos][zpos][2] = allVariants[color][2];
  }

  if (reverseX)
    swapint(startx, endx);
  if (reverseY)
    swapint(starty, endy);
  if (reverseZ)
    swapint(startz, endz);
  grid[endx][endy][endz][0] = allVariants[color][0];
  grid[endx][endy][endz][1] = allVariants[color][1];
  grid[endx][endy][endz][2] = allVariants[color][2];
}

int countUp(String cmd)
{
  if (color < 10)
  {
    grid[xpos][ypos][zpos][0] = allVariants[color][0];
    grid[xpos][ypos][zpos][1] = allVariants[color][1];
    grid[xpos][ypos][zpos][2] = allVariants[color][2];
    color++;
  }
  else
  {
    grid[xpos][ypos][zpos][0] = 4;
    grid[xpos][ypos][zpos][1] = 4;
    grid[xpos][ypos][zpos][2] = 4;
    color = 0;
    zpos++;
    if (zpos > 3 && ypos >= 3 && xpos >= 3)
    {
      xpos = 0;
      ypos = 0;
      zpos = 0;
    }
    else if (zpos > 3 && ypos > 3)
    {
      ypos = 0;
      zpos = 0;
      xpos++;
    }
    else if (zpos > 3)
    {
      zpos = 0;
      ypos++;
    }
  }
  return 1;
}

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
