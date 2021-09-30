#include "block.h"
#include <cmath>
#include <iostream>

int Block::height() const {
  return data[0].size();
}

int Block::width() const {
  return data.size();
}

void Block::render(PNG &im, int x) const {
   /**
   * Renders the given block onto img with its upper
   * left corner at (x, 0). Assumes block fits on the 
   * image.
   */
   for (int xcoord = 0; xcoord < (signed) data.size(); xcoord++) {
    for (int ycoord = 0; ycoord < (signed) data[0].size(); ycoord++) {
      *(im.getPixel(x + xcoord, ycoord)) = data[xcoord][ycoord];
   }
}
}

void Block::build(PNG &im, int x, int width) {
  /** 
   * Creates a block that is width X img.height pixels in size
   * by copying the pixels from (x, 0) to (x+width-1, img.height-1)
   * in img. Assumes img is large enough to supply these pixels.
   */
   for (int xcoord = x; xcoord < x+width; xcoord++) {
     vector<HSLAPixel> temp;
    for (int ycoord = 0; ycoord < (signed) im.height(); ycoord++) {
      temp.push_back(*im.getPixel(xcoord,ycoord));
    }
    data.push_back(temp);
  }
}
