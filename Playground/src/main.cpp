
#include <cstdint>
#include <vector>

#include <esat/window.h>
#include <esat/draw.h>
#include <esat/sprite.h>
#include <esat/input.h>
#include <esat/time.h>

#include "Grid.hpp"
#include "Agent.hpp"
#include "Render.hpp"

const uint32_t kWindowWidth = 640;
const uint32_t kWindowHeight = 480;

int esat::main(int, char **) {

  esat::WindowInit(kWindowWidth, kWindowHeight);
  esat::WindowSetMouseVisibility(true);


  while (esat::WindowIsOpened() && !esat::IsSpecialKeyDown(esat::kSpecialKey_Escape)) {
    esat::DrawBegin();
    esat::DrawClear(0, 0, 0);


    esat::DrawEnd();
    esat::WindowFrame();
  }
  
  esat::WindowDestroy();

  return 0;
}
