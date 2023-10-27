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
int resetIt(String cmd);
int drawWholeCube(String cmd);
int crazyFollowColors(String cmd);
int drawLineAPI(String cmd);
void planarSpin();
void fountain();
void tunnel();
int planarFlop3D(String cmd);
void chaseTheDot();
void checkResetGrid();
void resetGrid();
void drawLine(int color, int startx, int starty, int startz, int endx, int endy, int endz);
void drawBoxWalls(int startx, int starty, int startz, int endx, int endy, int endz, int color);
int countUp(String cmd);
void drawLed(int x, int y, int z, int color);
void resetLed(int x, int y, int z, int color);
void set_pins(int low_pin, int high_pin);
void reset_pins(int low_pin, int high_pin);
void reset_all_pins();
#line 5 "/Users/drewowl/workspace/cube/src/cube.ino"
unsigned long microDelay = 10;
unsigned long lastLoopTime = 0;
unsigned long loopTime = 100;
unsigned long lastAnimationChange = 0;
unsigned long animationChange = 60000;
unsigned long now = 0;

bool haltAnimation = false;
bool continuePattern = false;

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

Animation currentAnimation = drawWholeCubeAnimation;

void setup()
{
  // Particle.function("countUp", countUp);
  Particle.function("lightIt", lightIt);
  Particle.function("resetIt", resetIt);
  // Particle.function("drawLineAPI", drawLineAPI);
  // Particle.function("planarSpin", planarSpin);
  // Particle.function("planarFlop3D", planarFlop3D);
  // Particle.function("drawZRow", drawZRow);
  // Particle.function("drawWholeCube", drawWholeCube);
}

void loop()
{
  if (!haltAnimation)
  {
    setCurrentAnimation();
  }
  checkAnimationChange();
  setupAndRunTimedLoop();
}

void setCurrentAnimation()
{
  loopTime = 200;
  microDelay = 50;
  animationChange = 60000;
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
  case fountainAnimation:
    fountain();
    break;
  case tunnelAnimation:
    tunnel();
    break;
  }
}

void checkAnimationChange()
{
  now = millis();
  if ((now - lastAnimationChange) >= animationChange)
  {
    haltAnimation = false;
    resetGrid();
    lastAnimationChange = now;
    if (currentAnimation == tunnelAnimation)
    {
      currentAnimation = chaseTheDotAnimation;
    }
    else
    {
      currentAnimation = static_cast<Animation>((currentAnimation + 1) % 11);
    }
  }
}

void setupAndRunTimedLoop()
{
  now = millis();
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
  animationChange = 10000;
  ypos = ypos == 0 ? 3 : ypos - 1;
  if (ypos == 3)
  {
    color = nextColor(color);
  }
  for (int x = 0; x < 4; x++)
  {
    for (int z = 0; z < 4; z++)
    {
      grid[x][ypos][z][0] = allColors[color][0];
      grid[x][ypos][z][1] = allColors[color][1];
      grid[x][ypos][z][2] = allColors[color][2];
    }
  }
  return 1;
}

int drawXRow(String cmd)
{
  animationChange = 10000;
  int y = random(0, 4);
  int z = random(0, 4);
  color = nextColor(color);
  if (sscanf(cmd, "%d, %d, %d", &y, &z, &color) == 3)
  {
    for (int x = 0; x < 4; x++)
    {
      grid[x][y][z][0] = allColors[color][0];
      grid[x][y][z][1] = allColors[color][1];
      grid[x][y][z][2] = allColors[color][2];
    }
  }
  else
  {
    for (int x = 0; x < 4; x++)
    {
      grid[x][y][z][0] = allColors[color][0];
      grid[x][y][z][1] = allColors[color][1];
      grid[x][y][z][2] = allColors[color][2];
    }
  }
  return 1;
}

int drawYRow(String cmd)
{
  animationChange = 10000;
  int x = random(0, 4);
  int z = random(0, 4);
  color = nextColor(color);
  if (sscanf(cmd, "%d, %d, %d", &x, &z, &color) == 3)
  {
    for (int y = 0; y < 4; y++)
    {
      grid[x][y][z][0] = allColors[color][0];
      grid[x][y][z][1] = allColors[color][1];
      grid[x][y][z][2] = allColors[color][2];
    }
  }
  else
  {
    for (int y = 0; y < 4; y++)
    {
      grid[x][y][z][0] = allColors[color][0];
      grid[x][y][z][1] = allColors[color][1];
      grid[x][y][z][2] = allColors[color][2];
    }
  }
  return 1;
}

