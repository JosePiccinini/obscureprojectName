/*
 * =====================================================================================
 *
 *       Filename:  win32_handmade.cpp
 *
 !*    Description: Base entry point for the game
 *
 *        Version:  1.0
 *        Created:  10/4/2017 1:48:45 PM
 *       Revision:  none
 *       Compiler:  c++
 *
 *         Author:  Jose Piccinini
 *
 * =====================================================================================
 */

#include <windows.h>

	LRESULT CALLBACK
MainWindowCallback(HWND Window,
		UINT Message,
		WPARAM WParam,
		LPARAM LParam)
{
	LRESULT result = 0;
	switch(Message)
	{
		case WM_SIZE:
			{
				OutputDebugString("WM_SIZE\n");
			} break;
		case WM_DESTROY:
			{
				OutputDebugString("WM_DESTROY\n");
			} break;
		case WM_CLOSE:
			{
				OutputDebugString("WM_CLOSE\n");
			} break;
		case WM_ACTIVATEAPP:
			{
				OutputDebugString("WM_ACTIVATEAPP\n");
			} break;
		case WM_PAINT:
			{
				PAINTSTRUCT Paint;
				HDC DeviceContext = BeginPaint(Window, &Paint);
				int X = Paint.rcPaint.left;
				int Y = Paint.rcPaint.top;
				int Height = Paint.rcPaint.right - Paint.rcPaint.left;
				int Width = Paint.rcPaint.bottom - Paint.rcPaint.top; 
				PatBlt(DeviceContext, X, Y, Width, Height, WHITENESS);
				EndPaint(Window, &Paint);
			} break;
		default:
			{
				result = DefWindowProc(Window, Message, WParam, LParam);
			} break;
	}
	return(result);
}

	int CALLBACK
WinMain(HINSTANCE Instance,
		HINSTANCE PrevInstance,
		LPSTR CommandLine,
		int ShowCode)
{
	WNDCLASS WindowClass = {};
	WindowClass.style = CS_OWNDC|CS_HREDRAW|CS_VREDRAW;
	WindowClass.lpfnWndProc = MainWindowCallback;
	WindowClass.hInstance = Instance;
	WindowClass.lpszClassName = "HandmadeHeroWindowClass";

	if (RegisterClass(&WindowClass))
	{
		HWND WindowHandle =
			CreateWindowEx(
					0,
					WindowClass.lpszClassName,
					"Handmade Hero",
					WS_OVERLAPPEDWINDOW|WS_VISIBLE,
					CW_USEDEFAULT,
					CW_USEDEFAULT,
					CW_USEDEFAULT,
					CW_USEDEFAULT,
					0,
					0,
					Instance,
					0);

		if (WindowHandle)
		{
			for(;;)
			{
				MSG	Message;
				BOOL MessageResult = GetMessage(&Message, 0, 0, 0);
				if (MessageResult > 0)
				{
					TranslateMessage(&Message);
					DispatchMessage(&Message);

				}
				else
				{
					break;
				}
			}
		}
		else
		{
			return 1;
		}
	}
return 0;
}
