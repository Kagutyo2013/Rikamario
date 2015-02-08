#ifndef _TEXTURE_H
#define _TEXTURE_H

namespace asset{
	class Texture{
	private:
		int m_handle;		//�摜�n���h��
		int m_width = 0;	//�摜�̕�
		int m_height = 0;	//�摜�n���h��
	public:
		Texture() = default;
		
		virtual ~Texture(){
			if (m_handle == -1){
				DeleteGraph(m_handle);
			}
		}

		inline void setHandle(const int&handle){
			m_handle = handle;
		}
		inline void setWidth(const int&width){
			m_width = width;
		}
		inline void setHeight(const int&height){
			m_height = height;
		}

		inline const int& getHandle()const{
			return m_handle;
		}
		inline const int& getWidth()const{
			return m_width;
		}
		inline const int& getHeight()const{
			return m_height;
		}
	};
}

#endif