int drawZRow(String cmd)
{
  animationChange = 10000;
  int x = random(0, 4);
  int y = random(0, 4);
  color = nextColor(color);
  if (sscanf(cmd, "%d, %d, %d", &x, &y, &color) == 3)
  {
    for (int z = 0; z < 4; z++)
    {
      grid[x][y][z][0] = allColors[color][0];
      grid[x][y][z][1] = allColors[color][1];
      grid[x][y][z][2] = allColors[color][2];
      ;
    }
  }
  else
  {
    for (int z = 0; z < 4; z++)
    {
      grid[x][y][z][0] = allColors[color][0];
      grid[x][y][z][1] = allColors[color][1];
      grid[x][y][z][2] = allColors[color][2];
      ;
    }
  }
  return 1;
}

int lightIt(String cmd)
{
  haltAnimation = true;
  int x = 0;
  int y = 0;
  int z = 0;
  int color = 0;
  if (sscanf(cmd, "%d, %d, %d, %d", &x, &y, &z, &color) == 4)
  {
    grid[x][y][z][0] = allColors[color][0];
    grid[x][y][z][1] = allColors[color][1];
    grid[x][y][z][2] = allColors[color][2];
  }
  return 1;
}

int resetIt(String cmd)
{
  resetGrid();
  return 1;
}

int drawWholeCube(String cmd)
{
  // animationChange = 10000;
  color = nextPrimaryColor(color);
  for (int x = 0; x < 4; x++)
  {
    for (int y = 0; y < 4; y++)
    {
      for (int z = 0; z < 4; z++)
      {
        grid[x][y][z][0] = primaryColors[color][0];
        grid[x][y][z][1] = primaryColors[color][1];
        grid[x][y][z][2] = primaryColors[color][2];
      }
    }
  }
  return 1;
}

int crazyFollowColors(String cmd)
{
  loopTime = 300;
  for (int x = 0; x < 4; x++)
  {
    for (int y = 0; y < 4; y++)
    {
      for (int z = 0; z < 4; z++)
      {
        grid[x][y][z][0] = allColors[color][0];
        grid[x][y][z][1] = allColors[color][1];
        grid[x][y][z][2] = allColors[color][2];
        color = nextColor(color);
      }
    }
  }
  return 1;
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
  if (planarSpinLoops > 12)
  {
    planarSpinLoops = 0;
    color = nextColor(color);
  }
  else
  {
    planarSpinLoops++;
  }
}

bool fountainUp = true;
int fountainZ = 0;
void fountain()
{
  loopTime = 50;
  if (fountainUp)
  {
    drawBoxWalls(1, 1, fountainZ, 2, 2, fountainZ, color);
    fountainZ++;
    if (fountainZ > 3)
    {
      fountainZ = 3;
      fountainUp = !fountainUp;
    }
  }
  else
  {
    drawBoxWalls(0, 0, fountainZ, 3, 3, fountainZ, color);
    fountainZ--;
    if (fountainZ < 0)
    {
      fountainZ = 0;
      fountainUp = !fountainUp;
      color = nextColor(color);
    }
  }
}

int tunnelIndex[] = {0, 1, 2, 3, 4, 5, 6, 7};
void tunnel()
{
  loopTime = 50;
  int color1[] = {0, 0, 0, 0, 2, 2, 2, 2};
  int color2[] = {2, 2, 2, 2, 0, 0, 0, 0};

  drawBoxWalls(1, 1, 0, 2, 2, 0, color1[tunnelIndex[0]]);
  drawBoxWalls(1, 1, 0, 2, 2, 0, color1[tunnelIndex[0]]);
  drawBoxWalls(1, 1, 0, 2, 2, 0, color2[tunnelIndex[0]]);
  drawBoxWalls(1, 1, 1, 2, 2, 1, color1[tunnelIndex[1]]);
  drawBoxWalls(1, 1, 1, 2, 2, 1, color2[tunnelIndex[1]]);
  drawBoxWalls(1, 1, 2, 2, 2, 2, color1[tunnelIndex[2]]);
  drawBoxWalls(1, 1, 2, 2, 2, 2, color2[tunnelIndex[2]]);
  drawBoxWalls(1, 1, 3, 2, 2, 3, color1[tunnelIndex[3]]);

  drawBoxWalls(1, 1, 3, 2, 2, 3, color2[tunnelIndex[3]]);
  drawBoxWalls(0, 0, 3, 3, 3, 3, color1[tunnelIndex[4]]);
  drawBoxWalls(0, 0, 3, 3, 3, 3, color2[tunnelIndex[4]]);
  drawBoxWalls(0, 0, 2, 3, 3, 2, color1[tunnelIndex[5]]);
  drawBoxWalls(0, 0, 2, 3, 3, 2, color2[tunnelIndex[5]]);
  drawBoxWalls(0, 0, 1, 3, 3, 1, color1[tunnelIndex[6]]);
  drawBoxWalls(0, 0, 1, 3, 3, 1, color2[tunnelIndex[6]]);
  drawBoxWalls(0, 0, 0, 3, 3, 0, color1[tunnelIndex[7]]);
  drawBoxWalls(0, 0, 0, 3, 3, 0, color2[tunnelIndex[7]]);

  for (int i = 0; i < 8; i++)
  {
    // index[i] = index[i]==7?0:index[i]+1;
    tunnelIndex[i] = (tunnelIndex[i] + 1) % 8;
  }
}

