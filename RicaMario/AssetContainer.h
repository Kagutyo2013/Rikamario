#ifndef _ASSET_CONTAINER_H
#define _ASSET_CONTAINER_H

template < class Asset >
class AssetContainer{
protected:
	std::map<std::string, std::shared_ptr<Asset>> m_container;
public:
	AssetContainer() = default;
	virtual ~AssetContainer() = default;
	/*�I�u�W�F�N�g��o�^����
	**@param new_obj �o�^����I�u�W�F�N�g�̃|�C���^
	**@param name �o�^���閼�O
	*/
	void registerObject(Asset* new_obj, const std::string& name){
		m_container.insert(std::make_pair(name, std::shared_ptr<Asset>(new_obj)));
	}
	/*�o�^�����I�u�W�F�N�g�̒����疼�O�ŒT��
	**@param �o�^�������O
	*/
	const std::shared_ptr<Asset> findAssetByname(const std::string& name){
		return m_container.find(name)->second;
	}

	//�o�^�����f�[�^�ɕs���ȃf�[�^�������Ă����ꍇ�Atrue��Ԃ�
	const bool includeInvalidObject()const{
		for (const auto& obj : m_container){
			if (obj.second->getHandle() == -1){
				return true;
			}
		}
		return false;
	}
};

#endif