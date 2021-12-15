#include "gdisplay.h"

bool init_gdisplay(gdisplay_t* gd)
{
	return gd->init_fn();
}

bool draw_gdisplay(gdisplay_t* gd, uint16_t col, uint16_t row, image_t* img)
{
	return gd->draw_fn(col,row,img->data,img->size);
}

bool clear_gdisplay(gdisplay_t* gd)
{
	return gd->clear_fn();
}
