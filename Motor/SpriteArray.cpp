#include "SpriteArray.h"
SpriteArray::SpriteArray() {

}
SpriteArray::~SpriteArray() {

}
void SpriteArray::add() {
	Sprite sprite;
	double x, y, w, h;
	x = (double)rand() / RAND_MAX * 2 - 1;
	y = (double)rand() / RAND_MAX * 2 - 1;
	w = h = (double)rand() / RAND_MAX;
	if (y + h > 1) {
		h = w = 1 - y;
	}
	if (x + w > 1) {
		w = h = 1 - x;
	}
	sprite.init(x, y, w, h);
	sprites.push_back(sprite);
}
void SpriteArray::draw() {
	for (int i = 0; i < sprites.size(); i++) {
		sprites[i].draw();
	}
}
void SpriteArray::del() {
	if (!sprites.empty()) sprites.erase(sprites.begin());
}
int SpriteArray::get_size() {
	return sprites.size();
}