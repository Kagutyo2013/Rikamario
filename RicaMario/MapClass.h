#ifndef _MAPCLASS_H
#define _MAPCLASS_H

#define MAP_XSIZE 20
#define MAP_YSIZE 15

#include "BlockObjectBase.h"
#include "Block0.h"
#include "Block1.h"

class MapClass{
private:
	//マップのデータ
	std::vector<std::vector<int>> m_mapdata;
	std::vector<std::vector<std::unique_ptr<BlockObjBase>>> m_blocks;

	//ブロックの変更
	void changeBlock(const int x, const int y, const int id, const std::unique_ptr<Root>& root);
public:
	//初期化
	void init();

	//ロード
	void loadTexture(const std::unique_ptr<Root>& root);
	
	//設定
	void set(const std::unique_ptr<Root>& root);

	//更新
	void update();

	//その他
	void setDrawIn(const std::unique_ptr<Root>& root);
	void setDrawOut(const std::unique_ptr<Root>& root);
};
#endif