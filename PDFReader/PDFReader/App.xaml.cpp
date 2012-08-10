//
// App.xaml.cpp
// App 类的实现。
//

#include "pch.h"
#include "MainPage.xaml.h"

using namespace PDFReader;

using namespace Platform;
using namespace Windows::ApplicationModel;
using namespace Windows::ApplicationModel::Activation;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Interop;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

// “空白应用程序”模板在 http://go.microsoft.com/fwlink/?LinkId=234227 上提供

/// <summary>
/// 初始化单一实例应用程序对象。这是执行的创作代码的第一行，
/// 逻辑上等同于 main() 或 WinMain()。
/// </summary>
App::App()
{
	InitializeComponent();
	Suspending += ref new SuspendingEventHandler(this, &App::OnSuspending);
}

/// <summary>
/// 在应用程序由最终用户正常启动时进行调用。
/// 当启动应用程序以执行打开特定的文件或显示搜索结果等操作时
/// 将使用其他入口点。
/// </summary>
/// <param name="pArgs">Details about the launch request and process.</param>
void App::OnLaunched(Windows::ApplicationModel::Activation::LaunchActivatedEventArgs^ pArgs)
{
	// Do not repeat app initialization when already running, just ensure that
	// the window is active
	if (pArgs->PreviousExecutionState == ApplicationExecutionState::Running)
	{
		Window::Current->Activate();
		return;
	}

	if (pArgs->PreviousExecutionState == ApplicationExecutionState::Terminated)
	{
		//TODO: 从之前挂起的应用程序加载状态
	}

	// 创建一个 Frame 以用作导航上下文并导航至第一页
	auto rootFrame = ref new Frame();
	if (!rootFrame->Navigate(TypeName(MainPage::typeid)))
	{
		throw ref new FailureException("Failed to create initial page");
	}

	// 将 Frame 放置在当前窗口中并确保其处于活动状态
	Window::Current->Content = rootFrame;
	Window::Current->Activate();
}

/// <summary>
/// 在将要挂起应用程序执行时调用。在不知道应用程序
/// 将被终止还是恢复的情况下保存应用程序状态，
/// 并让内存内容保持不变。
/// </summary>
/// <param name="sender">挂起的请求的源。</param>
/// <param name="e">有关挂起的请求的详细信息。</param>
void App::OnSuspending(Object^ sender, SuspendingEventArgs^ e)
{
	(void) sender;	// Unused parameter
	(void) e;	// Unused parameter

	//TODO: 保存应用程序状态并停止任何后台活动
}
