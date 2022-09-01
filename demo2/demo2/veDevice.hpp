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
		//禁止拷贝
		veDevice(veDevice&) = delete;
		veDevice& operator=(veDevice&) = delete;

		void createInstance();//创建实例
	private:
		//object
		VkInstance instance;//实例
		VkDebugUtilsMessengerEXT debugMessenger;//debug代理
		VkDevice device_;//逻辑设备
		VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;//物理设备,初始化位空
		VkSurfaceKHR surface_;//渲染表面
		veWindow& window;//窗口对象
		VkQueue graphicsQueue_, presentQueue_;//渲染与呈现队列
		//function
		std::vector<const char*> getRequiredExtensions();//获取扩展
		void hasGflwRequiredInstanceExtensions();//判断是否支持需要的扩展
		bool checkValidationLayerSupport();//判断是否支持所需验证层
		void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);//填充回调代理函数所需的结构体
		void setupDebugMessenger();//设置回调
		void pickPhysicalDevice();//选取物理设备
		void createSurface();
		void createLogicalDevice();//创建逻辑设备
		bool isDeviceSuitable(VkPhysicalDevice device);//筛选物理设备
		QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);//得到合适的队列族的索引
		SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);//获取渲染表面支持的功能
		const std::vector<const char*> validationLayers = { "VK_LAYER_KHRONOS_validation" };//填充需要的校验层
		const std::vector<const char*> deviceExtensions = { VK_KHR_SWAPCHAIN_EXTENSION_NAME };
	};
}