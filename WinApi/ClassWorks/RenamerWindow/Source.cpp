#include <Windows.h>
#include <tchar.h>
#include <Windowsx.h>

LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK EnumWindowsProc(HWND, LPARAM);

TCHAR szClassWindow[] = TEXT("Класс окна");

INT WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPTSTR lpszCmdLine, int nCmdShow){
	HWND hWnd;
	MSG Msg;
	WNDCLASSEX wcl;

	wcl.cbSize = sizeof(wcl);
	wcl.style = CS_HREDRAW | CS_VREDRAW;
	wcl.lpfnWndProc = WindowProc;
	wcl.cbClsExtra = 0;
	wcl.cbWndExtra = 0;
	wcl.hInstance = hInst;	// дескриптор данного приложения
	wcl.hIcon = LoadIcon(NULL, IDI_APPLICATION);	// загрузка стандартной иконки
	wcl.hCursor = LoadCursor(NULL, IDC_ARROW);	// загрузка стандартного курсора	
	wcl.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// заполнение окна белым цветом
	wcl.lpszMenuName = NULL;	// приложение не содержит меню
	wcl.lpszClassName = szClassWindow;	// имя класса окна
	wcl.hIconSm = NULL;	// отсутствие маленькой иконки для связи с классом окна

	// 2. Регистрация класса окна
	if (!RegisterClassEx(&wcl))
		return 0; // при неудачной регистрации - выход

	// 3. Создание окна
	// создается окно и  переменной hWnd присваивается дескриптор окна
	hWnd = CreateWindowEx(
		0,		// расширенный стиль окна
		szClassWindow,	//имя класса окна
		TEXT("Бульбуляторщик"), // заголовок окна
		WS_OVERLAPPEDWINDOW,				// стиль окна
		/* Заголовок, рамка, позволяющая менять размеры, системное меню, кнопки развёртывания и свёртывания окна  */
		CW_USEDEFAULT,	// х-координата левого верхнего угла окна
		CW_USEDEFAULT,	// y-координата левого верхнего угла окна
		CW_USEDEFAULT,	// ширина окна
		CW_USEDEFAULT,	// высота окна
		NULL,			// дескриптор родительского окна
		NULL,			// дескриптор меню окна
		hInst,		// идентификатор приложения, создавшего окно
		NULL);		// указатель на область данных приложения

	// 4. Отображение окна
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd); // перерисовка окна

	// 5. Запуск цикла обработки сообщений
	while (GetMessage(&Msg, NULL, 0, 0)) // получение очередного сообщения из очереди сообщений
	{
		TranslateMessage(&Msg);	// трансляция сообщения
		DispatchMessage(&Msg);	// диспетчеризация сообщений
	}
	return Msg.wParam;
}

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam)
{
	switch (uMessage)
	{
	case WM_CLOSE:
	{
		int res = MessageBox(
			0,
			TEXT("Вы действительно хотите?"),
			TEXT("Скажите пожалуйста!"),
			MB_YESNO | MB_ICONINFORMATION);
		if (res == IDYES){
			DestroyWindow(hWnd);
		}
	} break;
	case WM_DESTROY:
		PostQuitMessage(0); // посылка сообщения WM_QUIT
		break;
	case WM_KEYDOWN:
		if (wParam == VK_CONTROL){
			EnumWindows(EnumWindowsProc, (LPARAM)hWnd);
		} 
		break;
	default:
		// все сообщения, которые не обрабатываются в данной оконной функции 
		// направляются обратно Windows на обработку по умолчанию
		return DefWindowProc(hWnd, uMessage, wParam, lParam);
}
return 0;
}

BOOL CALLBACK EnumWindowsProc(HWND hWnd, LPARAM lParam){
	TCHAR caption[_MAX_PATH] = { 0 }, classname[100] = { 0 }, text[500] = { 0 };
	GetWindowText(hWnd, caption, 100);//получаем текст заголовка нашего окна
	GetClassName(hWnd, classname, 100);//получаем имя класса окна

	if (!lstrcmp(classname, TEXT("CalcFrame"))) {
		int res = MessageBox(0, TEXT("Сделали"), TEXT("Готово"), MB_OK | MB_ICONINFORMATION);
		SetWindowText(hWnd, TEXT("Бульбулятор"));
	}
	return TRUE;
}