#include "Block1.h"


//loadŒn

void Block1::loadTexture(const std::unique_ptr<Root>& root){
	auto new_tex = assetfactory::TextureFactory::createFromFile("image/block.bmp");
	root->tex_container.registerObject(new_tex, "Block1");
}


//‰Šú‰»
void Block1::init(const std::unique_ptr<Root>& root){
	m_blocktype = 0;
	m_blockstat = 0;
	sp_block.reset(new Sprite());
	sp_block->setTexture(root->tex_container.findAssetByname("Block1"));
}

//XV
void Block1::update(){
	sp_block->setPosition(m_x, m_y);
}
