/* Copyright 2021 ESAT. All rights reserved.    #####  #####      #     #####
* Author: Jose L. Hidalgo <jlhidalgo@esat.es>   #      #         # #      #
* Author: Gustavo Aranda <garanda@esat.es>      ###     ###     #   #     #
*                                               #          #   #     #    #
* Helpers                                       #####  #####  #       #   #
*/

#ifndef ESAT_HELPERS_H
#define ESAT_HELPERS_H 1

#include <esat/sprite.h>
#include <esat_extra/imgui.h>

namespace esat {

	void MemView(const char *window_title, const void* mem_ptr, size_t mem_size);
  
} /* esat */

namespace ImGui {
  // Helper method to include a SpriteHandle into an ImGui window
  IMGUI_API void ImageFromSpriteHandle(esat::SpriteHandle img, 
      const ImVec2& size, 
      const ImVec2& uv0 = ImVec2(0, 0), 
      const ImVec2& uv1 = ImVec2(1,1), 
      const ImVec4& tint_col = ImVec4(1,1,1,1), 
      const ImVec4& border_col = ImVec4(0,0,0,0));
} /* ImGui */

#endif