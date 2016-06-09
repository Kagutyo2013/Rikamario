#include "MapClass.h"

void MapClass::init(){
	m_blocks.resize((MAP_YSIZE)+2);
	for (int i = 0; i < (MAP_YSIZE)+2; i++){
		m_blocks.at(i).resize((MAP_XSIZE)+2);
		for (int j = 0; j < (MAP_XSIZE)+2; j++){
			m_blocks.at(i).at(j).reset(new Block0());
		}
	}
}

void MapClass::loadTexture(const std::unique_ptr<Root>& root){
	std::unique_ptr<Block0> block0;
	block0.reset(new Block0());
	block0->loadTexture(root);

	std::unique_ptr<Block1> block1;
	block1.reset(new Block1());
	block1->loadTexture(root);
}

void MapClass::set(const std::unique_ptr<Root>& root){
	for (int i = 0; i < (MAP_YSIZE)+2; i++){
		for (int j = 0; j < (MAP_XSIZE)+2; j++){
			m_blocks.at(i).at(j)->init(root);
			m_blocks.at(i).at(j)->setPosition(0, j * 32 - 16);
			m_blocks.at(i).at(j)->setPosition(1, i * 32 - 16);
			m_blocks.at(i).at(j)->update();
		}
	}
}

void MapClass::update(){
	for (int i = 0; i < (MAP_YSIZE)+2; i++){
		for (int j = 0; j < (MAP_XSIZE)+2; j++){
			m_blocks.at(i).at(j)->update();
		}
	}
}


void MapClass::changeBlock(const int x,const int y,const int id, const std::unique_ptr<Root>& root){
	int m_x = m_blocks.at(x).at(y)->getPosition(0);
	int m_y = m_blocks.at(x).at(y)->getPosition(1);

	m_blocks.at(x).at(y).reset(new Block1());
	m_blocks.at(x).at(y)->init(root);
	m_blocks.at(x).at(y)->setPosition(0, m_x);
	m_blocks.at(x).at(y)->setPosition(1, m_y);
	m_blocks.at(x).at(y)->update();
}
void MapClass::setDrawIn(const std::unique_ptr<Root>& root){
	for (int i = 0; i < (MAP_YSIZE)+2; i++){
		for (int j = 0; j < (MAP_XSIZE)+2; j++){
			m_blocks.at(i).at(j)->setDrawIn(root);
		}
	}
}

void MapClass::setDrawOut(const std::unique_ptr<Root>& root){
	for (int i = 0; i < (MAP_YSIZE)+2; i++){
		for (int j = 0; j < (MAP_XSIZE)+2; j++){
			m_blocks.at(i).at(j)->setDrawOut(root);
		}
	}
}