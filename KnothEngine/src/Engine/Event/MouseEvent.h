#pragma once
#include "knothpch.h"
#include "Engine/Core.h"
#include "Event.h"

namespace Knoth {
	class KNOTH_API MouseMovedEvent : public Event{
	public:
		MouseMovedEvent(int x, int y) 
			: _MouseX(x), _MouseY(y) {}

		inline float GetX() const { return _MouseX; }
		inline float GetY() const { return _MouseY; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseMovedEvent: " << _MouseX << ", " << _MouseY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:
		float _MouseX, _MouseY;
	};

	class KNOTH_API MouseScrolledEvent : public Event {
	public:
		MouseScrolledEvent(float xOffset, float yOffset)
			: _XOffset(xOffset), _YOffset(yOffset){}

		inline float GetXOffset() const { return _XOffset; }
		inline float GetYOffset() const { return _YOffset; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << _XOffset << ", " << _YOffset;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:
		float _XOffset, _YOffset;
	};

	class KNOTH_API MouseButtonEvent : public Event {
	public:
		inline int GetMouseButton() const { return _button; }
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	protected:
		MouseButtonEvent(int button) : _button(button){}
		int _button;
	};

	class KNOTH_API MouseButtonPressedEvent : public MouseButtonEvent {
	public:
		MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << _button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class KNOTH_API MouseButtonReleasedEvent : public MouseButtonEvent {
	public:
		MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << _button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}