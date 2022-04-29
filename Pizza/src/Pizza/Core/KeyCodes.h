#pragma once

namespace Pizza
{
	typedef enum class KeyCode : uint16_t
	{
		// From glfw3.h
		Space               = 32,
		Apostrophe          = 39, /* ' */
		Comma               = 44, /* , */
		Minus               = 45, /* - */
		Period              = 46, /* . */
		Slash               = 47, /* / */

		D0                  = 48, /* 0 */
		D1                  = 49, /* 1 */
		D2                  = 50, /* 2 */
		D3                  = 51, /* 3 */
		D4                  = 52, /* 4 */
		D5                  = 53, /* 5 */
		D6                  = 54, /* 6 */
		D7                  = 55, /* 7 */
		D8                  = 56, /* 8 */
		D9                  = 57, /* 9 */

		Semicolon           = 59, /* ; */
		Equal               = 61, /* = */

		A                   = 65,
		B                   = 66,
		C                   = 67,
		D                   = 68,
		E                   = 69,
		F                   = 70,
		G                   = 71,
		H                   = 72,
		I                   = 73,
		J                   = 74,
		K                   = 75,
		L                   = 76,
		M                   = 77,
		N                   = 78,
		O                   = 79,
		P                   = 80,
		Q                   = 81,
		R                   = 82,
		S                   = 83,
		T                   = 84,
		U                   = 85,
		V                   = 86,
		W                   = 87,
		X                   = 88,
		Y                   = 89,
		Z                   = 90,

		LeftBracket         = 91,  /* [ */
		Backslash           = 92,  /* \ */
		RightBracket        = 93,  /* ] */
		GraveAccent         = 96,  /* ` */

		World1              = 161, /* non-US #1 */
		World2              = 162, /* non-US #2 */

		/* Function keys */
		Escape              = 256,
		Enter               = 257,
		Tab                 = 258,
		Backspace           = 259,
		Insert              = 260,
		Delete              = 261,
		Right               = 262,
		Left                = 263,
		Down                = 264,
		Up                  = 265,
		PageUp              = 266,
		PageDown            = 267,
		Home                = 268,
		End                 = 269,
		CapsLock            = 280,
		ScrollLock          = 281,
		NumLock             = 282,
		PrintScreen         = 283,
		Pause               = 284,
		F1                  = 290,
		F2                  = 291,
		F3                  = 292,
		F4                  = 293,
		F5                  = 294,
		F6                  = 295,
		F7                  = 296,
		F8                  = 297,
		F9                  = 298,
		F10                 = 299,
		F11                 = 300,
		F12                 = 301,
		F13                 = 302,
		F14                 = 303,
		F15                 = 304,
		F16                 = 305,
		F17                 = 306,
		F18                 = 307,
		F19                 = 308,
		F20                 = 309,
		F21                 = 310,
		F22                 = 311,
		F23                 = 312,
		F24                 = 313,
		F25                 = 314,

		/* Keypad */
		KP0                 = 320,
		KP1                 = 321,
		KP2                 = 322,
		KP3                 = 323,
		KP4                 = 324,
		KP5                 = 325,
		KP6                 = 326,
		KP7                 = 327,
		KP8                 = 328,
		KP9                 = 329,
		KPDecimal           = 330,
		KPDivide            = 331,
		KPMultiply          = 332,
		KPSubtract          = 333,
		KPAdd               = 334,
		KPEnter             = 335,
		KPEqual             = 336,

		LeftShift           = 340,
		LeftControl         = 341,
		LeftAlt             = 342,
		LeftSuper           = 343,
		RightShift          = 344,
		RightControl        = 345,
		RightAlt            = 346,
		RightSuper          = 347,
		Menu                = 348
	} Key;

	inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
	{
		os << static_cast<int32_t>(keyCode);
		return os;
	}
}

