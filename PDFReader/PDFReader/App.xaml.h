//
// App.xaml.h
// App 类的声明。
//

#pragma once

#include "App.g.h"

namespace PDFReader
{
	/// <summary>
	/// 提供特定于应用程序的行为，以补充默认的应用程序类。
	/// </summary>
	ref class App sealed
	{
	public:
		App();
		virtual void OnLaunched(Windows::ApplicationModel::Activation::LaunchActivatedEventArgs^ pArgs) override;

	private:
		void OnSuspending(Platform::Object^ sender, Windows::ApplicationModel::SuspendingEventArgs^ e);
	};
}