int flopX = 0;
int flopY = 0;
int flopZ = 0;
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
  if (std::equal(std::begin(grid[xpos][ypos][zpos]), std::end(grid[xpos][ypos][zpos]), std::begin(allColors[color])))
  {
    color = nextColor(color);
  }
  grid[xpos][ypos][zpos][0] = allColors[color][0];
  grid[xpos][ypos][zpos][1] = allColors[color][1];
  grid[xpos][ypos][zpos][2] = allColors[color][2];
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
    grid[xpos][ypos][zpos][0] = allColors[color][0];
    grid[xpos][ypos][zpos][1] = allColors[color][1];
    grid[xpos][ypos][zpos][2] = allColors[color][2];
  }

  if (reverseX)
    swapint(startx, endx);
  if (reverseY)
    swapint(starty, endy);
  if (reverseZ)
    swapint(startz, endz);
  grid[endx][endy][endz][0] = allColors[color][0];
  grid[endx][endy][endz][1] = allColors[color][1];
  grid[endx][endy][endz][2] = allColors[color][2];
}

void drawBoxWalls(int startx, int starty, int startz, int endx, int endy, int endz, int color)
{
  if (startx > endx)
    swapint(startx, endx);
  if (starty > endy)
    swapint(starty, endy);
  if (startz > endz)
    swapint(startz, endz);

  for (int i = startz; i <= endz; i++)
  {
    // draw y walls
    for (int j = starty; j <= endy; j++)
    {
      grid[startx][j][i][0] = allColors[color][0];
      grid[startx][j][i][1] = allColors[color][1];
      grid[startx][j][i][2] = allColors[color][2];

      grid[endx][j][i][0] = allColors[color][0];
      grid[endx][j][i][1] = allColors[color][1];
      grid[endx][j][i][2] = allColors[color][2];
    }
    // draw x walls
    for (int j = startx; j <= endx; j++)
    {
      grid[j][starty][i][0] = allColors[color][0];
      grid[j][starty][i][1] = allColors[color][1];
      grid[j][starty][i][2] = allColors[color][2];

      grid[j][endy][i][0] = allColors[color][0];
      grid[j][endy][i][1] = allColors[color][1];
      grid[j][endy][i][2] = allColors[color][2];
    }
  }
}

int countUp(String cmd)
{
  if (color < 3)
  {
    grid[xpos][ypos][zpos][0] = primaryColors[color][0];
    grid[xpos][ypos][zpos][1] = primaryColors[color][1];
    grid[xpos][ypos][zpos][2] = primaryColors[color][2];
    grid[3 - xpos][3 - ypos][3 - zpos][0] = primaryColors[color][0];
    grid[3 - xpos][3 - ypos][3 - zpos][1] = primaryColors[color][1];
    grid[3 - xpos][3 - ypos][3 - zpos][2] = primaryColors[color][2];
    color++;
  }
  else
  {
    color = 0;
    grid[xpos][ypos][zpos][0] = 4;
    grid[xpos][ypos][zpos][1] = 4;
    grid[xpos][ypos][zpos][2] = 4;
    grid[3 - xpos][3 - ypos][3 - zpos][0] = 4;
    grid[3 - xpos][3 - ypos][3 - zpos][1] = 4;
    grid[3 - xpos][3 - ypos][3 - zpos][2] = 4;
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
