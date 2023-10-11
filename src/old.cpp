// void oldPlanarSpin()
// {
//   for (int i = 0; i < 100; i++)
//   {
//     int spinsPerColor = 20; // a spin is actually half a revolution
//     for (int i = 0; i < spinsPerColor; i++)
//     {
//       for (int x = 0; x < 3; x++)
//       {
//         drawLine(color, x, 0, 0, 3 - x, 3, 0);
//         drawLine(color, x, 0, 1, 3 - x, 3, 1);
//         drawLine(color, x, 0, 2, 3 - x, 3, 2);
//         drawLine(color, x, 0, 3, 3 - x, 3, 3);
//       }
//       for (int y = 0; y < 3; y++)
//       {
//         drawLine(color, 3, y, 0, 0, 3 - y, 0);
//         drawLine(color, 3, y, 1, 0, 3 - y, 1);
//         drawLine(color, 3, y, 2, 0, 3 - y, 2);
//         drawLine(color, 3, y, 3, 0, 3 - y, 3);
//       }
//       for (int i = 0; i < 100; i++)
//       {
//         rgbMainLoop();
//       }
//     }
//     color = nextColor(color);
//   }
// }

// int countUpOld(String cmd)
// {

//     int delayTime = 500;
//     if (sscanf(cmd, "%d", &delayTime) == 1)
//     {
//         Log.info("delayTime=%d", delayTime);
//     }
//     set_pins(D3, D7); // (0,0,0, Red)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A7, D3); // (0,0,1, Red)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A3, A7); // (0,0,2, Red)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D7, A3); // (0,0,3, Red)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D2, D7); // (0,1,0, Red)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A6, D2); // (0,1,1, Red)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A2, A6); // (0,1,2, Red)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D7, A2); // (0,1,3, Red)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D1, D7); // (0,2,0, Red)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A5, D1); // (0,2,1, Red)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A1, A5); // (0,2,2, Red)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D7, A1); // (0,2,3, Red)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D0, D7); // (0,3,0, Red)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A4, D0); // (0,3,1, Red)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A0, A4); // (0,3,2, Red)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D7, A0); // (0,3,3, Red)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D3, D6); // (1,0,0, Red)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A4, D3); // (1,0,1, Red)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A2, A4); // (1,0,2, Red)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D6, A2); // (1,0,3, Red)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D2, D6); // (1,1,0, Red)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A5, D2); // (1,1,1, Red)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A3, A5); // (1,1,2, Red)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D6, A3); // (1,1,3, Red)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D1, D6); // (1,2,0, Red)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A6, D1); // (1,2,1, Red)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A0, A6); // (1,2,2, Red)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D6, A0); // (1,2,3, Red)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D0, D6); // (1,3,0, Red)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A7, D0); // (1,3,1, Red)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A1, A7); // (1,3,2, Red)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D6, A1); // (1,3,3, Red)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D3, D5); // (2,0,0, Red)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A6, D3); // (2,0,1, Red)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A1, A6); // (2,0,2, Red)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D5, A1); // (2,0,3, Red)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D2, D5); // (2,1,0, Red)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A7, D2); // (2,1,1, Red)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A0, A7); // (2,1,2, Red)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D5, A0); // (2,1,3, Red)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D1, D5); // (2,2,0, Red)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A4, D1); // (2,2,1, Red)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A3, A4); // (2,2,2, Red)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D5, A3); // (2,2,3, Red)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D0, D5); // (2,3,0, Red)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A5, D0); // (2,3,1, Red)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A2, A5); // (2,3,2, Red)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D5, A2); // (2,3,3, Red)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D3, D4); // (3,0,0, Red)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A5, D3); // (3,0,1, Red)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A0, A5); // (3,0,2, Red)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D4, A0); // (3,0,3, Red)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D2, D4); // (3,1,0, Red)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A4, D2); // (3,1,1, Red)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A1, A4); // (3,1,2, Red)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D4, A1); // (3,1,3, Red)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D1, D4); // (3,2,0, Red)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A7, D1); // (3,2,1, Red)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A2, A7); // (3,2,2, Red)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D4, A2); // (3,2,3, Red)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D0, D4); // (3,3,0, Red)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A6, D0); // (3,3,1, Red)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A3, A6); // (3,3,2, Red)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D4, A3); // (3,3,3, Red)
//     delay(delayTime);
//     reset_all_pins();

