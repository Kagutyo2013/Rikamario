#ifndef BLOCK_OBJECT_BASE
#define BLOCK_OBJECT_BASE

#include "TextureFactory.h"
#include "SoundFactory.h"
#include "Sprite.h"
#include "Root.h"
#include "AssetContainer.h"
#include "Texture.h"
#include "Sound.h"

class BlockObjBase{
private: 
	
protected:
	int m_x;
	int m_y;
	int m_blocktype;
	int m_blockstat;
	std::shared_ptr<Sprite> sp_block;

public:
	//èâä˙âª
	virtual void init(const std::unique_ptr<Root>& root) = 0;
	
	//loadån
	virtual void loadTexture(const std::unique_ptr<Root>& root) = 0;

	//çXêV
	virtual void update() = 0;
	
	//getån
	void setBlockType(const int& type){
		m_blocktype = type;
	}
	void setBlockStat(const int& stat){
		m_blocktype = stat;
	}
	void setPosition(const int& select, const int& arg){
		if (select == 0){
			m_x = arg;
		}
		if (select == 1){
			m_y = arg;
		}
	}

	//setån
	const int getBlockType()const{
		return m_blocktype;
	}
	const int getBlockStat()const{
		return m_blockstat;
	}
	const int getPosition(int select)const{
		if (select == 0){
			return m_x;
		}
		if (select == 1){
			return m_y;
		}
		return -1;
	}

	virtual void setDrawIn(const std::unique_ptr<Root>& root) = 0;

	virtual void setDrawOut(const std::unique_ptr<Root>& root) = 0;

};

#endif