#pragma once
#include "veWindow.hpp"
#include "veDevice.hpp"
namespace vengin {
	class applic
	{
	public:
		applic();
		~applic();
		//��ֹ��������
		applic(const applic&) = delete;
		applic& operator=(const applic&) = delete;
		
		void run();
	private:
		veWindow vWindow{800,600,"hello vulkan"};
	};
}
