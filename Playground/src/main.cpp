
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

  Grid grid(kWindowWidth, kWindowHeight, 32.0f);

  Agent agent;
  agent.set_position({100.0f, 100.0f});
  agent.set_scale(32.0f);

  Agent agent2;
  agent2.set_position({300.0f, 100.0f});
  agent2.set_scale(32.0f);

  std::vector<Drawable*> draw_list;
  draw_list.push_back(&agent);
  draw_list.push_back(&agent2);

  grid.add_object(agent2, 40);
  grid.add_object(agent, 100);

  Render render;

  while (esat::WindowIsOpened() && !esat::IsSpecialKeyDown(esat::kSpecialKey_Escape)) {
    esat::DrawBegin();
    esat::DrawClear(0, 0, 0);

    grid.draw();
    render.draw(draw_list);


    esat::DrawEnd();
    esat::WindowFrame();
  }
  
  esat::WindowDestroy();

  return 0;
}