// From glfw3.h
#define PZ_KEY_SPACE           ::Pizza::Key::Space
#define PZ_KEY_APOSTROPHE      ::Pizza::Key::Apostrophe    /* ' */
#define PZ_KEY_COMMA           ::Pizza::Key::Comma         /* , */
#define PZ_KEY_MINUS           ::Pizza::Key::Minus         /* - */
#define PZ_KEY_PERIOD          ::Pizza::Key::Period        /* . */
#define PZ_KEY_SLASH           ::Pizza::Key::Slash         /* / */
#define PZ_KEY_0               ::Pizza::Key::D0
#define PZ_KEY_1               ::Pizza::Key::D1
#define PZ_KEY_2               ::Pizza::Key::D2
#define PZ_KEY_3               ::Pizza::Key::D3
#define PZ_KEY_4               ::Pizza::Key::D4
#define PZ_KEY_5               ::Pizza::Key::D5
#define PZ_KEY_6               ::Pizza::Key::D6
#define PZ_KEY_7               ::Pizza::Key::D7
#define PZ_KEY_8               ::Pizza::Key::D8
#define PZ_KEY_9               ::Pizza::Key::D9
#define PZ_KEY_SEMICOLON       ::Pizza::Key::Semicolon     /* ; */
#define PZ_KEY_EQUAL           ::Pizza::Key::Equal         /* = */
#define PZ_KEY_A               ::Pizza::Key::A
#define PZ_KEY_B               ::Pizza::Key::B
#define PZ_KEY_C               ::Pizza::Key::C
#define PZ_KEY_D               ::Pizza::Key::D
#define PZ_KEY_E               ::Pizza::Key::E
#define PZ_KEY_F               ::Pizza::Key::F
#define PZ_KEY_G               ::Pizza::Key::G
#define PZ_KEY_H               ::Pizza::Key::H
#define PZ_KEY_I               ::Pizza::Key::I
#define PZ_KEY_J               ::Pizza::Key::J
#define PZ_KEY_K               ::Pizza::Key::K
#define PZ_KEY_L               ::Pizza::Key::L
#define PZ_KEY_M               ::Pizza::Key::M
#define PZ_KEY_N               ::Pizza::Key::N
#define PZ_KEY_O               ::Pizza::Key::O
#define PZ_KEY_P               ::Pizza::Key::P
#define PZ_KEY_Q               ::Pizza::Key::Q
#define PZ_KEY_R               ::Pizza::Key::R
#define PZ_KEY_S               ::Pizza::Key::S
#define PZ_KEY_T               ::Pizza::Key::T
#define PZ_KEY_U               ::Pizza::Key::U
#define PZ_KEY_V               ::Pizza::Key::V
#define PZ_KEY_W               ::Pizza::Key::W
#define PZ_KEY_X               ::Pizza::Key::X
#define PZ_KEY_Y               ::Pizza::Key::Y
#define PZ_KEY_Z               ::Pizza::Key::Z
#define PZ_KEY_LEFT_BRACKET    ::Pizza::Key::LeftBracket   /* [ */
#define PZ_KEY_BACKSLASH       ::Pizza::Key::Backslash     /* \ */
#define PZ_KEY_RIGHT_BRACKET   ::Pizza::Key::RightBracket  /* ] */
#define PZ_KEY_GRAVE_ACCENT    ::Pizza::Key::GraveAccent   /* ` */
#define PZ_KEY_WORLD_1         ::Pizza::Key::World1        /* non-US #1 */
#define PZ_KEY_WORLD_2         ::Pizza::Key::World2        /* non-US #2 */

