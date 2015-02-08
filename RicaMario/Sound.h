#ifndef _SOUND_H
#define _SOUND_H

namespace asset{
	class Sound{
	private:
		int m_handle;		//�T�E���h�n���h��
	public:
		Sound() = default;

		virtual ~Sound(){
			if (m_handle == -1){
				DeleteSoundMem(m_handle);
			}
		}

		inline void setHandle(const int&handle){
			m_handle = handle;
		}

		inline const int& getHandle()const{
			return m_handle;
		}

		//�Đ��֐�
		void play()const{
			if (m_handle != -1){
				PlaySoundMem(m_handle,DX_PLAYTYPE_BACK,true);
			}
		}
		//��~�֐�
		void stop()const{
			StopSoundMem(m_handle);
		}
		//�Đ�����֐�
		bool isPlaying()const{
			if (m_handle != -1){
				return CheckSoundMem(m_handle) == 1;
			}
			return false;
		}
		//���ʕύX�֐�
		void changeVolume(const int& volume){
			if (m_handle != -1){
				ChangeVolumeSoundMem(volume, m_handle);
			}
		}
	};
}

#endif