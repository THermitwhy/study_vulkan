#pragma once
#include "veWindow.hpp"
namespace vengin {
	struct QueueFamilyIndices {
		uint32_t graphicsFamily;
		uint32_t presentFamily;
		bool graphicsFamilyHasValue = false;
		bool presentFamilyHasValue = false;
		bool isComplete() { return graphicsFamilyHasValue && presentFamilyHasValue; }
	};
	struct SwapChainSupportDetails {
		VkSurfaceCapabilitiesKHR capabilities;
		std::vector<VkSurfaceFormatKHR> formats;
		std::vector<VkPresentModeKHR> presentModes;
	};
	class veDevice
	{
	public:
#ifdef NDEBUG
		const bool enableValidationLayers = false;
#else
		const bool enableValidationLayers = true;
#endif
		veDevice(veWindow &window);
		~veDevice();
		//��ֹ����
		veDevice(veDevice&) = delete;
		veDevice& operator=(veDevice&) = delete;

		void createInstance();//����ʵ��
	private:
		//object
		VkInstance instance;//ʵ��
		VkDebugUtilsMessengerEXT debugMessenger;//debug����
		VkDevice device_;//�߼��豸
		VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;//�����豸,��ʼ��λ��
		VkSurfaceKHR surface_;//��Ⱦ����
		veWindow& window;//���ڶ���
		VkQueue graphicsQueue_, presentQueue_;//��Ⱦ����ֶ���
		//function
		std::vector<const char*> getRequiredExtensions();//��ȡ��չ
		void hasGflwRequiredInstanceExtensions();//�ж��Ƿ�֧����Ҫ����չ
		bool checkValidationLayerSupport();//�ж��Ƿ�֧��������֤��
		void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);//���ص�����������Ľṹ��
		void setupDebugMessenger();//���ûص�
		void pickPhysicalDevice();//ѡȡ�����豸
		void createSurface();
		void createLogicalDevice();//�����߼��豸
		bool isDeviceSuitable(VkPhysicalDevice device);//ɸѡ�����豸
		QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);//�õ����ʵĶ����������
		SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);//��ȡ��Ⱦ����֧�ֵĹ���
		const std::vector<const char*> validationLayers = { "VK_LAYER_KHRONOS_validation" };//�����Ҫ��У���
		const std::vector<const char*> deviceExtensions = { VK_KHR_SWAPCHAIN_EXTENSION_NAME };
	};
}