/* Function keys */
#define PZ_KEY_ESCAPE          ::Pizza::Key::Escape
#define PZ_KEY_ENTER           ::Pizza::Key::Enter
#define PZ_KEY_TAB             ::Pizza::Key::Tab
#define PZ_KEY_BACKSPACE       ::Pizza::Key::Backspace
#define PZ_KEY_INSERT          ::Pizza::Key::Insert
#define PZ_KEY_DELETE          ::Pizza::Key::Delete
#define PZ_KEY_RIGHT           ::Pizza::Key::Right
#define PZ_KEY_LEFT            ::Pizza::Key::Left
#define PZ_KEY_DOWN            ::Pizza::Key::Down
#define PZ_KEY_UP              ::Pizza::Key::Up
#define PZ_KEY_PAGE_UP         ::Pizza::Key::PageUp
#define PZ_KEY_PAGE_DOWN       ::Pizza::Key::PageDown
#define PZ_KEY_HOME            ::Pizza::Key::Home
#define PZ_KEY_END             ::Pizza::Key::End
#define PZ_KEY_CAPS_LOCK       ::Pizza::Key::CapsLock
#define PZ_KEY_SCROLL_LOCK     ::Pizza::Key::ScrollLock
#define PZ_KEY_NUM_LOCK        ::Pizza::Key::NumLock
#define PZ_KEY_PRINT_SCREEN    ::Pizza::Key::PrintScreen
#define PZ_KEY_PAUSE           ::Pizza::Key::Pause
#define PZ_KEY_F1              ::Pizza::Key::F1
#define PZ_KEY_F2              ::Pizza::Key::F2
#define PZ_KEY_F3              ::Pizza::Key::F3
#define PZ_KEY_F4              ::Pizza::Key::F4
#define PZ_KEY_F5              ::Pizza::Key::F5
#define PZ_KEY_F6              ::Pizza::Key::F6
#define PZ_KEY_F7              ::Pizza::Key::F7
#define PZ_KEY_F8              ::Pizza::Key::F8
#define PZ_KEY_F9              ::Pizza::Key::F9
#define PZ_KEY_F10             ::Pizza::Key::F10
#define PZ_KEY_F11             ::Pizza::Key::F11
#define PZ_KEY_F12             ::Pizza::Key::F12
#define PZ_KEY_F13             ::Pizza::Key::F13
#define PZ_KEY_F14             ::Pizza::Key::F14
#define PZ_KEY_F15             ::Pizza::Key::F15
#define PZ_KEY_F16             ::Pizza::Key::F16
#define PZ_KEY_F17             ::Pizza::Key::F17
#define PZ_KEY_F18             ::Pizza::Key::F18
#define PZ_KEY_F19             ::Pizza::Key::F19
#define PZ_KEY_F20             ::Pizza::Key::F20
#define PZ_KEY_F21             ::Pizza::Key::F21
#define PZ_KEY_F22             ::Pizza::Key::F22
#define PZ_KEY_F23             ::Pizza::Key::F23
#define PZ_KEY_F24             ::Pizza::Key::F24
#define PZ_KEY_F25             ::Pizza::Key::F25

/* Keypad */
#define PZ_KEY_KP_0            ::Pizza::Key::KP0
#define PZ_KEY_KP_1            ::Pizza::Key::KP1
#define PZ_KEY_KP_2            ::Pizza::Key::KP2
#define PZ_KEY_KP_3            ::Pizza::Key::KP3
#define PZ_KEY_KP_4            ::Pizza::Key::KP4
#define PZ_KEY_KP_5            ::Pizza::Key::KP5
#define PZ_KEY_KP_6            ::Pizza::Key::KP6
#define PZ_KEY_KP_7            ::Pizza::Key::KP7
#define PZ_KEY_KP_8            ::Pizza::Key::KP8
#define PZ_KEY_KP_9            ::Pizza::Key::KP9
#define PZ_KEY_KP_DECIMAL      ::Pizza::Key::KPDecimal
#define PZ_KEY_KP_DIVIDE       ::Pizza::Key::KPDivide
#define PZ_KEY_KP_MULTIPLY     ::Pizza::Key::KPMultiply
#define PZ_KEY_KP_SUBTRACT     ::Pizza::Key::KPSubtract
#define PZ_KEY_KP_ADD          ::Pizza::Key::KPAdd
#define PZ_KEY_KP_ENTER        ::Pizza::Key::KPEnter
#define PZ_KEY_KP_EQUAL        ::Pizza::Key::KPEqual

#define PZ_KEY_LEFT_SHIFT      ::Pizza::Key::LeftShift
#define PZ_KEY_LEFT_CONTROL    ::Pizza::Key::LeftControl
#define PZ_KEY_LEFT_ALT        ::Pizza::Key::LeftAlt
#define PZ_KEY_LEFT_SUPER      ::Pizza::Key::LeftSuper
#define PZ_KEY_RIGHT_SHIFT     ::Pizza::Key::RightShift
#define PZ_KEY_RIGHT_CONTROL   ::Pizza::Key::RightControl
#define PZ_KEY_RIGHT_ALT       ::Pizza::Key::RightAlt
#define PZ_KEY_RIGHT_SUPER     ::Pizza::Key::RightSuper
#define PZ_KEY_MENU            ::Pizza::Key::Menu
