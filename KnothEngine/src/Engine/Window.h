#pragma once
#include "knothpch.h"
#include "Engine/Core.h"
#include "Engine/Event/Event.h"

namespace Knoth {
	struct WindowProps {
		std::string Title;
		unsigned int Width;
		unsigned int Height;
		WindowProps(const std::string title = "Knoth engine",
			unsigned int width, unsigned int height) :
			Title(title), Width(width), Height(height){}
	};

	class KNOTH_API	Window {
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window();
		virtual void OnUpdate();
		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		// Window attributes
		virtual void SetEventCallback(const EventCallbackFn& callback);
		virtual void SetVSync(bool enabled);
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};
}