//     set_pins(D3, A3); // (0,0,0, Green)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A7, D7); // (0,0,1, Green)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A3, D3); // (0,0,2, Green)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D7, A7); // (0,0,3, Green)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D2, A2); // (0,1,0, Green)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A6, D7); // (0,1,1, Green)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A2, D2); // (0,1,2, Green)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D7, A6); // (0,1,3, Green)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D1, A1); // (0,2,0, Green)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A5, D7); // (0,2,1, Green)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A1, D1); // (0,2,2, Green)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D7, A5); // (0,2,3, Green)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D0, A0); // (0,3,0, Green)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A4, D7); // (0,3,1, Green)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A0, D0); // (0,3,2, Green)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D7, A4); // (0,3,3, Green)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D3, A2); // (1,0,0, Green)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A4, D6); // (1,0,1, Green)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A2, D3); // (1,0,2, Green)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D6, A4); // (1,0,3, Green)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D2, A3); // (1,1,0, Green)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A5, D6); // (1,1,1, Green)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A3, D2); // (1,1,2, Green)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D6, A5); // (1,1,3, Green)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D1, A0); // (1,2,0, Green)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A6, D6); // (1,2,1, Green)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A0, D1); // (1,2,2, Green)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D6, A6); // (1,2,3, Green)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D0, A1); // (1,3,0, Green)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A7, D6); // (1,3,1, Green)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A1, D0); // (1,3,2, Green)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D6, A7); // (1,3,3, Green)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D3, A1); // (2,0,0, Green)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A6, D5); // (2,0,1, Green)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A1, D3); // (2,0,2, Green)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D5, A6); // (2,0,3, Green)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D2, A0); // (2,1,0, Green)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A7, D5); // (2,1,1, Green)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A0, D2); // (2,1,2, Green)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D5, A7); // (2,1,3, Green)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D1, A3); // (2,2,0, Green)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A4, D5); // (2,2,1, Green)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A3, D1); // (2,2,2, Green)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D5, A4); // (2,2,3, Green)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D0, A2); // (2,3,0, Green)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A5, D5); // (2,3,1, Green)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A2, D0); // (2,3,2, Green)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D5, A5); // (2,3,3, Green)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D3, A0); // (3,0,0, Green)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A5, D4); // (3,0,1, Green)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A0, D3); // (3,0,2, Green)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D4, A5); // (3,0,3, Green)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D2, A1); // (3,1,0, Green)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A4, D4); // (3,1,1, Green)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A1, D2); // (3,1,2, Green)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D4, A4); // (3,1,3, Green)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D1, A2); // (3,2,0, Green)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A7, D4); // (3,2,1, Green)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A2, D1); // (3,2,2, Green)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D4, A7); // (3,2,3, Green)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D0, A3); // (3,3,0, Green)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A6, D4); // (3,3,1, Green)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A3, D0); // (3,3,2, Green)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D4, A6); // (3,3,3, Green)
//     delay(delayTime);
//     reset_all_pins();

//     set_pins(D3, A7); // (0,0,0, Blue)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A7, A3); // (0,0,1, Blue)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A3, D7); // (0,0,2, Blue)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D7, D3); // (0,0,3, Blue)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D2, A6); // (0,1,0, Blue)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A6, A2); // (0,1,1, Blue)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A2, D7); // (0,1,2, Blue)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D7, D2); // (0,1,3, Blue)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D1, A5); // (0,2,0, Blue)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A5, A1); // (0,2,1, Blue)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A1, D7); // (0,2,2, Blue)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D7, D1); // (0,2,3, Blue)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D0, A4); // (0,3,0, Blue)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A4, A0); // (0,3,1, Blue)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A0, D7); // (0,3,2, Blue)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D7, D0); // (0,3,3, Blue)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D3, A4); // (1,0,0, Blue)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A4, A2); // (1,0,1, Blue)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A2, D6); // (1,0,2, Blue)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D6, D3); // (1,0,3, Blue)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D2, A5); // (1,1,0, Blue)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A5, A3); // (1,1,1, Blue)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A3, D6); // (1,1,2, Blue)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D6, D2); // (1,1,3, Blue)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D1, A6); // (1,2,0, Blue)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A6, A0); // (1,2,1, Blue)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A0, D6); // (1,2,2, Blue)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D6, D1); // (1,2,3, Blue)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D0, A7); // (1,3,0, Blue)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A7, A1); // (1,3,1, Blue)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A1, D6); // (1,3,2, Blue)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D6, D0); // (1,3,3, Blue)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D3, A6); // (2,0,0, Blue)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A6, A1); // (2,0,1, Blue)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A1, D5); // (2,0,2, Blue)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D5, D3); // (2,0,3, Blue)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D2, A7); // (2,1,0, Blue)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A7, A0); // (2,1,1, Blue)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A0, D5); // (2,1,2, Blue)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D5, D2); // (2,1,3, Blue)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D1, A4); // (2,2,0, Blue)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A4, A3); // (2,2,1, Blue)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A3, D5); // (2,2,2, Blue)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D5, D1); // (2,2,3, Blue)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D0, A5); // (2,3,0, Blue)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A5, A2); // (2,3,1, Blue)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A2, D5); // (2,3,2, Blue)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D5, D0); // (2,3,3, Blue)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D3, A5); // (3,0,0, Blue)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A5, A0); // (3,0,1, Blue)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A0, D4); // (3,0,2, Blue)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D4, D3); // (3,0,3, Blue)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D2, A4); // (3,1,0, Blue)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A4, A1); // (3,1,1, Blue)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A1, D4); // (3,1,2, Blue)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D4, D2); // (3,1,3, Blue)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D1, A7); // (3,2,0, Blue)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A7, A2); // (3,2,1, Blue)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A2, D4); // (3,2,2, Blue)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D4, D1); // (3,2,3, Blue)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D0, A6); // (3,3,0, Blue)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A6, A3); // (3,3,1, Blue)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(A3, D4); // (3,3,2, Blue)
//     delay(delayTime);
//     reset_all_pins();
//     set_pins(D4, D0); // (3,3,3, Blue)
//     delay(delayTime);
//     reset_all_pins();

//     return 1;
// }

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