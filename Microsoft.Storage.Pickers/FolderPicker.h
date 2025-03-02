#pragma once
#include "FolderPicker.g.h"
#include "PickerCommon.h"

namespace winrt::Microsoft::Storage::Pickers::implementation
{
	struct FolderPicker : FolderPickerT<FolderPicker>
	{
		FolderPicker(winrt::Microsoft::UI::WindowId const& windowId);

		winrt::Microsoft::Storage::Pickers::PickerViewMode ViewMode();
		void ViewMode(winrt::Microsoft::Storage::Pickers::PickerViewMode const& value);

		hstring SettingsIdentifier();
		void SettingsIdentifier(hstring const& value);

		winrt::Microsoft::Storage::Pickers::PickerLocationId SuggestedStartLocation();
		void SuggestedStartLocation(winrt::Microsoft::Storage::Pickers::PickerLocationId const& value);

		hstring CommitButtonText();
		void CommitButtonText(hstring const& value);

		winrt::Windows::Foundation::Collections::IVector<hstring> FileTypeFilter();

		winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Storage::StorageFolder> PickSingleFolderAsync();

	private:
		winrt::Microsoft::UI::WindowId m_windowId{};

		PickerViewMode m_viewMode{ PickerViewMode::List };
		hstring m_settingsIdentifier{};
		PickerLocationId m_suggestedStartLocation{ PickerLocationId::Unspecified };
		hstring m_commitButtonText{};

		winrt::Windows::Foundation::Collections::IVector<hstring> m_fileTypeFilter{ winrt::single_threaded_vector<hstring>() };

		void CaptureParameters(PickerCommon::PickerParameters& parameters);
	};
}
namespace winrt::Microsoft::Storage::Pickers::factory_implementation
{
	struct FolderPicker : FolderPickerT<FolderPicker, implementation::FolderPicker>
	{
	};
}
